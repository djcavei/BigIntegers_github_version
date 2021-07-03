//
// Created by marti on 24/04/2021.
//

#include "BigIntegers.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

string map_add = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLxxxxxxxxxx0123456789klmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV0123456789012345678";
string map_sub = "0123456789";

BigIntegers::BigIntegers() {
    ss = "";
    sign = false;
};

BigIntegers::BigIntegers(string &s) {
    ss = s;
    ss[0] == '-' ? sign = true : sign = false;
};

//todo operatore piu ++++++
BigIntegers BigIntegers::operator+(BigIntegers& rhs){
    BigIntegers res;
    bool remainder = false;
    int n;
    if(sign == rhs.sign) {
        if(sign) {
            ss.erase(ss.begin());
            rhs.ss.erase(rhs.ss.begin());
        }
        int i = ss.size() - 1, j = rhs.ss.size() - 1;
        while (i >= 0 and j >= 0) {
            n = ss[i--] + rhs.ss[j--] + remainder;
            n > 105 ? remainder = true : remainder = false;
            res.ss.insert(res.ss.begin(), map_add[n]);
        }
        while (i >= 0) {
            res.ss.insert(res.ss.begin(), map_add[ss[i--] + remainder]);
            remainder = false;
        }
        while (j >= 0) {
            res.ss.insert(res.ss.begin(), map_add[rhs.ss[j--] + remainder]);
            remainder = false;
        }
        if (remainder) res.ss.insert(res.ss.begin(), '1');
        if (sign) {
            res.ss.insert(res.ss.begin(), '-');
            ss.insert(ss.begin(), '-');
            rhs.ss.insert(rhs.ss.begin(), '-');
        }
    } else {
        //parte la sub
    }
    return res;
};

//todo operatore meno ----
BigIntegers BigIntegers::operator-(BigIntegers &rhs) {
    BigIntegers res;
    if(sign == rhs.sign){
        cout<<"operation is -"<<endl;
        BigIntegers big, small;
        bool remainder = false;
        int n;
        if (ss.size() != rhs.ss.size()) {
            if (ss.size() > rhs.ss.size()) {
                sign ? res.sign = true : 0;
                big = *this;
                small = rhs;
            } else {
                sign ? 0 : res.sign = true;
                big = rhs;
                small = *this;
            }
        } else {
            int i{};
            while (ss.at(i) == rhs.ss.at(i)) i++;
            if (ss.at(i) > rhs.ss.at(i)) {
                sign ? res.sign = true : 0;
                big = *this;
                small = rhs;
            } else if (rhs.ss.at(i) > ss.at(i)) {
                sign ? 0 : res.sign = true;
                big = rhs;
                small = *this;
            } else {
                res.ss.insert(res.ss.begin(), '0');
                return res;
            }
        }
        if (big.sign) {
            big.ss.erase(big.ss.begin());
            small.ss.erase(small.ss.begin());
        }
        int i = big.ss.size() - 1, j = small.ss.size() - 1;
        while (i >= 0 and j >= 0) {
            n = big.ss[i] - small.ss[j] - remainder;
            n < 0 ? remainder = true : remainder = false;
            res.ss.insert(res.ss.begin(), map_sub[n + (10 * (big.ss[i--] - remainder < small.ss[j--]))]);
        }
        while (i >= 0) {
            res.ss.insert(res.ss.begin(), map_sub[big.ss[i--] - '0' - remainder]);
            remainder = false;
        }
        i = 0;
        while (res.ss.at(i) == '0') res.ss.erase(res.ss.begin());
        if (res.sign) res.ss.insert(res.ss.begin(), '-');
    }
    else {
        BigIntegers left = *this, right = rhs;
        right.ss.insert(right.ss.begin(), '-');
        res = left + right;
    }
    return res;
}

BigIntegers::~BigIntegers() {
    ss.erase(0, ss.size());
}

void BigIntegers::print() {
    cout<<ss;
    cout<<endl;
}