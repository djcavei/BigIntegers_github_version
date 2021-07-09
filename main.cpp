#include "BigIntegers.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s = "2";
    string s2 = "9999999";
//    swap(s,s2);
    BigIntegers left(s);
    BigIntegers right(s2);
    BigIntegers result;
    cout<<"result is"<<endl;
    result = left^64;
    result.print();
    result = result/left;
    result.print();
    /*result = left^64;
    result.print();
    result = result/right;
    result.print();*/
    return 0;
}