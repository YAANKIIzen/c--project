#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
#include <map>
#include <chrono>
#include <iomanip>

using namespace std;

// ===================== Fungsi Utility =====================

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayWelcome() {
    cout << "==================================================\n";
    cout << "   Welcome to the Number Guessing Game!\n";
    cout << "==================================================\n";
    cout << "I'm thinking of a number between 1 and 100.\n";
    cout << "You need to guess it within a limited number of chances.\n\n";
}

// Mengembalikan pasangan (chances, namaDifficulty)
pair<int, string> selectDifficulty() {
    cout << "Please select the difficulty level:\n";
    cout << "1. Easy (10 chances)\n";
    cout << "2. Medium (5 chances)\n";
    cout << "3. Hard (3 chances)\n";

    while (true) {
        cout << "Enter your choice: ";
        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number (1, 2, or 3).\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Great! You have selected the Easy difficulty level.\n";
                return {10, "Easy"};
            case 2:
                cout << "Great! You have selected the Medium difficulty level.\n";
                return {5, "Medium"};
            case 3:
                cout << "Great! You have selected the Hard difficulty level.\n";
                return {3, "Hard"};
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }
}

// Hint berdasarkan selisih
string getHint(int secret, int guess) {
    int diff = abs(secret - guess);
    if (diff <= 5)       return "You're very close! (within 5)";
    else if (diff <= 15) return "You're getting warm. (within 15)";
    else                 return "You're far off. (more than 15 away)";
}

// ===================== Satu Ronde Permainan =====================

bool playRound(map<string, int>& highScores) {
    int secretNumber = rand() % 100 + 1;   // 1..100
    auto [chances, difficulty] = selectDifficulty();

    cout << "You have " << chances << " chances to guess the correct number.\n";
    cout << "Let's start the game!\n";

    int attempts = 0;
    auto startTime = chrono::steady_clock::now();

    while (attempts < chances) {
        cout << "Enter your guess: ";
        int guess;
        if (!(cin >> guess)) {
            cout << "Invalid input. Please enter a number between 1 and 100.\n";
            clearInput();
            continue;
        }

        if (guess < 1 || guess > 100) {
            cout << "Please enter a number between 1 and 100.\n";
            continue;
        }

        attempts++;

        if (guess == secretNumber) {
            auto endTime = chrono::steady_clock::now();
            double elapsed = chrono::duration<double>(endTime - startTime).count();

            cout << "Congratulations! You guessed the correct number in "
                 << attempts << " attempts.\n";
            cout << fixed << setprecision(2);
            cout << "Time taken: " << elapsed << " seconds.\n";

            // Update high score
            if (highScores.find(difficulty) == highScores.end() ||
                attempts < highScores[difficulty]) {
                highScores[difficulty] = attempts;
                cout << "New high score for " << difficulty
                     << " difficulty: " << attempts << " attempts!\n";
            } else {
                cout << "Current high score for " << difficulty
                     << " difficulty: " << highScores[difficulty] << " attempts.\n";
            }
            return true;
        } else {
            if (guess > secretNumber)
                cout << "Incorrect! The number is less than your guess.\n";
            else
                cout << "Incorrect! The number is greater than your guess.\n";

            int remaining = chances - attempts;
            if (remaining <= 2 && remaining > 0) {
                cout << "Hint: " << getHint(secretNumber, guess) << "\n";
            }
            if (remaining > 0) {
                cout << "You have " << remaining << " chances left.\n";
            }
        }
    }

    cout << "Game over! You've run out of chances. "
         << "The correct number was " << secretNumber << ".\n";
    return false;
}

// ===================== Main Program =====================

int main() {
    srand(static_cast<unsigned int>(time(0)));

    displayWelcome();

    map<string, int> highScores;   // difficulty -> best attempts

    while (true) {
        playRound(highScores);

        // Tanya apakah ingin bermain lagi
        while (true) {
            cout << "\nDo you want to play again? (yes/no): ";
            string answer;
            cin >> answer;

            // Ubah ke lowercase
            for (auto& c : answer) c = tolower(c);

            if (answer == "yes" || answer == "y") {
                cout << "\n==================================================\n";
                break;
            } else if (answer == "no" || answer == "n") {
                cout << "\nThank you for playing! Here are your high scores:\n";
                if (highScores.empty()) {
                    cout << "  No high scores recorded.\n";
                } else {
                    for (const auto& [diff, score] : highScores) {
                        cout << "  " << diff << ": " << score << " attempts\n";
                    }
                }
                cout << "Goodbye!\n";
                return 0;
            } else {
                cout << "Please enter 'yes' or 'no'.\n";
            }
        }
    }

    return 0;
}
