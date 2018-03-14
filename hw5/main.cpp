#include "CustomerList.h"
#include <iostream>
using namespace std;
int main (void) {
int i = 0;
CustomerList *list = new CustomerList ();
list->to (i, new OrdinaryCustomer ("Vivian","Wang", "Taichung", "Holsten"));
++i;
list->to (i, new PremiumCustomer ("Sam", "Lee", "Kaohsiung", "Bordeaux"));
++i;
list->to (i, new OrdinaryCustomer ("John", "Chen", "Taipei", "Ginger Ale"));
/*++i;
list->to (i, new PremiumCustomer ("Homura", "Akemi", "Tokyo", "Choya"));*/
// Produce outputs (Write messages for the secretary) ¡Vfill in the code here
for(int j=0;j<=i;j++){
		list->at(j)->christmasPresent();
}
//Release previously allocated memory ¡Vfile in the code here
for(int j=0;j<=i;j++){
		//list->remove(j);
		delete list->at(j);
}

delete list;
return 0;
}
