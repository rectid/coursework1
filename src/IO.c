//
// Created by rect on 17.11.2023.
//

#include "../include/IO.h"

Text getText(){
    Text text;
    text.sentences = malloc(sizeof(Sentence));
    int textSize = 0, textBuffer=1;
    int nCounter=0;
    for(;;){
        Sentence tempSentence = getSentence(&nCounter);
        int equalSentence=0;
        for (int i = 0; i < textSize; ++i) {
            if(strcasecmp(tempSentence.chars,text.sentences[i].chars)==0){
                equalSentence=1;
                break;
            }
        }
        if (nCounter==2) break;
        else nCounter=0;
        if(equalSentence==1) continue;
        text.sentences[textSize++]=tempSentence;
        text.size=textSize;
            if (textSize == textBuffer) {
                textBuffer *= 2;
                text.sentences = realloc(text.sentences, sizeof(Sentence) * textBuffer);
            }

    };
    return text;

}


Sentence getSentence(int *nCounter){
    Sentence sentence;
    sentence.chars = malloc(sizeof(char));
    int sentenceSize = 0;
    int sentenceBuffer = 1;
    char tempChar;
    do{
        tempChar = getchar();
        if (tempChar=='\n') {
            (*nCounter)++;
            if((*nCounter)==2){
                break;
            }
            continue;
        }
        sentence.chars[sentenceSize++]=tempChar;


        if(sentenceSize==sentenceBuffer){
            sentenceBuffer *= 2;
            sentence.chars = realloc(sentence.chars, sizeof(char) * sentenceBuffer);
        }

    } while (tempChar!='.');
    sentence.chars[sentenceSize]='\0';
    sentence.size=sentenceSize;
    return sentence;
}

void printText(Text text){
    for (int i = 0; i < text.size; i++) {
        printf("%s\n", text.sentences[i].chars);
    }
    printf("\n");
}
