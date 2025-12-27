#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    int t;
    int n,m;

    cin >> t;
    for(int i = 0; i < t; i++){
        long long sum = 0;
        cin >> n >> m;
        for(int j = 0;j < n; j++){
            cin >> a[j];
        }
        sort(a, a + n, cmp);
        int k_max = min(m, n);
        for(int k = 0; k < k_max; k++){
            sum += (long long)a[k] * ( m - k );
        }
        cout << sum << endl;
    }
    return 0;

}