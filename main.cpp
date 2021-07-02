#include "BigIntegers.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s = "5";
    string s2 = "254";
    BigIntegers left(s);
    BigIntegers right(s2);
    BigIntegers result;
    left.print();
    right.print();
    result = left - right;
    cout<<"Il risultato e'"<<endl;
    result.print();
    return 0;
}