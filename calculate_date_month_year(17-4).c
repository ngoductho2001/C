#include<stdio.h>
#include<stdint.h>
/*
* File: calculate_date_month_year.c
* Author: Ngô Đức Thọ
* Date : 27/3/2023
* Description: This is a sample file for calculate_date_month_year
*/

int totalDay = 0;
/*
* Function: calculate_TotalDay
* Description: This function calculates the total day and check what day is it
* Input:
*   date - an integer value
*   month - an integer value
*   year - an integer value
* Output:
*   returns the total day and check day
*/
void calculateTotalDay(int date, int month, int year) {
    for (int i = 1; i < year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)//check leap year
            totalDay += 366;
        else 
            totalDay += 365;//add up the total number of years
    }

    int numberOfMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            numberOfMonth[1] = 29;//check leap month

        for (int i = 0; i < month - 1; i++) {
            totalDay += numberOfMonth[i];//add up the total number of months
        }
        totalDay += date - 1;//add up the total number of days
    //check what day it is and show it out
    int day = 0;
    int calculateDayOfWeek = (day + totalDay) % 7;//check day
    char *dayOfWeek[]={"Wesnesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
    printf("%d/%d/%d is: %s\n", date,month,year,dayOfWeek[calculateDayOfWeek]);
    printf("Total day: %d\n",totalDay);
}

int main() {
    int year,month,date;
    printf("INPUT:");
    scanf("%d %d %d", &date, &month, &year);
    calculateTotalDay(date,month,year);
}
