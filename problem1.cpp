#include <iostream>
using namespace std;

int hapusDanGeser(int daftar[], int sisa_astronot, int posisi_hapus) {
   for (int i = posisi_hapus; i < sisa_astronot - 1; i++) {
       daftar[i] = daftar[i + 1];
   }
   return sisa_astronot - 1;
}


int main() {
   int N, K;
   cout << "Masukkan jumlah astronot (N): ";
   cin >> N;
   cout << "Masukkan nilai K awal: ";
   cin >> K;
   int daftar[1000];
   int sisa_astronot = N;
   for (int i = 0; i < N; i++) {
       daftar[i] = i + 1;
   }

   int posisi = 0;

   while (sisa_astronot > 1) {
       if (K < 2) {
           K = 2;
       }
       posisi = (posisi + K - 1) % sisa_astronot;
    
       int astronot_gugur = daftar[posisi];
       cout << "Astronot nomor " << astronot_gugur << " tereliminasi!" << endl;

       sisa_astronot = hapusDanGeser(daftar, sisa_astronot, posisi);

       if (posisi == sisa_astronot) {
           posisi = 0;
       }

       if (astronot_gugur % 2 != 0) {
           K = K - 1;
       } 
       else {
           K = K + 2;
       }
   }
   cout << "Astronot yang selamat (Pemenang): Nomor " << daftar[0] << endl;


   return 0;
}


