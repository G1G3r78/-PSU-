#include <stdio.h>

int find(char *str, char *txt){
    for (int i = 0; txt[i]; ++i){
        for (int j = 0;;++j){
            if (!str[j]) return i;
            if (txt[i+j] != str[i]) break;
        }
    }
    return -1;
}