//
// Created by rect on 19.11.2023.
//

#include "../include/withoutNums.h"

Text getWithoutNums(Text text){
    Text newText;
    int newTextBuffer = 1;
    int newTextSize=0;
    newText.sentences = malloc(sizeof(Sentence)*newTextBuffer);
    for (int i=0;i<text.size;i++){
        Sentence tempSentence = text.sentences[i];
        Sentence newSentence;
        int newSentenceSize=0;
        int newSentenceBuffer=tempSentence.size+1;
        newSentence.chars = calloc(newSentenceBuffer,sizeof(wchar_t));
        wchar_t* tokBuffer;
        wchar_t * word = wcstok(wcsdup(tempSentence.chars),L" .,",&tokBuffer);
        int isNum = 1;
        int j=0;
        while (j<tempSentence.size) {
            wchar_t tempChar = tempSentence.chars[j];
            if(tempChar!=L' '&&tempChar!=L','&&tempChar!=L'.'){
            if(word==NULL) break;
            for(int k=0;k< wcslen(word);k++){
                if(!iswdigit(word[k])){
                    isNum=0;
                    break;
                }
            }

            int wordLength = wcslen(word);
            if (!isNum){
                newSentenceSize+= wordLength;
                j+= wordLength;
                if (newSentenceBuffer<=newSentenceSize){
                    newSentenceBuffer = newSentenceSize*2;
                    newSentence.chars = realloc(newSentence.chars,sizeof(wchar_t)*newSentenceBuffer);
                }

                wcscat(newSentence.chars,word);
            } else {

                if(tempSentence.chars[j+wordLength]=='.'){
                    if(newSentence.chars[newSentenceSize-2]==',') memmove(&newSentence.chars[j-2],&tempSentence.chars[j+wordLength],1);
                    else memmove(&newSentence.chars[newSentenceSize-1],&tempSentence.chars[j+wordLength],1);
                }
                if(tempSentence.chars[j+wordLength]==L','){
                    j+=wordLength+2;
                }
                if(tempSentence.chars[j+wordLength]==L' '){
                    j+=wordLength+1;
                }

            }
            word = wcstok(NULL,L" .,",&tokBuffer);
            isNum=1;
        } else {
                newSentence.chars[newSentenceSize++]=tempChar;
                j++;
            }

        }
        newText.sentences[newTextSize++]=newSentence;
        if (newTextBuffer<=newTextSize){
            newTextBuffer = newTextSize*2;
            newText.sentences = realloc(newText.sentences,sizeof(Sentence)*newTextBuffer);
        }
    }
    newText.size = newTextSize;
    return newText;
}
