#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

flip bit,
include the one
so, its about how many times the bits changing to left or right


*/


void solve(){
    int n,k;cin>>n>>k;

    vector<int> a(n),p(k);

    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<k;++i) cin>>p[i];


    int idx = p[0]-1;

    int b = a[idx];


    int l=0,r=0;

    int prev1=b,prev2=b;

    for(int i=0;i<n;++i){
        if(i<=idx){
            if(a[i]!=prev1){
                l++;
                prev1=a[i];
            }

        }
        else{
            if(a[i]!=prev2){
                r++;
                prev2=a[i];
            }

        }

    }

    if(prev2!=b) r++;
        

    cout<<max(l,r)<<endl;


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