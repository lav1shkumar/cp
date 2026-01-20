#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
no more than one move to the left, curr - left - cur == 2 moves, +(left+curr) to score
                                  curr -- next -- curr ---  +(next+curr)
                                
                                  curr -- next -- next --- +(next+next) , pos changed

                                  which one is bigger?
if i am making 1 move left, i will use i will use 2 less ele
1 - 2 - 3 - 4 - 5  -- 0 moves == 4
1 - 2 - 1 - 2 - 3  -- 1 move 1to3 == 3, total 4
for 2 moves 
1-2-1-2-1 == total 4 but z=2 , 1 to 2 == 2 only

5 to 3 to 2
k-(2*z)+1 == 5-2-1=3
           5-4-1=0


*/
void solve(){
    int n,k,Z; cin>>n>>k>>Z;
    vector<int> a(n);

    for(int i=0;i<n;++i) cin>>a[i];

    int ans = 0;
    // z==0 done 1 2 3 4 5 6 , k=5
    // z==1      1 2 3 4
    // z==2      1 2

    for (int z = 0; z <= Z && 2 * z <= k; ++z) {
        int r = k - 2 * z;  
        int base = accumulate(a.begin(), a.begin() + r + 1, 0LL);

        int bestPair = 0;
        for (int i = 1; i <= min(r + 1, n - 1); ++i) {
                bestPair = max(bestPair, a[i] + a[i - 1]);
        }
        int res = base + 1LL * z * bestPair;
        ans = max(ans, res);
    }

    cout <<ans<<endl;




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