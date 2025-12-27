#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100005;
int A[N], B[N], C[N];
int la, lb, lc;
void add(int A[], int B[], int C[]){
    for(int i = 0; i < lc; i++){
        C[i] += A[i] + B[i];
        C[i + 1] += C[i] / 10;
        C[i] %= 10;
    }
    if(C[lc]) lc++;
}
int main(){

    string a, b;
    cin >> a >> b;
    la = a.size(), lb = b.size(), lc = max(la, lb);
    for(int i = la - 1; ~ i; i--) A[la - 1 - i] = a[i] - '0';
    for(int i = lb - 1; ~ i; i--) B[lb - 1 - i] = b[i] - '0';
    add(A, B, C);// ~i equal to i > 0
    for(int i = lc - 1; ~ i; i--) printf("%d", C[i]);
    return 0;

}