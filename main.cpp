#include "BigIntegers.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s = "28373";
    string s2 = "25453";
    BigIntegers left(s);
    BigIntegers right(s2);
    BigIntegers result;
    left.print();
    right.print();
    result = left * right;
    cout<<"result is"<<endl;
    result.print();
    return 0;
}