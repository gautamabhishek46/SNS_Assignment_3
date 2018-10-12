//
// Created by abhishek on 12/10/18.
//

#include "MillerRobbin.h"
#include "math.h"
#include <random>
#include <iostream>
using namespace std;

bool MillerRobbin::test(unsigned long n) {
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    // Find m, k such that n - 1 = 2^k * m for some m >= 1
    unsigned long m = n - 1;
    unsigned long k = 0;

    while (m % 2 == 0) {
        m /= 2;
        k++;
    }

//    unsigned long k = (n - 1) / m;
    cout << "m = " << m << "; k = " << k << endl;
    return millerTest(n, m, k);

    // Iterate given nber of 'k' times
//    for (unsigned long i = 0; i < k; i++) {
//        if (!millerTest(n, m, k))
//            return false;
//    }
//
//    return true;
}

bool MillerRobbin::millerTest(unsigned long n, unsigned long m, unsigned long k) {
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(2, static_cast<int>(n - 2));

    int rando = uniform_dist(e1);
    cout << "random = " << rando << endl;

    unsigned long a = static_cast<unsigned long>(rando);

    // Compute a^m % n
    unsigned long T = mod_power(a, m, n);

    if (T == 1  || T == n-1)
        return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    for (unsigned long i = 0; i < k; i++)
    {
        T = (T * T) % n;
//        m *= 2;

        if (T == 1)
            return false;
        if (T == n-1)
            return true;
    }

    // Return composite
    return false;
}


unsigned long MillerRobbin::mod_power(unsigned long n, unsigned long p, unsigned long mod) {
    unsigned long result = 1;

    while (p){
        if(p % 2 == 0){
            n = (n * n) % mod;
            p = p / 2;
        }
        else{
            result *= n;
            result %= mod;
            p--;
        }
    }

    return result % mod;
}