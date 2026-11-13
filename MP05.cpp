#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Function prototypes
void printAscendingRow(int k);
void printDescendingRow(int k);
void countdown(int n);
void printGridRow(int row, int col, int n);
int getValidSize();
int getValidChoice();

// Ascending row using recursion
void printAscendingRow(int k) {
    if (k == 0) {
        return;
    }

    printAscendingRow(k - 1);
    cout << k << " ";
}

// Descending row using recursion
void printDescendingRow(int k) {
    if (k == 0) {
        return;
    }

    cout << k << " ";
    printDescendingRow(k - 1);
}

// Recursive countdown
void countdown(int n) {
    if (n == 0) {
        cout << "GO!" << endl;
        return;
    }

    cout << n << " ";
    countdown(n - 1);
}

// Recursive multiplication grid row
void printGridRow(int row, int col, int n) {
    if (col > n) {
        cout << endl;
        return;
    }

    cout << setw(4) << row * col;
    printGridRow(row, col + 1, n);
}

// Validate size from 1 to 9
int getValidSize() {
    int n;

    while (true) {
        cout << "Enter size (1-9): ";

        if (cin >> n) {
            if (n >= 1 && n <= 9) {
                return n;
            }

            cout << "Invalid size! Please enter 1 to 9.\n";
        }
        else {
            cout << "Invalid input! Numbers only.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Validate menu choice
int getValidChoice() {
    int choice;

    while (true) {
        cout << "\nEnter your choice: ";

        if (cin >> choice) {
            if (choice >= 0 && choice <= 4) {
                return choice;
            }

            cout << "Invalid choice! Select 0 to 4.\n";
        }
        else {
            cout << "Invalid input! Numbers only.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    int choice;
    int n;

    do {
        cout << "\n================================\n";
        cout << "   RECURSIVE NUMBER PATTERN\n";
        cout << "================================\n";
        cout << "1 - Ascending Triangle\n";
        cout << "2 - Descending Triangle\n";
        cout << "3 - Recursive Countdown\n";
        cout << "4 - Multiplication Grid\n";
        cout << "0 - Exit\n";
        cout << "================================\n";

        choice = getValidChoice();

        switch (choice) {

            case 1:
                n = getValidSize();

                cout << "\nAscending Triangle:\n";

                for (int row = 1; row <= n; row++) {
                    printAscendingRow(row);
                    cout << endl;
                }
                break;

            case 2:
                n = getValidSize();

                cout << "\nDescending Triangle:\n";

                for (int row = n; row >= 1; row--) {
                    printDescendingRow(row);
                    cout << endl;
                }
                break;

            case 3:
                n = getValidSize();

                cout << "\nRecursive Countdown:\n";
                countdown(n);
                break;

            case 4:
                n = getValidSize();

                cout << "\nMultiplication Grid:\n";

                for (int row = 1; row <= n; row++) {
                    printGridRow(row, 1, n);
                }
                break;

            case 0:
                cout << "\nThank you for using the program!\n";
                break;
        }

    } while (choice != 0);

    return 0;
}

