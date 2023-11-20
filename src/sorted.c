//
// Created by rect on 19.11.2023.
//

#include "../include/sorted.h"

int compare(const void *a, const void *b){
    Sentence* sentenceOne = (Sentence *) a;
    Sentence* sentenceTwo = (Sentence *) b;

    wchar_t *lastWordOne = NULL;
    wchar_t* tokBufferOne;
    wchar_t *tokenOne = wcstok(wcsdup(sentenceOne->chars), L" ,.", &tokBufferOne);
    while (tokenOne != NULL) {
        lastWordOne = tokenOne;
        tokenOne = wcstok(NULL, L" ,.", &tokBufferOne);
    }

    wchar_t *lastWordTwo = NULL;
    wchar_t* tokBufferTwo;
    wchar_t *tokenTwo = wcstok(wcsdup(sentenceTwo->chars), L" ,.", &tokBufferTwo);
    while (tokenTwo != NULL) {
        lastWordTwo = tokenTwo;
        tokenTwo = wcstok(NULL, L" ,.", &tokBufferTwo);
    }

    return wcslen(lastWordOne) - wcslen(lastWordTwo);
}

Text getSorted(Text text){

    qsort(text.sentences, text.size, sizeof(Sentence), compare);

    return text;
}
