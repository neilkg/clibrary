#include "vector.h"
#include <iostream>
using std::cout;


int main() {
    vector<int> other;
    other.push_back(1);
    other.push_back(2);
    cout << other.front();
    cout << other.back();
    other.push_front(-1);
    cout << other.front();
    other.pop_back();
    other.pop_front();
    cout << other.front();
    cout << other.back();
}
