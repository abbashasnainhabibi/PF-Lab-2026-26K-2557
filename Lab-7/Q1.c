#include <stdio.h>

int main(){
    int mat[3][3], trans[3][3], cof[3][3], adj[3][3];
    float inv[3][3];
    int i, j, r, c, k, det, minor, sign;
    int m[4];

    for(i=0;i<=2;i=i+1){
        for(j=0;j<=2;j=j+1){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nOriginal Matrix\n");
    for(i=0;i<=2;i=i+1){
        for(j=0;j<=2;j=j+1){
            printf("%6d", mat[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<=2;i=i+1){
        for(j=0;j<=2;j=j+1){
            trans[j][i] = mat[i][j];
        }
    }

    printf("\nTranspose\n");
    for(i=0;i<=2;i=i+1){
        for(j=0;j<=2;j=j+1){
            printf("%6d", trans[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<=2;i=i+1){
        for(j=0;j<=2;j=j+1){
            k = 0;
            for(r=0;r<=2;r=r+1){
                for(c=0;c<=2;c=c+1){
                    if(r!=i && c!=j){
                        m[k] = mat[r][c];
                        k = k + 1;
                    }
                }
            }
            minor = m[0]*m[3] - m[1]*m[2];
            if((i+j)%2 == 0){
                sign = 1;
            } else {
                sign = -1;
            }
            cof[i][j] = sign * minor;
        }
    }

    printf("\nCofactor Matrix\n");
    for(i=0;i<=2;i=i+1){
        for(j=0;j<=2;j=j+1){
            printf("%6d", cof[i][j]);
        }
        printf("\n");
    }

    det = 0;
    for(j=0;j<=2;j=j+1){
        det = det + mat[0][j] * cof[0][j];
    }

    printf("\nDeterminant = %d\n", det);

    for(i=0;i<=2;i=i+1){
        for(j=0;j<=2;j=j+1){
            adj[j][i] = cof[i][j];
        }
    }

    printf("\nAdjoint\n");
    for(i=0;i<=2;i=i+1){
        for(j=0;j<=2;j=j+1){
            printf("%6d", adj[i][j]);
        }
        printf("\n");
    }

    printf("\nInverse\n");
    if(det == 0){
        printf("Inverse does not exist because determinant is 0\n");
    } else {
        for(i=0;i<=2;i=i+1){
            for(j=0;j<=2;j=j+1){
                inv[i][j] = (float)adj[i][j] / det;
                printf("%8.2f", inv[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}