#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
[1,1,3,2,3,1,2,3,2] 

every element could be the length, starting or closing
can i use dp to jump over lengths?
1 to 3 to 2 to n  found a sol == 1 + 2 3 1 + 3 2

but i need nlogn solution, so cant track prev length

lets talk about smaller problem
2 3 2  -- either first 2 is size or last, both are valid bcz size==3
basically either 0==size-1 or n-1==size-1 then true

can we greddily do this??
probably not, local optimization wont spread globally

lets think about dp

can i do it using graph thing? maybe possile





*/

int n;
vector<int> arr;

void solve(){
    cin>>n;
    arr.assign(n,0);
    for(int i=0;i<n;++i) cin>>arr[i];

    vector<vector<int>> adj(n+1);
    for(int i=0;i<n;++i){
        int v=arr[i];
        //i can make this jump - v
        if((i+v+1)<=n) adj[i].push_back(i+v+1);
    }
    for(int i=n-1;i>=0;--i){
        int v=arr[i];
        if((i-v)>=0) adj[i-v].push_back(i+1);
    }
    set<int> vis;
    vis.insert(0);
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node==n){
            cout<<"YES"<<endl;
            return;
        }
        
        for(int child:adj[node]){
            if(vis.count(child)) continue;
            q.push(child);
            vis.insert(child);
        }

    }
    cout<<"NO"<<endl;
    
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