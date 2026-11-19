#include <iostream>
using namespace std;

int main() {
    int n;
    int total = 0;

    cout << "Masukkan Pembatas Angka: ";
    cin >> n;

    for(int i = 0; i <= n; i++) {
        total += i;
    }

cout << total << endl;


return 0;
}
