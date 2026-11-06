#include "../include/Customer.h"
#include "../include/Employee.h"
#include "../include/Clothing.h"
#include "../include/Accessory.h"
#include "../include/Invoice.h"
#include "../include/ShopManager.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
ShopManager<Product> quanLySanPham;
ShopManager<Employee> quanLyNhanVien;
ShopManager<Customer> quanLyKhachHang;
vector<Invoice*> danhSachHoaDon;
using namespace std;
void clearScreen(){
	system("cls");
}
void pauseScreen(){
	cout << "\n";
	system("pause");
}
void hienThiDanhSachSanPham(){
	clearScreen();
	if(quanLySanPham.size() == 0){
		cout << "\nKho hang dang trong!\n";
		return;
	}
	cout << "\n==================== DANH SACH SAN PHAM ====================\n";
	cout << left << setw(10) << "Ma SP"
	     << setw(25) << "Ten SP"
	     << setw(15) << "Gia ban"
	     << setw(10) << "Ton kho" << endl;
	cout << "------------------------------------------------------------\n";
	for(Product* p : quanLySanPham.getAll()){
		cout << left << setw(10) << p->getId()
		     << setw(25) << p->getName()
		     << setw(15) << fixed << setprecision(0) << p->getSellPrice()
		     << setw(10) << p->getQuantity() << endl;
	}
	cout << "\n============================================================\n";
}
void themSanPhamMoi(){
	clearScreen();
	int loai;
	cout << "\n---- THEM SAN PHAM MOI ----\n";
	cout << "1.Ao quan (Clothing)\n";
	cout << "2.Phu kien (Accessory)\n";
	cout << "Chon loai (1/2): "; cin >> loai;
	cin.ignore();
	if(loai != 1 && loai != 2){
		cout << "[Loi] Lua chon khong hop le! Vui long chon 1 hoac 2!\n";
		return;
	}
	string id,name;
	double giaBan;
	double giaNhap;
	int soLuong;
	cout << "Nhap ma san pham: "; getline(cin,id);
	if(quanLySanPham.findById(id) != nullptr){
		cout << "[Loi] Ma san pham nay da ton tai!\n";
		return;
	}
	cout << "Nhap ten san pham: "; getline(cin,name);
	cout << "Nhap gia ban: "; cin >> giaBan;
	cout << "Nhap gia nhap: "; cin >> giaNhap;
	cout << "Nhap so luong: "; cin >> soLuong;
	cin.ignore();
	if(loai == 1){
		string size,color,brand;
		cout << "Nhap size (S/M/L/XL): "; getline(cin,size);
		cout << "Nhap mau sac: "; getline(cin,color);
		cout << "Nhap thuong hieu: "; getline(cin,brand);
		quanLySanPham.add(new Clothing(id,name,giaNhap,giaBan,soLuong,size,color,brand));
		cout << "[Thanh Cong] Da them quan ao moi!\n";
	}
	else if(loai == 2){
		string material,type;
		cout << "Nhap chat lieu: "; getline(cin,material);
		cout << "Nhap loai phu kien (Mu/Tui/..): "; getline(cin,type);
		quanLySanPham.add(new Accessory(id,name,giaNhap,giaBan,soLuong,material,type));
		cout << "[Thanh Cong] Da them phu kien moi!\n";
	}
}
void xemChiTietSanPham(){
	clearScreen();
	string id;
	cout << "\nNhap ma san pham can xem chi tiet: ";
	cin.ignore();
	cin >> id;
	Product* p = quanLySanPham.findById(id);
	if(p != nullptr){
		cout << "\n--- CHI TIET SAN PHAM ---\n";
		p->display();
		cout << "---------------------------\n";
	}
	else{
		cout << "[Loi] Khong tim thay san pham muon xem!\n";
	}
}
void menuSanPham(){
	int choice;
	do{
		clearScreen();
		cout << "\n----- QUAN LY SAN PHAM -----\n";
		cout << "1.Xem danh sach san pham\n";
		cout << "2.Them san pham moi\n";
		cout << "3.Xem chi tiet san pham\n";
		cout << "0.Quay lai\n";
		cout << "Chon: "; cin >> choice;
		switch(choice){
			case 1:
				hienThiDanhSachSanPham();
				pauseScreen();
				break;
			case 2:
				themSanPhamMoi();
				pauseScreen();
				break;
			case 3:
				xemChiTietSanPham();
				pauseScreen();
				break;
			case 0:
				break;
			default:
				cout << "[Loi] Lua chon khong phu hop!\n";
				break;
		}
	}while(choice!=0);
}
void loadSanPham(){
	ifstream fin("data/products.txt");
	if(!fin.is_open()) return;
	string line;
	while(getline(fin,line)){
		if(line.empty() || line.length() < 2) continue;
		stringstream ss(line);
		string loai,id,ten,giaNhapStr,giaBanStr,soLuongStr;
		getline(ss,loai,'|');
		getline(ss,id,'|');
		getline(ss,ten,'|');
		getline(ss,giaNhapStr,'|');
		getline(ss,giaBanStr,'|');
		getline(ss,soLuongStr,'|');
		double giaNhap = stod(giaNhapStr);
		double giaBan = stod(giaBanStr);
		int soLuong = stoi(soLuongStr);
		if(loai == "CLOTHING"){
			string size,color,brand;
			getline(ss,size,'|');
			getline(ss,color,'|');
			getline(ss,brand,'|');
			quanLySanPham.add(new Clothing(id,ten,giaNhap,giaBan,soLuong,size,color,brand));
		}
		else if(loai == "ACCESSORY"){
			string material,type;
			getline(ss,material,'|');
			getline(ss,type,'|');
			quanLySanPham.add(new Accessory(id,ten,giaNhap,giaBan,soLuong,material,type));
		}
	}
	fin.close();
}
void saveSanPham(){
	ofstream fout("data/products.txt");
	if(!fout.is_open()) return;
	for(Product* p: quanLySanPham.getAll()){
		fout << p->getFileLine() << "\n";
	}
	fout.close();
}
void hienThiDanhSachKhachHang(){
	clearScreen();
	if(quanLyKhachHang.size() == 0){
		cout << "\nDanh sach khach hang dang trong!\n";
		return;
	}
	cout << "\n========================== DANH SACH KHACH HANG ========================\n";
	cout << left << setw(10) << "Ma KH"
		 << setw(25) << "Ten KH"
		 << setw(15) << "SDT"
		 << setw(10) << "Diem"
		 << setw(10) << "Loai" << endl;
	cout << "------------------------------------------------------------------------\n";
	for(Customer* c: quanLyKhachHang.getAll()){
		cout << left << setw(10) << c->getId()
		     << setw(25) << c->getName()
		     << setw(15) << c->getPhone()
		     << setw(10) << c->getPoints()
		     << setw(10) << c->getType() << endl;
	}
	cout << "==========================================================================\n";
}
void themKhachHangMoi(){
	clearScreen();
	string id,name,phone,address;
	cout << "\n---- THEM KHACH HANG MOI ----\n";
	cout << "Nhap ma khach hang: ";
	cin.ignore();
	getline(cin,id);
	if(quanLyKhachHang.findById(id) != nullptr){
		cout << "[Loi] Ma khach hang da ton tai!\n";
		return;
	}
	cout << "Nhap ten khach hang: ";
	getline(cin,name);
	cout << "Nhap so dien thoai: ";
	getline(cin,phone);
	cout << "Nhap dia chi: ";
	getline(cin,address);
	int diemBanDau;
	cout << "Nhap diem cho khach hang(neu la khach hang moi thi nhap 0): ";
	cin >> diemBanDau;
	cin.ignore();
	quanLyKhachHang.add(new Customer(id,name,phone,address,diemBanDau));
	cout << "[Thanh cong] Da them khach hang moi!\n";
}
void xemChiTietKhachHang(){
	clearScreen();
	string id;
	cin.ignore();
	cout << "\nNhap ma khach hang can xem chi tiet: ";
	getline(cin,id);
	Customer *c = quanLyKhachHang.findById(id);
	if(c != nullptr){
		cout << "\n---- CHI TIET KHACH HANG ----\n";
		c->display();
		cout << "----------------------------\n";
		int choice;
		cout << "Ban co muon cong diem cho khach hang nay khong?(1.Co, 0.Khong): ";
		cin >> choice;
		if(choice == 1){
			int diemCong;
			cout << "Nhap diem cong: ";
			cin >> diemCong;
			cin.ignore();
			c->addPoints(diemCong);
			cout << "[Thanh cong] Da cong thanh cong " << diemCong << " diem!\n";
			cout << "--- Thong tin sau khi cong diem ---\n";
			c->display();
		}
	}
	else{
		cout << "[Loi] Khong tim thay ma khach hang can xem!\n";
	}
}
void menuKhachHang(){
	int choice;
	do{
		clearScreen();
		cout << "\n----- QUAN LY KHACH HANG -----\n";
		cout << "1.Xem danh sach khach hang\n";
		cout << "2.Them khach hang moi\n";
		cout << "3.Xem chi tiet khach hang\n";
		cout << "0.Quay lai\n";
		cout << "Chon: ";
		cin >> choice;
		switch(choice){
			case 1:
				hienThiDanhSachKhachHang();
				pauseScreen();
				break;
			case 2:
				themKhachHangMoi();
				pauseScreen();
				break;
			case 3:
				xemChiTietKhachHang();
				pauseScreen();
				break;
			case 0:
				break;
			default:
				cout << "[Loi] Lua chon khong phu hop!\n";
		}
	}while(choice != 0);
}
void loadKhachHang(){
	ifstream fin("data/customers.txt");
	if(!fin.is_open()) return;
	string line;
	while(getline(fin,line)){
		if(line.empty() || line.length() < 2) continue;
		stringstream ss(line);
		string id,name,phone,address,pointsStr;
		getline(ss,id,'|');
		getline(ss,name,'|');
		getline(ss,phone,'|');
		getline(ss,address,'|');
		getline(ss,pointsStr,'|');
		int points = stoi(pointsStr);
		quanLyKhachHang.add(new Customer(id,name,phone,address,points));
	}
	fin.close();
}
void saveKhachHang(){
	ofstream fout("data/customers.txt");
	if(!fout.is_open()) return;
	for(Customer* c:quanLyKhachHang.getAll()){
		fout << c->getFileLine() << "\n";
	}
	fout.close();
}
void hienThiDanhSachNhanVien(){
	clearScreen();
	if(quanLyNhanVien.size() == 0){
		cout << "\nHien tai chua co nhan vien nao!\n";
		return;
	}
	cout << "\n========================================== DANH SACH NHAN VIEN =============================================\n";
	cout << left << setw(10) << "Ma NV"
	     << setw(25) << "Ten NV"
	     << setw(15) << "SDT"
	     << setw(15) << "Luong CB"
	     << setw(15) << "Ngay cong"
	     << setw(15) << "Chuc vu"
	     << setw(15) << "Luong thuc te" << endl;
	cout << "------------------------------------------------------------------------------------------------------------\n";
	for(Employee* e:quanLyNhanVien.getAll()){
		cout << left << setw(10) << e->getId()
		     << setw(25) << e->getName()
		     << setw(15) << e->getPhone()
		     << setw(15) << fixed << setprecision(0) << e->getBaseSalary()
		     << setw(15) << e->getWorkingDays()
		     << setw(15) << e->getRole()
		     << setw(15) << e->calcSalary() << endl;	
	}
	cout << "============================================================================================================\n";
}
void themNhanVienMoi(){
	clearScreen();
	string id,name,phone,address,role;
	double baseSalary;
	int workingDays;
	cout << "\n---- THEM NHAN VIEN MOI ----\n";
	cout << "Nhap ma nhan vien: ";
	cin.ignore();
	getline(cin,id);
	if(quanLyNhanVien.findById(id) != nullptr){
		cout << "[Loi] Ma nhan vien da ton tai!\n";
		return;
	}
	cout << "Nhap ten nhan vien: ";
	getline(cin,name);
	cout << "Nhap so dien thoai: ";
	getline(cin,phone);
	cout << "Nhap dia chi: ";
	getline(cin,address);
	cout << "Nhap luong CB: ";
	cin >> baseSalary;
	cout << "Nhap so ngay cong: ";
	cin >> workingDays;
	cout << "Nhap chuc vu(QuanLy/BanHang): ";
	cin.ignore();
	getline(cin,role);
	quanLyNhanVien.add(new Employee(id,name,phone,address,baseSalary,workingDays,role));
	cout << "[Thanh cong] Da them nhan vien moi!\n";
}
void loadNhanVien(){
    ifstream fin("data/employees.txt");
    if(!fin.is_open()) return;
    string line;
    while(getline(fin, line)) {
        if(line.empty() || line.length() < 2) continue;
        stringstream ss(line);
        string id, ten, sdt, diachi, luongStr, ngayStr, role;
        
        getline(ss, id, '|');
        getline(ss, ten, '|');
        getline(ss, sdt, '|');
        getline(ss, diachi, '|');
        getline(ss, luongStr, '|');
        getline(ss, ngayStr, '|');
        getline(ss, role, '|');
        
        if(!luongStr.empty() && !ngayStr.empty()) {
            double luong = stod(luongStr);
            int ngay = stoi(ngayStr);
            quanLyNhanVien.add(new Employee(id, ten, sdt, diachi, luong, ngay, role));
        }
    }
    fin.close();
}
void saveNhanVien(){
    ofstream fout("data/employees.txt");
    if(!fout.is_open()) return;
    for(Employee* e : quanLyNhanVien.getAll()) {
        fout << e->getFileLine() << "\n";
    }
    fout.close();
}
void menuNhanVien(){
    int choice;
    do {
        clearScreen();
        cout << "\n----- QUAN LY NHAN VIEN -----\n";
        cout << "1. Xem danh sach nhan vien\n";
        cout << "2. Them nhan vien moi\n";
        cout << "0. Quay lai\n";
        cout << "Chon: "; cin >> choice;
        switch(choice) {
            case 1:
            	hienThiDanhSachNhanVien();
            	pauseScreen();
            	break;
            case 2:
            	themNhanVienMoi();
            	pauseScreen();
            	break;
            case 0:
            	break;
            default:
            	cout << "[Loi] Lua chon khong phu hop!\n";
            	pauseScreen();
        }
    } while(choice != 0);
}
void taoHoaDonMoi(){
	clearScreen();
	string idHD,date,idKH,idNV;
	cout << "\n---- TAO HOA DON MOI ----\n";
	cout << "Nhap ma hoa don: ";
	cin.ignore();
	getline(cin,idHD);
	cout << "Nhap ngay mua(dd/mm/yyyy): ";
	getline(cin,date);
	cout << "Nhap ma khach hang: ";
	getline(cin,idKH);
	Customer* kh = quanLyKhachHang.findById(idKH);
	if(kh == nullptr){
		cout << "[Loi] Khong tim thay khach hang!\n";
		return;
	}
	cout << "Nhap ma nhan vien: ";
	getline(cin,idNV);
	Employee* nv = quanLyNhanVien.findById(idNV);
	if(nv == nullptr){
		cout << "[Loi] Khong tim thay nhan vien!\n";
		return;
	}
	Invoice* hd = new Invoice(idHD,date,kh,nv);
	while(true){
		string idSP;
		int sl;
		cout << "Nhap ma san pham (nhap 0 de ket thuc): ";
		getline(cin,idSP);
		if(idSP == "0") break;
		Product* sp = quanLySanPham.findById(idSP);
		if(sp == nullptr){
			cout << "[Loi] Khong tim thay san pham!\n";
			continue;
		}
		cout << "Nhap so luong mua: ";
		cin >> sl;
		cin.ignore();
		if(sl > sp->getQuantity()){
			cout << "[Loi] Kho khong du hang! (Chi con " << sp->getQuantity() << ")\n";
			continue;
		}
		hd->addDetail(sp,sl);
		cout << "Da them " << sp->getName() << "x" << sl << "\n";
	}
	hd->display();
    danhSachHoaDon.push_back(hd);
    cout << "\n[Thanh cong] Da tao hoa don moi!\n";
}
void hienThiDanhSachHoaDon(){
	clearScreen();
	if(danhSachHoaDon.size() == 0){
		cout << "\nChua co hoa don nao duoc luu!\n";
		return;
	}
	for(Invoice* hd:danhSachHoaDon){
		hd->display();
		cout << "\n";
	}
}
void menuHoaDon() {
    int choice;
    do {
        clearScreen();
        cout << "\n----- QUAN LY HOA DON -----\n";
        cout << "1. Tao hoa don moi\n";
        cout << "2. Xem danh sach hoa don\n";
        cout << "0. Quay lai\n";
        cout << "Chon: "; cin >> choice;
        
        switch(choice) {
            case 1: 
                taoHoaDonMoi(); 
                pauseScreen();
                break;
            case 2: 
                hienThiDanhSachHoaDon(); 
                pauseScreen();
                break;
            case 0: break;
            default: 
                cout << "[Loi] Lua chon khong phu hop!\n"; 
                pauseScreen();
        }
    } while(choice != 0);
}
void thongKeDoanhThu() {
    clearScreen();
    if (danhSachHoaDon.size() == 0) {
        cout << "\nChua co hoa don nao de thong ke!\n";
        return;
    }
    double tongDoanhThu = 0;
    int soLuongHoaDon = danhSachHoaDon.size();
    for (Invoice* hd : danhSachHoaDon) {
        tongDoanhThu += hd->getFinalTotal();
    }
    cout << "\n========== THONG KE DOANH THU ==========\n";
    cout << "Tong so hoa don da ban: " << soLuongHoaDon << "\n";
    cout << "Tong doanh thu: " << fixed << setprecision(0) << tongDoanhThu << " VND\n";
    cout << "Doanh thu trung binh/hoa don: " << tongDoanhThu / soLuongHoaDon << " VND\n";
    cout << "========================================\n";
}
void thongKeKhachHang() {
    clearScreen();
    if (quanLyKhachHang.size() == 0) {
        cout << "\nChua co khach hang nao!\n";
        return;
    }
    cout << "\n========== DANH SACH KHACH HANG VIP ==========\n";
    int countVIP = 0;
    for (Customer* c : quanLyKhachHang.getAll()) {
        if (c->getType() == "VIP") {
            cout << "- " << c->getName() << " | SDT: " << c->getPhone() 
                 << " | Diem: " << c->getPoints() << "\n";
            countVIP++;
        }
    }
    if (countVIP == 0) {
        cout << "Hien tai chua co khach hang nao dat hang VIP (>= 100 diem).\n";
    } else {
        cout << "----------------------------------------------\n";
        cout << "Tong so khach hang VIP: " << countVIP << "\n";
    }
    cout << "==============================================\n";
}
void menuThongKe() {
    int choice;
    do {
        clearScreen();
        cout << "\n----- THONG KE -----\n";
        cout << "1. Thong ke doanh thu\n";
        cout << "2. Danh sach khach hang VIP\n";
        cout << "0. Quay lai\n";
        cout << "Chon: "; cin >> choice;
        
        switch(choice) {
            case 1:
				thongKeDoanhThu();
				pauseScreen();
				break;
            case 2:
				thongKeKhachHang();
				pauseScreen();
				break;
            case 0:
				break;
            default:
				cout << "[Loi] Lua chon khong phu hop!\n";
				pauseScreen();
				break;
        }
    } while(choice != 0);
}
void hienThiMenuChinh(){
	cout << "\n============================================\n";
    cout << "       HE THONG QUAN LY SHOP QUAN AO        \n";
    cout << "============================================\n";
    cout << " 1. Quan ly San pham\n";
    cout << " 2. Quan ly Khach hang\n";
    cout << " 3. Quan ly Nhan vien\n";
    cout << " 4. Quan ly Hoa don\n";
    cout << " 5. Thong ke\n";
    cout << " 0. Thoat chuong trinh\n";
    cout << "============================================\n";
    cout << " Nhap lua chon cua ban: ";
}
int main() {
	loadSanPham();
	loadKhachHang();
	loadNhanVien();
	int choice;
	do{
		clearScreen();
		hienThiMenuChinh();
		cin >> choice;
		switch(choice){
			case 1:
				menuSanPham();
				break;
			case 2:
                menuKhachHang();
                break;
            case 3:
                menuNhanVien();
                break;
            case 4:
                menuHoaDon();
                break;
            case 5:
                menuThongKe();
                break;
            case 0:
                cout << "\nTam biet!\n"; 
                break;
            default:
                cout << "\nLua chon khong hop le!\n"; 
                pauseScreen();
        }
    } while (choice != 0);
	saveSanPham();
	saveKhachHang();
	saveNhanVien();
    return 0;
}
