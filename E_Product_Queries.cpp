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

6 == 1x6 , 2x3 , 3x2 so i can use sieve
1 to n, then 2*i till max until j/i<=i

*/


void solve(){
    int n;cin>>n;
    bool has_one=false;
    vector<int> arr(n+1,LLONG_MAX);


    for(int i=0;i<n;++i){
        int x;cin>>x;
        arr[x]=1;
    }


    for(int i=1;i<=n;++i){
        if(arr[i]==LLONG_MAX) continue;
        for(int j=2*i;j<=n;j+=i){
            if(arr[j/i]==LLONG_MAX) continue;
            arr[j]=min(arr[j],arr[j/i]+arr[i]);
        }
    }

    for(int i=1;i<=n;++i){
        if(arr[i]==LLONG_MAX) arr[i]=-1;
        cout<<arr[i]<<" ";
    }
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