#include <string.h> 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printSquare(int square[3][3]){
for (int i = 0; i < 3; i++){
    printf("[");
        for (int j = 0; j < 3; j++){
            printf("%d ",square[i][j]);
        }
        printf("]\n");
    }
}

bool testLoShu(int square[3][3]){
    int valueFirst = 0;
    int temp = 0;

    //Gets first value in order to check rest of rows, columns, and diagonals
    //Checks 3 rows, takes row one on own to validate a first value
    for(int i = 0; i < 3; i++){
        valueFirst = valueFirst + square[0][i];
    }

    for (int i = 1; i < 3; i++){
        temp = 0;
        for(int j = 0; j < 3; j++){
            temp = temp + square[i][j];
        }
        if(temp != valueFirst){
            return false;
        }
    }

    //Checks 3 columns
    for(int i = 0; i < 3; i++){
        temp = 0;
        for(int j = 0; j < 3; j++){
            temp = temp + square[j][i];
        }
        if(temp != valueFirst){
            return false;
        }  
    }

    //Check both possible diagonals
    temp = square[0][0] + square[1][1] + square[2][2];
    if(temp != valueFirst){
            return false;
        }  
    temp = square[0][2] + square[1][1] + square[2][0];
    if(temp != valueFirst){
            return false;
        }
    
    return true;


}

int main(void){ 
    int square[3][3];
    int newRandomSeed = 0;
    int randNumber;
    while(testLoShu != true){
        newRandomSeed++;
        srand(time(0) + newRandomSeed);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                randNumber = rand() % 9 + 1;
                square[i][j] = randNumber;
            }
        }
    }
    printf("Trials generated before success: %d\n", newRandomSeed);
    printSquare(square);
    return 0;
}