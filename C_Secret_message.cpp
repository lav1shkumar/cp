#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

idx = q*d + r

if d=3 then 0 == 3 == 6 == 9  at least one char count==4==n/d

*/


void solve(){
    int n , k; cin>>n>>k;

    string s[k];

    for(int i=0;i<k;++i) cin>>s[i];

    // d can be divisor of n
    for(int d=1;d<=n;++d){
        if(n%d) continue;
        // 0 to d-1 = rem
        string ans;

        for(int r=0;r<d;++r){
            // for 0 numbers = q*d+rem
            int freq[26]={0};

            for(int q=0;q<(n/d);++q){

                int idx = q*d+r;
                int p[26]={0};

                for(int x=0;x<k;++x){
                    p[s[x][idx]-'a']=1;
                }

                for(int i=0;i<26;++i) freq[i]+=p[i];
            }

            for(int i=0;i<26;++i){
                if(freq[i]==n/d){
                    ans.push_back(i+'a');
                    break;
                }
            }

        }
        
        if(ans.size()==d){  
            for(int i=0;i<n;++i){
                cout<<ans[i%d];
            }
            cout<<endl;
            return;

        }

    }


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