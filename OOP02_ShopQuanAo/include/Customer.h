#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"
class Customer:public Person{
	private:
		int points;
		string type;
		void updateType(); 
	public:
		Customer();
		Customer(string id,string name,string phone,string address,int points);
		~Customer();
		void display()const override;
		double getDiscountRate()const;
		int getPoints() const;
		string getType() const;
		void addPoints(int p);
		string getFileLine()const override;
};
#endif
