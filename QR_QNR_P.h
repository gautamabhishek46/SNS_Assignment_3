//
// Created by abhishek on 12/10/18.
//

#ifndef ASSIGNMENT3_QR_QNR_P_H
#define ASSIGNMENT3_QR_QNR_P_H

#include <bits/stdc++.h>
using namespace std;

class QR_QNR_P {
public:
    set<unsigned long> qr, qnr;

    // p will be given by user and it is assumed to be prime
    explicit QR_QNR_P(unsigned long p);

private:
    unsigned long p;
    void fit();
};

#endif //ASSIGNMENT3_QR_QNR_P_H
