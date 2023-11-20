//
// Created by rect on 15.11.2023.
//

#include "../include/main.h"
#include <stdio.h>

int main(){
    printf("Course work for option 5.7, created by Vladislav Poddubnyi.\n");
    int userChoice;
    scanf("%d\n",&userChoice);
    Text text = getText();
    switch (userChoice) {
        case 0:
            printText(text);
            break;
        case 1:
            printText(colorful(text));
            break;
        case 2:
            printText(getUpperCaseWords(text));
            break;
        case 3:
            printText(getSorted(text));
            break;
        case 4:
            printText(getWithoutNums(text));
            break;
        case 5:
            break;
    }
    return 0;
}
