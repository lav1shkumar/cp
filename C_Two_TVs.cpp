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


    int n;cin>>n;

    vector<pair<int,int>> coor(n);
    for(int i=0;i<n;++i) cin>>coor[i].first>>coor[i].second;

    if(n<3){
        cout<<"YES"<<endl;
        return 0;
    }

    sort(coor.begin(),coor.end());

    vector<bool> toggle(n,0);

    for(int i=1;i<n;++i){
        auto [k,j] = coor[i-1];
        auto [a,b] = coor[i];    

        k=max(k,a);
        j=min(j,b);

        if(k>j){
            toggle[i]=toggle[i-1];
        }
        else{
            toggle[i]=!toggle[i-1];
        }

    }

    int l=LLONG_MAX,r=0;
    int l1=LLONG_MAX,r1=0;

    for(int i=0;i<n;++i){
        auto [x,y]=coor[i];

        if(!toggle[i]){
            l=max(l,x);
            r=min(r,y);

            if(r>=l){
                cout<<"NO"<<endl;
                return 0;
            }
            l=x,r=y;
        }

        else{
            l1=max(l1,x);
            r1=min(r1,y);

            if(r1>=l1){
                cout<<"NO"<<endl;
                return 0;
            }
            l1=x,r1=y;

        }

    }
    cout<<"YES"<<endl;

}
