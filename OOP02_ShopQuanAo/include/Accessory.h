#ifndef ACCESSORY_H
#define ACCESSORY_H
#include "Product.h"
class Accessory:public Product{
	private:
		string material;
		string type;
	public:
		Accessory();
		Accessory(string id,string name,double importPrice,double sellPrice,int quantity,string material,string type);
		~Accessory();
		void display()const override;
		double calcProfit()const override;
		string getMaterial()const;
		string getType()const;
};
#endif
