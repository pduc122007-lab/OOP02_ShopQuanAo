#include "../include/Accessory.h"
#include <iomanip>
#include <sstream>
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
	cout << "\n[PHU KIEN]";
    cout << "\n + Ma SP     : " << id;
    cout << "\n + Ten       : " << name;
    cout << "\n + Loai      : " << type;
    cout << "\n + Chat lieu : " << material;
    cout << "\n + Gia ban   : " << fixed << setprecision(0) << sellPrice << " VND";
    cout << "\n + Ton kho   : " << quantity;
    cout << "\n";
}
double Accessory::calcProfit()const{
	return (sellPrice-importPrice)*quantity;
}
string Accessory::getFileLine()const{
	stringstream ss;
    ss << "ACCESSORY|" << id << "|" << name << "|" 
       << fixed << setprecision(0) << importPrice << "|" 
       << fixed << setprecision(0) << sellPrice << "|" 
       << quantity << "|" << material << "|" << type;
       return ss.str();
}
