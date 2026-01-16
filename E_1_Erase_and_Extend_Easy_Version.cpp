#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
can go n*k
pick a prefix os size 1 to n
and build the string ans get the minimum

*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;cin>>n>>k;
    string s;cin>>s;

    string pref;
    string ans(k,'z');

    for(int i=0;i<n;++i){
        pref.push_back(s[i]);

        string temp;
        while(temp.size()<k){
            temp+=pref;
        }
        while(temp.size()>k) temp.pop_back();
        ans=min(ans,temp);
    }

    cout<<ans<<endl;
}