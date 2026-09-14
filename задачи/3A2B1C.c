#include <stdio.h>

int main(){

    FILE *f = fopen("file.txt", "r");

    char current = fgetc(f);

    int count = 1;

    while (current != EOF){
        char next = fgetc(f);
        if (current == next) count++;
            else {
                printf("%d%c", count, current);
                count = 1;
                current = next;
            }
    }

    fclose(f);
    return 0;
}