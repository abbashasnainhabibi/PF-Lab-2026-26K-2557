#include <stdio.h>

void printGrid(int (*grid)[5]){
    int r, c;
    for(r = 0; r < 5; r++){
        for(c = 0; c < 5; c++){
            printf("%d", grid[r][c]);
            if(c < 4){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col){
    int count = 0;
    int dr, dc, nr, nc;
    for(dr = -1; dr <= 1; dr++){
        for(dc = -1; dc <= 1; dc++){
            if(dr == 0 && dc == 0){
                continue;
            }
            nr = row + dr;
            nc = col + dc;
            if(nr >= 0 && nr < 5 && nc >= 0 && nc < 5){
                if(grid[nr][nc] & 1){
                    count++;
                }
            }
        }
    }
    return count;
}

void nextGeneration(int (*grid)[5]){
    int r, c;
    for(r = 0; r < 5; r++){
        for(c = 0; c < 5; c++){
            int current = grid[r][c] & 1;
            int neighbours = countNeighbours(grid, r, c);

            if(current == 1){
                if(neighbours == 2 || neighbours == 3){
                    grid[r][c] |= 2;
                }
            }else{
                if(neighbours == 3){
                    grid[r][c] |= 2;
                }
            }
        }
    }

    for(r = 0; r < 5; r++){
        for(c = 0; c < 5; c++){
            grid[r][c] >>= 1;
        }
    }
}

int main(){
    int grid[5][5] = {0};
    int gens, g;

    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    while(1){
        printf("Enter number of generations (0-50): ");
        if(scanf("%d", &gens) != 1){
            return 1;
        }
        if(gens >= 0 && gens <= 50){
            break;
        }
        printf("Invalid number\n");
    }

    printf("Generation 0:\n");
    printGrid(grid);

    for(g = 1; g <= gens; g++){
        nextGeneration(grid);
        printf("Generation %d:\n", g);
        printGrid(grid);
    }

    return 0;
}
