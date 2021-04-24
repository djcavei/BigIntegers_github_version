//
// Created by marti on 24/04/2021.
//

#include "BigIntegers.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

BigIntegers::BigIntegers() {ss = "";};

BigIntegers::BigIntegers(string &s) {
    ss = s;
    istringstream buffer{s};
    unsigned long long n;
    char c;
    while(!buffer.eof()) {
        string cell;
        for(int j = 0; j < 19 && !buffer.eof(); j++) {
            buffer>>c;
            cell.push_back(c);
            if(buffer.eof()) cell.pop_back();
        }
        istringstream go{cell};
        go>>n;
        numb.push_back(n);
    }
};
BigIntegers BigIntegers::operator+(const BigIntegers& rhs) const{
    BigIntegers res;
    unsigned long long temp{};
    bool resto = false;

    for(int i = numb.size()-1; i >= 0;i++) {
        for(int j = rhs.numb.size()-1; j >= 0; j++) {

        }
    }
};
BigIntegers::~BigIntegers() {
    for(int i=0; i < numb.size();i++) numb.pop_back();
};
BigIntegers& BigIntegers::operator=(const BigIntegers& rhs) {
    delete this;
    for(unsigned long long i : rhs.numb) numb.push_back(i);
    return *this;
};
void BigIntegers::print() {
    for(unsigned long long elem : numb) cout<<elem;
    cout<<endl;
};