#include <iostream>
#include "Cube.h"
using namespace std;
int main()
{
		int a,b,c;
		Cube A,B;
		while(1){
				cout<<"��J�Ĥ@��cube���T���:";
				cin>>a>>b>>c;
				if(a>=0&&b>=0&&c>=0)
						break;
		}
		A.set_cube(a,b,c);
		while(1){
				cout<<"��J�ĤG��cube���T���:";
				cin>>a>>b>>c;
				if(a>=0&&b>=0&&c>=0)
						break;
		}
		B.set_cube(a,b,c);
		cout<<"cube1/cube2="<<A/B<<endl;
		if(A!=B==true)
				cout<<"cube1!=cube2\n";
		else
				cout<<"cube1=cube2\n";



		return 0;
}

