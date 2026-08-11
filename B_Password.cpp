#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
it should satisfy all three, pref suff and in middle

so, i can store all common pref and suffix and then check if any of them is present in middle or not
this is trie thing, find pattern which is the common pref suff, then search on 1 to n-2
nope, this will be n square
kmp??


fixprefixfix == 000 000012 678

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

    int j=0;
    for(int i=1;i<n;++i){

        while(j>0 && s[i]!=s[j]) j=kmp[j-1];

        if(s[i]==s[j]) j++;
        kmp[i]=j;
    
    }

    for(int v:kmp) cout<<v<<" ";





    

}
