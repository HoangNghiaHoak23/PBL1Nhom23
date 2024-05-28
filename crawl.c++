#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

#define MAXDATA 100

class Doibong {
public:
    string TenClb;
    Doibong(string TenClb = "") {
        this->TenClb = TenClb;
    }
    void NhapTenClb() {
        cout << "Nhap ten cau lac bo: ";
        getline(cin, TenClb);
    }
    string getTenClb() {
        return TenClb;
    }
    void XuatTenClb() {
        cout << TenClb << endl;
    }
};

class ThongTin : public Doibong {
private:
    int VT, Tr, T, H, B, HS, BT, BB, BTSK, TV, TD, Diem;

public:
    ThongTin(int VT = 0, int Tr = 0, int T = 0, int H = 0, int B = 0, int BT = 0, int BB = 0, int HS = 0, int BTSK = 0, int TV = 0, int TD = 0, int Diem = 0, string TenClb = "") : Doibong(TenClb) {
        this->VT = VT;
        this->Tr = Tr;
        this->T = T;
        this->H = H;
        this->B = B;
        this->BT = BT;
        this->BB = BB;
        this->HS = BT - BB;
        this->BTSK = BTSK;
        this->TV = TV;
        this->TD = TD;
        this->Diem = T * 3 + H;
    }

    int getVT() { return VT; }
    void setVT(int vt) { VT = vt; }
    int getTr() { return Tr; }
    int getT() { return T; }
    int getH() { return H; }
    int getB() { return B; }
    int getBT() { return BT; }
    int getBB() { return BB; }
    int getHS() { return HS; }
    int getBTSK() { return BTSK; }
    int getTV() { return TV; }
    int getTD() { return TD; }
    int getDiem() { return Diem; }

    void NhapThongtin() {
        Doibong::NhapTenClb();
        cout << "Nhap so tran: ";
        cin >> Tr;
        cout << "Nhap so tran thang: ";
        cin >> T;
        cout << "Nhap so tran hoa: ";
        cin >> H;
        cout << "Nhap so tran thua: ";
        cin >> B;
        cout << "Nhap so ban thang: ";
        cin >> BT;
        cout << "Nhap so ban thua: ";
        cin >> BB;
        cout << "Nhap so ban thang san khach: ";
        cin >> BTSK;
        cout << "Nhap so the vang: ";
        cin >> TV;
        cout << "Nhap so the do: ";
        cin >> TD;
    }

    void XuatThongTin() {
    	cout << "+----+-------------------------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------+" << endl;
    	cout << "| " << left << setw(4) << "VT" 
             << setw(33) << "TEN CLB" 
             << setw(6) << "Tr" 
             << setw(6) << "T" 
             << setw(6) << "H" 
             << setw(6) << "B" 
             << setw(6) << "BT" 
             << setw(6) << "BB" 
             << setw(6) << "HS" 
             << setw(6) << "BTSK" 
             << setw(6) << "TV" 
             << setw(6) << "TD" 
             << setw(6) << "Diem" 
             << " |" << endl;
        cout << "+----+-------------------------------+-----+-----+-----+-----+-----+----+-----+-----+------+-----+--------+" << endl;
        cout << "| " << left << setw(4) << VT 
             << setw(33) << TenClb
             << setw(6) << Tr 
             << setw(6) << T 
             << setw(6) << H 
             << setw(6) << B 
             << setw(6) << BT 
             << setw(6) << BB 
             << setw(6) << HS 
             << setw(6) << BTSK 
             << setw(6) << TV 
             << setw(6) << TD 
             << setw(6) << Diem << endl;
        cout << "+----+-------------------------------+-----+-----+-----+-----+-----+----+-----+-----+------+-----+--------+" << endl;
    }
    string toCSV() {
        stringstream ss;
        ss << VT << "," << TenClb << "," << Tr << "," << T << "," << H << "," << B << "," 
           << BT << "," << BB << "," << HS << "," << BTSK << "," << TV << "," << TD << "," << Diem;
        return ss.str();
    }
};

class QuanLiDuLieu {
    ThongTin Data[MAXDATA];
    int soluong;
public:
    QuanLiDuLieu() {
        soluong = 0;
    }

    void Them(ThongTin newData) {
        if (soluong < MAXDATA) {
            Data[soluong++] = newData;
            SapXep(); // Gọi hàm sắp xếp sau khi thêm
        } else {
            cout << "So luong doi bong da day" << endl;
        }
    }

    void HienThi() {
        for (int i = 0; i < soluong; i++) {
            Data[i].XuatThongTin();
        }
    }

