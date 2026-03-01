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

    int n;cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    int s=0;
    int count=0;
        
    set<int> st;
    vector<int> ans;

    for(int i=0;i<n;++i){
        int v=a[i];
        s+=v;
        if(v<0 && st.count(abs(v))==0){
            cout<<-1<<endl;
            return 0;
        }

        if(st.count(v)){
            cout<<-1<<endl;
            return 0;
        } 

        st.insert(v);

        if(s==0){
            ans.push_back(st.size());
            count++;
            st.clear();
        }

    }

    if(s!=0){
        cout<<-1<<endl;
        return 0;

    }

    cout<<count<<endl;

    for(int v:ans) cout<<v<<" ";

}