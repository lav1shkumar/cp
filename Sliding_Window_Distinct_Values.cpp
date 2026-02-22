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

    int n,k;cin>>n>>k;
    vector<int> a(n);

    for(int i=0;i<n;++i) cin>>a[i];

    set<int> st;
    map<int,int> freq;

    for(int i=0;i<k;++i){
        freq[a[i]]++;
        st.insert(a[i]);
    }

    cout<<st.size()<<" ";

    for(int i=k;i<n;++i){
        freq[a[i]]++;
        st.insert(a[i]);

        int l=i-k;
        int f = freq[a[l]]--;
        if(f==1){
            st.erase(a[l]);
        }

        cout<<st.size()<<" ";
    }


}
