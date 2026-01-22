#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
Anna - pick an ele and reverse

Sasha - pick two ele and :
                            a+b | b+a
                            size will dec by 1

in the end when size==1 game ends
if that ele >=10^m , Sasha wins else Anna


sasha will try to maximize and anna minimize
anna can pick ele with zero at last, so it can be reduced, else largest element
basically largest element?

sasha will pick the 2 smallest and mergee then big + small format


i just need to track no of zeroes

1 2007 800 1580
1 2007 800 851
1 8512007 800
1 8512007 8
88512007 1
70021588 1

9 56 1
9 65 1
659 1
6591


for anna if last zero exist then only makes sense to move
will only track digits

1 1
10

1 2007 800 1580
1 2007 8 1580
15808 1 2007


*/


void solve(){
    int n,m;cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    vector<int> zeros;

    int ans=0;

    for(int v:arr){
        string s = to_string(v);
        int size=s.size();
        int z=0;

        for(int i=size-1;i>=0;--i){
            if(s[i]=='0') z++;
            else break;
        }
        zeros.push_back(z);
        ans+=size-z;
    }

    sort(zeros.rbegin(),zeros.rend());
    for(int i=0;i<n;++i){
        if(i&1) ans+=zeros[i];
    }

    if(ans>=m+1){
        cout<<"Sasha"<<endl;
    }
    else cout<<"Anna"<<endl;


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