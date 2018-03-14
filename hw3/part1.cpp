#include<iostream>
#include"part1.h"
using namespace std;
node::node(int x, node* t) { 
		item=x; 
		next=t;
}
typedef node* nodePtr;
stack::stack() { 
		top=0; 
}
void stack::empty() const {
		if (top==0) cout << "true" << endl;
		else cout << "false" << endl; 
}
void stack::push(int element) {
		nodePtr temp=new node(element,top);
		//temp->item=element;
		//temp->next=top;
		top=temp;
}
int stack::pop() {
		nodePtr temp;
		if (top==0) {
				cout << "error code:";
				return 9527;
				}
		else{
				temp=top;
				top=top->next;
				return temp->item;
		}
}

int main()
{
		stack d;
		d.empty();
		d.push(5);
		d.push(6);
		cout << d.pop() << endl;
		d.empty();
		cout << d.pop() << endl;
		d.empty(); 
		return 0;
}
