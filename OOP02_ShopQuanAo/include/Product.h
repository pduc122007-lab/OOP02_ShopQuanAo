#ifndef PRODUCT_H
#define PRODUCT_H
#include<string>
#include<iostream>
using namespace std;
class Product{
	protected:
		string id;
		string name;
		double importPrice;//gia nhap
		double sellPrice;//gia ban
		int quantity;//soluongtonkho
	public:
		Product();
		Product(string id,string name,double importPrice,double sellPrice,int quantity);
		virtual ~Product();
		virtual void display() const = 0;
		virtual double calcProfit() const = 0;
		string getId() const;
		string getName() const;
		double getImportPrice() const;
		double getSellPrice() const;
		int getQuantity() const;
		void setQuantity(int q);
		void decreaseQuantity(int q);
};
#endif
