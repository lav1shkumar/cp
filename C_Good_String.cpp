#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
can we greedily do it,
if pos is even, we check it must be equal to prev chosen

is it optimal??
        1 1  2   2
            k-1  k   k>2
            not possible,
            greedy == optimal  

if len off remove one

*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    string s;cin>>s;

    string ans;
    for(int i=0;i<n;++i){
        int len = ans.size();
        if(len&1){
            if(s[i]!=ans.back()) ans.push_back(s[i]);
        }
        else ans.push_back(s[i]);
    }

    if(ans.size()&1) ans.pop_back();

    cout<<s.size()-ans.size()<<endl;
    if(!ans.empty()) cout<<ans<<endl;

}