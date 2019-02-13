#include <iostream>
#include <iomanip>
using namespace std;

// Start of month line                                                     

/*************************************************************************
 *                                                                         
 ************************************************************************/
int promptMonth()
{
   int month;

   cout << "Enter a month number: ";
   cin >> month;

   return month;
}

/*************************************************************************
 *                                                                         
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
 *                                                                         
 ************************************************************************/
int getMonth()
{
   int month = promptMonth();
   bool isAMonth = isMonth(month);
   while (!isAMonth)
      {
         cout << "Month must be beteen 1 and 12.\n";
         month = promptMonth();
         isAMonth = isMonth(month);
      }
   return month;
}

//Start of Year line                                                       

/*************************************************************************
 *                                                                         
 ************************************************************************/
int promptYear()
{
   int year;

   cout << "Enter year: ";
   cin >> year;

   return year;
}

/*************************************************************************
 *                                                                         
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
 *                                                                         
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
 *                                                                         
 ***********************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 == 0 && year % 400 != 0)
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
 *                                                                         
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
 *                                                                         
 ************************************************************************/
int computeOffset(int month, int year)
{
   int daysPast = 0;
   int offset;

   //count days of years                                                   
   for (int i = 1753; i < year; i++)
   {
      if(!isLeapYear(i))
      {
         daysPast += 365;
      }
      else
      {
         daysPast += 366;
      }
   }
   cout << " Loop: " << daysPast << endl;
   cout << "  .25: " << (year - 1753) * 365.25 << endl;
      cout << ".2422: " << (year - 1753) * 365.2422 << endl;
   cout << ".2425: " << (year - 1753) * 365.2425 << endl;

   //count days of months                                                  
   for (int i = 1; i < month; i++)
   {
      daysPast += numDaysinMonth(i, isLeapYear(year));
      cout << i << ": " << numDaysinMonth(i, isLeapYear(year)) << ", \n";
   }

   offset = daysPast % 7;
   cout << endl << "offset: " << offset << endl;       //DEBUG             
   return offset;
}

/*************************************************************************
 *                                                                         
 ************************************************************************/
void displayTable(int offset, int numDays)
{
   int day = offset + 1;
   int date = 1;

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   for(int i = offset + 1; i > 0; i--)
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
   for(int j = numDays; j > 0; j--)
   {
      if(day == 6)
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
 *                                                                         
 *                                                                         
 ************************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   int offset = computeOffset(month, year);
   bool isALeapYear = isLeapYear(year);     
   int numDays = numDaysinMonth(month, isALeapYear);
   
   displayTable(offset, numDays);

   return 0;
}