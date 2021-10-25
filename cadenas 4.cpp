#include <iostream>
#include "string.h"
using namespace std;

void formatearNum(char number[], char reg[]){
    char ar[3] = "ar";
    char en[3] = "en";
    int i = 0;
    if (strcmp(ar, reg) == 0)
    {
        for (i; i < strlen(number); i++)
        {
            if (number[i] == ',')
            {
                number[i] = '.';
            }
        }    
    }else{
        for (i = 0; i < strlen(number); i++)
        {
            if (number[i] == '.')
            {
                number[i] = ',';
            }
        }
    }
}


int main () {
    char number[80] = "753.941.123";
    char reg[3] = "en";

    formatearNum(number, reg);
    
    system("pause");
    return 0;
}