#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
try to equilize both sides or +-1 if odd


*/


void solve(){
    int n,m;cin>>n>>m;

    int total=0;
    vector<vector<int>> grid(n,vector<int> (m));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>grid[i][j];
            total+=grid[i][j];
        }
    }

    int ans= (total/2) * ((total+1)/2);

    vector<vector<int>> pref(n,vector<int> (m));

    for(int i=0;i<n;++i){
        pref[i][m-1]=grid[i][m-1];
        for(int j=m-2;j>=0;--j) pref[i][j]= pref[i][j+1] + grid[i][j];
    }

    cout<<ans<<endl;

    int r=0,c=0;

    int curr=0;

    while(r!=n && c!=m){

        // try to go down
        if(curr+pref[r][c]>(total/2)){
            cout<<"R";
            c++;
        }
        else{
            curr+=pref[r][c];
            cout<<"D";
            r++;
        }

    }

    while(r!=n){
        cout<<"D";
        r++;
    }
    while(c!=m){
        cout<<"R";
        c++;
    }

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