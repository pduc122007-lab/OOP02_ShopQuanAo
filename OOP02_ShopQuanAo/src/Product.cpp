#include "../include/Product.h"
Product::Product():id(""),name(""),importPrice(0.0),sellPrice(0.0),quantity(0){
}
Product::Product(string id,string name,double importPrice,double sellPrice,int quantity)
            :id(id),name(name),importPrice(importPrice),sellPrice(sellPrice),quantity(quantity){
}
Product::~Product(){
}
string Product::getId()const{
	return id;
}
string Product::getName()const{
	return name;
}
double Product::getImportPrice()const{
	return importPrice;
}
double Product::getSellPrice()const{
	return sellPrice;
}
int Product::getQuantity()const{
	return quantity;
}
void Product::setQuantity(int q){
	quantity=q;
}
void Product::decreaseQuantity(int q){
	quantity -= q;
	if(quantity < 0){
		quantity = 0;
	}
}

