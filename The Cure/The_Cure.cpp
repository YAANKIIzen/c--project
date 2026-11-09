#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

struct BarisLirik {
    string teks;
    int delayHurufMs;
    int jedaBarisMs;
};

void tampilkanBaris(const string& teks, int delayHurufMs) {
    for (char c : teks) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayHurufMs));
    }
    cout << endl;
}

int main() {
    vector<BarisLirik> lagu = {
    {"Why can't you come stitch me up?", 80, 450},
    {"Why can't it ever be enough?", 80, 450},
    {"Why can't you come stitch me up?", 80, 500},
    {"Why can't it ever be enough?", 70, 6000},
    {"It's not enough", 50, 5000},
    {"Oh because my head is full of poison", 80, 800},
    {"And my heart is full of doubt", 70, 900},
    {"I got toxins in my bloodstream", 70, 900},
    {"You tried so hard to suck out", 70, 900},
    {"And it feels like medication", 70, 900},
    {"And it's good for me i'm sure", 70, 900},
    {"But it don't matter how your love feels anymore", 80, 1000},
    {"It'll never be the cure", 120, 1000}
};
    cout << "================ The Cure ================" << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    for (const auto& baris : lagu) {
        tampilkanBaris(baris.teks, baris.delayHurufMs);
        this_thread::sleep_for(chrono::milliseconds(baris.jedaBarisMs));
    }
    return 0;
}
