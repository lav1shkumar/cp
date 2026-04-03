#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
vector<int> a;

void solve(){
    int n,m,l;cin>>n>>m>>l;

    a.assign(n,0);
    for(int i=0;i<n;++i) cin>>a[i];

    multiset<int> ms;
    for(int i=0;i<min(n+1,m);++i) ms.insert(0);

    int j=0;

    int ans = l;
    int rem = n;
    for(int i=1;i<=l;++i){
        ms.insert(*ms.begin()+1);
        ms.erase(ms.begin());

        if(j<n && i==a[j]){
            //cout<<i<<endl;
            auto it = --ms.end();
            ans-=*it;

            ms.erase(it);
            if(ms.size()<rem) ms.insert(0);
            j++,rem--;
        }

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