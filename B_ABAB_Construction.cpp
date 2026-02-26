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

    bool even=true,odd=false;



    for(int i=0;i<n;i++){
        char c = s[i];

        bool nxteven=false,nxtodd=false;

        if(even){
            char f = 'a';
            char b = (n-1-i)%2==0? 'a' : 'b';

            if (c=='?' || c==f) nxtodd = true;

            if (c=='?' || c==b) nxteven=true;

        }

        if(odd){
            char f = 'b';
            char b = (n-i)%2==0? 'a' : 'b';

            if (c=='?' || c==f) nxteven = true;

            if (c=='?' || c==b) nxtodd=true;

        }

        even=nxteven;
        odd=nxtodd;


        if(!even && !odd){
            cout<<"NO"<<endl;
            return;
        }

    }

    cout<<"YES"<<endl;

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