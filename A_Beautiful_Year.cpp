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



    for(int i=n+1;i<=n+1000000;++i){
        string s=to_string(i);
        unordered_set<char> st(s.begin(),s.end());

        if(s.size()==st.size()){
            cout<<i<<endl;
            return 0;
        }




    }

}