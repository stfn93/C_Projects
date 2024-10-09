#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    FILE *img = NULL;
    char filename[8];
    int count = 0;

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // While there's still data left to read from the memory card
    while (fread(buffer, sizeof(uint8_t), 512, card) == 512)
    {
        // Check if the block indicates the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the previous image file if one is open
            if (img != NULL)
            {
                fclose(img);
            }
            // Create a new file for the JPEG
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create %s.\n", filename);
                return 3;
            }
            count++;
        }
        // If an image file is open, write the block to the image file
        if (img != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, img);
        }
    }
    // Close the last image file if it was open
    if (img != NULL)
    {
        fclose(img);
    }

    // Close the memory card file
    fclose(card);

    return 0;
}
