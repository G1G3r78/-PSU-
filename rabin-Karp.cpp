#include <stdio.h>
#include <string.h>

int rabinKarpSearch(char *text, char *str){
    unsigned int strLen = strlen(str); //длина подстроки
    unsigned int textLen = strlen(text); //длина строки

    int h = 0; //вспом. перемен.

    //хэш подстроки для поиска
    int strHash = ringHash(str, strLen, 0, &h);
    //хэш подстроки внутри строки
    int textHash = ringHash(text, strLen, 0, &h);

    //поиск совпадения хешей
    for (unsigned int k = 0; k <= (textLen-strLen); k++){
        if (strHash == textHash) {
            for (unsigned int i = 0; i < strLen && (str[i] == text[k+i]); i++){
                if (i == strLen-1) return k; //if(все символы (дойдя до последнего индексы совпали))

            }
        }
        //хэш следующего окна (страый хеш - вклад символа + вклад нового символа)
        textHash = ringHash(&text[k], strLen, textHash, &h);
    }
    return -1; //индекс окна(подстроки) не найден
}