#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
we just care about 0,1,2 ; because if indegree>=3 
we will end up with either one of these not in the paths
*/



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    vector<pair<int,int>> edges;
    vector<int> indegree(n,0);
    vector<int> ans(n-1,-1);

    for(int i=0;i<n-1;++i){
        int u,v;cin>>u;cin>>v;
        u--;v--;
        edges.push_back({u,v});
        indegree[u]++;
        indegree[v]++;
    }
    int count=0;
    for(int i=0;i<n;++i){
        if(indegree[i]>=3){
            for(int k=0;k<edges.size();++k){
                int u=edges[k].first;
                int v=edges[k].second;
                if((u==i||v==i) && ans[k]==-1) ans[k]=count++;
            }
            break;
        }
    }
    for(int &val:ans){
        if(val==-1) val=count++;
        cout << val << endl;
    }

}