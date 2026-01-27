#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
0 to l1 -- min k
but l1 to l2  or r1 to l2


reach till at least ln, 0 to l1, l1 to l2, l2 to l3 and so on...
is this optimal?
                nope, if points are overlapping

binary search


*/
bool check(int k,vector<pair<int,int>> &arr){
    int n=arr.size();
    int l = 0,r = 0;    
    for(auto [x,y]:arr){
        l-=k,r+=k;
        l=max(l,x);
        r=min(r,y);

        if(l>r) return false;

    }
        
    return true;
}

void solve(){
    int n;cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i].first>>arr[i].second;

    int l=0,r=1e9+1;
    int ans=0;
    while(r>=l){
        int mid = (l+r)/2;

        if(check(mid,arr)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;

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