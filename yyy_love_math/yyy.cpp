#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long candidate, num;
    int count = 0;
    
    // 摩尔投票过程
    for (int i = 0; i < n; i++) {
        cin >> num;
        
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    // 由于题目保证存在多数元素，直接输出候选者
    cout << candidate << endl;
    
    return 0;
}
