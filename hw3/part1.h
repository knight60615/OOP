#ifndef PART1_H
#define PART1_H

class node{
		public:
		int item;
		node* next;
		node(int x, node* t);
};
typedef node* nodePtr;
class stack{
		private:
		nodePtr top;
		public:
		stack();
		void empty() const;
		void push(int element);
		int pop();
};

#endif
