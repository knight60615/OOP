#ifndef PART2_H
#define PART2_H

struct Point {
		int x; // x-coordinate
		int y; // y-coordinate
};
struct Node {
		Point pt;
		Node *next, *prev; 
};
class LinkedList {
		public:
				LinkedList(); // constructor
				~LinkedList(); // destructor
				int getSize() const;
				// return the number of elements (node) of the linked list
				bool isEmpty() const; // return true if the list is empty
				void clear(); // make the circular doubly linked list empty
				void deleteCurrentNode(); // delete the current node. The current
				// pointer will point to the next node of the deleted node
				void pointToNext();
				// make the current_pointer point to the next node
				void pointToPrev();
				// make the current_pointer point to the previous node
				Point getCurrentPoint() const;
				// return the Point pointed by the current_pointer
				void insertToNext( const Point& pt );
				// insert a Point next to the current node
				void insertToPrev( const Point& pt );
				// insert a Point before the current node
		private:
				// The current pointer. It points to the current node.
				// If the linked list is empty, it equals to NULL.
				Node* current_pointer;
};

class Polygon {
		public:
				Polygon();
				~Polygon();
				void setPolygon( Point pts[], int size );
				Polygon* splitPolygon();
				bool isCollide( Polygon& inPolygon );
				bool isEdgeIntersect( const Point& ptA, const Point& ptB );
		private:
				LinkedList vertexList;
};

#endif 
