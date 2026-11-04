#include <iostream>
#include "../include/Customer.h"
#include "../include/Employee.h"
#include "../include/Clothing.h"
#include "../include/Accessory.h"
#include "../include/Invoice.h"

using namespace std;

int main() {
    cout << "=== TEST IN HOA DON ===\n";

    // 1. T?o Khách hàng (VIP), Nhân viên, và 2 S?n ph?m
    Customer kh("KH001", "Nguyen Van A", "0901234567", "Ha Noi", 150); // 150 ði?m -> VIP (gi?m 10%)
    Employee nv("NV001", "Tran Thi B", "0987654321", "HCM", 10000000, 26, "BanHang");
    
    Clothing ao("SP001", "Ao thun nam", 150000, 250000, 50, "L", "Trang", "Nike");
    Accessory mu("SP002", "Mu luoi trai", 50000, 120000, 100, "Vai", "Mu");

    // 2. T?o hóa ðõn
    Invoice hd("HD001", "04/11/2026", &kh, &nv);
    
    // 3. Khách mua 2 cái áo, 1 cái m?
    hd.addDetail(&ao, 2);
    hd.addDetail(&mu, 1);
    
    // 4. In hóa ðõn ra màn h?nh
    hd.display();
    
    // 5. Ki?m tra t?n kho sau khi mua
    cout << "\n--- KIEM TRA TON KHO SAU KHI MUA ---\n";
    cout << "Ton kho ao: " << ao.getQuantity() << " (Mong doi: 48)\n";
    cout << "Ton kho mu: " << mu.getQuantity() << " (Mong doi: 99)\n";

    return 0;
}
