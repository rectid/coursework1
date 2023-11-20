//
// Created by rect on 17.11.2023.
//

#ifndef CW_COLORFUL_H
#define CW_COLORFUL_H

#include "structs.h"
#include <string.h>
#include <stdio.h>
#include "stdlib.h"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

Text colorful(Text text);
#endif //CW_COLORFUL_H
