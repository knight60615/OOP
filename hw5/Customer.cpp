#include"Customer.h"
#include <iostream>
#include <cstring>
using namespace std;
int Customer::num=0;
int OrdinaryCustomer::onum=0;
int PremiumCustomer::pnum=0;
Customer::Customer (char *f, char *s, char *t){
		strcpy(fname,f);
		strcpy(sname,s);
		strcpy(town,t);
		num++;
		no=num;
}
/*Customer::Customer (Customer &c){
		strcpy(this->fname,c.fname);
		strcpy(this->sname,c.sname);
		strcpy(this->town,c.town);
		num++;
}*/
Customer::~Customer(){}
OrdinaryCustomer::OrdinaryCustomer (char *f, char *s, char *t, char *b):Customer (f,s,t){
		strcpy(beer,b);
		onum++;
		ono=onum;
}
/*OrdinaryCustomer::OrdinaryCustomer (OrdinaryCustomer &c){
		strcpy(this->fname,c.fname);
		strcpy(this->sname,c.sname);
		strcpy(this->town,c.town);
		strcpy(this->beer,c.beer);
		onum++;
}*/
OrdinaryCustomer::~OrdinaryCustomer (){
		onum--;
		num--;
		cout<<"Survived "<<onum<<" OrdinaryCustomer, and "<<num<<" Customer."<<endl;
	}
void OrdinaryCustomer::christmasPresent (void){
		cout<<fname<<" "<<sname<<", at "<<town<<endl;
		cout<<"This is the "<<ono<<"th OrdinaryCustomer, and "<<no<<"th Customer."<<endl;
		cout<<"Please send one bottle "<<beer<<" using ordinary present wrapper.\n"<<endl;
}
PremiumCustomer::PremiumCustomer (char *f, char *s, char *t, char *w):Customer (f,s,t){
		strcpy(wine,w);
		pnum++;
		pno=pnum;
}
/*PremiumCustomer::PremiumCustomer (PremiumCustomer &c){
		strcpy(this->fname,c.fname);
		strcpy(this->sname,c.sname);
		strcpy(this->town,c.town);
		strcpy(this->wine,c.wine);
		pnum++;
}*/
PremiumCustomer::~PremiumCustomer (void){
		pnum--;
		num--;
		cout<<"Survived "<<pnum<<" PremiumCustomer, and "<<num<<" Customer."<<endl;	
		}
void PremiumCustomer::christmasPresent (void){
		cout<<fname<<" "<<sname<<", at "<<town<<endl;
		cout<<"This is the "<<pno<<"th PremiumCustomer, and "<<no<<"th Customer."<<endl;
		cout<<"Please send one bottle "<<wine<<" using premium present wrapper.\n"<<endl;
}
