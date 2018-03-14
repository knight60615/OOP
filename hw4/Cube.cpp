#include"Cube.h"

Cube::Cube(){x=y=z=0;}
Cube::~Cube(){}
void Cube::set_cube(int a,int b,int c){
		/*this->*/x=a;
		/*this->*/y=b;
		/*this->*/z=c;
}
double operator/(const Cube& a,const Cube& b){
		int sum1,sum2;
		double result;
		sum1=a.x+a.y+a.z;
		sum2=b.x+b.y+b.z;
		result=(double)sum1/(double)sum2;
		return result;
}
bool Cube::operator!=(const Cube& a){
		int vol1,vol2;
		vol1=this->x*this->y*this->z;
		vol2=a.x*a.y*a.z;
		if(vol1!=vol2)
				return true;
		else
				return false;
}
