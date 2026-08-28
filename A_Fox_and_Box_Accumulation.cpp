#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
arguments: 
        pile with > streanth should be below


0 1 0 2 0 1 1 2 10

10 2 2 1 1 1 0 0 0

--- 10 2 2 1
--- 1 1
--- 0
--- 0
--- 0

put zero on top

--- 10 2 1 0
--- 2 1 0
--- 1 0

try to put ideal one basically, lowerbound

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
    
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];


    sort(a.begin(),a.end());

    vector<int> ans;

    for(int i=0;i<n;++i){
        int v = a[i];

        bool ok=false;
        for(int &u:ans){
            if(v>=u){
                u++;
                ok=true;
                break;
            }


        }

        if(!ok) ans.push_back(1);
    }               

    cout<<ans.size();

}