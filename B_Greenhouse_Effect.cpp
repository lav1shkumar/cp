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

    int n,m;
    cin>>n>>m;

    vector<int> a(n);


    for(int i=0;i<n;++i){
        int s;cin>>s;
        s--;
        double pos;cin>>pos;
        a[i]=s;
    }
    
    vector<int> lis;

    for(int i=0;i<n;++i){
        int v=a[i];

        if(!lis.empty()){
            if(lis.back()<=v) lis.push_back(v);
            else{
                int idx = upper_bound(lis.begin(),lis.end(),v)-lis.begin();
                lis[idx]=v;
            }
        }
        else lis.push_back(v);
    }
    
    cout<<n-lis.size();
}