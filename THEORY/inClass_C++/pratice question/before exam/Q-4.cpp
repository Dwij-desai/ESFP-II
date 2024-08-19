#include <iostream>
#include <string>

using namespace std;

// Node structure for doubly linked list
struct Node {
    int productId;
    string productName;
    int productQty;
    double productPrice;
    double totalPrice;
    Node* prev;
    Node* next;

    Node(int id, string name, int qty, double price) : productId(id), productName(name), productQty(qty), productPrice(price), totalPrice(qty * price), prev(nullptr), next(nullptr) {}
};

class ComputerShop {
private:
    Node* head;
    Node* tail;

public:
    ComputerShop() : head(nullptr), tail(nullptr) {}

    void addProduct(int productId, string productName, int productQty, double productPrice) {
        Node* newNode = new Node(productId, productName, productQty, productPrice);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printSalesBillReport() {
        Node* current = head;
        cout << "Product ID\tProduct Name\tProduct Qty\tProduct Price\tTotal Price" << endl;
        while (current) {
            cout << current->productId << "\t\t" << current->productName << "\t\t" << current->productQty << "\t\t" << current->productPrice << "\t\t" << current->totalPrice << endl;
            current = current->next;
        }
    }

    void searchRecordById(int productId) {
        Node* current = head;
        cout << "Product ID\tProduct Name\tProduct Qty\tProduct Price\tTotal Price" << endl;
        while (current) {
            if (current->productId == productId) {
                cout << current->productId << "\t\t" << current->productName << "\t\t" << current->productQty << "\t\t" << current->productPrice << "\t\t" << current->totalPrice << endl;
                break;
            }
            current = current->next;
        }
        if (!current) {
            cout << "Product with ID " << productId << " not found." << endl;
        }
    }

    ~ComputerShop() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    ComputerShop shop;
    shop.addProduct(101, "Mobile", 3, 10000);
    shop.addProduct(102, "Laptop", 1, 25000);
    shop.addProduct(103, "Printer", 2, 3000);

    shop.printSalesBillReport();

    char searchRecord;
    cout << "Do you want to search record (Y/N)? ";
    cin >> searchRecord;

    if (toupper(searchRecord) == 'Y') {
        int searchOption;
        cout << "How do you want to search record by name or id: 1 for id, 2 for name: ";
        cin >> searchOption;

        if (searchOption == 1) {
            int productId;
            cout << "Enter product id: ";
            cin >> productId;
            shop.searchRecordById(productId);
        } else if (searchOption == 2) {
            // Add search by name logic here
            cout << "Search by name functionality not implemented." << endl;
        } else {
            cout << "Invalid search option." << endl;
        }
    }

    return 0;
}
