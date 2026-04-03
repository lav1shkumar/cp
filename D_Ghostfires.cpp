#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
lets be greedy here, pick the one has highest, if possible


upper bound on vig = trwo small + 1



*/

void solve(){
    int x,y,z;cin>>x>>y>>z;


    int r = min(x,y+z+1);
    int g = min(y,x+z+1);
    int b = min(z,x+y+1);


    vector<pair<int, char>> v = {{r,'R'},{g,'G'},{b,'B'}};
    sort(v.rbegin(), v.rend());
    
    int t = r+g+b;
    string ans(t,' ');
    int o = (t)/2;


    vector<int> seq;

    int canOdd = -1;

    for(int i=0;i<3;++i){
        if(v[i].first==o) canOdd=i;
    }

    if(canOdd!=-1){
        swap(v[canOdd],v[2]);        
    }

    int l = (t%2!=0)?t-1:t-2;
    int k = (t%2!=0)?t-2:t-1;

    for(int i=l;i>=0;i-=2) seq.push_back(i);
    for(int i=k;i>=1;i-=2) seq.push_back(i);




    int i=0;

    for(auto [cnt,c]:v){
        while(cnt--) ans[seq[i++]]=c;

    }

    cout<<ans<<endl;
    
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