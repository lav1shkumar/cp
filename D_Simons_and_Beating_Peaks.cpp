#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;

    vector<int> arr(n);
    
    for(int i=0;i<n;++i) cin>>arr[i];


    vector<int> pref(n),suff(n);

    stack<int> st;
    for(int i=0;i<n;++i){
        while(!st.empty() && arr[st.top()] < arr[i]) st.pop();

        st.push(i);

        pref[i] = st.size();
    }

    stack<int> st1;

    for(int i=n-1;i>=0;--i){
        while(!st1.empty() && arr[st1.top()] < arr[i]) st1.pop();

        st1.push(i);

        suff[i] = st1.size();

    }

    int ans=max(pref[n-1],suff[0]);

    for(int i=1;i<n-1;++i){
        ans=max(ans,pref[i]+suff[i+1]);
    }

    cout<<n-ans<<endl;
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