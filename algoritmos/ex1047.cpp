#include <iostream>
 
using namespace std;
 
int main() {

    int ih, im, fh, fm, initT, finT, tot;
    cin >> ih >> im >> fh >> fm;

    initT = ih * 60 + im;
    finT = fh * 60 + fm;

    if (initT >= finT)
    {
        tot = 24 * 60 - initT + finT;
    } else {
        tot = finT - initT;
    }

    cout << "O JOGO DUROU " << tot/60 << " HORA(S) E " << tot%60 << " MINUTO(S)" << endl;

    return 0;
}