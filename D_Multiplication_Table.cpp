#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
for every ro we can see how many ele less than x, so bs



*/
int n,m,k;
bool check(int x){
    int cnt=0;
    for(int i=1;i<=n;++i){
        int t = (x-1)/i;
        cnt+=min(t,m);
    }

    if(cnt<k) return true;
    return false;
}


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;

    int l=1,r=n*m;

    int ans=0;
    while(r>=l){
        int mid = (l+r)/2;

        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    cout<<ans<<endl;

}