#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
basically binary search type shit
or divide in two ranges


*/

void solve(){
    int n,x;cin>>n>>x;

    if(x>n) {
        cout<<-1<<endl;
        return;
    }

    int steps=0;
    int l=n,r=n;
    
    while (r >= x) {
        if (x >= l && x <= r) {
            cout << steps<<endl;
            return;
        }
        l = l/2;  
        r = (r+1)/2;
        steps++;
    }
    cout <<-1<<endl;
    
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