#include <iostream>
using namespace std;
    
int hitungPanjangArray(char s[]) {
    int p = 0;
    while (s[p] != '\0') {
        p++;
    }
    return p;
}

char ubahKeKapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int ambilNilaiAlfabet(char c) {
    c = ubahKeKapital(c);
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A') + 1;
    }
    return 0;
}

char angkaToChar(int val) {
    return 'A' + (val - 1);
}

void enkripsiSandiAlien(char teks[], char hasil[]) {
    int panjangTeks = hitungPanjangArray(teks);

    for (int i = 0; i < panjangTeks; i++) {
        char karakterAsli = teks[i];
        int nilaiAsli = ambilNilaiAlfabet(karakterAsli);

        int geser = 0;
        if (i == 0) {
            geser = 0;
        } else {
            char hurufSebelumnya = teks[i - 1];
            geser = ambilNilaiAlfabet(hurufSebelumnya);
        }

        int nilaiBaru = nilaiAsli + geser;

        if (nilaiBaru > 26) {
            nilaiBaru = ((nilaiBaru - 1) % 26) + 1;
        }
        hasil[i] = angkaToChar(nilaiBaru);
    }

    hasil[panjangTeks] = '\0';
}

int main() {
    char pesan[1000];
    char pesanTerenkripsi[1000];

    
    cout << "**Program Sandi untuk Alien**" << endl;
    cout << "Masukkan pesan: ";
    cin >> pesan;

    enkripsiSandiAlien(pesan, pesanTerenkripsi);

    cout << "Pesan sandi: " << pesanTerenkripsi << endl;

    return 0;
}



