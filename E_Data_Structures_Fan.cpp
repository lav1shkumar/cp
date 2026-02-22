#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){

    int n;cin>>n;
    vector<int> a(n);
    vector<int> pref(n,0);

    cin>>a[0];
    pref[0]=a[0];

    for(int i=1;i<n;++i){
        cin>>a[i];
        pref[i]=pref[i-1]^a[i];
    }

    string s;cin>>s;

    int ans[2]={0,0};

    for(int i=0;i<n;++i){
        if(s[i]=='0') ans[0]^=a[i];
        else ans[1]^=a[i]; 
    }

    int q;cin>>q;

    while(q--){
        int t;cin>>t;
        if(t==2){
            int v;cin>>v;
            cout<<ans[v]<<" ";
        }

        else{
            int a,b;cin>>a>>b;
            a--,b--;

            int p = pref[b];
            if(a!=0) p^=pref[a-1];

            ans[0]^=p;
            ans[1]^=p;
        }


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