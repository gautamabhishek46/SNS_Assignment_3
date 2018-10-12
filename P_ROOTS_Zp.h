//
// Created by abhishek on 12/10/18.
//

#ifndef ASSIGNMENT3_P_ROOTS_ZP_H
#define ASSIGNMENT3_P_ROOTS_ZP_H

#include <bits/stdc++.h>
using namespace std;


class P_ROOTS_Zp {
public:
    explicit P_ROOTS_Zp(unsigned long p);
    map<unsigned long, vector<unsigned long>> roots_map;
    void print();

private:
    unsigned long p;
    void fit();
    vector<unsigned long> calculate_primitive_roots_of(unsigned long n);
    unsigned long mod_power(unsigned long n, unsigned long p, unsigned long mod);
};


#endif //ASSIGNMENT3_P_ROOTS_ZP_H
