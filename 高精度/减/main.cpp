#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
const int N = 100005;
int A[N], B[N], C[N];
int la, lb, lc;
bool cmp(int A[], int B[]){
    if(la != lb)return la > lb;
    for(int i = la - 1; ~ i; i--){
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}
void sub(int A[], int B[], int C[]){
    for(int i = 0; i < lc; i++){
        if(A[i] < B[i]){
            A[i+1]--;
            A[i] += 10;
        }
        C[i] = A[i] - B[i];
    }
    while(lc > 0 && C[lc] == 0) lc--;

}
int main(){
    string a, b;
    cin >> a >> b;
    la = a.size(), lb = b.size(), lc = max(la, lb);
    for(int i = la -1; ~ i; i--) A[la - 1 - i] = a[i] - '0';
    for(int i = lb -1; ~ i; i--) B[lb - 1 - i] = b[i] - '0';
    if(!cmp(A, B)) swap(A, B), swap(la, lb), cout <<'-';
    sub(A, B, C);
    for(int i = lc; ~ i; i--) printf("%d",C[i]);
    return 0;
}