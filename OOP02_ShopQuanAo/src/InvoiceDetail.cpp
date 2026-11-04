#include "../include/InvoiceDetail.h"
#include <iomanip>
InvoiceDetail::InvoiceDetail():product(nullptr),quantity(0),unitPrice(0.0){
}
InvoiceDetail::InvoiceDetail(Product* product,int quantity):product(product),quantity(quantity){
	if(product != nullptr){
		unitPrice = product->getSellPrice();
	}
	else{
		unitPrice = 0.0;
	}
}
InvoiceDetail::~InvoiceDetail(){
}
int InvoiceDetail::getQuantity()const{
	return quantity;
}
double InvoiceDetail::getSubTotal()const{
	return quantity*unitPrice;
}
Product* InvoiceDetail::getProduct()const{
	return product;
}
void InvoiceDetail::display()const{
	if(product != nullptr){
		cout << left << setw(10) << product->getId()
		     << setw(20) << product->getName()
		     << setw(10) << quantity
		     << setw(15) << fixed << setprecision(0) << unitPrice
		     << setw(15) << getSubTotal() << endl;
	}
}
