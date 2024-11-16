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
        // file.ignore();

    }
    virtual void xuat()
    {
        cout << MAHANG << setw(15);
        cout << TENHANG << setw(20);
        cout << LOAI << setw(20);
    }
};
class THUCPHAM : public HANGHOA
{
protected:
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
        cout << setw(20) << SOKY << setw(10);
        cout << GIATIEN << setw(10) << "\n";
    }
}; class GIADUNG : public HANGHOA
{
protected:
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
        cout << setw(10) << SOLUONG << setw(20);
        cout << GIATIEN << setw(10) << "\n";
    }
};
//==================================================
class KHACHHANG
{
protected:

    string TENKHACHHANG;
    string SDT;
    float GIATIEN;
public:
    virtual void docfile(ifstream& file)
    {

        getline(file, TENKHACHHANG, ',');
        getline(file, SDT, ',');

    }
    virtual void xuat()
    {
        cout << TENKHACHHANG << setw(35);
        cout << SDT << setw(10);
    }
};
class THANHTOANTHE : public KHACHHANG
{
protected:
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

        //        file >> GIATIEN;
        //        file.ignore();
    }
    void xuat()
    {
        KHACHHANG::xuat();
        cout << setw(10) << MATHE << setw(20);
        cout << NGAY;
        // cout << GIATIEN << setw(10)<<"\n";
    }
};
class THANHTOANDIEM : public KHACHHANG
{
protected:
    float SODIEM;
public:
    void docfile(ifstream& file)
    {
        string tmp;
        KHACHHANG::docfile(file);
        file >> SODIEM;
        getline(file, tmp, ',');
        file.ignore();
        //        file >> GIATIEN;
        //        file.ignore();
    }
    void xuat()
    {
        KHACHHANG::xuat();
        cout << setw(10) << SODIEM << setw(15);
        //cout << GIATIEN << setw(10)<<"\n";
    }
};
//=====================================================
class SIEUTHI
{
private:
    vector<KHACHHANG*> p1;
    vector<HANGHOA*>p;
    int n = 5;
    int m = 5;
    int k = 3;
    int h = 2;
public:
    void docfilekhachhang()
    {
        p1.resize(m + n);
        ifstream file("khachhang.csv");
        if (file.is_open())
        {
            string line;
            getline(file, line);
            for (int i = 0; i < n; i++)
            {
                p1[i] = new THANHTOANDIEM;
                p1[i]->docfile(file);
            }
            for (int j = n; j < m + n; j++)
            {
                p1[j] = new THANHTOANTHE;
                p1[j]->docfile(file);
            }
            cout << "Da doc file!\n";
            file.close();
        }
        else cout << "Khong mo duoc file!\n";
    }
    ~SIEUTHI()
    {
        for (int i = 0; i < p1.size(); i++)
            delete p1[i];
        for (int j = 0; j < p.size(); j++)
            delete p[j];
    }
    void xuatkhachhang()
    {
        cout << "TEN KHACH HANG" << setw(15);
        cout << "SO DIEN THOAI" << setw(10);
        cout << "SO DIEM" << setw(15);
        cout << "MA THE" << setw(15);
        cout << "HAN SU DUNG" << "\n";
        //  cout << "GIA TIEN" << setw(10)<< "\n";
        for (int i = 0; i < n; i++)
            p1[i]->xuat();
        for (int i = n; i < n + m; i++)
            p1[i]->xuat();
    }

    void docfilehanghoa()
    {
        p.resize(k + h);
        ifstream file("hanghoa.csv");
        if (file.is_open())
        {
            string line;
            getline(file, line);
            for (int i = 0; i < k; i++)
            {
                p[i] = new GIADUNG;
                p[i]->docfile(file);
            }
            for (int j = k; j < k + h; j++)
            {
                p[j] = new THUCPHAM;
                p[j]->docfile(file);
            }
            cout << "Da doc file!\n";
            file.close();
        }
        else cout << "Khong mo duoc file!\n";
    }

    void xuathanghoa()
    {
        cout << "MA HANG" << setw(15);
        cout << "TEN HANG" << setw(15);
        cout << "LOAI" << setw(10);
        cout << "SO LUONG" << setw(10);
        cout << "SO KG" << setw(10);
        cout << "GIA TIEN" << setw(10) << "\n";
        for (int i = 0; i < k; i++)
            p[i]->xuat();
        for (int i = k; i < k + h; i++)
            p[i]->xuat();
    }
    void menu()
    {
        int choice;
        do {
            cout << "\t\t===================Menu==================\n";
            cout << "1.Doc danh sach hang hoa\n";
            cout << "2.Xuat danh sach hang hoa\n";
            cout << "\t\t===================End==================\n";
            cout << "Nhap lua chon: ";
            cin >> choice;
            switch (choice)
            {
            case 1: docfilehanghoa();
                docfilekhachhang(); break;
            case 2: xuathanghoa();
                xuatkhachhang(); break;
            }
        } while (choice != 0);

    }
};
int main()
{
    SIEUTHI sv;
    sv.menu();
    system("pause");
    return 0;
}
