#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
size 2n
n zeroes, rest permutation

find k, ak==0

only n values are equal, and those are zero





*/


void solve(){
    int n;cin>>n;

    for(int i=1;i<n;++i){

        cout<<"? "<<2*i<<" "<<2*i-1<<endl;

        int x; cin>>x;

        if(x){
            cout<<"! "<<2*i<<endl;
            return;
        }

    }

    cout<<"? "<<1<<" "<<2*n<<endl;
    cout.flush();

    int x; cin>>x;

    if(x){
        cout<<"! "<<2*n<<endl;
        return;
    }


    cout<<"? "<<2<<" "<<2*n<<endl;
    cout.flush();

    cin>>x;

    if(x){
        cout<<"! "<<2*n<<endl;
        return;
    }

    cout<<"! "<<2*n-1<<endl;




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