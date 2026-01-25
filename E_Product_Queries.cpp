#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
min number of ele required to make a*b*c... == i or -1
lets say i is 6: 1 2  : pairs = 1,6   2,3 
            
i == 1, is 1 in arr then 1 else -1
for others : cnt ai>1 only
i need to see if arr has one

i can do bfs as edge cost 1

*/


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    bool has_one=false;

    for(int i=0;i<n;++i){
        cin>>arr[i];
        if(arr[i]==1) has_one=true;
    }

    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());


    vector<int> unique_elements;
    for(int x:arr) if(x>1 && x<=n) unique_elements.push_back(x);

    vector<int> dist(n+1,-1);
    queue<int> q;
    for(int x:unique_elements){
        if(dist[x]==-1){
            dist[x]=1;
            q.push(x);
        }
    }

    if(has_one) dist[1]=1;
    while(!q.empty()){
        int u= q.front();
        q.pop();

        for(int v:unique_elements){
            if(u>(n/v)) break;
            int next=u*v;

            if(dist[next]==-1){
                dist[next]=dist[u]+1;
                q.push(next);
            }
        }
    }
    for(int i=1;i<=n;++i) cout<<dist[i]<<" ";
    cout<<endl;
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