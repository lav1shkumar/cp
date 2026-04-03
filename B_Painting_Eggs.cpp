#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

|totala - totalb| <=500
| sum of some a's - sum of some b's| <=500
pick all a, then try to reduce a

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

    int k=0;
    priority_queue<tuple<int,int,int>> pq;

    for(int i=0;i<n;++i){
        int x,y;cin>>x>>y;
        k+=x;
        pq.push({x,y,i});
    }

    int p=0;
    string ans(n,'A');

    while(!pq.empty() && abs(k-p)>500){
        auto [a,b,i] = pq.top();
        pq.pop();

        k-=a;
        p+=b;

        ans[i]='G';
    }

    if(abs(k-p)<=500){
        cout<<ans<<endl;
    }
    else cout<<-1<<endl;


}