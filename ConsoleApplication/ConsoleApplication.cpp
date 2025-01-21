#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


int multidimensionalArrays() {
    string input = "2 2\n3 1 5 4\n5 1 2 8 9 3\n0 1\n1 3";
    istringstream cin(input);

    int arrays;
    int queries;

    cin >> arrays >> queries;
    vector<vector<int>> arrayOfArrays;

    for (int i = 0; i < arrays; i++) {
        int arraySize;
        cin >> arraySize;
        vector<int> innerArray;

        for (int j = 0; j < arraySize; j++) {
            int innerValue;
            cin >> innerValue;
            innerArray.push_back(innerValue);
        }
        arrayOfArrays.push_back(innerArray);
    }

    for (int i = 0; i < queries; i++) {
        int targetArray;
        int targetIndex;
        cin >> targetArray >> targetIndex;

        int result = arrayOfArrays[targetArray][targetIndex];
        cout << result << endl;
    }

    return 0;
}

class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
        return first_name_;
    }
    const string& get_last_name() const {
        return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};

ostream& operator<<(ostream& os, const Person& person) {
    os << "first_name=" << person.get_first_name() << ",last_name=" << person.get_last_name();
    return os;
}

int main() {
    string input = "hello world";
    istringstream cin(input);
    
    string first_name, last_name;
    cin >> first_name >> last_name;
    auto p = Person(first_name, last_name);
    cout << p.get_first_name() << endl;
    cout << p << endl;
    return 0;
}