    void XuatBang() {
        cout << "+----+-------------------------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------+" << endl;
        cout << "| " << left << setw(4) << "VT" 
             << setw(33) << "TEN CLB" 
             << setw(6) << "Tr" 
             << setw(6) << "T" 
             << setw(6) << "H" 
             << setw(6) << "B" 
             << setw(6) << "BT" 
             << setw(6) << "BB" 
             << setw(6) << "HS" 
             << setw(6) << "BTSK" 
             << setw(6) << "TV" 
             << setw(6) << "TD" 
             << setw(6) << "Diem" 
             << " |" << endl;
        cout << "+----+-------------------------------+-----+-----+-----+-----+-----+----+-----+-----+------+-----+--------+" << endl;
        for (int i = 0; i < soluong; i++) {
            cout << "| " << left << setw(4) << Data[i].getVT() 
                 << setw(33) << Data[i].getTenClb() 
                 << setw(6) << Data[i].getTr() 
                 << setw(6) << Data[i].getT() 
                 << setw(6) << Data[i].getH() 
                 << setw(6) << Data[i].getB() 
                 << setw(6) << Data[i].getBT() 
                 << setw(6) << Data[i].getBB() 
                 << setw(6) << Data[i].getHS() 
                 << setw(6) << Data[i].getBTSK() 
                 << setw(6) << Data[i].getTV() 
                 << setw(6) << Data[i].getTD() 
                 << setw(6) << Data[i].getDiem() 
                 << " |" << endl;
        }
        cout << "+----+-------------------------------+-----+-----+-----+-----+-----+----+-----+-----+------+-----+--------+" << endl;
    }

    void Xoa(int a) {
        if (a >= 0 && a < soluong) {
            for (int i = a; i < soluong - 1; i++) {
                Data[i] = Data[i + 1];
            }
            soluong--;
            SapXep(); 
        } else {
            cout << "Nhap sai vi tri" << endl;
        }
    }

    void Sua(int VT, ThongTin newData) {
        if (VT >= 0 && VT < soluong) {
            Data[VT] = newData;
            SapXep(); 
        } else {
            cout << "Khong hop le" << endl;
        }
    }

    void TracuuVT(int VT) {
        if (VT >= 0 && VT < soluong) {
            Data[VT].XuatThongTin();
        } else {
            cout << "Khong tim thay" << endl;
        }
    }

