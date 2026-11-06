#include "../include/Clothing.h"
#include <iomanip>
#include <sstream>
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
	cout << "\n[AO QUAN]";
    cout << "\n + Ma SP     : " << id;
    cout << "\n + Ten       : " << name;
    cout << "\n + Size      : " << size;
    cout << "\n + Mau sac   : " << color;
    cout << "\n + Thuong hieu: " << brand;
    cout << "\n + Gia ban   : " << fixed << setprecision(0) << sellPrice << " VND";
    cout << "\n + Ton kho   : " << quantity;
    cout << "\n";
}
double Clothing::calcProfit()const{
	return (sellPrice-importPrice)*quantity;
}
string Clothing::getFileLine()const{
	stringstream ss;
	ss << "CLOTHING|" << id << "|" << name << "|" 
       << fixed << setprecision(0) << importPrice << "|" 
       << fixed << setprecision(0) << sellPrice << "|" 
       << quantity << "|" << size << "|" << color << "|" << brand;
    return ss.str();
}
