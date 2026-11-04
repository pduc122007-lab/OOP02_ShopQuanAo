#include "../include/Clothing.h"
Clothing::Clothing():Product(),size(""),color(""),brand(""){
}
Clothing::Clothing(string id,string name,double importPrice,double sellPrice,int quantity,string size,string color,string brand)
     :Product(id,name,importPrice,sellPrice,quantity),size(size),color(color),brand(brand){
}
Clothing::~Clothing(){
}
string Clothing::getSize()const{
	return size;
}
string Clothing::getColor()const{
	return color;
}
string Clothing::getBrand()const{
	return brand;
}
void Clothing::display()const{
	cout << "[Ao quan] ID: " << id << " | Ten: " << name
	     << " | Size: " << size << " | Mau: " << color
	     << " | Brand: " << brand << " | Gia ban: " << sellPrice
	     << " | Ton kho: " << quantity << endl;
}
double Clothing::calcProfit()const{
	return (sellPrice-importPrice)*quantity;
}
