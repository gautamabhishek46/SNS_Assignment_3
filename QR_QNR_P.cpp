//
// Created by abhishek on 12/10/18.
//

#include "QR_QNR_P.h"

void QR_QNR_P::fit() {
    for(unsigned long i = 1; i < this->p; i++){
        (this->qr).insert((i * i) % p);
    }

    for(unsigned long i = 1; i < this->p; i++){
        if(this->qr.find(i) == this->qr.end())
            (this->qnr).insert(i);
    }
}

QR_QNR_P::QR_QNR_P(unsigned long p) {
    // Assuming that p is prime
    this->p  = p;
    this->fit();
}
