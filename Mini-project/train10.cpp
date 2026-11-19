#include <iostream>
using namespace std;
int main() {
    int kelas;
    int siswa;
    int score;

    cout << "Jumlah kelas: ";
    cin >> kelas;

    cout << "Jumlah siswa: ";
    cin >> siswa;

    for(int i = 1; i <= kelas; i++){
        cout << "--- kelas " << i << " ---"<< endl ;
        for(int j = 1; j <= siswa; j++){
                cout << "Enter score Siswa - " << j << ": ";
                cin >> score;
                if(score >= 0 && score <= 100){
                        if(score >= 90){
                cout << "Score siswa: " << score << " -> Status: Cumlaude"<< endl;
                        } else if(score >= 75){
                            cout << "Score siswa: " << score << " -> Status: Lulus"<< endl;
                        } else if(score < 75){
                            cout << "Score siswa: " << score << " -> Status: Mengulang"<< endl;
                        }
                        } else {
                            cout << "Error: Nilai tidak di temukan!"<< endl;
                }
        }
    }



return 0;
}
