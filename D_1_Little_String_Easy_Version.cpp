#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n,c;cin>>n>>c;
    string s;cin>>s;

    if(s[n-1]=='0'){
        cout<<-1<<endl;
        return;
    }

    int ans=1,check=1;

    for(int i=0;i<n-1;++i){
        int t;
        if(s[i]=='1'){
            t=2;
        }
        else{
            t=i;
        }
        ans= (ans*t)%MOD;
        check=(check*t)%c;
    }
    
    if(check==0){
        cout<<-1 <<endl;
    }else{
        cout<< ans<<endl;
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