#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/

long long binpow(long long a, long long b, long long MOD) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) 
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;cin>>s;
    int a,b;cin>>a>>b;

    int n=s.size();

    vector<int> suff(n);
    suff[n-1] = (s[n-1]-'0')%b;

    int power = 1;
    for(int i=n-2;i>=0;--i){
        power = (power*10)%b;
        suff[i] = ((s[i]-'0') * power%b + suff[i+1])%b;
    }

    int left=0;

    for(int i=0;i<n-1;++i){
        left = (left*10 + (s[i]-'0'))%a;

        if(s[i+1]=='0') continue;

        if(left==0 && suff[i+1]==0){
            cout<<"YES\n";
            cout<<s.substr(0,i+1)<<endl;
            cout<<s.substr(i+1)<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;
}