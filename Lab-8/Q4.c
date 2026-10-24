#include <stdio.h>

float averageSteps(int *steps, int n){
    float sum = 0.0;
    int i;
    for(i = 0; i < n; i++){
        sum = sum + *(steps + i);
    }
    return sum / n;
}

int countGoalDays(int *steps, int n, int goal){
    int count = 0;
    int i;
    for(i = 0; i < n; i++){
        if(*(steps + i) >= goal){
            count++;
        }
    }
    return count;
}

int main(){
    int steps[7];
    int i;
    float avg;
    int goals;

    for(i = 0; i < 7; i++){
        printf("Enter steps for day %d: ", i + 1);
        scanf("%d", &steps[i]);
    }

    avg = averageSteps(steps, 7);
    goals = countGoalDays(steps, 7, 8000);

    printf("Average steps: %.2f\n", avg);
    printf("Days goal reached (8000 or more): %d\n", goals);

    return 0;
}
