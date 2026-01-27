#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
i want all elements of b > a
greatest in b is 3, remove all x>=3 from a
i can use max heap



*/


void solve(){
    int n,m;cin>>n>>m;
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    pq1.push(1);

    for(int i=1;i<n;++i){
        int a;cin>>a;
        pq1.push(a);
    }
    for(int i=0;i<n;++i){
        int a;cin>>a;
        pq2.push(a);
    }

    int ans=0;
    while(!pq1.empty() && !pq2.empty()){

        while(!pq1.empty() && pq1.top()>=pq2.top()){
            pq1.pop();
        }

        if(!pq1.empty() && pq1.top()<pq2.top()){
            ans++;
            pq1.pop();
            pq2.pop();
        }
    }

    cout<<n-ans<<endl;

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