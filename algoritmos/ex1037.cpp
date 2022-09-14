#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    float a;

    cin >> a;

    if (a < 0.0000 || a > 100.0000)
    {
        cout << "Fora de intervalo" << endl;
    } else if (a >= 0.0000 && a <= 25.0000) {
        cout << "Intervalo [0,25]" << endl;
    } else if (a > 25.0000 && a <= 50.0000) {
        cout << "Intervalo (25,50]" << endl;
    } else if (a > 50.0000 && a <= 75.0000) {
        cout << "Intervalo (50,75]" << endl;
    } else {
        cout << "Intervalo (75,100]" << endl;
    }
 
    return 0;
}