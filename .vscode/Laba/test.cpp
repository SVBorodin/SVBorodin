#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
    short A;
    int i;

    // Input and display number A
    cout << "Input A (short): ";
    cin >> A;
    cout << A << " = " << bitset<8>(A) << endl;

    // Input and validate bit position i
    cout << "Input bit position i (0-7): ";
    cin >> i;
    if (i < 0 || i > 7) {
        cout << "Error: bit position must be between 0 and 7!" << endl;
        return 1;
    }

    // Extract i-th bit value
    bool bitValue = (A >> i) & 1;
    cout << "Bit " << i << " = " << bitValue << endl;

    // Processing based on bit value
    if (bitValue) {
        // Three consecutive right shifts
        for (int shift = 1; shift <= 3; ++shift) {
            A = A >> 1;
            cout << "Shift " << shift << ": " << A << " = " << bitset<8>(A) << endl;
        }
    } else {
        int M;
        cout << "Input M: ";
        cin >> M;
        
        int diff = M - 5;
        if (diff > 0) {
            cout << "M is greater than 5 by " << diff << endl;
        } else if (diff < 0) {
            cout << "M is less than 5 by " << -diff << endl;
        } else {
            cout << "M equals 5" << endl;
        }
    }

    // Input and display day of week
    int N;
    cout << "\nInput day of week number (1-7): ";
    cin >> N;

    switch (N) {
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        case 4: cout << "Thursday" << endl; break;
        case 5: cout << "Friday" << endl; break;
        case 6: cout << "Saturday" << endl; break;
        case 7: cout << "Sunday" << endl; break;
        default: cout << "Error: day number must be between 1 and 7!" << endl;
    }

    return 0;
}