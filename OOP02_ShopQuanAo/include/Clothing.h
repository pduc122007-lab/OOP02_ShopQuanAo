#ifndef CLOTHING_H
#define CLOTHING_H
#include "Product.h"
class Clothing:public Product{
	private:
		string size;
		string color;
		string brand;
	public:
		Clothing();
		Clothing(string id,string name,double importPrice,double sellPrice,int quantity,string size,string color,string brand);
		~Clothing();
		void display()const override;
		double calcProfit()const override;
		string getSize()const;
		string getColor()const;
		string getBrand()const;
		string getFileLine()const override;
};
#endif
