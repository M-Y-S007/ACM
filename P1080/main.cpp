#include<bits/stdc++.h>
using namespace std;
struct BigIntSimple{
    vector<int> digits;

    BigIntSimple(long long x = 0){
        while(x){
            digits.push_back(x%10);
            x /= 10;
        }
        if(digits.empty()) digits.push_back(0);
    }

    BigIntSimple operator*(int x) const{
        BigIntSimple res;
        int carry = 0;
        for(int i = 0; i < digits.size() || carry; i++){
            if(i < digits.size()) carry += digits[i] * x;
            res.digits.push_back(carry % 10);
            carry /= 10;
        }
        return res;
    }

    BigIntSimple operator/(int x) const{
        BigIntSimple res;
        long long rem = 0;
        res.digits.resize(digits.size());

        for(int i = digits.size() - 1; i >= 0; i--){
            rem = rem * 10 + digits[i];
            res.digits[i] = rem / x;
            rem %= x;
        }
        while(res.digits.size() > 1 && res.digits.back() == 0)
            res.digits.pop_back();
        return res;
    }
    bool operator<(const BigIntSimple& b) const {
        if (digits.size() != b.digits.size())
            return digits.size() < b.digits.size();
        for (int i = digits.size() - 1; i >= 0; i--)
            if (digits[i] != b.digits[i])
                return digits[i] < b.digits[i];
        return false;
    }
    string toString() const{
        string s;
        for(int i = digits.size() - 1; i >= 0; i--){
            s += char(digits[i] + '0');
        }
        return s;
    }
};

struct Minister{
    int left,right;
    long long product;
};

int main(){
    int n;
    cin >> n;
    int king_left, king_right;
    cin >> king_left >> king_right;
    vector<Minister> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].left >> v[i].right;
        v[i].product = (long long)v[i].left * v[i].right;
    }

    sort(v.begin(),v.end(),[](Minister&a, Minister&b){
        return a.product < b.product;
    });
    BigIntSimple product = king_left;
    BigIntSimple maxReward = 0;

    for(int i = 0; i < n; i++){
        BigIntSimple reward = product / v[i].right;
        if(maxReward < reward){
            maxReward = reward;
        }
        product = product * v[i].left;
    }
    cout << maxReward.toString() << endl;
    return 0;
}