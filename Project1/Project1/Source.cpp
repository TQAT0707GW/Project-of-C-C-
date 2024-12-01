#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
class HANGHOA
{
protected:
    int MAHANG;
    string TENHANG, LOAI;
    float GIATIEN;
public:
    virtual void docfile(ifstream& file)
    {
        file >> MAHANG;
        file.ignore();
        getline(file, TENHANG, ',');
        getline(file, LOAI, ',');
    }
    virtual void xuat()
    {
        cout << MAHANG << "\t" << setw(12);
        cout << TENHANG << setw(13);
        cout << LOAI << setw(20);
    }
    virtual void set_thongtin1sp(int MAHANG, string TENHANG, string LOAI, float GIATIEN)
    {
        this->MAHANG = MAHANG;
        this->TENHANG = TENHANG;
        this->LOAI = LOAI;
        this->GIATIEN = GIATIEN;
    }
    virtual void nhap() = 0;
    virtual int get_MAHANG() { return MAHANG; }
    virtual void set_LOAI(string LOAI)
    {
        this->LOAI = LOAI;
    }
    virtual string getloai()
    {
        return LOAI;
    }
    virtual void setsoluong(int x) = 0;
    virtual float get_soluong() = 0;
    virtual string get_tenhang()
    {
        return TENHANG;
    }
    virtual float get_giatien() {
        return GIATIEN;
    }
    virtual void set_MAHANG(int MAHANG)
    {
        this->MAHANG = MAHANG;
    }
    virtual void set_TENHANG(string TENHANG)
    {
        this->TENHANG = TENHANG;
   }
    virtual void set_GIATIEN(float GIATIEN)
    {
        this->GIATIEN = GIATIEN;
    }
    virtual float tinhtien() = 0;
  
};
class THUCPHAM : public HANGHOA
{
private:
    float SOKY;
public:
    void docfile(ifstream& file)
    {
        string tmp;
        HANGHOA::docfile(file);
        getline(file, tmp, ',');
        file >> SOKY;
        file.ignore();
        file >> GIATIEN;
        file.ignore();
    }
    void xuat()
    {
        HANGHOA::xuat();
        cout << setw(23) << SOKY << setw(10);
        cout << GIATIEN << "\n";
    }
    void nhap()
    {
        cout << "Nhap Ma hang Hoa: ";  cin >> MAHANG;
        cout << "Nhap Ten Hang: "; cin.ignore(); getline(cin, TENHANG);
        cout << "Nhap SO Ky: "; cin >> SOKY;
        cout << "Nhap Gia Tien: "; cin >> GIATIEN;
    }
    void setsoluong(int SOKY)
    {
        this->SOKY = SOKY;
    }
    float get_soluong()
    {
        return SOKY;
    }
    float tinhtien()
    {
        return SOKY * GIATIEN;
    }
}; 
class GIADUNG : public HANGHOA
{
private:
    float SOLUONG;
public:
    void docfile(ifstream& file)
    {
        string tmp;
        HANGHOA::docfile(file);
        file >> SOLUONG;
        getline(file, tmp, ',');
        file.ignore();
        file >> GIATIEN;
        file.ignore();
    }
    void xuat()
    {
        HANGHOA::xuat();
        cout << setw(10) << SOLUONG << setw(23);
        cout << GIATIEN << "\n";
    }
    void nhap()
    {
        cout << "Nhap Ma hang Hoa: ";  cin >> MAHANG;
        cout << "Nhap Ten Hang: "; cin.ignore(); getline(cin, TENHANG);
        cout << "Nhap SO Luong: "; cin >> SOLUONG;
        cout << "Nhap Gia Tien: "; cin >> GIATIEN;
    }
    void setsoluong(int SOLUONG)
    {
        this->SOLUONG=SOLUONG;
    }
    float get_soluong()
    {
        return SOLUONG;
    }
    float tinhtien()
    {
        return SOLUONG * GIATIEN;
    }
};
//==================================================
class KHACHHANG
{
protected:
    string TENKHACHHANG;
    string SDT;
    string loaiKH;
public:
    virtual void docfile(ifstream& file)
    {
        getline(file, TENKHACHHANG, ',');
        getline(file, SDT, ',');
    }
    virtual void xuat()
    {
        cout << TENKHACHHANG << "\t"<<setw(17);
        cout << SDT << setw(10);
    }
    virtual void set_loai(string loaiKH)
    {
        this->loaiKH = loaiKH;
    }
    virtual void nhapthongtin1KH()
    {
        cout <<"\nNhap ho ten khach hang: "; cin.ignore();
        getline(cin, TENKHACHHANG);
        cout << "\nNhap so dien thoai(7 so): ";
        cin >> SDT;
    }
    virtual string get_sdt()
    {
        return SDT;
    }
    virtual string get_loaiKH()
    {
        return loaiKH;
    }
    virtual float get_sodiem() { return 0; }
    virtual void set_sodiem(float SODIEM) { }
    virtual void set_ten(string TENKHACHHANG)
    {
        this->TENKHACHHANG = TENKHACHHANG;
    }
    virtual void set_sdt(string SDT)
    {
        this->SDT = SDT;
    }
    virtual string get_mathe() { return 0; }
};
class THANHTOANTHE : public KHACHHANG
{
private:
    string MATHE;
    string NGAY;
public:
    void docfile(ifstream& file)
    {
        string tmp;
        KHACHHANG::docfile(file);
        getline(file, tmp, ',');
        getline(file, MATHE, ',');
        file >> NGAY;
    }
    void xuat()
    {
        KHACHHANG::xuat();
        cout <<"\t\t" << setw(1) << MATHE << setw(15);
        cout << NGAY<<"\n";
    }
    void nhapthongtin1KH()
    {
        KHACHHANG::nhapthongtin1KH();
        cout << "\nNhap ma the(vi du L123): "; cin >> MATHE;
        cout << "\nNhap han su dung(vi du 11/11/2003): "; cin >> NGAY;
    }
    string get_mathe()
    {
        return MATHE;
    }
    
};
class THANHTOANDIEM : public KHACHHANG
{
private:
    float SODIEM;
public:
    void docfile(ifstream& file)
    {
        string tmp;
        KHACHHANG::docfile(file);
        file >> SODIEM;
        getline(file, tmp, ',');
        file.ignore();
    }
    void xuat()
    {
        KHACHHANG::xuat();
        cout << setw(13) << SODIEM << setw(15)<<"\n";
    }
    void nhapthongtin1KH()
    {
        KHACHHANG::nhapthongtin1KH();
        cout << "\nNhap so diem: ";
        cin >> SODIEM;
    }
    float get_sodiem()
    {
        return SODIEM;
    }
    void set_sodiem(float SODIEM)
    {
        this->SODIEM = SODIEM;
    }
};
//=====================================================
class SIEUTHI
{
private:
    vector<KHACHHANG*> kh;
    vector<HANGHOA*>hh;
    vector<HANGHOA*>giohang;
    vector<HANGHOA*>ls;
    int n = 5;
    int m = 5;
    int k = 4;
    int h = 6;
    float tongtien = 0;
public:
    void docfilekhachhang()
    {
        kh.resize(m + n);
        ifstream file("khachhang.csv");
        if (file.is_open())
        {
            string line;
            getline(file, line);
            for (int i = 0; i < n; i++)
            {
                kh[i] = new THANHTOANDIEM;
                kh[i]->docfile(file);
                kh[i]->set_loai("DIEM");
            }
            for (int j = n; j < m + n; j++)
            {
                kh[j] = new THANHTOANTHE;
                kh[j]->docfile(file);
                kh[j]->set_loai("THE");
            }
            cout << "Da doc file!\n";
            file.close();
        }
        else cout << "Khong mo duoc file!\n";
    }
    ~SIEUTHI()
    {
        for (int i = 0; i < kh.size(); i++)
            delete kh[i];
        for (int j = 0; j < hh.size(); j++)
            delete hh[j];
    }
    //print khachhang
    void xuatkhachhang()
    {
        cout << "TEN KHACH HANG" << setw(15);
        cout << "SO DIEN THOAI" << setw(10);
        cout << "SO DIEM" << setw(15);
        cout << "MA THE" << setw(15);
        cout << "HAN SU DUNG" << "\n";
        for (int i = 0; i < kh.size(); i++)
            kh[i]->xuat();
    }
    //read data from excel file of hanghoa
    void docfilehanghoa()
    {
        hh.resize(k + h);
        ifstream file("hanghoa.csv");
        if (file.is_open())
        {
            string line;
            getline(file, line);
            for (int i = 0; i < k; i++)
            {
                hh[i] = new GIADUNG;
                hh[i]->docfile(file);
            }
            for (int j = k; j < k + h; j++)
            {
                hh[j] = new THUCPHAM;
                hh[j]->docfile(file);
            }
            cout << "Da doc file!\n";
            file.close();
        }
        else cout << "Khong mo duoc file!\n";
    }
    void xuathanghoa()
    {
        cout << "MA HANG" << setw(15);
        cout << "TEN HANG" << setw(10);
        cout << "LOAI" << setw(15);
        cout << "SO LUONG" << setw(10);
        cout << "SO KG" << setw(10);
        cout << "DON GIA" << setw(10) << "\n";
        for (int i = 0; i < hh.size(); i++) {
            if (hh[i]->get_soluong() != 0)
            {
                hh[i]->xuat();
            }
        }
    }
    void Them_1hanghoa()
    {
        string tmp;
        while (tmp != "THUCPHAM" && tmp != "GIADUNG")
        {
            cout << "Nhap loai hang hoa: (THUCPHAM/GIADUNG)";
            cin >> tmp;
        }
        if (tmp == "THUCPHAM")
        {
            HANGHOA* tmp1 = new THUCPHAM;
            tmp1->set_LOAI(tmp);
            tmp1->nhap();
            hh.insert(hh.end(), tmp1);
        }
        else if (tmp == "GIADUNG")
        {
            HANGHOA* tmp2 = new GIADUNG;
            tmp2->set_LOAI(tmp);
            tmp2->nhap();
            hh.insert(hh.begin(), tmp2);
        }
    }
    void Chinhsua_1hanghoa()
    {
        int tmp;
        cout << "Nhap Ma Hang Can Chinh Sua: "; cin >> tmp;
        for (int i = 0; i < hh.size(); i++)
        {
            if (tmp == hh[i]->get_MAHANG())
            {
                hh[i]->nhap();
                return;
            }
        }
        cout << "Khong tim Thay Ma Hang!\n";
    }
    void xoa_1hanghoa()
    {
        int tmp;
        cout << "Nhap Ma Hang Can Xoa: "; cin >> tmp;
        for (int i = 0; i < hh.size(); i++)
        {
            if (tmp == hh[i]->get_MAHANG())
            {
                hh.erase(hh.begin() + i);
                cout << "Da xoa san pham!\n";
                return;
            }
        }
        cout << "Khong tim Thay Ma Hang!\n";
    }
    void themthanhvien()
    {
        KHACHHANG* x = NULL;
        string loai;
        do {
            cout << "\nNhap loai Khach hang:(DIEM-THE): ";
            cin >> loai;
        } while (loai != "DIEM" && loai != "THE");
        if (loai == "DIEM")
        {
            x = new THANHTOANDIEM;
            x->set_loai(loai);
            x->nhapthongtin1KH();
            kh.insert(kh.begin(), x);
        }
        else
        {
            x = new THANHTOANTHE;
            x->set_loai(loai);
            x->nhapthongtin1KH();
            kh.insert(kh.end(), x);
        }
    }
    void xoathanhvien()
    {
        string sodt;
        cout << "\nNhap so dien thoai(7 so): ";
        cin >> sodt;
        for (int i = 0; i < kh.size(); i++)
        {
            if (kh[i]->get_sdt() == sodt)
            {
                kh.erase(kh.begin()+i);
                cout << "\nDa xoa khach hang khoi he thong!\n";
                return;
            }
        }
        cout << "\nNhap sai so dien thoai!\n";
    }
    void chinhsuathongtin()
    {
        string sodt;
        cout << "\nNhap so dien thoai(7 so): ";
        cin >> sodt;
        for (int i = 0; i < kh.size(); i++)
        {
            if (kh[i]->get_sdt() == sodt)
            {
                kh[i]->nhapthongtin1KH();
                return;
            }
        }
        cout << "\nNhap sai so dien thoai!\n";
    }
    void GIOHANG()
    {
        xuathanghoa();
        while (true)
        {
            int msp; int sl;
            cout << "\nNhap 0 de thoat\n";
            cout << "Nhap ma sp(3 so): "; cin >> msp;
            if (msp != 0)
            {
                for (int i = 0; i < hh.size(); i++)
                {
                    if (hh[i]->get_MAHANG() == msp)
                    {
                        if (hh[i]->getloai() == "THUCPHAM")//if mechandise is thucpham 
                        {
                            cout << "\nNhap so ky: "; cin >> sl;//enter a weight
                            if (hh[i]->get_soluong() < sl)// if more than quantity in warehouse
                            {
                                cout << "\nKhong du so luong\n";
                                break;
                            }
                            else
                            {
                                HANGHOA* x = new THUCPHAM;
                                x->set_thongtin1sp(msp, hh[i]->get_tenhang(), "THUCPHAM", hh[i]->get_giatien());//add a merchandise to basket
                                x->setsoluong(sl);
                                giohang.push_back(x);
                                hh[i]->setsoluong(hh[i]->get_soluong() - sl);//set again quantity after buying
                            }
                        }
                        else
                        {
                            cout << "\nNhap so luong: "; cin >> sl;
                            if (hh[i]->get_soluong() < sl)
                            {
                                cout << "\nKhong du so luong\n";
                                break;
                            }
                            else
                            {
                                HANGHOA* x = new GIADUNG;
                                x->set_thongtin1sp(msp, hh[i]->get_tenhang(), "GIADUNG", hh[i]->get_giatien());
                                x->setsoluong(sl);
                                giohang.push_back(x);
                                hh[i]->setsoluong(hh[i]->get_soluong() - sl);
                            }
                        }
                    }
                }
            }
            else break;}}
    /// <summary>
    /// modify a basket after chose 
    /// </summary>
    void CHINHSUAGIOHANG()
    {
        xuatGIOHANG();
        while (true)
        {
            int msp;
            cout << "\nNhap 0 de thoat\n";
            cout << "Nhap ma sp(3 so): "; cin >> msp;
            //In this section, we only can delete a one mechandise from basket
            if (msp != 0)
            {
                for (int i = 0; i < giohang.size(); i++)
                {
                    if (giohang[i]->get_MAHANG() == msp)
                    {
                        for (int j = 0; j < hh.size(); j++)
                        {
                            if (giohang[i]->get_MAHANG() == hh[j]->get_MAHANG())
                            {
                                hh[j]->setsoluong(hh[j]->get_soluong() + giohang[i]->get_soluong());
                                break;
                            }
                        }
                        giohang.erase(giohang.begin() + i); 
                    }
                }
            }
            else
                break;
        }
    }
    //function to print basket
    void xuatGIOHANG()
    {
        cout << "MA HANG" << setw(15);
        cout << "TEN HANG" << setw(10);
        cout << "LOAI" << setw(15);
        cout << "SO LUONG" << setw(10);
        cout << "SO KG" << setw(10);
        cout << "GIA TIEN" << setw(10) << "\n";
        for (int i = 0; i < giohang.size(); i++)
            giohang[i]->xuat();
    }
    //paying
    void tinhtien()
    {
        xuatGIOHANG();
        float sum = 0;
        for (int i = 0; i < giohang.size(); i++)
        {
            sum += giohang[i]->tinhtien();//sum 
        }
        cout << "\nTong tien la: " << sum << endl;
        string sdt; char c;
        //enter a number. If not exist, a new customer. We add a phone number of new customer to excel file "KhachHang"
        do {
            cout << "\nNhap so dien thoai: "; cin >> sdt; //confirm a number
            cout << "\nXac nhan so dien thoai la dung(y/n): "; cin >> c;
        } while (c != 'y');
        for (int i = 0; i < kh.size(); i++)
        {
            if (kh[i]->get_sdt() == sdt)
            {
                if (kh[i]->get_loaiKH() == "DIEM")
                {
                    cout << "\nHien tai ban dang co so diem la: " << kh[i]->get_sodiem() << "\n";//print the exist point
                    cout << "Ban co muon su dung diem khong(y/n): "; cin >> c;//Do you want to use a point
                    if (c == 'y')
                    {
                        if (sum > kh[i]->get_sodiem())
                        {
                            sum = sum - kh[i]->get_sodiem();//subtract a point and set a point
                            kh[i]->set_sodiem(0);
                            tongtien = sum;
                            cout << "\nSo diem moi cua ban la: " << kh[i]->get_sodiem() << "\n";
                            return;
                        }
                        else //if not use point, customers will paying a cash
                        {
                            kh[i]->set_sodiem(kh[i]->get_sodiem()-sum);
                            sum = 0;
                            tongtien = sum;
                            cout << "\nSo diem moi cua ban la: " << kh[i]->get_sodiem() << "\n";
                            return;
                        }
                    }
                    else
                    {
                        kh[i]->set_sodiem(kh[i]->get_sodiem()+sum * 5 / 100);
                        tongtien = sum;
                        cout << "\nSo diem moi cua ban la: " << kh[i]->get_sodiem() << "\n";
                        return;
                    }
                }
                else//customer is using a credit card discounted a 15% 
                {
                    cout << "\nBan dang co the voi ma the la: " << kh[i]->get_mathe() << "\n";
                    cout<<"Ban co mang theo the khong(y/n): "; cin >> c;
                    if (c == 'y')
                    {
                        sum = sum - sum * 15 / 100;
                        tongtien = sum;
                        return;
                    }
                    else
                    {
                        tongtien = sum;
                        return;
                    }
                }
            }
        }
        cout << "\nKhong tim thay khach hang!Vui long dang ky diem!\n";//if not a exist customer
        KHACHHANG* x = NULL;
        x = new THANHTOANDIEM;//automically paying a point
        x->set_sodiem(sum * 5 / 100);
        x->set_loai("DIEM");
        string ten;
        cout << "\nNhap ho ten: "; cin.ignore(); getline(cin, ten);//set information of customer
        cout << "\nSo diem moi cua ban la: " << x->get_sodiem();
        x->set_sdt(sdt);
        x->set_ten(ten);
        kh.push_back(x);
        tongtien = sum;
    }
    //print a bill
    void inhoadon()
    {
        if (!giohang.empty())
        {
            tinhtien();
            for (int i = 0; i < giohang.size(); i++)//read data from a basket and store in ls
            {
                if (giohang[i]->getloai() == "THUCPHAM")
                {
                    HANGHOA* x = new THUCPHAM;
                    x->set_thongtin1sp(giohang[i]->get_MAHANG(), giohang[i]->get_tenhang(), giohang[i]->getloai(), giohang[i]->get_giatien());
                    x->setsoluong(giohang[i]->get_soluong());
                    ls.push_back(x);
                }
                else
                {
                    HANGHOA* x = new GIADUNG;
                    x->set_thongtin1sp(giohang[i]->get_MAHANG(), giohang[i]->get_tenhang(), giohang[i]->getloai(), giohang[i]->get_giatien());
                    x->setsoluong(giohang[i]->get_soluong());
                    ls.push_back(x);
                }
                
            }
            cout << "\n-----------CUA HANG VTT----------\n";
            cout << "D\C:227 Nguyen Van Cu, Quan 5, TPHCM\n";
            cout << "Hotline:1234567\n";
            cout << "\t\tHOA DON BAN HANG\n";
            if (giohang.empty() == false)
            {
                for (int i = 0; i < giohang.size(); i++)
                {
                    giohang[i]->xuat();
                }
            }
            cout << "\t\t\t\t\tTong tien: " << tongtien << endl;
            cout << "Cam on QUY KHACH!HEN GAP LAI!\n";
            tongtien = 0;
            xoadonhang();
        }
        else
            cout << "\nGio hang trong!\n";
    }
    //print a history of bill
    void lichsuhoadon()
    {
        if (!ls.empty()) {
            for (int i = 0; i < ls.size(); i++)
                ls[i]->xuat();
        }
        else
            cout << "\nLich su hang trong!\n";
    }
    void tinhtongtientrongngay()//sum of the day
    {
        float sum = 0;
        for (int i = 0; i < ls.size(); i++)
            sum+=ls[i]->tinhtien();
        lichsuhoadon();
        cout << "\nTong tien :" << sum << endl;
    }
    void xoalichsuhoadontrongngay()//delete a history after print data into excel file
    {
        int t = ls.size();
        for (int i = 0; i < t; i++)
        {
            delete ls[i];
        }
        ls.clear();
        cout << "\nDa xoa lich su!\n";
    }
    void xuatfile()
    {
        ofstream file;
        file.open("Lichsudonhang.csv");
        file << "MA HANG" << ',' << "TEN HANG" <<','<< "LOAI" << ',' << "SOLUONG" << ',' << "SOKY" << ',' << "DONGIA" << "\n";
        for (int i = 0; i < ls.size(); i++)
        {
            file << ls[i]->get_MAHANG() << ',' << ls[i]->get_tenhang() << ',' << ls[i]->getloai();
            if (ls[i]->getloai() == "THUCPHAM")
            {
                file << ',' <<','<< ls[i]->get_soluong() << ',' << ls[i]->get_giatien()<<"\n";
            }
            else
            {
                file << ',' << ls[i]->get_soluong() << ','<<',' << ls[i]->get_giatien()<<"\n";
            }
        }
        file.close();
    }
    void xoadonhang()
    {
        int t = giohang.size();
        for (int i = 0; i < t; i++)
        {
            delete giohang[i];
        }
        giohang.clear();
    }
    void menu1()
    {
        int luachon;
        do {
            system("cls");
            cout << "\t\t===================KHACH HANG==================\n";
            cout << "0.Thoat khoi menu KHACH HANG\n";
            cout << "1.Doc danh sach khach hang\n";
            cout << "2.Xuat danh sach khach hang\n";
            cout << "3.Them thong tin khach hang\n";
            cout << "4.Xoa thanh vien\n";
            cout << "5.Chinh sua thong tin khach hang\n";
            cout << "\t\t===================End==================\n";
            cout << "Nhap lua chon: ";
            cin >> luachon;
            switch (luachon)
            {
            case 1:
                docfilekhachhang(); break;
            case 2:
                xuatkhachhang(); break;
            case 3:
                themthanhvien(); break;
            case 4:
                xoathanhvien(); break;
            case 5:
                chinhsuathongtin(); break;
            case 0: menu(); break;
            }
            system("pause");
        } while (luachon != 0);
    }
    void menu2()
    {
        int choice;
        do {
            system("cls");
            cout << "\t\t===================Quan Ly hang Hoa==================\n";
            cout << "0.Thoat khoi menu HANG HOA\n";
            cout << "1.Doc file Hang Hoa\n";
            cout << "2.Xuat Danh Sach Hang Ton Trong Kho\n";
            cout << "3.Them Thong Tin 1 Hang Hoa\n";
            cout << "4.Chinh Sua Thong Tin 1 Hang Hoa\n";
            cout << "5. Xoa 1 Hang Hoa Trong Kho\n";
            cout << "\t\t===================End==================\n";
            cout << "Nhap lua chon: ";
            cin >> choice;
            switch (choice)
            {
            case 1: docfilehanghoa(); break;
            case 2: xuathanghoa(); break;
            case 3: Them_1hanghoa(); break;
            case 4: Chinhsua_1hanghoa(); break;
            case 5: xoa_1hanghoa(); break;
            case 0: menu(); break;
            }
            system("pause");
        } while (choice != 0);
    }
    void menu3()
    {
        int choice;
        do {
            system("cls");
            cout << "\t\t===================Menu==================\n";
            cout << "0.Thoat khoi menu\n";
            cout << "1.Them san pham vao gio hang\n";
            cout << "2.Xuat gio hang\n";
            cout << "3.Xoa san pham trong gio hang\n";
            cout << "4.In hoa don\n";
            cout << "\t\t===================End==================\n";
            cout << "Nhap lua chon: ";
            cin >> choice;
            switch (choice)
            {
            case 1: GIOHANG(); break;
            case 2: xuatGIOHANG(); break;
            case 3: CHINHSUAGIOHANG(); break;
            case 4: inhoadon(); break;
            case 0: menu(); break;
            }
            system("pause");
        } while (choice != 0 );
    }
    void menu4()
    {
        int choice;
        do {
            system("cls");
            cout << "\t\t===================Menu==================\n";
            cout << "0.Thoat khoi menu\n";
            cout << "1.Xem lich su don hang cua sieu thi\n";
            cout << "2.Tinh tong tien cua sieu thi trong ngay\n";
            cout << "3.Xoa lich su don hang\n";
            cout << "4.In lich su don hang ra file\n";
            cout << "\t\t===================End==================\n";
            cout << "Nhap lua chon: ";
            cin >> choice;
            switch (choice)
            {
            case 1: lichsuhoadon(); break;
            case 2: tinhtongtientrongngay(); break;
            case 3: xoalichsuhoadontrongngay(); break;
            case 4:xuatfile(); break;
            case 0: menu(); break;
            }
            system("pause");
        } while (choice != 0);
    }
    void menu()
    {
        int choice;
        do {
            system("cls");
            cout << "\t\t===================Menu==================\n";
            cout << "1.Quan ly Khach Hang\n";
            cout << "2.Quan ly Hang Hoa\n";
            cout << "3.Quan Ly gio hang\n";
            cout << "4.Quan Ly lich su don hang\n";
            cout << "\t\t===================End==================\n";
            cout << "Nhap lua chon: ";
            cin >> choice;
            switch (choice)
            {
            case 1: menu1(); break;
            case 2: menu2(); break;
            case 3: menu3(); break;
            case 4: menu4(); break;
            }
            system("pause");
        } while (choice != 0);

    }
};
int main()
{
    SIEUTHI sv;
    sv.menu();
}
