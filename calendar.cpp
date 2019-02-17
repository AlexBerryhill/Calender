/*************************************************************************
* Program:                                                                 
*    Project 07, Calendar                                                  
*    Brother Ridges, CS124                                                 
* Author:                                                                  
*    Alexander Berryhill                                                   
* Summary:                                                                 
*    This program will take a year and month from the user and display a   
*    calendar.                                                             
*                                                                          
*                                                                          
*                                                                          
*    Estimated:  3.5 hrs                                                   
*    Actual:     4.0 hrs                                                   
*      The most difficult part was getting the offset right, and filling   
*      all of those description boxes.                                     
*************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Start of month line                                                     

/*************************************************************************
 * promptMonth will prompt and get a month from the user                   
 ************************************************************************/
int promptMonth()
{
   int month;

   cout << "Enter a month number: ";
   cin >> month;
   
   return month;
}

/*************************************************************************
 * isMonth will check if the month is actually a month.                    
 ************************************************************************/
bool isMonth(int month)
{
   bool isMonth;

   if (month <= 12 && month > 0)
   {
      isMonth = true;
   }
   else
   {
      isMonth = false;
   }

   return isMonth;
}

/*************************************************************************
 * getMonth will make sure you get an accurate month.                      
 ************************************************************************/
int getMonth()
{
   int month = promptMonth();
   bool isAMonth = isMonth(month);
   while (!isAMonth)
   {
      cout << "Month must be between 1 and 12.\n";
      month = promptMonth();
      isAMonth = isMonth(month);
   }
   return month;
}

//Start of Year line                                                       

/*************************************************************************
 * promptYear will prompt and get a year from the user.                    
 ************************************************************************/
int promptYear()
{
   int year;

   cout << "Enter year: ";
   cin >> year;

   return year;
}

/*************************************************************************
 * isRecentYear will check if the year is after 1752.                      
 ************************************************************************/
bool isRecentYear(int year)
{
   bool isRecentYear;

   if (year > 1752)
   {
      isRecentYear = true;
   }
   else
   {
      isRecentYear = false;
   }

   return isRecentYear;
}

/*************************************************************************
 * getYear will make sure you get a year after 1752                        
 ************************************************************************/
int getYear()
{
   int year = promptYear();
   bool isYear = isRecentYear(year);
   while (!isYear)
   {
      cout << "Year must be 1753 or later.\n";
      year = promptYear();
      isYear = isRecentYear(year);
   }
   return year;
}

/************************************************************************  
 * isLeapYear will check if your year is a leap year.                      
 ***********************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 == 0 && year % 100 != 0)
   {
      return true;
   }
   else if (year % 4 == 0 && year % 400 == 0)
   {
      return true;
   }
   else
      {
      return false;
   }
}

//Start of display line                                                    

/*************************************************************************
 * displayName will display the months name and the year.                  
 ************************************************************************/
void displayName(int month, int year)
{

   char monthName [12][256] = {"January", "February", "March", "April",
                               "May", "June", "July", "August",
                               "September", "October", "November",
                               "December"};

   cout << endl << monthName[month - 1] << ", " << year << endl;
   return;
}

/*************************************************************************
 * numDaysinMonth will find the number of days in a given month.           
 ************************************************************************/
int numDaysinMonth(int month, bool isLeapYear)
{
   int numDays;
   if (month == 1 || month == 3 || month == 5 || month == 7
       || month == 8 || month == 10 || month == 12)
   {
      numDays = 31;
   }
   else if (month == 4 || month == 6 || month == 9 || month == 11)
      {
      numDays = 30;
   }
   else if (month == 2 && !isLeapYear)
   {
      numDays = 28;
   }
   else if (month == 2 && isLeapYear)
   {
      numDays = 29;
   }

   return numDays;
}

/*************************************************************************
 * computeOffset will take a month and year then output the offset.        
 ************************************************************************/
int computeOffset(int month, int year)
{
   int daysPast = 0;
   int offset;
   bool isALeapYear = isLeapYear(year);


   //count days of years                                                   
   for (int i = 1753; i < year; i++)
   {
      if (!isLeapYear(i))
      {
         daysPast += 365;
      }
      else
      {
        daysPast += 366;
      }
   }

   //count days of months                                                  
   for (int i = 1; i < month; i++)
   {
      daysPast += numDaysinMonth(i, isALeapYear);
   }

   offset = daysPast % 7;
   return offset;
}

/*************************************************************************
 * displayTable will display the calendar portion.                         
 ************************************************************************/
void displayTable(int offset, int numDays)
{
   int day = offset + 1;
   int date = 1;
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   for (int i = offset + 1; i > 0; i--)
   {
      if (offset == 6)
      {
         i = 0;
         day = 0;
      }
      else
      {
         cout << "    ";
      }
   }
      for (int j = numDays; j > 0; j--)
   {
      if (day == 6 && date != numDays)
      {
         cout << setw(4) << date << endl;
         date++;
         day = 0;
      }
      else
      {
         cout << setw(4) << date;
         date++;
         day++;
      }
   }
   cout << endl;

   return;
}

/*************************************************************************
 * display will call the Name to displayed then the Table.                 
 ************************************************************************/
void display(int month, int year, int offset, int numDays)
{
   displayName(month, year);
   displayTable(offset, numDays);
}

/*************************************************************************
 * main will set integers to the get functions and then call display with 
 * those values.                                                           
 ************************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   int offset = computeOffset(month, year);
   bool isALeapYear = isLeapYear(year);
   int numDays = numDaysinMonth(month, isALeapYear);

   display(month, year, offset, numDays);
   return 0;
}
