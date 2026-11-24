#include <iostream>
#include <string>
using namespace std;

string hextobin(string chuoi)
{
    if (chuoi.length() != 16) {
        return "";
    }

    string banghex = "0123456789ABCDEF";
    string ketqua = "";

    for (int i = 0; i < 16; i++) {
        char kytu = chuoi[i];
        if (kytu >= 'a' && kytu <= 'f') {
            kytu = kytu - 'a' + 'A';
        }

        int giatri = -1;
        for (int j = 0; j < 16; j++) {
            if (kytu == banghex[j]) {
                giatri = j;
                break;
            }
        }

        if (giatri == -1) {
            return "";
        }

        for (int j = 3; j >= 0; j--) {
            ketqua += char('0' + ((giatri >> j) & 1));
        }
    }

    return ketqua;
}

int main()
{
    string banro, khoa;

    cout << "DES - Buoc 1: nhap va doi hex sang nhi phan\n";
    cout << "Moi gia tri gom 16 ky tu hex (0-9, A-F).\n";
    cout << "Ban ro = ";
    cin >> banro;
    string banrobit = hextobin(banro);
    if (banrobit == "") {
        cout << "Ban ro khong hop le.\n";
        return 1;
    }

    cout << "Khoa = ";
    cin >> khoa;
    string khoabit = hextobin(khoa);
    if (khoabit == "") {
        cout << "Khoa khong hop le.\n";
        return 1;
    }

    cout << "Ban ro (64 bit) = " << banrobit << '\n';
    cout << "Khoa   (64 bit) = " << khoabit << '\n';
    cout << "Chua thuc hien ma hoa DES.\n";
    return 0;
}
