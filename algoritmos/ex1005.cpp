#include<bits/stdc++.h>

using namespace std;

int main()
{
    double A, B, MEDIA = 0;

    cin >> A >> B;

    MEDIA= (A * 3.5 + B * 7.5) / (3.5 + 7.5);

    cout << fixed;
    cout << setprecision(5) << "MEDIA = " << MEDIA << endl;

    return 0;
}