#include<stdio.h>
#include<string.h>
/*
* File: sortArray.c
* Author: Ngô Đức Thọ
* Date : 5/4/2023
* Description: This is a sample file read and print the amount of money
*/

/*
* Function: printMoney
* Description: This function print the amount of money
* Input:
*   inputNumber - an integer value
*   string - a char string value
* Output:
*   returns the sort print the amount of money
*/
void printMoney(int inputNumber, char *string) {
    char *units[] = {"", "mot ", "hai ", "ba ", "bon ", "nam ", "sau ", "bay ", "tam " ,"chin "};
    char *dozens[] = {"", "muoi ", "hai muoi ", "ba muoi ", "bon muoi ", "nam muoi ", "sau muoi ", "bay muoi ", "tam muoi ", "chin muoi "};
    char *hundreds[] = {"", "mot tram ", "hai tram ", "ba tram ", "bon tram ", "nam tram ", "sau tram ", "bay tram ", "tam tram ", "chin tram "};
    char *millions[] = {"","nghin ","trieu "};

    int million = inputNumber / 1000000;
    int thounsand = (inputNumber / 1000) % 1000;
    int rest = inputNumber % 1000;

    if(million > 0) {
        printMoney(million, string);
        strcat(string, millions[2]);
    }
    if(thounsand > 0) {
        printMoney(thounsand, string);
        strcat(string, millions[1]);
    }

    if(rest > 0) {
       int hundred = rest / 100;
       if (hundred > 0) {
           strcat(string,hundreds[hundred]); 
       }
       int dozen = (rest / 10) % 10;
       int unit = rest % 10;
       if (dozen > 0) {
            if (dozen == 1 && unit > 0) {
                strcat(string, "muoi " );
           } else {
                strcat(string, dozens[dozen]);
           }
       }
       if (unit > 0) {
            if(dozen == 0 && hundred != 0 ) {
                strcat(string,"linh");                
            } else if(dozen == 0 && hundred == 0) {
                strcat(string,"khong tram linh ");
            } else {
                strcat(string, units[unit]);
            }
       }
    }

}
int main(){
    int inputNumber;
    char inputString[100]="";
    scanf("%d", &inputNumber);  
    printMoney(inputNumber,inputString);
    printf("%sdong",inputString);
    return 0;
}
