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

    int n,m,k; cin>>n>>m>>k;


    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    vector<int> diff;
    for(int i=1;i<n;++i) diff.push_back(a[i]-a[i-1]);

    sort(diff.rbegin(),diff.rend());

    // how much i can skip? k-1
    int ans=0;
    for(int i=k-1;i<n-1;++i){
        ans+=diff[i];
    }
    ans+=1;
    ans+=k-1;


    cout<<ans<<endl;


}