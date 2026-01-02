#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/

void solve(){
    int n;cin>>n;
    //fact
    vector<int> fact;
    int f=1;
    int mul=1;

    while(f<=n){
        f*=mul++;
        if(f<=n) fact.push_back(f);
    }

    // how many possible = 15max 2 to the power 15 okay
    int m = fact.size();
    int  ans= __builtin_popcountll(n);

    for(int mask=0;mask<(1<<m);mask++){
        int count = 0;
        int sum=0;

        for(int i=0;i<m;++i){
            if(mask&(1<<i)){
                sum+=fact[i];
                count++;
            }
        }

        if(sum>n) continue;

        int need = n-sum;
        count+=__builtin_popcountll(need);

        ans=min(ans,count);
    }

    cout << ans << endl;


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}