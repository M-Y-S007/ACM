#include <iostream>
using namespace std;
int main()
{
    int year,month;
    cin>>year>>month;
    int dayInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
    bool isLeapYear = (year%4==0 &&year%100!=0) || (year%400==0);
    int days = dayInMonth[month-1];
    if(month ==2 && isLeapYear){
    	days = 29;
	}
    cout<<days;
    return 0;
	}
    


    
