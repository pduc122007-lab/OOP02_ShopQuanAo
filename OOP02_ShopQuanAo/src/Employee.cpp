#include"../include/Employee.h"
#include<iomanip>
Employee::Employee():Person(),baseSalary(0.0),workingDays(0),role(""){
}
Employee::Employee(string id,string name,string phone,string address,double baseSalary,int workingDays,string role):
	Person(id,name,phone,address),baseSalary(baseSalary),workingDays(workingDays),role(role){
}
Employee::~Employee(){
}
void Employee::display()const{
	cout << fixed << setprecision(0);
	cout << "NV: " << id << " | " << name << " | " << phone << " | " << address << " | Luong co ban: "
	     << baseSalary << " | Ngay cong: " << workingDays << " | Chuc vu: " << role << " | Luong thuc nhan: "
	     << calcSalary() << "VND" << endl;
}
double Employee::calcSalary()const{
	double salary=baseSalary*workingDays/26.0;
	if(role == "QuanLy") return salary*1.2;
	else return salary;
}
