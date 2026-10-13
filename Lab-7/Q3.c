#include <stdio.h>

int main(){
    int a[3][3], b[3][3], res[3][3];
    int r1, c1, r2, c2, i, j, k;

    printf("Enter rows of first matrix (1 to 3): ");
    scanf("%d", &r1);
    printf("Enter columns of first matrix (1 to 3): ");
    scanf("%d", &c1);
    printf("Enter rows of second matrix (1 to 3): ");
    scanf("%d", &r2);
    printf("Enter columns of second matrix (1 to 3): ");
    scanf("%d", &c2);

    if(r1<1 || r1>3 || c1<1 || c1>3 || r2<1 || r2>3 || c2<1 || c2>3){
        printf("Invalid size. Maximum size is 3x3\n");
        return 0;
    }

    if(c1 != r2){
        printf("Multiplication not possible because columns of first matrix (%d) are not equal to rows of second matrix (%d)\n", c1, r2);
        return 0;
    }

    printf("\nEnter first matrix\n");
    for(i=0;i<=r1-1;i=i+1){
        for(j=0;j<=c1-1;j=j+1){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter second matrix\n");
    for(i=0;i<=r2-1;i=i+1){
        for(j=0;j<=c2-1;j=j+1){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nFirst Matrix\n");
    for(i=0;i<=r1-1;i=i+1){
        for(j=0;j<=c1-1;j=j+1){
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }

    printf("\nSecond Matrix\n");
    for(i=0;i<=r2-1;i=i+1){
        for(j=0;j<=c2-1;j=j+1){
            printf("%6d", b[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<=r1-1;i=i+1){
        for(j=0;j<=c2-1;j=j+1){
            res[i][j] = 0;
            for(k=0;k<=c1-1;k=k+1){
                res[i][j] = res[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    printf("\nResult Matrix (%d x %d)\n", r1, c2);
    for(i=0;i<=r1-1;i=i+1){
        for(j=0;j<=c2-1;j=j+1){
            printf("%6d", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}