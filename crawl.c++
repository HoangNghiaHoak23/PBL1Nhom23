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
        while (Tr < 0) {
            cout << "Gia tri khong hop le, vui long nhap lai: ";
            cin >> Tr;
        }
        cout << "Nhap so tran thang: ";
        cin >> T;
        while (T < 0) {
            cout << "Gia tri khong hop le, vui long nhap lai: ";
            cin >> T;
        }
        cout << "Nhap so tran hoa: ";
        cin >> H;
        while (H < 0) {
            cout << "Gia tri khong hop le, vui long nhap lai: ";
            cin >> H;
        }
        cout << "Nhap so tran thua: ";
        cin >> B;
        while (B < 0) {
            cout << "Gia tri khong hop le, vui long nhap lai: ";
            cin >> B;
        }
        cout << "Nhap so ban thang: ";
        cin >> BT;
        while (BT < 0) {
            cout << "Gia tri khong hop le, vui long nhap lai: ";
            cin >> BT;
        }
        cout << "Nhap so ban thua: ";
        cin >> BB;
        while (BB < 0) {
            cout << "Gia tri khong hop le, vui long nhap lai: ";
            cin >> BB;
        }
        cout << "Nhap so ban thang san khach: ";
        cin >> BTSK;
        while (BTSK < 0) {
            cout << "Gia tri khong hop le, vui long nhap lai: ";
            cin >> BTSK;
        }
        cout << "Nhap so the vang: ";
        cin >> TV;
        while (TV < 0) {
            cout << "Gia tri khong hop le, vui long nhap lai: ";
            cin >> TV;
        }
        cout << "Nhap so the do: ";
        cin >> TD;
        while (TD < 0) {
            cout << "Gia tri khong hop le, vui long nhap lai: ";
            cin >> TD;
        }
        HS = BT - BB;
        Diem = T * 3 + H;
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

    string Hamghifile() {
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
    // Thêm dữ liệu
    void Them(ThongTin newData) {
        if (soluong < MAXDATA) {
            Data[soluong++] = newData;
            SapXep();
        } else {
            cout << "So luong doi bong da day" << endl;
        }
    }
    // Hiển thị thông tin
    void HienThi() {
        for (int i = 0; i < soluong; i++) {
            Data[i].XuatThongTin();
        }
    }
    // Xuất dữ liệu ra màn hình
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
    // Hàm xóa dữ liệu
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
    // Hàm sửa dữ liệu
    void Sua(int VT, ThongTin newData) {
        if (VT >= 0 && VT < soluong) {
            Data[VT] = newData;
            SapXep(); 
        } else {
            cout << "Khong hop le" << endl;
        }
    }
    // Tra cứu bằng vị trí
    void TracuuVT(int VT) {
        if (VT >= 0 && VT < soluong) {
            Data[VT].XuatThongTin();
        } else {
            cout << "Khong tim thay" << endl;
        }
    }
    // Tra cứu bằng tên câu lạc bộ
    void TracuuTenClb(string TenClb){
        bool a = false;
        for(int i = 0; i < soluong; i++){
            if(Data[i].getTenClb() == TenClb){
                Data[i].XuatThongTin();
                a = true;
            }
        }
        if(!a){
            cout << "Khong tim thay ten doi bong trong du lieu " << endl;
        }
    }
    // Tra cứu thông tin
    void TracuuBXH(){
        for(int i = 0; i < soluong; i++){
            if(Data[i].getVT() == 1){
                cout << "Cau lac bo duoc tham du AFC Champions League la: ";
                cout << Data[i].getTenClb() << endl;
            }
            if(Data[i].getVT() == soluong - 1){
                cout << "Cau lac bo tham gia da playoff xuong hang la: ";
                cout << Data[i].getTenClb() << endl;
            }
            if(Data[i].getVT() == soluong){
                cout << "Cau lac bo xuong hang la: ";
                cout << Data[i].getTenClb() << endl;
            }
        }
    }
    // Thong ke bang xep hang
    void ThongKe() {
        int tongBT = 0, tongBB = 0, tongTV = 0, tongTD = 0;
        for (int i = 0; i < soluong; i++) {
            tongBT += Data[i].getBT();
            tongBB += Data[i].getBB();
            tongTV += Data[i].getTV();
            tongTD += Data[i].getTD();
        }
        cout << "Tong so ban thang: " << tongBT << endl;
        cout << "Tong so ban thua: " << tongBB << endl;
        cout << "Tong so the vang: " << tongTV << endl;
        cout << "Tong so the do: " << tongTD << endl;
    }
    // Đọc file 
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
            string a;
            getline(ss, a, ','); VT = stoi(a);
            getline(ss, TenClb, ',');
            getline(ss, a, ','); Tr = stoi(a);
            getline(ss, a, ','); T = stoi(a);
            getline(ss, a, ','); H = stoi(a);
            getline(ss, a, ','); B = stoi(a);
            getline(ss, a, ','); BT = stoi(a);
            getline(ss, a, ','); BB = stoi(a);
            HS = BT - BB;
            getline(ss, a, ',');
            getline(ss, a, ','); BTSK = stoi(a);
            getline(ss, a, ','); TV = stoi(a);
            getline(ss, a, ','); TD = stoi(a);
            Diem = T * 3 + H;
            ThongTin newData = ThongTin(VT, Tr, T, H, B, BT, BB, HS, BTSK, TV, TD, Diem, TenClb);
            Them(newData);
        }
        file.close();
    }
    // Hàm sắp xếp
    void SapXep() {
        for (int i = 0; i < soluong - 1; i++) {
            for (int j = 0; j < soluong - i - 1; j++) {
                if (Data[j].getDiem() < Data[j + 1].getDiem() || 
                   (Data[j].getDiem() == Data[j + 1].getDiem() && Data[j].getHS() < Data[j + 1].getHS()) ||
                   (Data[j].getDiem() == Data[j + 1].getDiem() && Data[j].getHS() == Data[j + 1].getHS() && Data[j].getBT() < Data[j + 1].getBT()) ||
                   (Data[j].getDiem() == Data[j + 1].getDiem() && Data[j].getHS() == Data[j + 1].getHS() && Data[j].getBT() == Data[j + 1].getBT() && Data[j].getBTSK() < Data[j + 1].getBTSK())) {
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
    // Ghi file
    void GhiFile(string filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Khong the mo file " << filename << endl;
            return;
        }
        file << "VT,TenClb,Tr,T,H,B,BT,BB,HS,BTSK,TV,TD,Diem\n";
        for (int i = 0; i < soluong; i++) {
            file << Data[i].Hamghifile() << endl;
        }    
        file.close();
    }
};
// Class người dùng
class User {
public:
    QuanLiDuLieu* QuanLy;
    User(QuanLiDuLieu* QuanLy) : QuanLy(QuanLy) {}
    // Hàm menu của người dùng
    void Menu() {
        cout << "BAN DANG XEM DU LIEU VOI TU CACH LA NGUOI DUNG" << endl;
        int n;
        do {
            cout << "+---------------------------------------------------+" << endl;
            cout << "|          CAC CHUC NANG CUA USER                   |" << endl;
            cout << "|---------------------------------------------------|" << endl;
            cout << "|             1. HIEN THI BANG XEP HANG             |" << endl;
            cout << "|             2. TIM KIEM DOI BONG                  |" << endl;
            cout << "|             3. THONG KE BANG XEP HANG             |" << endl;
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
                    cout << "1. Tim kiem bang vi tri" << endl;
                    cout << "2. Tim kiem bang ten doi bong" << endl;
                    cout << "3. Tra cuu xep hang : Xuong hang, da playoff xuong hang, duoc tham du afc champion ship" << endl;
                    cout << "0. Thoat chuc nang tim kiem" << endl;
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
                    case 3: {
                        cout << "BAN DA CHON CHUC NANG TRA CUU NHUNG DOI XUONG HANG, PLAYOFF XUONG HANG, DUOC DU AFC CHAMPIONS LEAGUE" << endl;
                        QuanLy->TracuuBXH();
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
            case 3: {
                cout << "BAN DA CHON CHUC NANG THONG KE" << endl;
                QuanLy->ThongKe();
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
// Class người quản trị viên
class Admin : public User {
public:
    Admin(QuanLiDuLieu* QuanLy) : User(QuanLy) {}
    bool DangNhap() {
        string tk, mk;
        while (true) {
            cout << "Nhap tai khoan (nhan 0 de thoat): ";
            getline(cin, tk);
            if (tk == "0") return false;
            cout << "Nhap mat khau: ";
            getline(cin, mk);
            // Tài khoản của admin là : admin và mật khẩu là admin123
            if (tk == "admin" && mk == "admin123") {
                return true;
            } else {
                cout << "Tai khoan hoac mat khau sai. Vui long thu lai." << endl;
            }
        }
    }
    // Hàm menu của quản trị viên
    void Menu() {
        if (!DangNhap()) {
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
            cout << "|             8. THONG KE BANG XEP HANG             |" << endl;
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
                while (Tr < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> Tr;
                }
                cout << "Nhap so tran thang: ";
                cin >> T;
                while (T < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> T;
                }
                cout << "Nhap so tran hoa: ";
                cin >> H;
                while (H < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> H;
                }
                cout << "Nhap so tran thua: ";
                cin >> B;
                while (B < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> B;
                }
                cout << "Nhap so ban thang: ";
                cin >> BT;
                while (BT < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> BT;
                }
                cout << "Nhap so ban thua: ";
                cin >> BB;
                while (BB < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> BB;
                }
                cout << "Nhap so ban thang san khach: ";
                cin >> BTSK;
                while (BTSK < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> BTSK;
                }
                cout << "Nhap so the vang: ";
                cin >> TV;
                while (TV < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> TV;
                }
                cout << "Nhap so the do: ";
                cin >> TD;
                while (TD < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> TD;
                }
                HS = BT - BB;
                Diem = T * 3 + H;
                ThongTin newData = ThongTin(VT, Tr, T, H, B, BT, BB, HS, BTSK, TV, TD, Diem, TenClb);
                QuanLy->Them(newData);
                cin.ignore();
                break;
            }
            case 2: {
                cout << "BAN DA CHON CHUC NANG XUAT DU LIEU " << endl;
                QuanLy->XuatBang();
                break;
            }
            case 3: {
                int m;
                do {
                    cout << "1. Tim kiem bang vi tri" << endl;
                    cout << "2. Tim kiem bang ten doi bong" << endl;
                    cout << "3. Tra cuu xep hang : Xuong hang, da playoff xuong hang, duoc tham du afc champion ship" << endl;
                    cout << "0. Thoat chuc nang tim kiem" << endl;
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
                    case 3: {
                        cout << "BAN DA CHON CHUC NANG TRA CUU NHUNG DOI XUONG HANG, PLAYOFF XUONG HANG, DUOC DU AFC CHAMPIONS LEAGUE" << endl;
                        QuanLy->TracuuBXH();
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
                while (Tr < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> Tr;
                }
                cout << "Nhap so tran thang: ";
                cin >> T;
                while (T < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> T;
                }
                cout << "Nhap so tran hoa: ";
                cin >> H;
                while (H < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> H;
                }
                cout << "Nhap so tran thua: ";
                cin >> B;
                while (B < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> B;
                }
                cout << "Nhap so ban thang: ";
                cin >> BT;
                while (BT < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> BT;
                }
                cout << "Nhap so ban thua: ";
                cin >> BB;
                while (BB < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> BB;
                }
                cout << "Nhap so ban thang san khach: ";
                cin >> BTSK;
                while (BTSK < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> BTSK;
                }
                cout << "Nhap so the vang: ";
                cin >> TV;
                while (TV < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> TV;
                }
                cout << "Nhap so the do: ";
                cin >> TD;
                while (TD < 0) {
                    cout << "Gia tri khong hop le, vui long nhap lai: ";
                    cin >> TD;
                }
                HS = BT - BB;
                Diem = T * 3 + H;
                ThongTin newData = ThongTin(VT, Tr, T, H, B, BT, BB, HS, BTSK, TV, TD, Diem, TenClb);
                QuanLy->Sua(VT - 1, newData);
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
            case 8: {
                cout << "BAN DA CHON CHUC NANG THONG KE" << endl;
                QuanLy->ThongKe();
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
    cout << "DU AN QUAN LY DU LIEU CRAWL TU WEBSITE - NHOM 23 - HOANG NGHIA HOA - PHAM THI HONG NHUNG" << endl;
    int a;
    cout << "+---------------------------------------------------+" << endl;
    cout << "|                DANG NHAP                          |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "|               1. ADMIN                            |" << endl;
    cout << "|               2. USER                             |" << endl;
    cout << "+---------------------------------------------------+" << endl;
    do{
    cout << "CHUC NANG BAN CHON: ";
    cin >> a;
    cin.ignore();
    switch(a){
        case 1: {
        Admin admin(&QuanLy);
        admin.Menu();
        break;
        }
    case 2: {
        User user(&QuanLy);
        user.Menu();
        break;
    }
    default: {
        cout << "BAN DA NHAP SAI LENH VUI LONG NHAP LAI" << endl;
    }
    }} while(true);
    return 0;
}
