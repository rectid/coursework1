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
        int newSentenceBuffer=tempSentence.size;
        newSentence.chars = calloc(newSentenceBuffer,sizeof(char));
        char* temp = strdup(tempSentence.chars);
        char* word = strtok(temp," .,");
        int isNum = 1;
        int j=0;
        while (j<tempSentence.size) {
            char tempChar = tempSentence.chars[j];
            if(tempChar!=' '&&tempChar!=','&&tempChar!='.'){
            if(word==NULL) break;
            for(int k=0;k< strlen(word);k++){
                if(!isdigit(word[k])){
                    isNum=0;
                    break;
                }
            }

            int wordLength = strlen(word);
            if (!isNum){
                newSentenceSize+= wordLength;
                j+= wordLength;
                if (newSentenceBuffer<=newSentenceSize){
                    newSentenceBuffer = newSentenceSize*2;
                    newSentence.chars = realloc(newSentence.chars,sizeof(char)*newSentenceBuffer);
                }

                strcat(newSentence.chars,word);
            } else {

                if(tempSentence.chars[j+wordLength]=='.'){
                    if(newSentence.chars[newSentenceSize-2]==',') memmove(&newSentence.chars[j-2],&tempSentence.chars[j+wordLength],1);
                    else memmove(&newSentence.chars[newSentenceSize-1],&tempSentence.chars[j+wordLength],1);
                }
                if(tempSentence.chars[j+wordLength]==','){
                    j+=wordLength+2;
                }
                if(tempSentence.chars[j+wordLength]==' '){
                    j+=wordLength+1;
                }

            }
            word = strtok(NULL," .,");
            isNum=1;
        } else {
                newSentence.chars[newSentenceSize++]=tempChar;
                j++;
            }

        }
        newText.sentences[newTextSize++]=newSentence;
        if (newTextBuffer<=newTextSize){
            newTextBuffer = newTextSize+1;
            newText.sentences = realloc(newText.sentences,sizeof(Sentence)*newTextBuffer);
        }
    }
    newText.size = newTextSize;
    return newText;
}
