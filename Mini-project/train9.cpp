#include <iostream>
using namespace std;

int main() {
    int n ;
    int score;

    cout << "Jumlah Siswa: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
            cout << "Masukkan nilai siswa ke-" << i << ": ";
            cin >> score;
            if( score >= 0 && score <= 100){
        if(score >= 85){
            cout << "\nStatus: Lulus 'A'\n";
        } else if(score >= 75){
            cout << "\nStatus: Lulus 'B'\n";
        } else if(score < 70) {
            cout << "\nTidak Lulus.\n";
    }
        } else {
            cout << "\nError: Nilai Harus antara 0 - 100!\n";
        }
    }


return 0;
}
