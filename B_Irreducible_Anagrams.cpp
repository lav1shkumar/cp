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

    string s;cin>>s;

    int q;cin>>q;

    int n=s.size();


    vector<vector<int>> pref(26,vector<int> (n+1,0));
    for(int i=0;i<n;++i){
        pref[s[i]-'a'][i+1]++;
    }

    for(int i=0;i<26;++i){
        for(int j=1;j<=n;++j) pref[i][j]+=pref[i][j-1];
    }


    for(int i=0;i<q;++i){
        int l,r;cin>>l>>r;

        l--,r--;

        if(l==r || s[l]!=s[r]){
            cout<<"Yes"<<endl;
            continue;
        }

        int cnt=0;
        for(int i=0;i<26;++i){
            if(pref[i][r+1]-pref[i][l]>0) cnt++;
        }

        if(cnt>2){
            cout<<"Yes"<<endl;
            continue;
        }

        cout<<"No"<<endl;

    }

}