#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;

    vector<string> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    vector<unordered_set<char>> st(m);

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            st[j].insert(a[i][j]);
        }
    }

    int ans=1;
    for(int i=0;i<m;++i){
        ans = (ans * st[i].size())%MOD;

    }

    cout<<ans<<endl;

}