#include "../include/Customer.h"
Customer::Customer():Person(),points(0),type("Thuong"){
}
Customer::Customer(string id,string name,string phone,string address,int points):Person(id,name,phone,address),points(points){
	updateType();
}
Customer::~Customer(){
}
void Customer::display()const{
	cout << "KH: " << id << " | " << name << " | " << phone << " | " << address << " | Diem: " << points << " | Loai: " << type << endl;
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
