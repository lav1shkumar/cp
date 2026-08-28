#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
hpm/(atk_y - def_m ) ceil value of it



b can be at max 200
c can be at max 100



*/
int a,b,c;
int x,y,z;
int l,m,n;


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c;
    cin>>x>>y>>z;

    cin>>l>>m>>n;


    int ans=LLONG_MAX;

    for(int i=b;i<202;++i){
        for(int j=c;j<=max(c,y);++j){
            
            int req_a = i-b;
            int req_d = j-c;
            
            int diff_m = max(0ll,i-z);
            int diff_y = max(0ll,y-j);

            if(diff_m==0) continue;

            int times = (x+diff_m-1)/diff_m;
            
            int dmg =  diff_y*times;
            dmg-=a;
            int req_hp = max(0ll,dmg+1);

            int total_price = req_hp*l + req_a*m + req_d*n;

            ans=min(ans,total_price);

        }

    }


    cout<<ans<<endl;


}
