#ifndef Time_H
#define Time_H
#include<iostream>
using namespace std;
class Time{
		friend ostream& operator<<(ostream&,const Time&);
		friend istream& operator>>(istream&,Time&);
		private:
		int d,h,m,s;
		public:	
		Time();
		Time(int);
		Time(int,int,int,int);
		~Time();
		Time operator+(const Time&);
		Time operator-(const Time&);
		bool operator<(const Time&);
		bool operator>(const Time&);
		bool operator<=(const Time&);
		bool operator>=(const Time&);
		bool operator==(const Time&);
		bool operator!=(const Time&);
		Time& operator++();	//++«e¸m
		Time operator++(int);	//++«á¸m
		Time& operator--();
		Time operator--(int);
};
#endif
