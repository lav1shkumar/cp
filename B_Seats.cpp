#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
0000100001000

1001 -- optimal
010   -- one
010010 -- two

three zeroes cons -- one req
i can split from 1 and start doing this 1001 thing
i can get no of zeroes from the indices of 1



*/


void solve(){
    int n;cin>>n;
    string s;cin>>s;

    vector<int> ones;
    for(int i=0;i<n;++i) {
        if(s[i]=='1') ones.push_back(i);
    }

    if(ones.empty()){
        cout <<(n+2)/3<<endl;
        return;
    }
    int cnt = ones.size();

    cnt += (ones[0]+1)/3;

    for(int i=0; i<ones.size()-1;++i) {
        int gap = ones[i+1]-ones[i]-1;
        cnt += gap/3;
    }

    int z = (n-1)-ones.back();
    cnt += (z+1)/3;

    cout<<cnt<<endl;

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