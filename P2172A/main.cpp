#include<bits/stdc++.h>
using namespace std;
int main(){
    int g, c, l;
    
    scanf("%d %d %d",&g, &c, &l);
    int a[3] = {g, c, l};
    sort(a, a + 3);
    if(a[2] - a[0] >= 10){
        printf("check again");
    }
    else{
        printf("final %d",a[1]);
    }
    
}