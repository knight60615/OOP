#include "part2.h"
#include <iostream>
using namespace std;
int main(){
		int num;
		cout<<"輸入點的數目:";
		cin>>num;
		Point ptt;
		LinkedList vertexList;
		Point a[num];
		cout<<"輸入x y:"<<endl;
		for(int i=0;i<num;i++)
				cin>>a[i].x>>a[i].y;

		if(vertexList.isEmpty()) cout<<"empty"<<endl;
		else cout<<"not empty"<<endl;
		for(int j=0; j<num; j++) {
				{
						vertexList.insertToPrev( a[j] );
						vertexList.pointToPrev();
						ptt = vertexList.getCurrentPoint();
						cout<<ptt.x<<"\t"<<ptt.y<<endl;
				}
		}

		if(vertexList.isEmpty()) cout<<"empty"<<endl;
		else cout<<"not empty"<<endl;
		int s = vertexList.getSize();
		cout<<"size:"<<s<<endl;

		ptt = vertexList.getCurrentPoint();
		cout<<"current:"<<ptt.x<<"\t"<<ptt.y<<endl;
		vertexList.deleteCurrentNode();
		ptt = vertexList.getCurrentPoint();
		cout<<"current:"<<ptt.x<<"\t"<<ptt.y<<endl;



		vertexList.clear();
		if(vertexList.isEmpty()) cout<<"empty"<<endl;
		else cout<<"not empty"<<endl;

		cout<<"-----------------------------\n";


		int num2;
		cout<<"輸入點的數目:";
		cin>>num2;

		Point c[num2];
		cout<<"輸入x y:"<<endl;
		for(int k=0;k<num2;k++)
				cin>>c[k].x>>c[k].y;

		Polygon  g;
		g.setPolygon(c,num2);

		Polygon *gc;
		gc = g.splitPolygon();

		//      cout<<gc->vertexList.getSize()<<endl;

		cout<<"輸入點的數目:";
		int num3;
		cin>>num3;
		Point b[num3];
		cout<<"輸入x y:"<<endl;
		for(int l=0;l<num3;l++)
				cin>>c[l].x>>c[l].y;
		Polygon p;
		p.setPolygon(b,num3);
		if(g.isCollide(p))cout<<"collide"<<endl;
		else cout<<"not collide"<<endl;
}
