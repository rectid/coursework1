//
// Created by rect on 17.11.2023.
//

#ifndef CW_STRUCTS_H
#define CW_STRUCTS_H
typedef struct{
    char* chars;
    int size;
}Sentence;

typedef struct{
    Sentence* sentences;
    int size;
}Text;

typedef struct{
    char* word;
    int* occurrences;
    int occurrencesSize;
} Word;


#endif //CW_STRUCTS_H
