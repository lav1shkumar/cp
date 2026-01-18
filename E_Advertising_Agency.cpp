#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
first i need to find max sum in can get
then i can see number of ways to make it
and i can go n square

wait i will only pick bigger k elements, then i can count

*/


// --------------------------------------------
// Fast Modular Inverse using Fermat's Theorem
// --------------------------------------------
long long modInverse(long long a, long long mod){
    long long res = 1;
    long long power = mod - 2;  // a^(mod-2) % mod

    while (power){
        if (power & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        power >>= 1;
    }

    return res;
}

// ----------------------------
// nCr using multiplicative DP
// ----------------------------
long long nCr(long long n, long long r){
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    // symmetry: C(n,r) = C(n,n-r)
    if (r > n - r) r = n - r;

    long long res = 1;

    for (long long i = 1; i <= r; i++){
        res = res * (n - r + i) % MOD;        // multiply numerator
        res = res * modInverse(i, MOD) % MOD; // divide by i using inverse
    }

    return res % MOD;
}

void solve(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    sort(arr.rbegin(),arr.rend());

    // i need to count now,
    unordered_map<int,int> mp;
    for(int val:arr) mp[val]++;

    unordered_map<int,int> mpk;
    for(int i=0;i<k;++i){
        mpk[arr[i]]++;
    }
    // now i can do ncr thing with mod
    int ans=1;
    set<int> st;
    for(int i=0;i<k;++i){
        int v = arr[i];
        if(st.count(v)) continue;
        int need = mpk[v];
        int available = mp[v];
        st.insert(v);
        ans= (ans*nCr(available,need))%MOD;
    }

    cout<<ans<<endl;


}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) solve();

}