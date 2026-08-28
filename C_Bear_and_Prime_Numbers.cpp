#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int MOD = 1e9+7;


// Observations
/*
so i need f(p) in range
i can get all primes using sieve till 1e7
then, do simiar to sieve, prime*2, prime*3, sum their frequencies
use pref array

btw  ri<2*1e9 not useful cuz x<=10^7, so make it that


*/
int mp[10000001];


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;

    int M=-1;
    
    for(int i=0;i<n;++i){
        int x;cin>>x;
        mp[x]++;
        M=max(M,x);
    }
    M++;

    vector<int> prime(M,1);
    prime[0]=prime[1]=0;

    for(int i=2;i*i<M;++i){
        if(prime[i]){
            for(int j=i*i;j<M;j+=i) prime[j]=0;
        }
    }

    vector<int> cnt(M,0);

    for(int i=2;i<M;++i){
        if(prime[i]==0) continue;
        
        int a=0;

        for(int j=i;j<M;j+=i){
            a+=mp[j];
        }

        cnt[i]=a;
    }
    
    vector<int> pref(M+1,0);
    for(int i=1;i<=M;++i) pref[i]=pref[i-1]+cnt[i-1];
    

    int m;cin>>m;
    for(int i=0;i<m;++i){
        int l,r;cin>>l>>r;

        if(r>=M) r=M-1;

        if(l>=M){
            cout<<0<<endl;
            continue;
        }

        int ans = pref[r+1]-pref[l];

        cout<<ans<<endl;

    }


}