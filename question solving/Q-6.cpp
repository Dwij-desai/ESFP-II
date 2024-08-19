#include <iostream>
#include <string>
using namespace std;

struct Product {
    int pid;
    string pname;
    int pqty;
    int pprice;
};

int main() {
    const int MAX_PRODUCTS = 100;
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (true) {                              //Read fuction
        int pid, pqty, pprice;
        string pname;

        cout << "Enter product info as daily basis (pid, pname, pqty, pprice): ";
        cin >> pid >> pname >> pqty >> pprice;

        products[numProducts] = {pid, pname, pqty, pprice};
        numProducts++;

        char cont;
        cout << "Do you want to continue (Y/N)? ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y') {
            break;
        }
    }

    cout << "pid\t" << "pname\t" << "pqty\t" << "pprice\t" << "Total_Price" << endl;    // display fuction
    for (int i = 0; i < numProducts; i++) {
        int total_price = products[i].pqty * products[i].pprice;
        cout << products[i].pid << "\t" << products[i].pname << "\t"
             << products[i].pqty << "\t" << products[i].pprice << "\t" << total_price << endl;
    }

    //To show perticular product

    char showRecord;
    cout << "Do you want to see sales record (Y/N)? ";
    cin >> showRecord;
    if (showRecord == 'Y' || showRecord == 'y') {
        int choice;
        cout << "How to find daily sales record by id or name (Press <1> for id and press <2> for name): ";
        cin >> choice;

        if (choice == 1) {
            int id;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "pid\t" << "pname\t" << "pqty\t" << "pprice\t" << "Total_Price" << endl;
            for (int i = 0; i < numProducts; i++) {
                if (products[i].pid == id) {
                    int total_price = products[i].pqty * products[i].pprice;
                    cout << products[i].pid << "\t" << products[i].pname << "\t"
                         << products[i].pqty << "\t" << products[i].pprice << "\t" << total_price << endl;
                }
            }
        } else if (choice == 2) {
            string name;
            cout << "Enter product name: ";
            cin >> name;
            cout << "pid\t" << "pname\t" << "pqty\t" << "pprice\t" << "Total_Price" << endl;
            for (int i = 0; i < numProducts; i++) {
                if (products[i].pname == name) {
                    int total_price = products[i].pqty * products[i].pprice;
                    cout << products[i].pid << "\t" << products[i].pname << "\t"
                         << products[i].pqty << "\t" << products[i].pprice << "\t" << total_price << endl;
                }
            }
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
