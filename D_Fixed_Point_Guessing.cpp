#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
1 2 3 4 5 6 7 , n==odd

7 4 5 2 3 6 1 == 6 remain

query to find 6 == 1 to mid and mid to n
                    right part will be where only 1 element match the range i believe
                    here -- 4 to 7 , 2 3 6 1, only 6 is the matching range
                    ans will be when we reach l==r , l will be the ans
                    
need a check func to check no of mismatch



*/
bool check(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();
    int s=r-l+1;
    int cnt=0;
    for(int i=0;i<s;++i){
        int a;cin>>a;
        if(a>=l && a<=r) cnt++;
        
    }
    return cnt&1;
}

void solve(){
    int n;cin>>n;
    // interaction

    cout.flush();
    int l=1,r=n;

    while(r>l){
        int mid=(l+r)/2;
        if(check(l,mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<"! "<<l<<endl;
    cout.flush();
    

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