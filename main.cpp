#include "BigIntegers.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s = "10";
    string s2 = "2";
//    swap(s,s2);
    BigIntegers left(s);
    BigIntegers right(s2);
    BigIntegers result;
    left.print();
    right.print();
    result = left - right;
    cout<<"result is"<<endl;
    result.print();
    result = !left;
    result.print();
    result = left^3;
    return 0;
}