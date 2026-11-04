#ifndef INVOICE_H
#define INVOICE_H
#include <string>
#include <vector>
#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "Employee.h"
#include "InvoiceDetail.h"
class Invoice{
	private:
		string id;
		string date;
		Customer* customer;
		Employee* employee;
		vector<InvoiceDetail> details;
	public:
		Invoice();
		Invoice(string id,string date,Customer* customer,Employee* employee);
		~Invoice();
		void display()const;
		void addDetail(Product* p,int qty);
		double calcTotal()const;
		Customer* getCustomer()const;
		string getId()const;
		string getDate()const;
		double getFinalTotal()const;
};
#endif
