#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
diff % i ==0
1 to n-1
1 2 3 4 

1 to n
1 to n-1 diff are possible
can i arrange
first ele can be anything % 1 == 0
5

1 5 2 4 3
3 4 2 5 1

done



*/


void solve(){
    int n;cin>>n;

    vector<int> perm;
    set<int> st;
    for(int i=2;i<=n;++i) st.insert(i);
    perm.push_back(1);
    for(int i=1;i<n;++i){
        int diff = n-i;
        int a = perm[i-1] + diff;
        int b = perm[i-1] - diff;
        if(st.count(a)){
             perm.push_back(a);
             st.erase(a);
        }
        else if(st.count(b)){
             perm.push_back(b);
             st.erase(b);
        }
    
    }

    for(int i=n-1;i>=0;--i) cout<<perm[i]<<" ";
    cout<<endl;


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