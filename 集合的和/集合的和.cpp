#include <iostream>
using namespace std;

int main() {
    long long sum = 0;
    int n = 0;
    int x;
    
    while (cin >> x) {
        sum += x;
        n++;
    }
    
    long long result = sum * (1LL << (n - 1));
    cout << result << endl;
    
    return 0;
}
