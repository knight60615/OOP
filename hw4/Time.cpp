#include<iostream>
#include<cstring>
#include<cstdlib>
#include"Time.h"
Time::Time(){d=h=m=s=0;}
Time::Time(int sec){
		if(sec<0)
				d=h=m=s=0;
		else if(sec>=0&&sec<60){
				s=sec;
				d=h=m=0;
		}
		else{
				m=sec/60;
				if(m>=60){
						h=m/60;
						if(h>=24){
								d=h/24;
								h=h%24;
						}
						m=m%60;
				}
				s=sec%60;
		}
}
Time::Time(int day,int hour,int min,int sec){
		if(day<0||hour<0||min<0||sec<0)
				d=h=m=s=0;
		else{
				d=day;
				h=hour;
				m=min;
				s=sec;
				if(s>=60){
						m=m+s/60;
						s=s%60;
				}
				if(m>=60){
						h=h+m/60;
						m=m%60;
				}
				if(h>=24){
						d=d+h/24;
						h=h%24;
				}
		}
}
Time::~Time(){}
ostream& operator<<(ostream& out,const Time& t){
		out<<t.d<<"~"<<t.h<<":"<<t.m<<":"<<t.s;
		return out;
}
istream& operator>>(istream& in,Time& t){
		char temp[30],*p;
		in>>temp;
		p=strtok(temp,"~");
		t.d=atoi(p);
		p=strtok(NULL,":");
		t.h=atoi(p);
		p=strtok(NULL,":");
		t.m=atoi(p);
		p=strtok(NULL,":");
		t.s=atoi(p);
		if(t.d<0||t.h<0||t.m<0||t.s<0)
				t.d=t.h=t.m=t.s=0;
		return in;
}
Time Time::operator+(const Time& a){
		Time temp;
		temp.d=this->d+a.d;
		temp.h=this->h+a.h;
		temp.m=this->m+a.m;
		temp.s=this->s+a.s;
		if(temp.s>=60){
				temp.m=temp.m+temp.s/60;
				temp.s=temp.s%60;
		}
		if(temp.m>=60){
				temp.h=temp.h+temp.m/60;
				temp.m=temp.m%60;
		}
		if(temp.h>=24){
				temp.d=temp.d+temp.h/24;
				temp.h=temp.h%24;
		}
		return temp;
}
Time Time::operator-(const Time& a){
		Time temp;
		if(this->d<a.d||(this->d==a.d&&this->h<a.h)||(this->d==a.d&&this->h==a.h&&this->m<a.m)||(this->d==a.d&&this->h==a.h&&this->m==a.m&&this->s<a.s))
				temp.d=temp.h=temp.m=temp.s=0;
		else{
				temp.d=this->d-a.d;
				temp.h=this->h-a.h;
				temp.m=this->m-a.m;
				temp.s=this->s-a.s;
				while(temp.s<0){
						temp.s+60;
						temp.m--;
				}
				while(temp.m<0){
						temp.m+60;
						temp.h--;
				}
				while(temp.h<0){
						temp.h+24;
						temp.d--;
				}
		}
		return temp;
}
bool Time::operator<(const Time& a){
		if(this->d<a.d||(this->d==a.d&&this->h<a.h)||(this->d==a.d&&this->h==a.h&&this->m<a.m)||(this->d==a.d&&this->h==a.h&&this->m==a.m&&this->s<a.s))
				return true;
		else
				return false;
}
bool Time::operator<=(const Time& a){
		if(this->d<a.d||(this->d==a.d&&this->h<a.h)||(this->d==a.d&&this->h==a.h&&this->m<a.m)||(this->d==a.d&&this->h==a.h&&this->m==a.m&&this->s<=a.s))
				return true;
		else
				return false;
}
bool Time::operator>(const Time& a){
		if(this->d>a.d||(this->d==a.d&&this->h>a.h)||(this->d==a.d&&this->h==a.h&&this->m>a.m)||(this->d==a.d&&this->h==a.h&&this->m==a.m&&this->s>a.s))
				return true;
		else
				return false;
}
bool Time::operator>=(const Time& a){
		if(this->d>a.d||(this->d==a.d&&this->h>a.h)||(this->d==a.d&&this->h==a.h&&this->m>a.m)||(this->d==a.d&&this->h==a.h&&this->m==a.m&&this->s>=a.s))
				return true;
		else
				return false;
}
bool Time::operator==(const Time& a){
		if(this->d==a.d&&this->h==a.h&&this->m==a.m&&this->s==a.s)
				return true;
		else
				return false;
}
bool Time::operator!=(const Time& a){
		if(this->d!=a.d||this->h!=a.h||this->m!=a.m||this->s!=a.s)
				return true;
		else
				return false;
}
Time& Time::operator++(){
		s++;
		if(s>=60){
				m++;
				s=s-60;
		}
		if(m>=60){
				h++;
				m=m-60;
		}
		if(h>=24){
				d++;
				h=h-24;
		}
		return *this;
}
Time Time::operator++(int){
		Time temp(d,h,m,s);
		s++;
		if(s>=60){
				m++;
				s=s-60;
		}
		if(m>=60){
				h++;
				m=m-60;
		}
		if(h>=24){
				d++;
				h=h-24;
		}
		return temp;
}
Time& Time::operator--(){
		s--;
		if(s<0){
				m--;
				s=s+60;
		}
		if(m<0){
				h--;
				m=m+60;
		}
		if(h<0){
				d--;
				h=h+24;
		}
		return *this;
}
Time Time::operator--(int){
		Time temp(d,h,m,s);
		s--;
		if(s<0){
				m--;
				s=s+60;
		}
		if(m<0){
				h--;
				m=m+60;
		}
		if(h<0){
				d--;
				h=h+24;
		}
		return temp;
}
