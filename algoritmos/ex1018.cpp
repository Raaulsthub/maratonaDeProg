#include <iostream>
 
using namespace std;
 
int main() {
    
    int quant;

    cin >> quant;

    cout << quant << endl;

    cout << quant / 100 << " nota(s) de R$ 100,00" << endl;
    quant %= 100;

    cout << quant / 50 << " nota(s) de R$ 50,00" << endl;
    quant %= 50;

    cout << quant / 20 << " nota(s) de R$ 20,00" << endl;
    quant %= 20;

    cout << quant / 10 << " nota(s) de R$ 10,00" << endl;
    quant %= 10;

    cout << quant / 5 << " nota(s) de R$ 5,00" << endl;
    quant %= 5;

    cout << quant / 2 << " nota(s) de R$ 2,00" << endl;
    quant %= 2;

    cout << quant << " nota(s) de R$ 1,00" << endl;
 
    return 0;
}