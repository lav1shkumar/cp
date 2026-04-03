#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
int x,y;
int t1,t2;
int n;
string s;
vector<int> prefx,prefy;
bool check(int d){
    int a = prefx[n]*(d/n) + prefx[d%n]+x;
    int b = prefy[n]*(d/n) + prefy[d%n]+y;


    int remainb = abs(t2-b);
    int remaina = abs(t1-a);

    //cout<<remaina<<" "<<remainb<<" "<<d<<endl;

    if(remaina+remainb <= d) return true;

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

    cin>>x>>y;
    cin>>t1>>t2;
    cin>>n;
    cin>>s;

    prefx.assign(n+1,0);
    prefy.assign(n+1,0);

    unordered_map<char,int> mpx,mpy;
    mpx['L'] = -1;
    mpx['R'] = 1;
    mpx['U'] = 0;
    mpx['D'] = 0;

    mpy['U'] = 1;
    mpy['D'] = -1;
    mpy['L'] = 0;
    mpy['R'] = 0;
    

    for(int i=0;i<n;++i){
        prefx[i+1] = prefx[i] + mpx[s[i]];
        prefy[i+1] = prefy[i] + mpy[s[i]];
    }


    int l=0,r=1e16+1;
    int ans=-1;

    while(r>=l){
        int mid=(l+r)/2;

        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;

    }

    cout<<ans<<endl;

}