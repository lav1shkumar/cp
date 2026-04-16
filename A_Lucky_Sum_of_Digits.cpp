#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
a*4 + b*7 == n

put 4 first then 7
 7*4 vs 4*7 == lcm

lets bruteforce

*/


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;

    int size=INT_MAX;
    int x=-1,y=-1;

    for(int b=0;b<=(n/7);++b){
        int sum = 7*b;

        int diff = n-sum;

        if(diff%4==0){
            int a = diff/4;

            if(size>a+b){
                size=a+b;
                x=a,y=b;
            }
            else if(size==a+b && y>b){
                x=a,y=b;
            }
        }

    }

    if(x==-1){
        cout<<-1<<endl;
        return 0;
    }

    while(x--) cout<<4;
    while(y--) cout<<7;

}