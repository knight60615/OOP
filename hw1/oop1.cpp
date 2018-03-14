#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
		char input[50],*p,a;
		int i,number[50];
		cout<<"Please input your expression:\n";
		while(fgets(input,50,stdin)!=NULL){
				if (input[strlen(input)-1]=='\n')
						input[strlen(input)-1]=0; /* replace newline with null */
				i=0;
				p=strtok(input," ");
				while (p!=NULL) {
						if(strcmp(p,"+")==0){
								number[i-2]=number[i-2]+number[i-1];
								i--;
						}
						else if(strcmp(p,"-")==0){
								number[i-2]=number[i-2]-number[i-1];	
								i--;
						}
						else if(strcmp(p,"*")==0){
								number[i-2]=number[i-2]*number[i-1];
								i--;
						}
						else if(strcmp(p,"/")==0){
								number[i-2]=number[i-2]/number[i-1];
								i--;
						}
						else if(strcmp(p,"%")==0){
								number[i-2]=number[i-2]%number[i-1];
								i--;
						}
						else if(strcmp(p,"^")==0){
								number[i-2]=pow(number[i-2],number[i-1]);
								i--;
						}
						else{
								number[i]=atoi(p);
								i++;
						}
						p=strtok(NULL," ");
				}
				cout<<number[0]<<endl;
				cout<<"Continue? (Y/N) ";
				cin>>a;
				if(a=='Y'||a=='y'){
						cout<<"Please input your expression:\n";
						getchar();		/*¥Î¨Ó¦Y±¼\n*/
				}
				else
						break;
		}
		return 0;
}
