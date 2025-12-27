#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 10;
bool bad[MAXN];
int next_ok[MAXN];

bool haveSeven(int x){
    while(x){
        if(x % 10 == 7){
            return true;
        }
        x /= 10;
    }
    return false;
}

void preprocess(){
    for(int i = 1; i < MAXN; i++){
        if(haveSeven(i) && !bad[i]){
            for(int j = i; j < MAXN; j += i){
                bad[j] = true;
            }
        }
    }


    int last_ok = MAXN;
    for(int i = MAXN - 1; i >= 1; i--){
        if(!bad[i]){
            next_ok[i] = i;
            last_ok = i;
        }else{
            next_ok[i] = last_ok;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    preprocess();
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if(bad[x]){
            cout << -1 << "\n";
        }else{
            int ans = x + 1;
            while(ans < MAXN && bad[ans]){
                ans++;
            }
            cout << (ans < MAXN ? ans : -1) << "\n";
        }
    }
    return 0;
}












































/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, bool> memo_seven;
unordered_map<int, bool> memo_valid;
bool seven(int x){
    if(memo_seven.count(x)){
        return memo_seven[x];
    }
    ll y = x;
    bool has7 = false;
    while(y){
        if(y % 10 == 7){
            has7 = true;
            break;
        }
        y /= 10;
    }
    memo_seven[x] = has7;
    return has7;
}
bool find_seven(int x){
    if(memo_valid.count(x)) return memo_valid[x];
    
    if(seven(x)){
        memo_valid[x] = false;
        return false;
    }
    
    int t = sqrt(x);
    bool valid = true;
    for(int i = 2; i <= t; i++){
        if(x % i == 0){
            if(seven(i) || seven(x / i)){
                valid = false;
                break;
            }
        }
    }
    memo_valid[x] = valid;
    return valid;
}
int main(){
    int t;
    cin >> t;
    for(ll i = 0; i < t; i++){
        int x;
        int k = 1;
        cin >> x;
        if(!find_seven(x)){
            cout << -1 << endl;
        }else{
            for(int j = x + 1;;j++){
                if(find_seven(j)){
                    cout << j << endl;
                    break;
                }
            }
        }
        
    }
    return 0;
}*/