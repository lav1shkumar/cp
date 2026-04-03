#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
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

    int n,x;cin>>n>>x;

    int t=0;
    vector<int> a(n);
    for(int i=0;i<n;++i){
         cin>>a[i];
         t+=a[i];
    }

    map<int,int> freq;

    vector<int> pow(n);
    for(int i=0;i<n;++i){
        pow[i]= t-a[i];
        freq[pow[i]]++;
    }

    int ans=t;

    while(!freq.empty()){

        auto it = freq.begin();
        int k = it->first;
        int v = it->second;

        if(v%x==0){

            freq[k+1]+=v/x;
            freq.erase(it);

        }
        else{
            ans=min(ans,k);
            break;
        }

    }

    int res = binpow(x,ans,MOD);
    cout<<res<<endl;

}
