#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

-  + == ans
+  + == ai>aj

k==inf 


*/


void solve(){
    int n;cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    int cnt=0;
    for(int i=0;i<n;++i){
        int x=0,y=0;
        for(int j=i+1;j<n;++j){
            if(a[i]>a[j]) x++;
            if(a[j]>a[i]) y++; 

        }

        cout<<max(x,y)<<" ";

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