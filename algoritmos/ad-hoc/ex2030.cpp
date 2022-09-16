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
        /*for (int i = R; i >= 0; i--) {
            long long temp = (R - i) * t1 + ((R - i) / V) * A + (i) * t2; 
            if (min_t == - 1) {
                min_t = temp;
                pit_stops = (R - i) / V;
            }
            if (temp < min_t) {
                min_t = temp;
                pit_stops = (R - i) / V;
            }
        }*/

        R -= V;

        for (int i = 0; i <= R / V; i++) {
            long long temp = i * A + (i * V) * t1 + ((R - (i * V)) * t2);
            if (min_t == -1) {
                min_t = temp;
                pit_stops = i;
            } else if (min_t > temp) {
                min_t = temp;
                pit_stops = i;
            }
        }

        min_t += V * t1;

        cout << "Teste #" << i + 1 << endl;
        cout << min_t << " " << pit_stops << endl;
        cout << endl;
    }

 
    return 0;
}