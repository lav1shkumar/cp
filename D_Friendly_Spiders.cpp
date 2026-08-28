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

    int n;cin>>n;
    vector<int> a(n);

    vector<vector<int>> factors(n);

    int maxi=0;
    for(int i=0;i<n;++i){
        int x;cin>>x;
        maxi=max(maxi,x);

        for(int j=2;j*j<=x;++j){
            if(x%j==0){
                factors[i].push_back(j);
                
                while(x%j==0) x/=j;
            }

        }

        if(x>1) factors[i].push_back(x);
    }

    vector<vector<int>> adj(maxi+1);


    for(int i=0;i<n;++i){
        for(int f:factors[i]) adj[f].push_back(i);
    }



    int s,d;cin>>s>>d;
    s--,d--;


    queue<int> q;
    vector<int> dp(n,-1);
    vector<int> parent(n,-1);
    q.push(s);
    dp[s]=0;

    unordered_set<int> vis;

    
    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(int f:factors[node]){
            if(vis.count(f)) continue;
            vis.insert(f);

            for(int child:adj[f]){
                if(dp[child]==-1){
                    dp[child]=dp[node]+1;
                    parent[child]=node;
                    q.push(child);
                }
            }

        }

    }

    if(dp[d]==-1){
        cout<<-1<<endl;
        return 0;
    }

    vector<int> path;

    while(d!=-1){
        path.push_back(d);
        d=parent[d];
    }

    cout<<path.size()<<endl;
    for(int i=path.size()-1;i>=0;--i) cout<<path[i]+1<<" ";

}