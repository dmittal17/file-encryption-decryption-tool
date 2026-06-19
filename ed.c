#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch;
    char name[50];
    char key;

    printf("PRESS 1 if you want to choose ENCRYPTION\n");
    printf("PRESS 2 if you want to choose DECRYPTION\n");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
        {
            printf("ENTER THE NAME OF YOUR FILE TO ENCRYPT\n");
            scanf("%49s", name);

            printf("ENTER YOUR CHARACTER KEY\n");
            scanf(" %c", &key);

            FILE *fptr = fopen(name, "rb");

            if (fptr == NULL)
            {
                printf("Error opening input file!\n");
                return 1;
            }

            FILE *fpr = fopen("encrypted_file.txt", "wb");

            if (fpr == NULL)
            {
                printf("Error creating output file!\n");
                fclose(fptr);
                return 1;
            }

            int c;
            while ((c = fgetc(fptr)) != EOF)
            {
                unsigned char x = (unsigned char)c;
                x = x ^ key;
                fputc(x, fpr);
            }

            fclose(fptr);
            fclose(fpr);

            printf("Encryption complete.\n");
            break;
        }

        case 2:
        {
            printf("ENTER THE NAME OF YOUR FILE TO DECRYPT\n");
            scanf("%49s", name);

            printf("ENTER YOUR CHARACTER KEY\n");
            scanf(" %c", &key);

            FILE *fpoint = fopen(name, "rb");

            if (fpoint == NULL)
            {
                printf("Error opening input file!\n");
                return 1;
            }

            FILE *fp = fopen("decrypted_file.txt", "wb");

            if (fp == NULL)
            {
                printf("Error creating output file!\n");
                fclose(fpoint);
                return 1;
            }

            int d;
            while ((d = fgetc(fpoint)) != EOF)
            {
                unsigned char x = (unsigned char)d;
                x = x ^ key;
                fputc(x, fp);
            }

            fclose(fpoint);
            fclose(fp);

            printf("Decryption complete.\n");
            break;
        }

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}