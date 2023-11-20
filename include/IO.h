//
// Created by rect on 17.11.2023.
//

#ifndef CW_IO_H
#define CW_IO_H
#include <ctype.h>
#include "structs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
Text getText();
void printText(Text text);
Sentence getSentence(int *nCounter);
#endif //CW_IO_H
