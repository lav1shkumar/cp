#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+9;


// Observations
/*
min score = 
k=3

score = +1, 0  OR x2 , try not to x2 

score is monotonic with idx, only inc with idx
so we try not to double it at the end

and we need logn or rootn soln

first wrong == n-k*wrong; then we will have wrong-1 deg of size k-1
okay

or i need to see how many i can deduce, rest just -1 from score


maybe see how many blocks of size k can be made = n/k;
if worng>= this, no doubling, else
n/k - wrong = doubling blocks
if b blocks as such:    

                    2k , 6k , 14k , 30k == k(2^+2^2+..2^b) = k * 2(2^b-1)

                                            but also remaining one?
                                            just do +1?

                                            m - how many idx covered (b*k)
                                            and sum that?

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

    int n,m,k;cin>>n>>m>>k;

    int wrong = n-m;

    int safe = (wrong*(k-1)); 

    int rest = max(0ll,m-safe);

    int score=0;

    
    int b = max(0ll,rest/k);

    score = (score+(k*(binpow(2,b+1,MOD)-2+MOD))%MOD)%MOD;

    int remain = (m-(b*k)%MOD+MOD)%MOD;

    score = (score + remain)%MOD;

    cout<<score<<endl;


}