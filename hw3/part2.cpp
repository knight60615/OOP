#include<iostream>
#include<algorithm>
#include"part2.h"
using namespace std;
LinkedList::LinkedList(){
		cout << "Constructing LinkedList..." << endl;
		//current_pointer=new Node;
		current_pointer=0;
}
LinkedList::~LinkedList(){
		cout << "Deleting LinkedList..."<< endl;
		//	delete current_pointer;
}
int LinkedList::getSize() const{
		int count=0;
		Node* ptr;
		ptr=current_pointer;
		do{
				ptr=ptr->next;
				count++;
		}while(ptr!=current_pointer);
		return count;
}
bool LinkedList::isEmpty() const{
		if(current_pointer==0)
				return true;
		else
				return false;
}
void LinkedList::clear(){
		while(current_pointer->next!=current_pointer)
				deleteCurrentNode();
		delete(current_pointer);
}
void LinkedList::deleteCurrentNode(){
		Node* ptr;
		ptr=current_pointer;
		ptr->next->prev=ptr->prev;
		ptr->prev->next=ptr->next;
		current_pointer=current_pointer->next;
		delete(ptr);
}
void LinkedList::pointToNext(){
		current_pointer=current_pointer->next;
}
void LinkedList::pointToPrev(){
		current_pointer=current_pointer->prev;
}
Point LinkedList::getCurrentPoint() const{
		return current_pointer->pt;
}
void LinkedList::insertToNext( const Point& pt ){
		Node* temp=new Node;
		temp->pt=pt;
		temp->prev=current_pointer;
		temp->next=current_pointer->next;
		current_pointer->next->prev=temp;
		current_pointer->next=temp;
}
void LinkedList::insertToPrev( const Point& pt ){
		Node* temp=new Node;
		temp->pt=pt;
		temp->prev=current_pointer->prev;
		temp->next=current_pointer;
		current_pointer->prev->next=temp;
		current_pointer->prev=temp;
}
Polygon::Polygon(){
		cout << "Constructing Polygon..." << endl;
		LinkedList vertexList;
}
Polygon::~Polygon(){
		cout << "Deleting Polygon..." << endl;
}
void Polygon::setPolygon( Point pts[], int size ){
		vertexList.clear();
		for( int i=0; i<size; i++ )
		{
				vertexList.insertToNext( pts[i] );
				vertexList.pointToNext();
		}
}
Polygon* Polygon::splitPolygon(){
		int n=vertexList.getSize();
		if(n<=3) return NULL;
		else{
				int m=n/2+1;
				Polygon* temp = new Polygon;
				for( int i=0; i<m; i++ )
				{
						Point p=vertexList.getCurrentPoint();
						temp->vertexList.insertToNext(p);
						temp->vertexList.pointToNext();
						if(i==0||i==m-1)
								vertexList.pointToNext();
						else
								vertexList.deleteCurrentNode();
				}
				return temp;
		}
}
bool Polygon::isCollide( Polygon& inPolygon ){
		if(inPolygon.vertexList.isEmpty()==true)
				return false;
		else{
				Point a,b;
				int size=inPolygon.vertexList.getSize();
				for(int i=0;i<size;i++){
						a=inPolygon.vertexList.getCurrentPoint();
						inPolygon.vertexList.pointToNext();
						b=inPolygon.vertexList.getCurrentPoint();
						if(inPolygon.isEdgeIntersect(a,b)==true)
								return true;
				}
				return false;
		}
}
// checks if point q lies on line segment p-r
bool onSegment(Point p, Point q, Point r)
{
		if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
						q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
				return true;

		return false;
}

// To find orientation of ordered triplet (p, q, r).
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
		// reference from http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
		int val = (q.y - p.y) * (r.x - q.x)-(q.x - p.x) * (r.y - q.y);

		if (val == 0) return 0;  // colinear

		return (val > 0)? 1: 2; // clock or counterclock wise
}

// line segment p1-q1 and line segent p2-q2 have intersection point or not.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
		//Find four orientations needed for general and special case 
		int o1 = orientation(p1, q1, p2);
		int o2 = orientation(p1, q1, q2);
		int o3 = orientation(p2, q2, p1);
		int o4 = orientation(p2, q2, q1);

		// General case- line segment A crosses  line segment B, looks like shape X.
		if (o1 != o2 && o3 != o4)
				return true;

		// Special Cases-one end point of line segment A(p1-q1 or p2-q2) lie s on line segment B(p2-q2 or p1-q1), looks like shape T.
		if (o1 == 0 && onSegment(p1, p2, q1)) return true;

		if (o2 == 0 && onSegment(p1, q2, q1)) return true;

		if (o3 == 0 && onSegment(p2, p1, q2)) return true;

		if (o4 == 0 && onSegment(p2, q1, q2)) return true;

		return false;
}

bool Polygon::isEdgeIntersect(const Point& ptA, const Point& ptB)
{
		Point polystart, polyend;
		bool flag=false;
		int count=0;
		int size=vertexList.getSize();
		if(size>=3)
		{
				count=0;	
				while(count<=size)
				{
						polystart=vertexList.getCurrentPoint();
						vertexList.pointToNext();
						polyend=vertexList.getCurrentPoint();

						flag=doIntersect(ptA, ptB, polystart, polyend);
						if(flag==true)
								break;	
						count++;
				}
		}
		else
				cout<<"This is not a polygon"<<endl;
		return flag;
}
