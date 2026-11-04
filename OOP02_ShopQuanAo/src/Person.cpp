#include "../include/Person.h"
Person::Person():name(""),id(""),phone(""),address(""){
}
Person::Person(string id,string name,string phone,string address):id(id),name(name),phone(phone),address(address){
}
Person::~Person(){
}
string Person::getId()const{
	return id;
}
string Person::getName()const{
	return name;
}
string Person::getPhone()const{
	return phone;
}
string Person::getAddress()const{
	return address;
}
void Person::setName(string name){
	this->name=name;
}
void Person::setPhone(string phone){
	this->phone=phone;
}
void Person::setAddress(string address){
	this->address=address;
}
