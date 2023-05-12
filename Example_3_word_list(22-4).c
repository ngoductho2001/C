#include<stdio.h>
#include<string.h>
#include<ctype.h>
/*
* File: Example_3_word_list.c
* Author: Ngô Đức Thọ
* Date : 3/4/2023
* Description: This is a sample file for count and print the number of times the word on the screen
*/
void countWord(char inputString[]);

int main(){
    char str[] = "kho cua lep to so toi mot mot hai nhung nguoi khon ep to so toi mot mot hai hai HI HI";
    countWord(str);
    return 0;
}

/*
* Function: countWord
* Description: This function count and print the number of times the word
* Input:
*   inputString - a char value
*  
* Output:
*   returns count and print the number of times the word
*/
void countWord(char inputString[]) {
    char words[50][50];
    char freq[20], wordCount = 0, numWord = 0, i,j;//variable freq: count the times of word; wordCount:count the number of letters in the word; numberWord: the number of times of the word
    for (i = 0; inputString[i] != '\0'; i++) {// the for loop runs until the string encounters a null character
        if (isspace(inputString[i])) {// When encountering a space, split the word and count the number of times the word
            words[numWord][wordCount] = '\0';
            wordCount = 0;
            numWord++;
        } else
        {
            words[numWord][wordCount] = tolower(inputString[i]);//If it's uppercase, change it to lowercase
            wordCount++;
        }      
    }
    words[numWord][wordCount] = '\0';
    numWord++;
    for (i = 0; i < numWord; i++) {
        freq[i] = 1;
        for (j = i + 1; j < numWord; j++) {
            if (strcmp(words[i],words[j]) == 0) {
                freq[i]++;//count the number of times the words
                strcpy(words[j],"");
            }
        }
    }

    printf("word\tso lan xuat hien\n");
    for (i = 0; i < numWord; i++) {
        if ( strlen(words[i]) > 0 && freq[i] >= 2) {
            printf ("%s\t%d\n",words[i],freq[i]);// print words and the number of times the words
        }
    }
}

