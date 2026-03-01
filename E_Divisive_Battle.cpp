#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
int fun(int v){
    set<int> st;

    for(int i=2;i*i<=v;++i){
        while(v%i==0){
            st.insert(i);
            v/=i;
        }
    }

    if(v>1) st.insert(v);

    if(st.size()>1) return -1; // alice win if more than two prime fac 

    if(st.size()==0) return 1; // prime

    return *st.begin();
}

void solve(){
    int n;cin>>n;

    vector<int> a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i];

    if(is_sorted(a.begin(),a.end())) {
        cout<<"Bob\n";
        return;
    }

    for(int i=0;i<n;++i){
        b[i]=fun(a[i]);
        //cout<<b[i]<<" ";
    }

    if(*min_element(b.begin(),b.end())==-1){
        cout<<"Alice\n";
        return;
    }

    if(is_sorted(b.begin(),b.end())) {
        cout<<"Bob\n";
        return;
    }

    cout<<"Alice\n";


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