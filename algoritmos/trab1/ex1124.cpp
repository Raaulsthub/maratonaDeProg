#include <iostream>
#include <math.h>
 
using namespace std;

bool fits (int L, int C, int R1, int R2) {
    if (L < 2*R1 || L < 2*R2 || C < 2*R1 || C < 2*R2) return false;
    // formula tirada de
    // https://math.stackexchange.com/questions/2079582/packing-two-different-circles-in-a-rectangle
    int aux = sqrt(pow(L - R1 - R2, 2) + pow(C - R1 - R2, 2));
    if (aux < (R1 + R2)) return false;
    return true;
}
 
int main() {
 
    int L, C, R1, R2;

    cin >> L >> C >> R1 >> R2;

    while (L || C || R1 || R2) {

        bool can_fit = fits(L, C, R1, R2);

        if (can_fit) cout << "S" << endl;
        else cout << "N" << endl;

        cin >> L >> C >> R1 >> R2;
    }

    return 0;
}