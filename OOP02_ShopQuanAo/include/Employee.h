#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
class Employee:public Person{
	private:
		double baseSalary;
		int workingDays;
		string role;
	public:
		Employee();
		Employee(string id,string name,string phone,string address,double baseSalary,int workingDays,string role);
		~Employee();
		void display()const override;
		double calcSalary() const;
};
#endif
