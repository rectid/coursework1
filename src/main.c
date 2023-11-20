//
// Created by rect on 15.11.2023.
//

#include "../include/main.h"

int main(){
    setlocale(LC_ALL, "");
    wprintf(YELLOW L"Course work for option 5.7, created by Vladislav Poddubnyi.\n" DEFAULT);
    switch (getChoice()) {
        case 0:
            printText(getText());
            break;
        case 1:
            printText(getColored(getText()));
            break;
        case 2:
            printText(getUpperCaseWords(getText()));
            break;
        case 3:
            printText(getSorted(getText()));
            break;
        case 4:
            printText(getWithoutNums(getText()));
            break;
        case 5:
            break;
        default:
            fwprintf(stderr, RED L"Error: Incorrect function. Input 5 for list of functions.\n");
    }
    return 0;
}
