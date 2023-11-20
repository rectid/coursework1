//
// Created by rect on 17.11.2023.
//

#include "../include/colored.h"

Text getColored(Text text) {
    Text coloredText;
    coloredText.sentences = malloc(sizeof(Sentence)*text.size);
    int coloredTextSize = 0;
    for (int i = 0; i < text.size; i++) {
        Sentence tempSentence = text.sentences[i];
        Sentence newSentence;
        int newSentenceSize=0;
        int newSentenceBuffer=tempSentence.size+1;
        newSentence.chars = calloc(newSentenceBuffer,sizeof(wchar_t));
        int j =0;
        wchar_t* tokBuffer;
        wchar_t* word = wcstok(wcsdup(tempSentence.chars),L" ,.",&tokBuffer);
        while (j<tempSentence.size) {
            wchar_t tempChar = tempSentence.chars[j];

            if(tempChar!=' '&&tempChar!=','&&tempChar!='.'){
                int wordLength = wcslen(word);
                j+= wordLength;
                int color = wordLength%4;
                wchar_t * toCatWord = calloc(wordLength, (wcslen(RED)*2+wordLength)*sizeof(wchar_t));


                switch (color) {
                    case 0:
                        wcscat(toCatWord, RED);
                        break;
                    case 1:
                        wcscat(toCatWord, BLUE);
                        break;
                    case 2:
                        wcscat(toCatWord, GREEN);
                        break;
                    case 3:
                        wcscat(toCatWord, YELLOW);
                        break;
                }
                wcscat(toCatWord, word);
                wcscat(toCatWord, DEFAULT);

                newSentenceSize+= wcslen(toCatWord);
                if (newSentenceBuffer<=newSentenceSize){
                    newSentenceBuffer = newSentenceSize*3;
                    newSentence.chars = realloc(newSentence.chars,sizeof(wchar_t)*newSentenceBuffer);
                }

                wcscat(newSentence.chars,toCatWord);
                word = wcstok(NULL,L" ,.",&tokBuffer);
            } else {
                newSentence.chars[newSentenceSize++]=tempChar;
                j++;
            }


        }
        coloredText.sentences[coloredTextSize++]=newSentence;

    }

    coloredText.size = text.size;

    return coloredText;
}

