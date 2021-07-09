#include "BigIntegers.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s = "2";
    string s2 = "1";
//    swap(s,s2);
    string s3 = "1000";
    BigIntegers left(s);
    BigIntegers right(s2);
    BigIntegers result;
    BigIntegers three(s3);
    left.print();
    cout<<"result is"<<endl;
    result = (left^64) - right;
    result = result/three;
    result.print();
    return 0;
}