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

string hoanvi(string chuoi)
{
    int ip[64] = {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7
    };
    string ketqua = "";

    for (int i = 0; i < 64; i++) {
        ketqua += chuoi[ip[i] - 1];
    }

    return ketqua;
}

int main()
{
    string banro, khoa;

    cout << "DES - Buoc 2: hoan vi IP va tach L0, R0\n";
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

    string sauip = hoanvi(banrobit);
    string l = "", r = "";
    for (int i = 0; i < 32; i++) {
        l += sauip[i];
        r += sauip[i + 32];
    }

    cout << "Sau IP = " << sauip << '\n';
    cout << "L0 = " << l << '\n';
    cout << "R0 = " << r << '\n';
    cout << "Chua thuc hien 16 vong DES.\n";
    return 0;
}
