#include <stdio.h>
#include <string.h>

#define MAX 1000
//таблица(массив) pi - макс. длин совп. префффиксов и суффиксов
void pi_prefix_suffix(char pattern[], int pi[], int n){//подстрока, pi - макс. длин совп. префффиксов и суффиксов, длина подстроки
    pi[0] = 0;//первый всегда 0
    //всё что написал ниже строка это подстрока, а подстрока это префиксы/суффиксы
    for (int i = 1; i < n; i++){
        int j = pi[i-1];//длина найденного совпадающего префиска
        while (j > 0 && pattern[i] != pattern[j]){ //пока не совпадают символы строки и подстроки, уводим подстроку назад, начиная с индекса-длины
            j = pi[j-1];
        }
        if (pattern[i] == pattern[j]){ //символы теперь совпадают, значит стравниваем послед. символы строки и подстроки
            j++;
        }
        pi[i] = j;
    }
}

int kmp(char text[], char pattern[]) {//поиск индекса начала подстроки
    int n = strlen(text);//длина строки
    int m = strlen(pattern); //длина подстроки

    int pi[MAX];//массив длин совпадений

    pi_prefix_suffix(pattern, pi, n);//построение pi

    int j = 0;

    for (int i = 0; i < n; i++){
        while (j > 0 && text[i] != pattern[j]){
            j = pi[j-1];
        }
        if (pattern[j] == text[i]){
            j++;
        }
        if (j == m) {
            return i-m+1;//нашли подстроку и выводим индекс
        }
    }
    return -1;
}

int main(){

    char text[] = "ABABDABABC";
    char pattern[] = "ABABC";

    int result = kmp(text, pattern);

    if (result == -1)
    {
        printf("Подстрока не найдена\n");
    }
    else
    {
        printf("Подстрока найдена с позиции %d\n", result);
    }

    return 0;
}