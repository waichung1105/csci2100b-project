#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* file = fopen ("qs-half.txt", "r");
    int i = 0;
    int count = 1;

    while (count <= 10){
        fscanf (file, "%*s %d", &i);
        printf ("%d ", i);
        printf("\n");
        count++;
    }
    fclose (file);
}