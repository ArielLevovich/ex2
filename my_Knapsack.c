#include <stdio.h>
#include "my_mat.h"

int main(){
    char items[5];
    int weights[5];
    int values[5];
    int selected_bool[] = {0,0,0,0,0};
    for(int i = 0; i < SIZE_ITEMS; i++) {
        scanf("%c %d %d", items[i], values[i],weights[i]);
    }
    printf("Maximum profit: " + selectItems(weights,values,selected_bool));
    printf("Selected items: ");
    for(int j = 0; j < SIZE_ITEMS; j++) {
        if(selected_bool[j] == 1){
            printf("%d"+values[j]);
        }
    }

    return 0;
}


    