#include <stdio.h>
#include "3C_functions.h"

#define TEXTLINE_LENGTH 255

int main(int *argc, char *argv[])
{
    FILE *fInputHandle;
    FILE *fOutputHandle;

    fInputHandle = fopen(argv[1], "r");

    if(fInputHandle == NULL)
    {
        printf("Nepavyko atidaryti duomenu failo!\nNaudojimas: ./OutFile.out <input_file.txt> <output_file.txt>\n");
        return 0;
    }

    fOutputHandle = fopen(argv[2], "w");

    if(fOutputHandle == NULL)
    {
        printf("Nepavyko sukurti rezultatu failo!\nNaudojimas: ./OutFile.out <input_file.txt> <output_file.txt>\n");
        return 0;
    }

    char cText[TEXTLINE_LENGTH];
    char cFinalLine[TEXTLINE_LENGTH];

    while(fgets(cText, TEXTLINE_LENGTH - 1, fInputHandle) != NULL)
    {
        FormatLine(cText, sizeof(cText), cFinalLine);
        fputs(cFinalLine, fOutputHandle);
    }
    fclose(fInputHandle);
    fclose(fOutputHandle);
    return 0;
}

