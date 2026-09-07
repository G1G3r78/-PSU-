#include <iostream>
#include <string>

using namespace std;

const int NO_OF_CHARS = 10;

//эвристика плохого символа - таблица вхождений и сдвигов символов подстроки
void badCharHeuristic(string str, int strLen, int badChar[NO_OF_CHARS]){
    for (int i = 0; i < NO_OF_CHARS; i++){
        badChar[i] = -1;//-1 если символа нет в подстроке
    }
    for (int i = 0; i < strLen; i++){
        badChar[str[i]] = i;//массив позиций последних вхождений символов подстроки
    }
}

void search(string text, string str){
    int textSize = text.size();
    int strSize = str.size();
    int badChar[NO_OF_CHARS];

    int s = 0;//перем. для вычисления последнего вхождения и сдвига

    badCharHeuristic(str, strSize, badChar);

    while (s <= (textSize-strSize)){
        for (int j = strSize-1; j >= 0 && str[j] == text[j+s]; j--){
            if (j < 0) {
                cout << "Есть совпадение - найдена подстрока со сдвига " << s << endl;
                s += (s + strSize < textSize) ? strSize - badChar[text[s+strSize]] : 1;//свдиг на след. символ
            }
                else s += max(1, j - badChar[text[j+s]]);//сдвиг, text[j+s] - индекс где произошло несовпадение
        }
    }
}