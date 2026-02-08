#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
opening and closing should be equal else -1
if closing first then seq2 , open first then seq1

i only need 2 seq at max

(()) and ))((


))()((


*/


void solve(){
    int n;cin>>n;
    string s;cin>>s;

    vector<int> color(n,0);

    

    int bal=0;
    bool one=false,two=false;

    for(int i=0;i<n;++i){
        if(s[i]==')'){    

            if(bal==0){
                color[i]=2;
                two=true;
            }
            else{
                color[i]=color[i-1];
            }
            bal--;
            
        }

        else{
            if(bal==0){
                color[i]=1;
                one=true;
            }
            else{
                color[i]=color[i-1];
            }
            bal++;
        }

    }
    if(bal!=0) cout<<-1<<endl;

    else if(!one || !two){
        cout<<1<<endl;
        for(int i=0;i<n;++i) cout<<1<<" ";
        cout<<endl;
    }
    else{
        cout<<2<<endl;
        for(int clr:color) cout<<clr<<" ";
        cout<<endl;
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