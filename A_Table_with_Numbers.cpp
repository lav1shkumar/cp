#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
pair should lie in range, 1 to h and 1 to l ,
// no of such pairs will be ans
i need max such pairs

total pos pairs = for n numbers = n/2, if odd then n-1/2



*/


void solve(){
    int n,h,l;cin>>n>>h>>l;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    if(h>l) swap(h,l);

    int both=0,inh=0,inl=0,res=0;
    for(int val:arr){
        if(val<=h) both++;
        else if(val<=l) res++;
    }

    int p=0;
    if(res>both) p=both;
    else {
        p=res;
        p+=(both-res)/2;
    }
    
    cout<<p<<endl;

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