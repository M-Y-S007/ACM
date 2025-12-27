#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        long long n;
        cin >> n;
        
        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        unordered_set<long long> seen;
        vector<long long> result;
        
        for (long long num : nums) {
            if (seen.find(num) == seen.end()) {
                result.push_back(num);
                seen.insert(num);
            }
        }
        
        for (long long i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    
    return 0;
}