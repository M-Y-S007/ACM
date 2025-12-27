#include<iostream>
#include<algorithm>
using namespace std;
struct p{
    int l;
    int r;
}a[1000005];

bool cmp(p c, p d){
    return c.r < d.r;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].l >> a[i].r;
    }
    sort(a, a + n, cmp);
    int count = 0;
    int last_end = -1;
    for(int i = 0; i < n; i++){
        if(a[i].l >= last_end){
            count++;
            last_end = a[i].r;
        }

    }
    cout << count << endl;
    return 0;
}