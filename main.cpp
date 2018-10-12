#include <bits/stdc++.h>
#include "QR_QNR_P.h"
#include "P_ROOTS_Zp.h"
#include "MillerRobbin.h"

using namespace std;

void q1(unsigned long p) {
    QR_QNR_P qr_qnr_set(p);

    cout << "QR set = ";

    for (auto i: qr_qnr_set.qr)
        cout << i << " ";

    cout << endl;

    cout << "QNR set = ";

    for (auto i: qr_qnr_set.qnr)
        cout << i << " ";

    cout << endl;
}

void q2(unsigned long p) {
    P_ROOTS_Zp p_roots_zp(p);
    p_roots_zp.print();
}

void q3(unsigned long prime){
    MillerRobbin millerRobbin;

    if(millerRobbin.test(prime)){
        cout << prime << " is probably prime." << endl;
    }
    else{
        cout << prime << " is not prime";
    }
}

int main() {
    unsigned long choice = 1;
    unsigned long prime;

    while (choice) {
        cout << endl;
        cout << "Your choices are : " << endl << endl;
        cout << "   1. Program to find QR and QNR for any Zp*. (Question 1)" << endl;
        cout << "   2. Program to find all primitive roots for the set Zp*. (Question 2)" << endl;
        cout << "   3. Program Miller Rabbin test. (Question 3)" << endl;

        cout << "   0. Exit" << endl << endl;

        cout << "Please enter your choice = ";

        cin >> choice;

        cout << endl;

        switch (choice) {
            case 1: {
                cout << "Please enter a prime : ";
                cin >> prime;
                q1(prime);
            }
                break;

            case 2: {
                cout << "Please enter a prime : ";
                cin >> prime;
                q2(prime);
            }
                break;

            case 3: {
                cout << "Please enter a prime : ";
                cin >> prime;
                q3(prime);
            }
                break;
            case 0: {
                cout << endl << endl;
                cout << "Bye Bye" << endl;
            }
                break;
            default: {
                cout << "You have made an invalid choice. Please try again." << endl;
            }
        }
    }

    return 0;
}