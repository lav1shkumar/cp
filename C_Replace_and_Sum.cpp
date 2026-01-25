#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

4 3 2 1
5 1 3 1

5 3 3 1


end result must be decreasing arr


1 2  = 8
2 4  = 7
3 4  = 4


wait i need to propogate max from right to left



*/


void solve(){
    int n,q;cin>>n>>q;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> pref(n);
    vector<int> arr(n);

    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];

    arr[n-1]=max(a[n-1],b[n-1]);    

    for(int i=n-2;i>=0;--i){
        arr[i]=max({a[i],b[i],arr[i+1]});
    }

    pref[0]=arr[0];
    for(int i=1;i<n;++i) pref[i]=pref[i-1]+arr[i];


    for(int i=0;i<q;++i){
        int l,r;cin>>l>>r;
        l--,r--;

        if(l==0){
            cout<<pref[r]<<" ";
        }
        else{
            cout<<pref[r]-pref[l-1]<<" ";
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