#include <iostream>
using namespace std;

int main() {
    int k;

    cout << "How many: ";
    cin >> k;

    for(int i = 1; i <= k; i++){
        if(i % 2 == 0){
            cout << i << " - EVEN" << endl;
        } else {
        cout << i << " - ODD" << endl;

        }
    }


return 0;
}
