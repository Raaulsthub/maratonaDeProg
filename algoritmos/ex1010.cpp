#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int code1, code2, units1, units2;
    float price1, price2, value;

    cin >> code1 >> units1 >> price1;
    cin >> code2 >> units2 >> price2;

    value = units1 * price1 + units2 * price2;

    cout << fixed;
    cout << setprecision(2) << "VALOR A PAGAR: R$ " << value << endl;
    return 0;
}