//
// Created by marti on 24/04/2021.
//

#include "BigIntegers.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

BigIntegers::BigIntegers() {ss = "";
    map_add = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLxxxxxxxxxx0123456789klmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV0123456789012345678";
    map_sub = "0123456789";
    sign = false;
};

BigIntegers::BigIntegers(string &s) {
    ss = s;
    map_add = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLxxxxxxxxxx0123456789klmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV0123456789012345678";
    map_sub = "0123456789";
    ss[0] == '-' ? sign = true : sign = false;
};
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
        return res;
    } else {
        //parte la sub
    }
};
BigIntegers BigIntegers::operator-(BigIntegers &rhs) {
    BigIntegers res;
    BigIntegers left, right;
    bool insert_final;

    bool remainder = false;
    int n;
    if(sign == rhs.sign) {
        if(sign) {
            //pensa
        }
        int i = ss.size() - 1, j = rhs.ss.size() - 1;
        while(i >= 0 and j >= 0) {
            n = ss[i] - rhs.ss[j] - remainder;
            n < 0 ? remainder = true : remainder = false;
            res.ss.insert(res.ss.begin(), map_sub[n + (10*(ss[i--] < rhs.ss[j--]))]);
        }
        while (i >= 0) {
            res.ss.insert(res.ss.begin(), map_add[ss[i--] - remainder]);
            remainder = false;
        }
        while (j >= 0) {
            res.ss.insert(res.ss.begin(), map_add[rhs.ss[j--] - remainder]);
            remainder = false;
        }
    }
    return res;
}
BigIntegers::~BigIntegers() {
    ss.erase(0, ss.size());
};
BigIntegers& BigIntegers::operator=(const BigIntegers& rhs) {
    ss = rhs.ss;
    return *this;
};
void BigIntegers::print() {
    cout<<ss;
    cout<<endl;
};