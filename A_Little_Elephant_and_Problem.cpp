#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;++i) cin>>arr[i];

    vector<int> sorted=arr;
    sort(sorted.begin(),sorted.end());

    int cnt=0;
    for(int i=0;i<n;++i){
        if(arr[i]!=sorted[i]) cnt++;
    }


    if(cnt==0 || cnt==2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


}