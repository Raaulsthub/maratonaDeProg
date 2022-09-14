#include <iostream>
#include<bits/stdc++.h>

using namespace std;
 
int main() {
    
    int quant, dec;
    double value;

    cin >> value;

    quant = value;
    dec = (int)(value * 100) % 100;

    cout << "NOTAS:" << endl;

    cout << quant / 100 << " nota(s) de R$ 100.00" << endl;
    quant %= 100;

    cout << quant / 50 << " nota(s) de R$ 50.00" << endl;
    quant %= 50;

    cout << quant / 20 << " nota(s) de R$ 20.00" << endl;
    quant %= 20;

    cout << quant / 10 << " nota(s) de R$ 10.00" << endl;
    quant %= 10;

    cout << quant / 5 << " nota(s) de R$ 5.00" << endl;
    quant %= 5;

    cout << quant / 2 << " nota(s) de R$ 2.00" << endl;
    quant %= 2;

    cout << "MOEDAS:"<< endl;

    cout << quant << " moeda(s) de R$ 1.00" << endl;

    cout << dec / 50 << " moeda(s) de R$ 0.50" << endl;
    dec %= 50;

    cout << dec / 25 << " moeda(s) de R$ 0.25" << endl;
    dec %= 25;

    cout << dec / 10 << " moeda(s) de R$ 0.10" << endl;
    dec %= 10;

    cout << dec / 5 << " moeda(s) de R$ 0.5" << endl;
    dec %= 5;

    cout << dec << " moeda(s) de R$ 0.01" << endl;
    return 0;

}