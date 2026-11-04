#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<iostream>
using namespace std;
class Person{
	protected:
		string id;
		string name;
		string phone;
		string address;
	public:
		Person();
		Person(string id,string name,string phone,string address);
		virtual ~Person();
		virtual void display() const = 0;
		string getId() const;
		string getName() const;
		string getPhone() const;
		string getAddress() const;
		void setName(string name);
		void setPhone(string phone);
		void setAddress(string address);
};
#endif

