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

    string s;cin>>s;
    int n=s.size();

    vector<int> kmp(n,0);

    int len=0;
    for(int i=1;i<n;++i){
        while(len!=0 && s[i]!=s[len]){
            len=kmp[len-1];
        }
 
        if(s[i]==s[len]) len++;

        kmp[i]=len;
    }

    //for(int v:kmp) cout<<v<<" ";

    if(kmp[n-1]==0){
        cout<<"Just a legend";
        return 0;
    }

    for(int i=0;i<n-1;++i){
        if(kmp[i]==kmp[n-1]){
            string ans = s.substr(n-kmp[n-1]);
            cout<<ans<<endl;
            return 0;
        }
    }

    if(kmp[kmp[n-1]-1]!=0){
        string ans = s.substr(n-kmp[kmp[n-1]-1]);
        cout<<ans<<endl;
        return 0;
    }

    cout<<"Just a legend";
}