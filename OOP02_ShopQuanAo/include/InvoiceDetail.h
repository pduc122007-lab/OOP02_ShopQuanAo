#ifndef INVOICEDETAIL_H
#define INVOICEDETAIL_H
#include "Product.h"
class InvoiceDetail{
	private:
		Product* product;
		int quantity;
		double unitPrice;
	public:
		InvoiceDetail();
		InvoiceDetail(Product* product,int quantity);
		~InvoiceDetail();
		int getQuantity()const;
		Product* getProduct()const;
		double getSubTotal()const;
		void display()const;
		
};
#endif
