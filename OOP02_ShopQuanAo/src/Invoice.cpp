#include "../include/Invoice.h"
#include <iomanip>
Invoice::Invoice():id(""),date(""),customer(nullptr),employee(nullptr){
}
Invoice::Invoice(string id,string date,Customer* customer,Employee* employee)
    :id(id),date(date),customer(customer),employee(employee){
}
Invoice::~Invoice(){
}
Customer* Invoice::getCustomer()const{
	return customer;
}
string Invoice::getId()const{
	return id;
}
string Invoice::getDate()const{
	return date;
}
void Invoice::addDetail(Product* p,int qty){
	p->decreaseQuantity(qty);
	details.push_back(InvoiceDetail(p,qty));
}
double Invoice::calcTotal()const{
	double total=0;
	for(const auto &detail : details){
		total += detail.getSubTotal();
	}
	if(customer != nullptr){
		total = total * (1.0-customer->getDiscountRate());
	}
	return total;
}
double Invoice::getFinalTotal()const{
	return calcTotal();
}
void Invoice::display() const {
    cout << "\n====================================================================\n";
    cout << setw(25) << " " << "HOA DON BAN HANG\n"; 
    cout << "====================================================================\n";
    cout << " Ma hoa don : " << id << "\n";
    cout << " Ngay mua   : " << date << "\n";
    if(customer){
        cout << " Khach hang : " << customer->getName()
             << " (" << customer->getType()
             << " - Giam gia " << 100 * customer->getDiscountRate() << "%)\n";
    }
    if(employee){
        cout << " Nhan vien  : " << employee->getName() << "\n";
    }
    cout << "--------------------------------------------------------------------\n";
    cout << left << setw(10) << "Ma SP"
         << setw(20) << "Ten SP"
         << setw(10) << "SL"
         << setw(15) << "Don Gia"
         << setw(15) << "Thanh Tien" << "\n";
    cout << "--------------------------------------------------------------------\n";
    for(const auto& detail : details){
        detail.display();
    }
    cout << "--------------------------------------------------------------------\n";
    double tongTruocGiam = 0;
    for(const auto& detail : details){
        tongTruocGiam += detail.getSubTotal();
    }
    double tienGiam = 0;
    if(customer != nullptr){
        tienGiam = tongTruocGiam * customer->getDiscountRate();
    }
    double tongCuoiCung = calcTotal();
    string strTong = " Tong cong hoa don:";
    strTong.resize(50, ' ');
    
    string strGiam = " Tien giam gia VIP:";
    strGiam.resize(50, ' ');
    
    string strThanhToan = " TONG THANH TOAN:";
    strThanhToan.resize(50, ' ');
    
    cout << strTong << right << setw(11) << fixed << setprecision(0) << tongTruocGiam << " VND\n";
    if(tienGiam > 0){
        cout << strGiam << right << setw(11) << -tienGiam << " VND\n";
    }
    cout << "--------------------------------------------------------------------\n";
    cout << strThanhToan << right << setw(11) << tongCuoiCung << " VND\n";
    cout << "====================================================================\n";
    cout << setw(10) << " " << "Cam on quy khach da mua hang. Hen gap lai!\n"; 
    cout << "====================================================================\n";
}
