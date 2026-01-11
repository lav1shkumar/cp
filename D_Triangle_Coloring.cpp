#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;


// Observations
/*
triples == 123   456   678   etc
n%6==0, means even triples

lets think about ways to pick max edges
    at max we can pick 2 edges of all triples
    so i will do it in a way that, the max 2 of edges will get selected

    obseervation: there is no possible way to select all 3 edges
                so optimally, we can pick 2 edges from every triple

    no of ways, only possible for some triple, if there are other ways to make max
    if all are same then = 3 ways ,
    if 2 are same then : if(bigger) only 1 way, no other
                         else; 2 ways

    for a pair, if one is RBB then other will be BRR
    i have to choose half triples for all
    then i can assign 

    now i know weather red/blue for an edge, i have to assign color to the vertex that have max two edges(adj)


*/
long long modInverse(long long a, long long MOD){
    long long res = 1;
    long long power = MOD - 2;  // a^(mod-2) % mod

    while (power){
        if (power & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
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


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    int triples=n/3;
    vector<tuple<int,int,int>> wt(triples);
    for(int i=0;i<triples;++i){
        int a,b,c;cin>>a>>b>>c;
        vector<int> s = {a,b,c};
        sort(s.rbegin(),s.rend());
        wt[i]={s[0],s[1],s[2]};
    }
    
    vector<int> minwt(triples);
    for(int i=0;i<triples;++i){
        auto [a,b,c] = wt[i];
        if(a==b && b==c) minwt[i]=3;
        else if(b==c) minwt[i]=2;
        else minwt[i]=1;
    }

    int ans = nCr(n/3,n/6);
    for(int i=0;i<triples;++i){
        ans=(ans*minwt[i])%MOD;
    }

    cout<<ans<<endl;

}