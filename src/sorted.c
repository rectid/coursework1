//
// Created by rect on 19.11.2023.
//

#include "../include/sorted.h"

int compare(const void *a, const void *b){
    Sentence* sentenceOne = (Sentence *) a;
    Sentence* sentenceTwo = (Sentence *) b;

    char *lastWordOne = NULL;
    char *tokenOne = strtok(strdup(sentenceOne->chars), " ,.");
    while (tokenOne != NULL) {
        lastWordOne = tokenOne;
        tokenOne = strtok(NULL, " ,.");
    }

    char *lastWordTwo = NULL;
    char *tokenTwo = strtok(strdup(sentenceTwo->chars), " ,.");
    while (tokenTwo != NULL) {
        lastWordTwo = tokenTwo;
        tokenTwo = strtok(NULL, " ,.");
    }

    return strlen(lastWordOne) - strlen(lastWordTwo);
}

Text getSorted(Text text){

    qsort(text.sentences, text.size, sizeof(Sentence), compare);

    return text;
}
