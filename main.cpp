#include "BigIntegers.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s = "1231236471274617246712647123878237482734829348273948293487293487296127";
    string s2 = "83283912831972381792387129381729381273918273918";
    BigIntegers left(s);
    BigIntegers right(s2);
    BigIntegers result;
    result = left + right;
    left.print();
    right.print();
    return 0;
}