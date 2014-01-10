#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "Time.h"
              
ostream& operator<<( ostream &output, const Time& time )
{
	output << ((time.hour == 0 || time.hour == 12) ? 12 : time.hour % 12) << ":" 
          << setfill ('0') << setw(2) << time.minute
          << (time.hour < 12 ? " AM" : " PM" );
	return output;
} 

istream& operator>>( istream &input, Time &time )  
{   
	int h, m;
	string AMorPM; 
	input >> setw(2) >> setfill('0') >> h;
	input.ignore();
	input >> setw(2) >> setfill('0') >> m;
	input.ignore();
	input >> setw(2) >> AMorPM;
	if (AMorPM == "AM" || AMorPM == "am")
	{
		time.stdTimeToUniversal(h, m, true);
	}
	else if (AMorPM == "PM"|| AMorPM == "pm")
	{
		time.stdTimeToUniversal(h, m, false);
	}
	return input;
}  

void Time::stdTimeToUniversal(int h, int m, bool isAM)
{
	if (h == 0)
	{
		h = 12;			//Flip the hour to 12
	}
	else if (h == 12)
	{
		h = 0;			 //Flip the hour to 0
	}
	if (h <= 12 && h >= 0)
	{
		if (isAM)
		{
			setTime(h, m);	//Set time normally
		}
		else
		{
			setTime(h + 12, m);	//Add 12 to the hour and set the time
		}
	}
}

Time::Time(int hour, int minute)
{
	 setTime(hour, minute);
	 cout << "constructorTIME\n";
}


double Time::operator-(const Time& obj2)
{
	double dif;
	dif = double(hour) + double(minute)/60.00 - double(obj2.hour) - double(obj2.minute)/60.00;
	return abs(dif);
}

Time& Time::setTime(int hour, int minute) //Set time in universal time
{
	 setHour(hour);
	 setMinute(minute);
	 return *this; 
}

Time& Time::setHour(int h) //Set hour in universal time
{
	  hour = (h >= 0 && h < 24) ? h : 0;  
	  return *this;
}  

Time& Time::setMinute(int m) //Set minute in universal time
{
	  minute = (m >= 0 && m < 60) ? m : 0;  
	  return *this;
} 

int Time::getHour() const  // Retrieves the hour in universal time
{
    return hour;
}

int Time::getMinute() const  // Retrieves the minute in universal time
{
    return minute;
}

void Time::printUniversal()const  //Prints the time in universal time
{
     cout << setfill('0') << setw(2) << hour << ":" 
          << setw(2) << minute << endl;
}

void Time::printStandard()const  //Prints the time in standard time
{
     cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" 
          << setfill ('0') << setw(2) << minute
          << (hour < 12 ? " AM" : " PM" )<< endl;
}