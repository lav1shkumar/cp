#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    int count=1;

    stack<int> st;
    st.push(a[0]);

    for(int i=1;i<n;++i){
        if(st.empty()){
            count++;
            st.push(a[i]);
        }

        else if(a[i]==st.top()+1) st.push(a[i]);

        else if(a[i]>st.top()+1){
            while(!st.empty()) st.pop();
            st.push(a[i]);
            count++;
        }

        else{
            while(!st.empty() && st.top()+1>a[i]) st.pop();

            if(st.empty()) count++;

            st.push(a[i]);

        }
    

    }

    cout<<count<<endl;
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