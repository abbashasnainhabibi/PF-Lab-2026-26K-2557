#include <stdio.h>

int main(){
    int arr[3][3][3];
    int l, a, b, i, j, match, diff, identical, distinct;

    for(l=0;l<=2;l=l+1){
        for(i=0;i<=2;i=i+1){
            for(j=0;j<=2;j=j+1){
                printf("Enter element [%d][%d][%d]: ", l, i, j);
                scanf("%d", &arr[l][i][j]);
            }
        }
    }

    for(l=0;l<=2;l=l+1){
        printf("\nLayer %d\n", l);
        for(i=0;i<=2;i=i+1){
            for(j=0;j<=2;j=j+1){
                printf("%6d", arr[l][i][j]);
            }
            printf("\n");
        }
    }

    identical = 0;
    distinct = 0;

    printf("\nLayer Comparison\n");
    for(a=0;a<=1;a=a+1){
        for(b=a+1;b<=2;b=b+1){
            match = 0;
            diff = 0;
            printf("\nLayer %d vs Layer %d\n", a, b);
            for(i=0;i<=2;i=i+1){
                for(j=0;j<=2;j=j+1){
                    if(arr[a][i][j] == arr[b][i][j]){
                        match = match + 1;
                    } else {
                        diff = diff + 1;
                        printf("Difference at [%d][%d]: %d and %d\n", i, j, arr[a][i][j], arr[b][i][j]);
                    }
                }
            }
            printf("Matching elements = %d, Different elements = %d\n", match, diff);
            if(diff == 0){
                printf("Result: Layer %d and Layer %d are Identical\n", a, b);
                identical = identical + 1;
            } else {
                printf("Result: Layer %d and Layer %d are Distinct\n", a, b);
                distinct = distinct + 1;
            }
        }
    }

    printf("\nSummary\n");
    printf("Total pairs compared = 3\n");
    printf("Identical pairs = %d\n", identical);
    printf("Distinct pairs = %d\n", distinct);

    if(identical == 3){
        printf("All three layers are identical\n");
    } else if(identical == 0){
        printf("All three layers are distinct\n");
    } else {
        printf("Some layers are identical and some are distinct\n");
    }

    return 0;
}