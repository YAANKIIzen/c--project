#include <iostream>
using namespace std;
int main() {
    int paket;
    int produk;
    int total;

    cout << "Jumlah Paket : ";
    cin >> paket;

    cout << "Jumlah Produk: ";
    cin >> produk;

    for(int i = 1; i <= paket; i++){
            cout << "Paket " << i << " ================ \n" ;
        for(int j = 1; j <= produk ; j++){
            cout << "Produk " << j << ": Stok \n" ;
        }
    }
        total = paket * produk;
        cout << "\nTotal produk semua: " << total;
        cout << endl;



return 0;
}

