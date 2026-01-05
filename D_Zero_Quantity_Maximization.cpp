#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
ci = d*ai+bi
ci==0 ,, d*ai==bi , d=bi/ai

so, bi/ai=di, 1 2.1 2 3 6 1
most occuring 1, do d==1, i have to use long double
wait handle ai=0, if bi==0 then only zero possible okay



*/



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    vector<long double> a(n);
    vector<long double> b(n);
    vector<long double> c(n,LLONG_MAX);

    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];

    for(int i=0;i<n;++i){
        if(a[i]!=0){
            c[i]=b[i]/a[i];
        }
    }
    int maxi = 0;
    unordered_map<long double,int> mp;
    for(int i=0;i<n;++i){
        if(c[i]==LLONG_MAX) continue;
        mp[c[i]]++;
        maxi=max(maxi,mp[c[i]]);
    }
    for(int i=0;i<n;++i){
        if(a[i]==0 && b[i]==0) maxi++; 
    }

    cout << maxi <<endl;



}
