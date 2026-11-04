#include "../include/Accessory.h"
Accessory::Accessory():Product(),material(""),type(""){
}
Accessory::Accessory(string id,string name,double importPrice,double sellPrice,int quantity,string material,string type)
    :Product(id,name,importPrice,sellPrice,quantity),material(material),type(type){
}
Accessory::~Accessory(){
}
string Accessory::getMaterial()const{
	return material;
}
string Accessory::getType()const{
	return type;
}
void Accessory::display()const{
	cout << "[Phu kien] ID: " << id <<  " | Loai: " << type << " | Ten: " << name
	     << "| Chat lieu: " << material << " | Gia ban: " << sellPrice
	     << " | Ton kho: " << quantity << endl;
}
double Accessory::calcProfit()const{
	return (sellPrice-importPrice)*quantity;
}
