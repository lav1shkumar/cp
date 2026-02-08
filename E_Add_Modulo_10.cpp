#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;++i) cin>>arr[i];

    bool mul10=false;
    for(int &val:arr){
        if(val&1) val+=val%10;
        if(val%10==0) mul10=true;
    }

    if(count(arr.begin(),arr.end(),arr[0])==n){
        cout<<"YES"<<endl;
        return;
    }
    else if(mul10){
        cout<<"NO"<<endl;
        return;
    }

    for(int &val:arr){
        while(val%10!=2) val+=val%10;
        val %= 20;
    }

    if(count(arr.begin(),arr.end(),arr[0])==n){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
    }


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