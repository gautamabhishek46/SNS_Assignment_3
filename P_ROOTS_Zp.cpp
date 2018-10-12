//
// Created by abhishek on 12/10/18.
//

#include "P_ROOTS_Zp.h"

P_ROOTS_Zp::P_ROOTS_Zp(unsigned long p) {
    this->p = p;
    this->fit();
}

void P_ROOTS_Zp::fit() {
    for(unsigned long i = 1; i <= p; i++){
        this->roots_map[i] = calculate_primitive_roots_of(i);

        cout << "Done for " << i << endl;
    }

//    roots_map[p] = calculate_primitive_roots_of(p);
}

vector<unsigned long> P_ROOTS_Zp::calculate_primitive_roots_of(unsigned long n) {
    vector<unsigned long> roots;
    unordered_set<unsigned long> mods;

    if(n < 3)
        return roots;

    for(unsigned long r = 1; r < n; r++){
        mods.clear();

        for(unsigned long x = 0; x < n - 1; x++){
            mods.insert(mod_power(r, x, n));
        }

        if(mods.size() == n - 1){
            roots.push_back(r);
        }
    }

    return roots;
}

unsigned long P_ROOTS_Zp::mod_power(unsigned long n, unsigned long p, unsigned long mod) {
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

void P_ROOTS_Zp::print() {
    cout << endl;
    for(const pair<const unsigned long, vector<unsigned long>> & x: this->roots_map){
        cout << x.first  << " has " << x.second.size() << " primitive roots : " << " are : ";

        if(x.first > 2) {
            if (!x.second.empty()) {

                for (const unsigned long &i: x.second) {
                    cout << i << ',';
                }

                cout << endl;
            } else {
                cout << "Does not exist." << endl;
            }
        }
        else{
            cout << "Roots are undefined." << endl;
        }
    }
}
