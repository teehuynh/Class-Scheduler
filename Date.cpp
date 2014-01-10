#include <iostream>
#include <iomanip>

using namespace std;

#include "Date.h"

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
 setDate(mn, dy, yr);
 cout << "constructorDATE\n";
}

Date& Date::setDate(int mn, int dy, int yr)
{
	setYear(yr);
	setMonth(mn);
	setDay(dy);

	return *this;
}

//friend functions that overload operators
ostream &operator<<(ostream& output, const Date& date) {
	output << right << setw(2) << setfill('0') << date.month
		   << '/' << setw(2) << date.day
		   << '/' << date.year;
	return output;
}

istream &operator>>(istream& input, Date& date) {
	input >> setw(2) >> date.month;
	input.ignore();
	input >> setw(2) >> date.day;
	input.ignore();
	input >> setw(4) >> date.year;
	return input;
}

//overloaded operators
bool Date::operator>(const Date& obj2) const {
	if(year > obj2.year) {
		return true;
	}
	else if (year == obj2.year && month > obj2.month) {
		return true;
	}
	else if (year == obj2.year && month == obj2.month && day > obj2.day) {
		return true;
	}
	return false;
}

bool Date::operator<(const Date& obj2) const {
	if(year < obj2.year) {
		return true;
	}
	else if (year == obj2.year && month < obj2.month) {
		return true;
	}
	else if (year == obj2.year && month == obj2.month && day < obj2.day) {
		return true;
	}
	return false;
}

bool Date::operator>=(const Date& obj2) const {
	return (operator>(obj2) || operator==(obj2));
}

bool Date::operator<=(const Date& obj2) const {
	return (operator<(obj2) || operator==(obj2));
}

bool Date::operator==(const Date &obj2) const{
	return (month == obj2.month &&  day == obj2.day && year == obj2.year); 
}

bool Date::operator!=(const Date& obj2) const {
	return (operator==(obj2) == false);
}

//PRIVATE CONST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(testDay > 0 && testDay <= daysPerMonth[month])
    {
     return testDay;
    }
    
    //determine whether testDay is valid for a specific month
    if(month == 2 && testDay == 29 && (year  % 400 == 0 || (year % 4  == 0 && year % 100 != 0)))
    {
      return testDay;
    }
    
    cout << "Invalid Day " << testDay << " was set to 1" << endl;
    return 1;  //keep data in valid state
}

//set functions
Date& Date::setYear(int yr) {
	year = (yr > 0) ? yr : 0;
	return *this;
}

Date& Date::setMonth(int mn) {
	month = (mn <= 1 || mn <= 12) ? mn : 0;
	return *this;
}

Date& Date::setDay(int dy) {
	day = dy;
	return *this;
}
//get functions
int Date::getDay() const{
	return day;
}

int Date::getMonth() const{
	return month;
}

int Date::getYear() const{
	return year;
}