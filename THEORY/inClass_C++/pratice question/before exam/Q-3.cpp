#include <iostream>

using namespace std;

class ParkingLot {
private:
    int R, C;
    int** parkingSpaces;

public:
    ParkingLot(int _R, int _C, int** _parkingSpaces) : R(_R), C(_C), parkingSpaces(_parkingSpaces) {}

    int findRowWithMostFullSpaces() {
        int maxCount = 0;
        int rowIndex = -1;

        for (int i = 0; i < R; i++) {
            int count = 0;
            for (int j = 0; j < C; j++) {
                if (parkingSpaces[i][j] == 1) {
                    count++;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                rowIndex = i;
            }
        }

        return rowIndex;
    }

    ~ParkingLot() {
        for (int i = 0; i < R; i++) {
            delete[] parkingSpaces[i];
        }
        delete[] parkingSpaces;
    }
};

int main() {
    int R, C;
    cout << "Enter the number of rows and columns in the parking lot: ";
    cin >> R >> C;

    int** parkingSpaces = new int*[R];
    for (int i = 0; i < R; i++) {
        parkingSpaces[i] = new int[C];
    }

    cout << "Enter the elements of the matrix (0/1) row-wise:" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> parkingSpaces[i][j];
        }
    }

    ParkingLot parkingLot(R, C, parkingSpaces);
    int rowIndex = parkingLot.findRowWithMostFullSpaces();

    if (rowIndex != -1) {
        cout << "Row " << rowIndex + 1 << " has the maximum number of 1's." << endl;
    } else {
        cout << "No rows have any 1's." << endl;
    }

    for (int i = 0; i < R; i++) {
        delete[] parkingSpaces[i];
    }
    delete[] parkingSpaces;

    return 0;
}
