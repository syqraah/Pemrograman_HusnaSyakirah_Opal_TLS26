#include <iostream>
using namespace std;

int hapusDanGeser(int daftar[], int sisa_pemain, int posisi_hapus) {
    for (int i = posisi_hapus; i < sisa_pemain - 1; i++) {
        daftar[i] = daftar[i + 1];
    }
    return sisa_pemain - 1;
}

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;
    int daftar[1000]; 
    int sisa_pemain = N; 
    for (int i = 0; i < N; i++) {
        daftar[i] = i + 1;
    }

    int posisi = 0;

    while (sisa_pemain > 1) {
        if (K < 2) {
            K = 2; 
        }
        posisi = (posisi + K - 1) % sisa_pemain;
      
        int astronot_gugur = daftar[posisi];
        cout << "Astronot nomor " << astronot_gugur << " tereliminasi!" << endl;

        sisa_pemain = hapusDanGeser(daftar, sisa_pemain, posisi);

        if (posisi == sisa_pemain) {
            posisi = 0;
        }

        if (astronot_gugur % 2 != 0) {
            K = K - 1;
        } else {
            K = K + 2; 
        }
    }
    cout << "Astronot yang selamat (Pemenang): Nomor " << daftar[0] << endl;

    return 0;
}
