#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
vector<int> clr;
unordered_map<int,unordered_set<int>> vset;



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;

    clr.assign(n,0);
    for(int i=0;i<n;++i){
        cin>>clr[i];
        vset[clr[i]];
    }

    for(int i=0;i<m;++i){
        int a,b;cin>>a>>b;
        a--,b--;

        if(clr[a]!=clr[b]){
            vset[clr[a]].insert(clr[b]);
            vset[clr[b]].insert(clr[a]);
        }

    }

    int ans=-1,val=INT_MIN;
    for(auto [k,v]:vset){
        int size = v.size();
        if(size>val){
            val=size;
            ans=k;
        }
        else if(size==val) ans=min(ans,k);

    }


    cout<<ans<<endl;


}