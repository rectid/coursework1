//
// Created by rect on 17.11.2023.
//

#include "../include/colorful.h"

Text colorful(Text text) {
    Text coloredText;
    coloredText.sentences = malloc(sizeof(Sentence)*text.size);
    int coloredTextSize = 0;
    for (int i = 0; i < text.size; i++) {
        Sentence tempSentence = text.sentences[i];
        char* temp = strdup(tempSentence.chars);
        Sentence newSentence;
        int newSentenceSize=0;
        int newSentenceBuffer=tempSentence.size;
        newSentence.chars = calloc(newSentenceBuffer,sizeof(char));
        int j =0;
        char* word = strtok(temp," ,.");
        while (j<tempSentence.size) {
            char tempChar = tempSentence.chars[j];

            if(tempChar!=' '&&tempChar!=','&&tempChar!='.'){
                int wordLength = strlen(word);
                j+= wordLength;
                int color = wordLength%4;
                char* toCatWord = calloc(wordLength,wordLength*2);


                switch (color) {
                    case 0:
                        strcat(toCatWord, RED);
                        break;
                    case 1:
                        strcat(toCatWord, BLUE);
                        break;
                    case 2:
                        strcat(toCatWord, GREEN);
                        break;
                    case 3:
                        strcat(toCatWord, YELLOW);
                        break;
                }
                strcat(toCatWord, word);
                strcat(toCatWord, RESET);

                newSentenceSize+= strlen(toCatWord);
                if (newSentenceBuffer<=newSentenceSize){
                    newSentenceBuffer = newSentenceSize*2;
                    newSentence.chars = realloc(newSentence.chars,sizeof(char)*newSentenceBuffer);
                }

                strcat(newSentence.chars,toCatWord);
                word = strtok(NULL, " ,.");
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

