#include <iostream>
#include <string>
using namespace std;

int hexso(char c)
{
    if (c >= 'a' && c <= 'f') {
        c = c - 'a' + 'A';
    }
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1;
}

bool dochex(string chuoi, int a[][4])
{
    if (chuoi.length() != 32) {
        return false;
    }

    for (int i = 0; i < 16; i++) {
        int cao = hexso(chuoi[2 * i]);
        int thap = hexso(chuoi[2 * i + 1]);
        if (cao == -1 || thap == -1) {
            return false;
        }
        a[i % 4][i / 4] = cao * 16 + thap;
    }
    return true;
}

void inmatran(int a[][4])
{
    string hex = "0123456789ABCDEF";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex[a[i][j] / 16] << hex[a[i][j] % 16];
            if (j < 3) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}

void addroundkey(int a[][4], int k[][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = a[i][j] ^ k[i][j];
        }
    }
}

int main()
{
    string banro, khoa;
    int a[4][4], k[4][4];

    cout << "AES-128 - Buoc 6: ma tran va AddRoundKey ban dau\n";
    cout << "Moi gia tri gom 32 ky tu hex, dien vao ma tran theo cot.\n";
    cout << "Ban ro = ";
    cin >> banro;
    if (dochex(banro, a) == false) {
        cout << "Ban ro khong hop le.\n";
        return 1;
    }

    cout << "Khoa = ";
    cin >> khoa;
    if (dochex(khoa, k) == false) {
        cout << "Khoa khong hop le.\n";
        return 1;
    }

    cout << "State ban dau:\n";
    inmatran(a);
    cout << "Khoa ban dau:\n";
    inmatran(k);

    addroundkey(a, k);
    cout << "Sau AddRoundKey 0:\n";
    inmatran(a);
    cout << "Chua thuc hien 10 vong AES.\n";
    return 0;
}
