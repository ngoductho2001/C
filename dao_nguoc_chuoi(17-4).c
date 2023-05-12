#include<stdio.h>
#include<string.h>
/*
* File: calculate_date_month_year.c
* Author: Ngô Đức Thọ
* Date : 27/3/2023
* Description: This is a sample file for contrary Array
*/
/*
* Function: contrary_Array
* Description: This function reverses the string
* Input:
*   inputString - an char value
* Output:
*   returns the contrary string    
*/
void contraryArray(char inputString[]) {
    char *word = strtok(inputString, " ");// pointer word pointer to the frist address of the string.
    char *totalWords[100];// declare a pointer named totalWords
    int size = 0; 
    while (word !=NULL) {//check if word is equal to null
        totalWords[size] = word;// add word into the totalWords Array
        size++;
        word = strtok(NULL, " ");
    }
    int i = 0;
    for (i = 0; i < size/2; i++) { // reserves the string totalWords
        char *temporyvarriable = totalWords[i];
        totalWords[i] = totalWords[size - 1 -i];
        totalWords[size - 1 - i] = temporyvarriable;
    }
    char outputString[100];
    strcat(outputString,"");
    for (int i = 0; i < size; i++) {
        strcat(outputString, totalWords[i]);// add each element of the array into the named string is outputString
        strcat(outputString," ");
    } 
    printf("%s",outputString);   
}

int main(){
    char inputString[1000]="hello everyone hi hello ban";
    contraryArray(inputString);
}



