#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
can go n*k
pick a prefix os size 1 to n
and build the string ans get the minimum


can't go n*k 
i have to optimally build ans
optimally pick a prefix ??

lets day i picked a pref of len 2 = ab
now next char should not be greater than s[i%len of pref] == ABCD or ABAB, 
D shauld be less or equal to B to extend


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


    int len=1;
    for(int i=1;i<n;++i){
        if(s[i%len]>s[i]) len=i+1;
        else if(s[i%len]<s[i]) break;
    }

    string pref=s.substr(0,len);

    string ans;
    while(ans.size()<k){
        ans+=pref;
    }

    while(ans.size()>k) ans.pop_back();

    cout<<ans<<endl;
}