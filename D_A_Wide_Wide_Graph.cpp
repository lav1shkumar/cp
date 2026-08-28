#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
int n;
vector<vector<int>> adj;

vector<int> get_dist(int start){
    vector<int> dis(n,-1);
    dis[start]=0;

    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int child:adj[node]){
            if(dis[child]==-1){
                dis[child]=dis[node]+1;
                q.push(child);
            }
        }
    }
    return dis;
}

int fartest_node(int start){
    auto dis = get_dist(start);
    return max_element(dis.begin(),dis.end())-dis.begin();
}


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    adj.assign(n,{});
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int a = fartest_node(0);
    int b = fartest_node(a);

    auto dis1 = get_dist(a);
    auto dis2 = get_dist(b);

    vector<vector<int>> added(n+1);

    for(int i=0;i<n;++i){
        int v = max(dis1[i],dis2[i]);
        added[v].push_back(i);
    }

    unordered_set<int> st;

    vector<int> ans(n,n);

    for(int k=n;k>=1;--k){
        for(int nodes:added[k]) st.insert(nodes);

        if(st.size()>0) ans[k-1]=n-st.size()+1;
    }

    for(int v:ans) cout<<v<<" ";

}