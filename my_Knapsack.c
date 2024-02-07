#include <stdio.h>
#include "my_mat.h"


// Make sure selectItems is correctly declared/defined
int selectItems(int weights[], int values[], int selected_bool[]);

int main(){
    char items[SIZE_ITEMS];
    int weights[SIZE_ITEMS];
    int values[SIZE_ITEMS];
    int selected_bool[SIZE_ITEMS] = {0, 0, 0, 0, 0};

    for(int i = 0; i < SIZE_ITEMS; i++) {
        scanf(" %c %d %d", &items[i], &values[i], &weights[i]);
    }

    printf("Maximum profit: %d", selectItems(weights, values, selected_bool));
    printf("\nSelected items: ");
    for(int j = 0; j < SIZE_ITEMS; j++) {
        if(selected_bool[j] == 1){
            printf("%c ", items[j]);
        }
    }

    return 0;
}



    