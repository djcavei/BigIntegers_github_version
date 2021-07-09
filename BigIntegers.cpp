//
// Created by marti on 24/04/2021.
//

#include "BigIntegers.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <exception>


using namespace std;

string map_add = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLxxxxxxxxxx01234567890lmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV01234567890123456789";
string map_sub = "0123456789";

BigIntegers::BigIntegers() {
    ss = "";
    sign = false;
};

BigIntegers::BigIntegers(string &s) {
    ss = s;
    if(ss[0] == '-') {
        sign = true;
        ss.erase(ss.begin());
    } else sign = false;
    //while(ss.at(0) == '0') ss.erase(ss.begin()); problema per le moltiplicazioni
};

BigIntegers::BigIntegers(const BigIntegers& that) {
    ss = that.ss;
    sign = that.sign;
};

//todo operatore -- prefisso
BigIntegers& BigIntegers::operator--() {
    string one("1");
    BigIntegers eins(one);
    *this = *this - eins;
    return *this;
}
//todo postfisso
BigIntegers BigIntegers::operator--(int) {
    string one("1");
    BigIntegers eins(one), res(*this);
    *this = *this - eins;
    return res;
}

//todo operatore ++ prefisso
BigIntegers& BigIntegers::operator++() {
    string one("1");
    BigIntegers eins(one);
    *this = *this + eins;
    return *this;
}
//todo postfisso
BigIntegers BigIntegers::operator++(int) {
    string one("1");
    BigIntegers eins(one), res(*this);
    *this = *this + eins;
    return res;
}

BigIntegers BigIntegers::operator%(BigIntegers& rhs) const {
    BigIntegers div(*this), res;
    while(div.sign == sign) {
        sign == rhs.sign ? div = div - rhs : div = div + rhs;
        if(div.sign == sign) ++res;
    }
    div.sign = false;
    return div;
}


//todo operatore diviso ///////
BigIntegers BigIntegers::operator/(BigIntegers& rhs) const {
    BigIntegers div = *this, res;
    if(rhs.ss.at(0) != 0){
        while(div.sign == sign && div.ss[0] != '0') {
            sign == rhs.sign ? div = div - rhs : div = div + rhs;
            if(div.sign == sign) ++res;
        }
    } else {
        cout<<"Zero divider not defined";
        throw (uncaught_exception());
    }
    res.sign = (sign!=rhs.sign);
    return res;
}

//todo operatore per *****
BigIntegers BigIntegers::operator*(BigIntegers& rhs) const{
    BigIntegers res;
    int remainder{}, counter{};
    for(int i = rhs.ss.size()-1; i >= 0 && rhs.ss.at(i) != '-'; i--) {
        string aux{};
        if(rhs.ss == "33")
            cout<<endl;
        for(int j = ss.size()-1; j >= 0 && ss.at(j) != '-'; j--) {
            char x = ((ss.at(j) - '0')*(rhs.ss.at(i)-'0'))+remainder;
            remainder = (int)x/10;
            x = (x%10)+'0';
            aux.insert(aux.begin(), x);
        }
        if(remainder!=0) {
            aux.insert(aux.begin(), (char)remainder+'0');
            remainder = 0;
        }
        BigIntegers temp(aux);
        for(int k=0;k<counter;k++) temp.ss.push_back('0');
        ++counter;
        res = res+temp;
    }
    res.sign = (sign!=rhs.sign);
    return res;
}

//todo operatore piu ++++++
BigIntegers BigIntegers::operator+(BigIntegers& rhs)const{
    BigIntegers res;
    bool remainder = false;
    int n;
    if(sign == rhs.sign) {
        res.sign = sign;
        int i = ss.size() - 1, j = rhs.ss.size() - 1;
        while (i >= 0 and j >= 0) {
            n = ss[i--] + rhs.ss[j--] + remainder;
            n > 105 ? remainder = true : remainder = false;
            res.ss.insert(res.ss.begin(), map_add[n]);
        }
        while (i >= 0) {
            res.ss.insert(res.ss.begin(), map_add[ss[i] + remainder]);
            remainder = true * (ss[i--] + remainder == 58);
        }
        while (j >= 0) {
            res.ss.insert(res.ss.begin(), map_add[rhs.ss[j] + remainder]);
            remainder = true * (rhs.ss[j--] + remainder == 58);
        }
        if (remainder) res.ss.insert(res.ss.begin(), '1');
    } else {
        BigIntegers aux = rhs;
        aux.sign = sign;
        res = *this - aux;
    }
    return res;
};

BigIntegers BigIntegers::operator^(int n) const {
    BigIntegers res(*this), multi(*this);
    if(n) {
        while (n > 1) {
            res = res * multi;
            n--;
        }
    } else {
        res.ss = "1";
        res.sign = false;
    }
    return res;
}

//todo operatore meno ----
BigIntegers BigIntegers::operator-(BigIntegers &rhs) const{
    BigIntegers res, big(*this), small(rhs);
    if(sign == rhs.sign) {
        int i{}, j{}, max = 1;
        if(rhs.ss.size() > ss.size()) max = 2;
        else if(ss.size() == rhs.ss.size()) {
            max = 0;
            while(!max && i < ss.size()) {
                if(ss.at(i) > rhs.ss.at(i)) max = 1;
                else if(rhs.ss.at(i) > ss.at(i)) max = 2;
                ++i;
            }
            if(!max) {
                res.ss.insert(res.ss.begin(), '0');
                return res;
            }
        }
        if(max == 2) swap(big, small);
        res.sign = big.sign;
        if(max == 2) big.sign ? res.sign = false : res.sign = true;
        i = big.ss.size() - 1, j = small.ss.size() - 1;
        int n{};
        bool remainder = false;
        while (i >= 0 and j >= 0) {
            n = big.ss[i] - small.ss[j] - remainder;
            n < 0 ? remainder = true : remainder = false;
            res.ss.insert(res.ss.begin(), map_sub[n + (10 * (big.ss[i--] - remainder < small.ss[j--]))]);
        }
        while (i >= 0) {
            n = big.ss[i] - remainder -'0';
            n < 0 ? remainder = true : remainder = false;
            res.ss.insert(res.ss.begin(), map_sub[n + (10 * (big.ss[i--] - remainder -'0' < 0))]);
        }
        i = 0;
        while (res.ss.at(i) == '0') res.ss.erase(res.ss.begin());
    }
    else {
        big.sign ? small.sign = true : small.sign = false;
        res = big + small;
    }
    return res;
}

BigIntegers BigIntegers::operator!() {
    BigIntegers two(*this), res(*this);
    --two;
    while(two.ss.at(0) != '0') {
        res = res * two;
        --two;
    }
    return res;
}

void BigIntegers::print() {
    if(sign) cout<<'-';
    cout<<ss;
    cout<<endl;
}