#include <stdio.h>

int main(){
    int a[5][5], b[5][5], pw[5][5], q[5][5];
    float t[5][5], det, f, tmp;
    int r, c, r2, c2, i, j, k, step, pv;
    int sq, zero, id, dg, sc, up, lo, sy, sk, eq, idem, nil, singular, z;

    printf("Enter rows (1 to 5): ");
    scanf("%d", &r);
    printf("Enter columns (1 to 5): ");
    scanf("%d", &c);

    if(r<1 || r>5 || c<1 || c>5){
        printf("Invalid size\n");
        return 0;
    }

    for(i=0;i<=r-1;i=i+1){
        for(j=0;j<=c-1;j=j+1){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMatrix\n");
    for(i=0;i<=r-1;i=i+1){
        for(j=0;j<=c-1;j=j+1){
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter rows of second matrix (1 to 5): ");
    scanf("%d", &r2);
    printf("Enter columns of second matrix (1 to 5): ");
    scanf("%d", &c2);

    if(r2<1 || r2>5 || c2<1 || c2>5){
        printf("Invalid size\n");
        return 0;
    }

    for(i=0;i<=r2-1;i=i+1){
        for(j=0;j<=c2-1;j=j+1){
            printf("Enter element [%d][%d] of second matrix: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    sq = 0;
    if(r == c){
        sq = 1;
    }

    zero = 1;
    for(i=0;i<=r-1;i=i+1){
        for(j=0;j<=c-1;j=j+1){
            if(a[i][j] != 0){
                zero = 0;
            }
        }
    }

    id = 1;
    dg = 1;
    sc = 1;
    up = 1;
    lo = 1;
    sy = 1;
    sk = 1;
    idem = 1;
    nil = 0;
    singular = 0;
    det = 0;

    if(sq == 1){
        for(i=0;i<=r-1;i=i+1){
            for(j=0;j<=r-1;j=j+1){
                if(i != j && a[i][j] != 0){
                    dg = 0;
                }
                if(i == j && a[i][j] != 1){
                    id = 0;
                }
                if(i == j && a[i][j] != a[0][0]){
                    sc = 0;
                }
                if(i > j && a[i][j] != 0){
                    up = 0;
                }
                if(i < j && a[i][j] != 0){
                    lo = 0;
                }
                if(a[i][j] != a[j][i]){
                    sy = 0;
                }
                if(a[i][j] != -a[j][i]){
                    sk = 0;
                }
            }
        }

        if(dg == 0){
            id = 0;
            sc = 0;
        }

        for(i=0;i<=r-1;i=i+1){
            for(j=0;j<=r-1;j=j+1){
                q[i][j] = 0;
                for(k=0;k<=r-1;k=k+1){
                    q[i][j] = q[i][j] + a[i][k] * a[k][j];
                }
                if(q[i][j] != a[i][j]){
                    idem = 0;
                }
            }
        }

        for(i=0;i<=r-1;i=i+1){
            for(j=0;j<=r-1;j=j+1){
                pw[i][j] = a[i][j];
            }
        }

        for(step=1;step<=r;step=step+1){
            if(nil == 0){
                z = 1;
                for(i=0;i<=r-1;i=i+1){
                    for(j=0;j<=r-1;j=j+1){
                        if(pw[i][j] != 0){
                            z = 0;
                        }
                    }
                }
                if(z == 1){
                    nil = 1;
                } else {
                    for(i=0;i<=r-1;i=i+1){
                        for(j=0;j<=r-1;j=j+1){
                            q[i][j] = 0;
                            for(k=0;k<=r-1;k=k+1){
                                q[i][j] = q[i][j] + pw[i][k] * a[k][j];
                            }
                        }
                    }
                    for(i=0;i<=r-1;i=i+1){
                        for(j=0;j<=r-1;j=j+1){
                            pw[i][j] = q[i][j];
                        }
                    }
                }
            }
        }

        for(i=0;i<=r-1;i=i+1){
            for(j=0;j<=r-1;j=j+1){
                t[i][j] = a[i][j];
            }
        }

        det = 1;
        for(i=0;i<=r-1;i=i+1){
            if(singular == 0){
                pv = -1;
                for(k=i;k<=r-1;k=k+1){
                    if(pv == -1 && (t[k][i] > 0.0001 || t[k][i] < -0.0001)){
                        pv = k;
                    }
                }
                if(pv == -1){
                    singular = 1;
                } else {
                    if(pv != i){
                        for(j=0;j<=r-1;j=j+1){
                            tmp = t[i][j];
                            t[i][j] = t[pv][j];
                            t[pv][j] = tmp;
                        }
                        det = -det;
                    }
                    det = det * t[i][i];
                    for(k=i+1;k<=r-1;k=k+1){
                        f = t[k][i] / t[i][i];
                        for(j=i;j<=r-1;j=j+1){
                            t[k][j] = t[k][j] - f * t[i][j];
                        }
                    }
                }
            }
        }
    }

    eq = 1;
    if(r != r2 || c != c2){
        eq = 0;
    } else {
        for(i=0;i<=r-1;i=i+1){
            for(j=0;j<=c-1;j=j+1){
                if(a[i][j] != b[i][j]){
                    eq = 0;
                }
            }
        }
    }

    printf("\nMatrix types that apply:\n");

    if(sq == 1){
        printf("Square Matrix\n");
    } else {
        printf("Rectangular Matrix\n");
    }

    if(zero == 1){
        printf("Zero Matrix\n");
        printf("Null Matrix\n");
    }

    if(r == 1){
        printf("Row Matrix\n");
    }

    if(c == 1){
        printf("Column Matrix\n");
    }

    if(sq == 1){
        if(id == 1){
            printf("Identity Matrix\n");
        }
        if(dg == 1){
            printf("Diagonal Matrix\n");
        }
        if(sc == 1){
            printf("Scalar Matrix\n");
        }
        if(up == 1){
            printf("Upper Triangular Matrix\n");
        }
        if(lo == 1){
            printf("Lower Triangular Matrix\n");
        }
        if(sy == 1){
            printf("Symmetric Matrix\n");
        }
        if(sk == 1){
            printf("Skew-Symmetric Matrix\n");
        }
        if(idem == 1){
            printf("Idempotent Matrix\n");
        }
        if(nil == 1){
            printf("Nilpotent Matrix\n");
        }
        if(singular == 1){
            printf("Singular Matrix (determinant = 0)\n");
        } else {
            printf("Non-Singular Matrix (determinant = %.2f)\n", det);
        }
    } else {
        printf("Singular / Non-Singular: not applicable (matrix is not square)\n");
    }

    if(eq == 1){
        printf("Equal Matrix (both matrices are equal)\n");
    } else {
        printf("The two matrices are not equal\n");
    }

    return 0;
}