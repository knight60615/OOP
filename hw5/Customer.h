#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;
// An abstract class for a Customer.
// Add to this class what is necessary
class Customer {
		protected:
			char fname[20],sname[20],town[20];
			int no;
			static int num;
		public:
		// Create a customer with:
		// f: first name
		// s: surname
		// t: town
		Customer (char *f, char *s, char *t);
		// Create a customer copying the properties from another object
		// c: a reference to the other Customer object
		//Customer (Customer &c);
		// Release previously allocated memory
		virtual ~Customer (void);
		// Write a message for the secretary, commonpart
		virtual void christmasPresent()=0;
};
class OrdinaryCustomer : public Customer {
		protected:
			char beer[20];
			int ono;
			static int onum;
		public:
		// Create an ordinary customer with:
		// f: first name
		// s: surname
		// t: town
		// b: favorite beerbrand
		OrdinaryCustomer (char *f, char *s, char *t, char *b);
		// Create an ordinary customer copying the properties from another object
		// c: a reference to the other OrdinaryCustomer object
		//OrdinaryCustomer (OrdinaryCustomer &c);
		// Release previously allocated memory
		virtual ~OrdinaryCustomer (void);
		// Write a message for the secretary, particularpart
		virtual void christmasPresent (void);
};
class PremiumCustomer : public Customer {
		protected:
			char wine[20];
			int pno;
			static int pnum;
		public:
		// Create a premium customer with:
		// f: first name
		// s: surname
		// t: town
		// w: favorite winebrand
		PremiumCustomer (char *f, char *s, char *t, char *w);
		// Create a premium customer copying the properties
		// from another object
		// c: a reference to the other PremiumCustomer object
		//PremiumCustomer (PremiumCustomer &c);
		// Release previously allocated memory
		virtual ~PremiumCustomer (void);
		// Write a message for the secretary, particular part
		virtual void christmasPresent (void);
};
#endif // CUSTOMER_H
