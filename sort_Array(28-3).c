
#include<stdio.h>
#include<stdint.h>
/*
* File: sortArray.c
* Author: Ngô Đức Thọ
* Date : 27/3/2023
* Description: This is a sample file sort for Array and count the number Of Ocurrences Array
*/

/*
* Function: contrary_Array
* Description: This function sort the array
* Input:
*   inputArray - an array value
*   size - an integer value
* Output:
*   returns the sort array    
*/
void sortArray(uint8_t inputArray[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(inputArray[j] > inputArray[i]) {
                int varriable = inputArray[j];
                inputArray[j] = inputArray [i];
                inputArray[i] = varriable;
            }
        }
    }
}

// create an array with 1000 elements equal to 0 
int countElementArray[1000]={0};

/*
* Function: number_Of_Ocurrences
* Description: This function count the number Of Ocurrences Array
* Input:
*   inputArray - an array value
*   size - an integer value
* Output:
*   returns Ocurrences of each element
*/
void number_Of_Ocurrences(uint8_t inputArray[], int size) {
    for (int i = 0; i < size; i++) {
        countElementArray[inputArray[i]]++;
    }
    for (int i = 0; i < size; i++) {
        if (countElementArray[inputArray[i]] != 0) {
            printf("%d %d\n",inputArray[i],countElementArray[inputArray[i]]);
            countElementArray[inputArray[i]] = 0;
        }
    }
}

int main(){
    int size;
    uint8_t inputArray[] = {64, 32, 90, 43, 25, 22, 12, 11, 9, 90, 43, 25, 88, 1, 2, 3, 1};
    size = sizeof(inputArray)/sizeof(inputArray[0]);
    number_Of_Ocurrences(inputArray,size);
}