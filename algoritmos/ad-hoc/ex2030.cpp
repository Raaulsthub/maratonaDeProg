// pitstop

#include <iostream>
 
using namespace std;
 
int main() {
 
    int N;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long t1, t2, A, V, R, pit_stops;
        long long min_t = -1;
        cin >> t1 >> t2 >> A >> V >> R;

        // i = numero de voltas dadas com pneu ruim
        for (int i = R; i >= 0; i++) {
            if (min_t == - 1) {
                min_t = (R - i) * t1 + ((R - i) / V) * A + i * t2;
                pit_stops = (R - i) / V;
            }
            if (((R - i) * t1 + ((R - i) / V) * A + i * t2) < min_t) {
                min_t = ((R - i) * t1 + ((R - i) / V) * A + i * t2);
                pit_stops = (R - i) / V;
            }
        }

        cout << "Teste #" << i << endl;
        cout << min_t << " " << pit_stops << endl;
    }

 
    return 0;
}