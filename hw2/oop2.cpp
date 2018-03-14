#include<iostream>
#include<sys/time.h>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<sstream>
using namespace std;
string IntToString(int &i){
		string s;
		stringstream ss(s);
		ss << i;	
		return ss.str();
}
int getDigit(int num){
		num*=2;
		if(num<10)
				return num;
		else{
				num=num/10+num%10;
				return num;
		}
}
int SumOfDoubleEvenPlace(const string& cardNumber){
		int num,sum=0;
		for(int i=cardNumber.length()-2;i>=0;i-=2){
				num=cardNumber[i]-'0';
				sum=sum+getDigit(num);
		}
		return sum;
}
int SumOfOddPlace(const string& cardNumber){
		int num,sum=0;
		for(int i=cardNumber.length()-1;i>=0;i-=2){
				num=cardNumber[i]-'0';
				sum=sum+num;
		}
		return sum;
}
bool startsWith(const string& cardNumber,const string& substr){
		if(cardNumber.find(substr,0)==0)
				return true;
		else
				return false;
}
bool isvalid(const string& cardNumber){
		int even,odd,temp;
		even=SumOfDoubleEvenPlace(cardNumber);
		odd=SumOfOddPlace(cardNumber);
		temp=(even+odd)%10;
		if(temp==0)
				return true;
		else
				return false;
}
string& fakeOne(const string& brand){
		int l;
		l=(rand()%3)+11;
		int even,odd,r;
		string temp,temp2;
		static string fake;
		fake.clear();
		for(int i=0;i<l;i++){
				r=rand()%10;
				temp.insert(i,IntToString(r));
	}
		//cout<<temp<<endl;
		temp2=brand+temp+"0";
		even=SumOfDoubleEvenPlace(temp2);
		odd=SumOfOddPlace(temp2);
		r=(10-(even+odd)%10)%10;
		fake=brand+temp+IntToString(r);
		//fake[fake.length()-1]=(10-(even+odd)%10)+'0';
		return fake;
}
int main(int argc, char *argv[])
{
		FILE *fp;
		if (argc>0)
				fp=fopen(argv[1],"r");

		if(fp==NULL){				
				cout<<"fopen failed\n";
				return 0;
		}
		char buf[30];
		string visa("4"),master("5"),america("37"),discover("6");
		int l;
		struct  timeval start;
		struct  timeval end;
		unsigned  long diff;
		srand(time(NULL));
		while (fgets(buf,30,fp)!=NULL) {
				if(buf[strlen(buf)-1]=='\n')
						buf[strlen(buf)-1]='\0';
				string str(buf);
				l=str.length();
				if(l==3){
						if(str=="004"){
								gettimeofday(&start,NULL);
								string &card=fakeOne(visa);
								gettimeofday(&end,NULL);
								diff=1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
								cout<<"Generated a valid Visa card #: "<<card<<"; Timing: "<<diff<<" microseconds"<<endl;
						}
						else if(str=="005"){
								gettimeofday(&start,NULL);
								string &card=fakeOne(master);
								gettimeofday(&end,NULL);
								diff=1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
								cout<<"Generated a valid MasterCard card #: "<<card<<"; Timing: "<<diff<<" microseconds"<<endl;
						}						
						else if(str=="006"){
								gettimeofday(&start,NULL);
								string &card=fakeOne(discover);
								gettimeofday(&end,NULL);
								diff=1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
								cout<<"Generated a valid Discover card #: "<<card<<"; Timing: "<<diff<<" microseconds"<<endl;
						}
						else
								cout<<str<<": an invalid card #\n";
				}
				else if(l==4){
						if(str=="0037"){
								gettimeofday(&start,NULL);
								string &card=fakeOne(america);
								gettimeofday(&end,NULL);
								diff=1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
								cout<<"Generated a valid American Express card #: "<<card<<"; Timing: "<<diff<<" microseconds"<<endl;
						}
					}
				else if(l>=13&&l<=16){
						if(startsWith(str,visa)==true){
								if(isvalid(str)==true)
										cout<<str<<": a valid Visa card #\n";
								else
										cout<<str<<": an invalid Visa card #\n";
						}
						else if(startsWith(str,master)==true){
								if(isvalid(str)==true)
										cout<<str<<": a valid MasterCard card #\n";
								else
										cout<<str<<": an invalid MasterCard card #\n";
						}
						else if(startsWith(str,america)==true){
								if(isvalid(str)==true)
										cout<<str<<": a valid American Express card #\n";
								else
										cout<<str<<": an invalid American Express card #\n";
						}
						else if(startsWith(str,discover)==true){
								if(isvalid(str)==true)
										cout<<str<<": a valid Discover card #\n";
								else
										cout<<str<<": an invalid Discover card #\n";
						}

				}
				else
						cout<<str<<": an invalid card #\n";
		}


		return 0;
}
