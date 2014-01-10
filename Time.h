//Time Class Definition with const member functions
#ifndef TIME_H
#define TIME_H

class Time
{
      friend ostream& operator<<(ostream&, const Time&);
      friend istream& operator>>(istream&, Time&);

      private:
              int hour;  //0-23 (24 hour clock format)
              int minute; //0-59 
              void stdTimeToUniversal(int, int, bool isAM);
      
      public:
             Time(int = 0, int = 0);
			 double operator-(const Time&); 
             Time& setTime(int, int); //The & return type enables cascading
             Time& setHour(int);
             Time& setMinute(int);
             int getHour() const;
             int getMinute() const;
             void printUniversal() const;
             void printStandard()const;
};

#endif