    void TracuuTenClb(string TenClb){
        bool a = false;
        for(int i = 0; i< soluong; i++){
            if(Data[i].getTenClb() == TenClb){
                Data[i].XuatThongTin();
                a = true;
            }
        }
        if(!a){
            cout << "Khong tim thay ten doi bong trong du lieu " << endl;
        }
    }
    
void DocFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the mo file " << filename << endl;
        return;
    }
    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string TenClb;
        int VT, Tr, T, H, B, HS, BTSK, TV, TD, Diem;
        int BT, BB;
        string temp;

        getline(ss, temp, ','); VT = stoi(temp);
        getline(ss, TenClb, ',');
        getline(ss, temp, ','); Tr = stoi(temp);
        getline(ss, temp, ','); T = stoi(temp);
        getline(ss, temp, ','); H = stoi(temp);
        getline(ss, temp, ','); B = stoi(temp);
        getline(ss, temp, ','); BT = stoi(temp);
        getline(ss, temp, ','); BB = stoi(temp);
        HS = BT - BB;
        getline(ss, temp, ',');
        getline(ss, temp, ','); BTSK = stoi(temp);
        getline(ss, temp, ','); TV = stoi(temp);
        getline(ss, temp, ','); TD = stoi(temp);
        getline(ss, temp, ','); Diem = stoi(temp);

        ThongTin newData = ThongTin(VT, Tr, T, H, B, BT, BB, HS, BTSK, TV, TD, Diem, TenClb);
        Them(newData);
    }
    file.close();
}
    void SapXep() {
        for (int i = 0; i < soluong - 1; i++) {
            for (int j = 0; j < soluong - i - 1; j++) {
                if (Data[j].getDiem() < Data[j + 1].getDiem() || 
                   (Data[j].getDiem() == Data[j + 1].getDiem() && Data[j].getHS() < Data[j + 1].getHS()) ||
                   (Data[j].getDiem() == Data[j + 1].getDiem() && Data[j].getHS() == Data[j + 1].getHS() && Data[j].getBT() < Data[j + 1].getBT())) {
                    ThongTin temp = Data[j];
                    Data[j] = Data[j + 1];
                    Data[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < soluong; i++) {
            Data[i].setVT(i + 1);
        }
    }
    void GhiFile(string filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Khong the mo file " << filename << endl;
            return;
        }

        file << "VT,TenClb,Tr,T,H,B,BT,BB,HS,BTSK,TV,TD,Diem\n";

        for (int i = 0; i < soluong; i++) {
        	if (Data[i].getVT() != 0) {
            file << Data[i].toCSV() << endl;
        }
    }    
        file.close();
    }
};

class User {
public:
    QuanLiDuLieu* QuanLy;
    User(QuanLiDuLieu* ql) : QuanLy(ql) {}
    virtual void Menu() {
        int n;
        do {
            cout << "+---------------------------------------------------+" << endl;
            cout << "|          CAC CHUC NANG CUA USER                   |" << endl;
            cout << "|---------------------------------------------------|" << endl;
            cout << "|             1. HIEN THI BANG XEP HANG             |" << endl;
            cout << "|             2. TIM KIEM DOI BONG                  |" << endl;
            cout << "|             0. THOAT CHUONG TRINH                 |" << endl;
            cout << "+---------------------------------------------------+" << endl;
            cout << endl;
            cout << "CHUC NANG BAN CHON: ";
            cin >> n;
            cin.ignore();

            switch (n) {
            case 1: {
                cout << "BAN DA CHON CHUC NANG HIEN THI BANG XEP HANG " << endl;
                QuanLy->DocFile("20232024.csv");
                QuanLy->XuatBang();
                break;
            }
            case 2: {
            int m;
                do {
                    cout << "1.Tim kiem bang vi tri" << endl;
                    cout << "2.Tim kiem bang ten doi bong" << endl;
                    cout << "0.Thoat chuc nang tim kiem" << endl;
                    cout << "Chuc nang ban muon chon: ";
                    cin >> m;
                    cin.ignore();
                    switch (m) {
                    case 1: {
                        cout << "BAN DA CHON CHUC NANG TIM KIEM BANG VI TRI " << endl;
                        int VT;
                        cout << "Nhap vi tri ma ban muon tim kiem: ";
                        cin >> VT;
                        QuanLy->TracuuVT(VT - 1);
                        break;
                    }
                    case 2: {
                        cout << "BAN DA CHON CHUC NANG TIM KIEM BANG TEN CLB " << endl;
                        string TenClb;
                        cout << "Nhap ten doi bong ma ban muon tim kiem: ";
                        getline(cin, TenClb);
                        QuanLy->TracuuTenClb(TenClb);
                        break;
                    }
                    case 0: {
                        break;
                    }
                    default: {
                        cout << "Ban da nhap sai lenh vui long nhap lai" << endl;
                        break;
                    }
                    }
                } while (m != 0);
                break;
            }
            case 0: {
                return;
            }
            default: {
                cout << "BAN DA NHAP SAI LENH VUI LONG NHAP LAI" << endl;
            }
            }
        } while (true);
    }
};

class Admin : public User {
public:
    Admin(QuanLiDuLieu* ql) : User(ql) {}
	bool DangNhap() {
        string tk, mk;
        cout << "Nhap tai khoan: ";
        getline(cin, tk);
        cout << "Nhap mat khau: ";
        getline(cin, mk);
        // Tài khoản của admin là : admin Còn mật khẩu là admin123
        return (tk == "admin" && mk == "admin123");
    }

    void Menu() {
    	if (!DangNhap()) {
            cout << "Tai khoan hoac mat khau sai. Vui long thu lai." << endl;
            return;
        } else {
        	cout << "BAN DANG QUAN LY DUOI DANH NGHIA ADMIN" << endl;
		}
        int n;
        do {
            cout << "+---------------------------------------------------+" << endl;
            cout << "|          CAC CHUC NANG CUA ADMIN                  |" << endl;
            cout << "|---------------------------------------------------|" << endl;
            cout << "|             1. THEM DU LIEU                       |" << endl;
            cout << "|             2. HIEN THI                           |" << endl;
            cout << "|             3. TRA CUU DU LIEU                    |" << endl;
            cout << "|             4. XOA DU LIEU BANG CHI SO            |" << endl;
            cout << "|             5. SUA DU LIEU                        |" << endl;
            cout << "|             6. GHI FILE                           |" << endl;
            cout << "|             7. DOC FILE                           |" << endl;
            cout << "|             0. THOAT CHUONG TRINH                 |" << endl;
            cout << "+---------------------------------------------------+" << endl;
            cout << endl;
            cout << "CHUC NANG BAN CHON: ";
            cin >> n;
            cin.ignore();

            switch (n) {
            case 1: {
                cout << "BAN DA CHON CHUC NANG THEM DU LIEU" << endl;
                string TenClb;
                int VT, Tr, T, H, B, HS, BTSK, TV, TD, Diem;
                int BT, BB;
                cout << "Nhap ten cau lac bo: ";
                getline(cin, TenClb);
                cout << "Nhap so tran: ";
                cin >> Tr;
                cout << "Nhap so tran thang: ";
                cin >> T;
                cout << "Nhap so tran hoa: ";
                cin >> H;
                cout << "Nhap so tran thua: ";
                cin >> B;
                cout << "Nhap so ban thang: ";
                cin >> BT;
                cout << "Nhap so ban thua: ";
                cin >> BB;
                cout << "Nhap so ban thang san khach: ";
                cin >> BTSK;
                cout << "Nhap so the vang: ";
                cin >> TV;
                cout << "Nhap so the do: ";
                cin >> TD;
                ThongTin newData = ThongTin(VT, Tr, T, H, B, BT, BB, HS, BTSK, TV, TD, Diem, TenClb);
                QuanLy->Them(newData);
                cin.ignore();
                break;
            }
            case 2: {
            	cout << "BAN DA CHON CHUC NANG XUAT DU LIEU " << endl;
        		cout << endl;
            	QuanLy->XuatBang();
            	break;
            }
            case 3: {
                int m;
                do {
                    cout << "1.Tim kiem bang vi tri" << endl;
                    cout << "2.Tim kiem bang ten doi bong" << endl;
                    cout << "0.Thoat chuc nang tim kiem" << endl;
                    cout << "Chuc nang ban muon chon: ";
                    cin >> m;
                    cin.ignore();
                    switch (m) {
                    case 1: {
                        cout << "BAN DA CHON CHUC NANG TIM KIEM BANG VI TRI " << endl;
                        int VT;
                        cout << "Nhap vi tri ma ban muon tim kiem: ";
                        cin >> VT;
                        QuanLy->TracuuVT(VT - 1);
                        break;
                    }
                    case 2: {
                        cout << "BAN DA CHON CHUC NANG TIM KIEM BANG TEN CLB " << endl;
                        string TenClb;
                        cout << "Nhap ten doi bong ma ban muon tim kiem: ";
                        getline(cin, TenClb);
                        QuanLy->TracuuTenClb(TenClb);
                        break;
                    }
                    case 0: {
                        break;
                    }
                    default: {
                        cout << "Ban da nhap sai lenh vui long nhap lai" << endl;
                        break;
                    }
                    }
                } while (m != 0);
                break;
            }
            case 4: {
                cout << "BAN DA CHON CHUC NANG XOA DU LIEU BANG VI TRI " << endl;
                int VT;
                cout << "Nhap vi tri ma ban muon xoa: ";
                cin >> VT;
                QuanLy->Xoa(VT - 1);
                break;
            }
            case 5: {
                cout << "BAN DA CHON CHUC NANG SUA DU LIEU " << endl;
                int VT;
                string TenClb;
                int Tr, T, H, B, HS, BTSK, TV, TD, Diem;
                int BT, BB;
                cout << "Nhap vi tri doi bong ma ban muon sua: ";
                cin >> VT;
                cin.ignore();
                cout << "Nhap ten cau lac bo: ";
                getline(cin, TenClb);
                cout << "Nhap so tran: ";
                cin >> Tr;
                cout << "Nhap so tran thang: ";
                cin >> T;
                cout << "Nhap so tran hoa: ";
                cin >> H;
                cout << "Nhap so tran thua: ";
                cin >> B;
                cout << "Nhap so ban thang: ";
                cin >> BT;
                cout << "Nhap so ban thua: ";
                cin >> BB;
                cout << "Nhap so ban thang san khach: ";
                cin >> BTSK;
                cout << "Nhap so the vang: ";
                cin >> TV;
                cout << "Nhap so the do: ";
                cin >> TD;
                ThongTin newData = ThongTin(VT, Tr, T, H, B, BT, BB, HS, BTSK, TV, TD, Diem, TenClb);
                QuanLy->Sua(VT, newData);
                break;
            }
            case 6: {
                cout << "BAN DA CHON CHUC NANG GHI FILE " << endl;
                QuanLy->GhiFile("20232024.csv");
                cout << "DU LIEU DA DUOC LUU VAO FILE " << endl;
                break;
            }
            case 7: {
                cout << "BAN DA CHON CHUC NANG DOC FILE VA HIEN THI " << endl;
                QuanLy->DocFile("20232024.csv");
                cout << "DU LIEU DA DUOC DOC " << endl;
                break;
            }
            case 0: {
                return;
            }
            default: {
                cout << "BAN DA NHAP SAI LENH VUI LONG NHAP LAI" << endl;
            }
            }
        } while (true);
    }
};
				

int main() {
    QuanLiDuLieu QuanLy;
    int a;

    cout << "+---------------------------------------------------+" << endl;
    cout << "|                DANG NHAP                          |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "|               1. ADMIN                            |" << endl;
    cout << "|               2. USER                             |" << endl;
    cout << "+---------------------------------------------------+" << endl;
    cout << "CHUC NANG BAN CHON: ";
    cin >> a;
    cin.ignore();

    if (a == 1) {
        Admin admin(&QuanLy);
        admin.Menu();
    } else if (a == 2) {
        User user(&QuanLy);
        user.Menu();
    } else {
        cout << "BAN DA NHAP SAI LENH VUI LONG NHAP LAI" << endl;
    }
    return 0;
}
