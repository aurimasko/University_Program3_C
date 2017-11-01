#include "3C_functions.h"

void FormatLine(char cText[], int iTextSize, char cFinalLine[])
{
    int iWordStartChar = 0, iWordEndChar = 0, iWordLength = 0;
    int iFoundOurWord = 0;
    int iLineSize = 0;
    int i = 0;

    for(i = 0; i < iTextSize; i++)
        cFinalLine[i] = 0;

    iWordStartChar = 0;

    while(cText[iWordStartChar] != '\n')
    {
        for(; cText[iWordStartChar] == ' '; iWordStartChar++);
        for(iWordEndChar = iWordStartChar; cText[iWordEndChar] != ' ' && cText[iWordEndChar] != '\n'; iWordEndChar++);

        iFoundOurWord = 0;
        iWordLength = iWordEndChar - iWordStartChar;

        for(i = 0; iWordStartChar+i < iWordEndChar; i++)
        {
            if(cText[iWordStartChar+i] == cText[iWordEndChar-i-1])
                iFoundOurWord = 1;
            else
            {
                iFoundOurWord = 0;
                break;
            }
        }

        if(iFoundOurWord == 1)
        {
            for(i = iWordStartChar; i < iWordEndChar; i++)
            {
                cFinalLine[iLineSize] = cText[i];
                iLineSize++;
            }
            cFinalLine[iLineSize] = '\n';
            iLineSize++;
        }
        iWordStartChar += iWordLength;
    }
}
