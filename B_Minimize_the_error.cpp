#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k1,k2;cin>>n>>k1>>k2;
    vector<int> a1(n);
    vector<int> a2(n);
    vector<int> diff(n);
    for(int i=0;i<n;++i) cin>>a1[i];
    for(int i=0;i<n;++i) cin>>a2[i];


    priority_queue<int> pq;
    for(int i=0;i<n;++i) pq.push(abs(a1[i]-a2[i]));
    int op=k1+k2;

    while(op!=0 &&pq.top()!=0){
        int maxi=pq.top();
        pq.pop();
        op--;
        maxi--;
        pq.push(maxi);
    }
    if(op!=0){
        if(op&1){
            cout<<1<<endl;
            return 0;
        }
        else{
            cout<<0<<endl;
            return 0;
        }
    }
    int ans=0;
    while(!pq.empty()){
        ans+=pq.top()*pq.top();
        pq.pop();
    }
    cout<<ans<<endl;

}