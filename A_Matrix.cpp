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

    int a;cin>>a;
    string s;cin>>s;

    int n=s.size();

    unordered_map<int,int> mp;

    for(int i=0;i<n;++i){
        int sum=0;
        for(int j=i;j<n;++j){
            sum+=s[j]-'0';

            mp[sum]++;
        }
    }

    int ans=0;

    if(a==0){
        // zero can mul with anything to give 0
        ans+=mp[0]*(n*(n+1)/2);
        ans*=2;
        ans-= mp[0]*mp[0];

        cout<<ans<<endl;

        return 0;
    }

    for(auto [x,v1]:mp){
        // x*y = a
        if(x==0 || a%x!=0) continue;

        int y = a/x;
        int v2 = mp[y];
        ans+= v1*v2;
    }

    cout<<ans<<endl;
}