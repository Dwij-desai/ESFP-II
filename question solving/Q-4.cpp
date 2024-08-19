#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Names {
public:
    string name;
};

int main() {
    Names names[5];

    cout << "Enter five names: ";
    for (int i = 0; i < 5; ++i) {
        cin >> names[i].name;
    }

    sort(names, names + 5, [](const Names& a, const Names& b) {
        return a.name < b.name;
    });
    cout << "Names in ascending order: ";
    for (int i = 0; i < 5; ++i) {
        cout << names[i].name << " ";
    }
    cout << endl;

    sort(names, names + 5, [](const Names& a, const Names& b) {
        return a.name > b.name;
    });
    cout << "Names in descending order: ";
    for (int i = 0; i < 5; ++i) {
        cout << names[i].name << " ";
    }
    cout << endl;

    return 0;
}
