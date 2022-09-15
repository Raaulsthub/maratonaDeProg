#include <iostream>
 
using namespace std;
 
int main() {
 
    long long N, M;
    int prime = 0; 

    cin >> N >> M;

    if (N % 2 == 0 && N != 2) N--;
    if (M % 2 == 0 && M != 2) M--;


    while (prime == 0) {
        prime = 1;
        for (int i = 2; i <= N / 2; i++) {
            if (N % i == 0) {
                prime = 0;
                break;
            }
        }
        if (prime != 1) N -= 2;
    }

    prime = 0;
    while (prime == 0) {
        prime = 1;
        for (int i = 2; i <= M / 2; i++) {
            if (M % i == 0) {
                prime = 0;
                break;
            }
        }
        if (prime != 1) M -= 2;
    }
    
    cout << N * M << endl;

    return 0;
}

// EASY