#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;
    int k;cin>>k;

    string s(n,0);
    for(int i=0;i<n;++i) cin>>s[i];


    vector<bool> zero(k,0);
    vector<bool> one(k,0);

    for(int i=0;i<n;++i){
        int idx = i%k;
        if(s[i]=='0'){
            if(one[idx]){
                cout << "NO" <<endl;
                return;
            }
            zero[idx]=true;
        }
        if(s[i]=='1'){
            if(zero[idx]){
                cout << "NO" <<endl;
                return;
            }
            one[idx]=true;
        }
    }

    for(int i=0;i<n;++i){
        int idx = i%k;
        if(s[i]=='?'){
            if(zero[idx]) s[i]='0';
            if(one[idx]) s[i]='1';
        }


    }


    int z=0,o=0;
    for(int i=0;i<k;++i){
        if(s[i]=='0') z++;
        if(s[i]=='1') o++;
    }

    if(z<=k/2 && o<=k/2){
        cout << "YES" <<endl;
        return;
    }
    cout << "NO" <<endl;
    return;




}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}