#include "../include/Customer.h"
Customer::Customer():Person(),points(0),type("Thuong"){
}
Customer::Customer(string id,string name,string phone,string address,int points):Person(id,name,phone,address),points(points){
	updateType();
}
Customer::~Customer(){
}
void Customer::display()const{
	cout << "\n[KHACH HANG]";
    cout << "\n + Ma KH   : " << id;
    cout << "\n + Ten     : " << name;
    cout << "\n + SDT     : " << phone;
    cout << "\n + Dia chi : " << address;
    cout << "\n + Diem    : " << points;
    cout << "\n + Loai    : " << type;
    cout << "\n";
}
double Customer::getDiscountRate()const{
	if(type == "VIP"){
		return 0.1;
	}
	else{
		return 0.0;
	}
}
int Customer::getPoints()const{
	return points;
}
string Customer::getType()const{
	return type;
}
void Customer::updateType(){
	if(points >= 100){
		type="VIP";
	}
	else{
		type="Thuong";
	}
}
void Customer::addPoints(int p){
	points+=p;
	updateType();
}
string Customer::getFileLine()const{
	return id + "|" + name + "|" + phone + "|" + address + "|" + to_string(points);
}
