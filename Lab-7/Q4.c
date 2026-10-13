#include <stdio.h>

int main(){
    int arr[3][3][3], lsum[3], lmax[3], lmin[3];
    float lavg, oavg;
    int l, i, j, total;
    int max, min, maxL, maxI, maxJ, minL, minI, minJ;
    int bestLayer, worstLayer, even, odd, pos, neg, zero;

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

    for(l=0;l<=2;l=l+1){
        lsum[l] = 0;
        lmax[l] = arr[l][0][0];
        lmin[l] = arr[l][0][0];
        for(i=0;i<=2;i=i+1){
            for(j=0;j<=2;j=j+1){
                lsum[l] = lsum[l] + arr[l][i][j];
                if(arr[l][i][j] > lmax[l]){
                    lmax[l] = arr[l][i][j];
                }
                if(arr[l][i][j] < lmin[l]){
                    lmin[l] = arr[l][i][j];
                }
            }
        }
    }

    printf("\nLayer-wise Analysis\n");
    for(l=0;l<=2;l=l+1){
        lavg = (float)lsum[l] / 9;
        printf("Layer %d: Total = %d, Average = %.2f, Max = %d, Min = %d\n", l, lsum[l], lavg, lmax[l], lmin[l]);
    }

    total = 0;
    max = arr[0][0][0];
    min = arr[0][0][0];
    maxL = 0; maxI = 0; maxJ = 0;
    minL = 0; minI = 0; minJ = 0;
    even = 0;
    odd = 0;
    pos = 0;
    neg = 0;
    zero = 0;

    for(l=0;l<=2;l=l+1){
        for(i=0;i<=2;i=i+1){
            for(j=0;j<=2;j=j+1){
                total = total + arr[l][i][j];
                if(arr[l][i][j] > max){
                    max = arr[l][i][j];
                    maxL = l;
                    maxI = i;
                    maxJ = j;
                }
                if(arr[l][i][j] < min){
                    min = arr[l][i][j];
                    minL = l;
                    minI = i;
                    minJ = j;
                }
                if(arr[l][i][j] % 2 == 0){
                    even = even + 1;
                } else {
                    odd = odd + 1;
                }
                if(arr[l][i][j] > 0){
                    pos = pos + 1;
                } else if(arr[l][i][j] < 0){
                    neg = neg + 1;
                } else {
                    zero = zero + 1;
                }
            }
        }
    }

    bestLayer = 0;
    worstLayer = 0;
    for(l=1;l<=2;l=l+1){
        if(lsum[l] > lsum[bestLayer]){
            bestLayer = l;
        }
        if(lsum[l] < lsum[worstLayer]){
            worstLayer = l;
        }
    }

    oavg = (float)total / 27;

    printf("\nOverall Insights\n");
    printf("Grand Total = %d\n", total);
    printf("Overall Average = %.2f\n", oavg);
    printf("Largest Element = %d at [%d][%d][%d]\n", max, maxL, maxI, maxJ);
    printf("Smallest Element = %d at [%d][%d][%d]\n", min, minL, minI, minJ);
    printf("Layer with highest total = Layer %d (%d)\n", bestLayer, lsum[bestLayer]);
    printf("Layer with lowest total = Layer %d (%d)\n", worstLayer, lsum[worstLayer]);
    printf("Even elements = %d, Odd elements = %d\n", even, odd);
    printf("Positive = %d, Negative = %d, Zero = %d\n", pos, neg, zero);

    return 0;
}