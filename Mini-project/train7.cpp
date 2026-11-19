#include <iostream>
using namespace std;
int main(){

    for(int i = 1; i <= 5; i++){
        cout << endl;
        for(int k = 1; k <= 5 ; k++){
                if(i == 1 || i == 5 || k == 1 || k == 5  ){
                        cout << "*";
       } else { cout << " "  ;}
    }
    }

return 0;
}
