//
// Created by rect on 18.11.2023.
//

#include "../include/upper_case_words.h"

Text getUpperCaseWords(Text text){
    Text newText;
    int wordArrayBuffer =1, newTextBuffer = 1;
    newText.sentences = malloc(sizeof(Sentence)*newTextBuffer);
    int wordArraySize = 0, newTextSize=0;
    Word* wordArray = malloc(wordArrayBuffer*sizeof(Word));
    for (int i=0;i<text.size;i++){
        Sentence tempSentence = text.sentences[i];
        char* tempSentenceChars = tempSentence.chars;
        char* word = strtok(tempSentenceChars," .,");

        while (word!=NULL){

            if (isupper(word[0])&& isupper(word[strlen(word)-1])){
                int founded=0;
                for (int j = 0; j < wordArraySize; ++j) {
                    if (strcmp(word,wordArray[j].word)==0){
                        founded=1;
                        if ((wordArray[j].occurrences[wordArray[j].occurrencesSize-1])==i) continue;
                        wordArray[j].occurrences = realloc(wordArray[j].occurrences,sizeof(int)*(wordArray[j].occurrencesSize*2));
                        wordArray[j].occurrences[wordArray[j].occurrencesSize++] = i;
                    }
                }
                if(founded==0){
                    wordArray[wordArraySize].occurrences = malloc(sizeof(int)*1);
                    wordArray[wordArraySize].occurrencesSize = 0;
                    wordArray[wordArraySize].occurrences[wordArray[wordArraySize].occurrencesSize++] = i;
                    wordArray[wordArraySize].word = strdup(word);
                    wordArraySize++;
                    if (wordArrayBuffer<=wordArraySize){
                        wordArrayBuffer+=1;
                        wordArray = realloc(wordArray, wordArrayBuffer*sizeof(Word));
                    }
                }
            }

            word = strtok(NULL," .,");
        }
    }

    for (int i = 0; i < wordArraySize; ++i) {
        Sentence newSentence;
        char* wordStructToString = calloc((strlen(wordArray[i].word)+(wordArray[i].occurrencesSize*5)),sizeof(char));
        char charOccurrences[wordArray[i].occurrencesSize][100];
        strcat(wordStructToString,wordArray[i].word);
        strcat(wordStructToString,": ");
        for (int j = 0; j < wordArray[i].occurrencesSize; ++j) {
            sprintf(charOccurrences[j], "%d", wordArray[i].occurrences[j]);
            strcat(wordStructToString, charOccurrences[j]);
            strcat(wordStructToString, " ");
        }
        int length = strlen(wordStructToString);
        wordStructToString[length]='\0';
        newSentence.chars= strdup(wordStructToString);
        free(wordStructToString);
        newSentence.size= strlen(newSentence.chars);
        if(newTextBuffer<=newTextSize){
            newTextBuffer*=2;
            newText.sentences = realloc(newText.sentences,sizeof(Sentence)*newTextBuffer);
        }
        newText.sentences[newTextSize++]=newSentence;
    }
    newText.size=newTextSize;
    return newText;
}