#include "BigIntegers.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s = "-3821983129381724819487394872394823749";
    string s2 = "-43273472734723948237987589387293487293487239";
    BigIntegers left(s);
    BigIntegers right(s2);
    BigIntegers result;
    left.print();
    right.print();
    result = left + right;
    cout<<"Il risultato e'"<<endl;
    result.print();
    return 0;
}