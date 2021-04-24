//
// Created by marti on 24/04/2021.
//

#include "BigIntegers.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;
string map {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLxxxxxxxxxx0123456789klmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV0123456789012345678"};


BigIntegers::BigIntegers() {ss = "";};

BigIntegers::BigIntegers(string &s) {
    ss = s;
};
BigIntegers BigIntegers::operator+(const BigIntegers& rhs) const{
    BigIntegers res;
    bool remainder = false;
    char n;
    int i = ss.size() - 1, j = rhs.ss.size() - 1;
    while(i >= 0 and j >= 0) {
        n = ss[i--] + rhs.ss[j--] + remainder;
        n > 105 ? remainder = true : remainder = false;
        res.ss.insert(res.ss.begin(), map[n]);
    }
    while(i >= 0) {
        res.ss.insert(res.ss.begin(), map[ss[i--]+remainder]);
        remainder = false;
    }
    while(j >= 0) {
        res.ss.insert(res.ss.begin(), map[rhs.ss[j--]+remainder]);
        remainder = false;
    }
    if(remainder) res.ss.insert(res.ss.begin(), '1');
    return res;
};
BigIntegers::~BigIntegers() {
    ss.erase(0, ss.size());
};
BigIntegers& BigIntegers::operator=(const BigIntegers& rhs) {
    ss = rhs.ss; //todo è banale
    return *this;
};
void BigIntegers::print() {
    cout<<ss;
    cout<<endl;
};