#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
int nb,ns,nc;
int pb,ps,pc;
string s;
int r;


bool check(int x){
    __int128 a=0,b=0,c=0;

    for(char ch:s){
        if(ch=='S') b++;
        else if(ch=='B') a++;
        else c++;
    }

    __int128 req_b = max((__int128)0,((__int128)x*a - nb)*pb);
    __int128 req_s = max((__int128)0,((__int128)x*b - ns)*ps);
    __int128 req_c = max((__int128)0,(__int128)(x*c - nc)*pc);

    //cout<<req_b<<" "<<req_s<<" "<<req_c<<" "<<x<<endl;
    
    if(req_b+req_c+req_s>r) return false;
    return true;
}



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;


    cin>>r;


    int i=0,j=1e17+1;
    int ans=0;

    while(j>=i){
        int mid = (i+j)/2;

        if(check(mid)){
            ans=mid;
            i=mid+1;
        }
        else j=mid-1;

    }

    cout<<ans;


}
