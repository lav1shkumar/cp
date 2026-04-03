#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;

    string s;cin>>s;

    for(int i=1;i<n-1;++i){
        if(s[i-1]=='1' && s[i+1]=='1') s[i]='1'; 
    }

    int maxi = 0;
    for(char c:s) if(c=='1') maxi++;

    for(int i=1;i<n-1;++i){
        if(s[i-1]=='1' && s[i+1]=='1') s[i]='0'; 
    }

    int mini = 0;
    for(char c:s) if(c=='1') mini++;

    cout<<mini<<" "<<maxi<<endl;

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