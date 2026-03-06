#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
digit dp?
maybe


1 3 5

11135

2 3 10

sum == good number, 

how many conbinations of a and b , ==n

first dig a or b
second dig prev*10+a|b

every idx 2 choices, 2^n possible comb, but their sums are limited

*/
int a,b,n;
long long binpow(long long a, long long b, long long MOD) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) 
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>n;

    vector<int> fact(n+1);
    fact[0]=fact[1]=1;

    for(int i=2;i<=n;++i) fact[i]=(fact[i-1]*i)%MOD;

    vector<int> sums;
    vector<int> cnt;
    cnt.push_back(1);
    

    int s=1;

    for(int i=0;i<=n;++i){
        sums.push_back(i*a + (n-i)*b);

        if(i>0){
            s = (s*(n-i+1))%MOD;
            s = (s * binpow(i,MOD-2,MOD))%MOD;

            cnt.push_back(s);
        }

        //cout<<sums[i]<<" "<<cnt[i]<<endl;
    }


    // i will check which ones are valid, then no of ways to make that sum?
    // ways to pick 1 a, 2 a ,3a == nc1,2,3 rest b
    // nC0,nc1 , nc2 , nc3 , nc4 ,.. nCn
    //  1,    n,  n*(n-1)/2! , n*(n-1)*(n-2)/3!
    int ans=0;
    for(int i=0;i<=n;++i){
        string v = to_string(sums[i]);

        bool ok=true;
        for(char c:v){
            if((c-'0')!=a && (c-'0')!=b){
                ok=false;
                break;
            }
        }

        if(ok) ans = (ans + cnt[i])%MOD;

    }


    cout<<ans<<endl;


}