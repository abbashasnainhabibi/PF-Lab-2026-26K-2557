#include <stdio.h>

int sumShelf(const int *shelf, int count){
    int sum = 0;
    int i;
    for(i = 0; i < count; i++){
        sum += *(shelf + i);
    }
    return sum;
}

int findLargestShelf(const int *counts, int numShelves){
    int maxIdx = 0;
    int i;
    for(i = 1; i < numShelves; i++){
        if(*(counts + i) > *(counts + maxIdx)){
            maxIdx = i;
        }
    }
    return maxIdx;
}

int main(){
    int shelfA[] = {101, 102, 103};
    int shelfB[] = {201, 202};
    int shelfC[] = {301, 302, 303, 304};

    int *shelves[] = {shelfA, shelfB, shelfC};
    int counts[] = {3, 2, 4};
    int numShelves = 3;
    int i;
    int largestIdx;

    for(i = 0; i < numShelves; i++){
        int total = sumShelf(shelves[i], counts[i]);
        printf("Shelf %d ID total: %d\n", i + 1, total);
    }

    largestIdx = findLargestShelf(counts, numShelves);
    printf("Shelf with the most books: Shelf %d (%d books)\n", largestIdx + 1, counts[largestIdx]);

    return 0;
}
