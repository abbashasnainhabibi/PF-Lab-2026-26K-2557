#include <stdio.h>

int isValidMark(int m){
    if(m >= 0 && m <= 100){
        return 1;
    }
    return 0;
}

void findMinMax(int arr[], int size, int *min, int *max){
    int i;
    *min = arr[0];
    *max = arr[0];
    for(i = 1; i < size; i++){
        if(arr[i] < *min){
            *min = arr[i];
        }
        if(arr[i] > *max){
            *max = arr[i];
        }
    }
}

int main(){
    int marks[5];
    int i, val;
    int min, max;

    for(i = 0; i < 5; i++){
        while(1){
            printf("Enter mark %d: ", i + 1);
            scanf("%d", &val);
            if(isValidMark(val)){
                marks[i] = val;
                break;
            }else{
                printf("Invalid mark, enter again\n");
            }
        }
    }

    findMinMax(marks, 5, &min, &max);

    printf("Lowest mark: %d\n", min);
    printf("Highest mark: %d\n", max);

    return 0;
}
