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

    int n,m;cin>>n>>m;    


    if(m<n-1 || m>2*(n+1)){
        cout<<-1<<endl;
        return 0;
    }

    if(n>m){
        cout<<"0";
        n--;
    }


    while(m>0 || n>0){
        if(m>n && n>0){
            cout<<"110";
            m-=2;
            n--;
        }
        else if(m==n && n>0){
            cout<<"10";
            m--;
            n--;
        }
        else{
            while(m>0){
                cout<<"1";
                m--;
            }
        }
    }
    cout<<endl;
    return 0;



}