//
// Created by marti on 24/04/2021.
//

#ifndef BIGINTEGERS_GITHUB_VERSION_BIGINTEGERS_H
#define BIGINTEGERS_GITHUB_VERSION_BIGINTEGERS_H
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

class BigIntegers {
public:
    BigIntegers();
    BigIntegers(string& s);
    void print();
    BigIntegers operator+(const BigIntegers& rhs) const;
    BigIntegers& operator=(const BigIntegers& rhs);
    ~BigIntegers();
    string ss;
private:
    vector<unsigned long long> numb;
};
#endif //BIGINTEGERS_GITHUB_VERSION_BIGINTEGERS_H
