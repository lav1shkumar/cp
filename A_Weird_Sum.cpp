#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
int count(vector<int> &v){
    int n=v.size();
    sort(v.rbegin(),v.rend());
    
    int count=0;
    for(int i=0,j=n-1;i<n;++i,j-=2){
        count+=j*v[i];
    }
    return count;

}


void solve(){
    int n,m;cin>>n>>m;

    unordered_map<int,vector<int>> x,y;
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int c;cin>>c;
            x[c].push_back(i);
            y[c].push_back(j);
        }
    }

    int ans=0;

    for(auto it:x){
        ans+=count(it.second);
    }
    for(auto it:y){
        ans+=count(it.second);
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
    solve();

}