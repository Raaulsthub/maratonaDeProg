#include <iostream>
#include <vector>
 
using namespace std;

bool delete_pair (vector<long long> *array, long long value) {
    for (int i = 0; i < array->size(); i++) {
        if (array->at(i) == value) {
            array->erase(array->begin() + i);
            return true;
        }
    }
    return false;
}
 
int main() {
    
    long long N;

    cin >> N;

    vector<long long> array;

    for (int i = 0; i < N; i++) {
        long long aux;
        cin >> aux;
        if (!delete_pair(&array, aux)) {
            array.push_back(aux);
        }
    }

    cout << array.at(0) << endl; 
 
    return 0;
}