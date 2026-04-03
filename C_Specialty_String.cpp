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

    stack<char> st;

    for(int i=0;i<n;++i){
        if(!st.empty() && st.top()==s[i]){
            st.pop();
            continue;
        }

        st.push(s[i]);

    }

    if(st.empty()){
        cout<<"YES\n";
    }
    else cout<<"NO\n";

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