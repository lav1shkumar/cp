#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
basically find arr contiguious block which hax max mul

wait: is it like max subarray sum type problem but with mul?
hmmm
i can use ssame approach then, first find that max mul

1 2 -1 2   == 2 is the max
then i can iter to see the window
lol can't due to negative nums

there's arr hard limit of element, can i utilize it?

first of all zero is not acceptable, we can always remove all element and get 1
0 should be not in the window

then i can count 2's and negatives
pick one with max 2's
try to make it positive by removing from left or right

maybe i have same 2's but other is neg, then pick pos one

*/


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;++i) cin>>arr[i];

    int best2=0,bx=0,by=n;

    for(int i=0;i<n;){
        if(arr[i]==0){
            i++;
            continue;
        }

        int L=i;
        while(i<n&&arr[i]!=0) i++;
        int R=i-1;

        int tot2=0,neg=0;
        for(int j=L;j<=R;j++){
            if(abs(arr[j])==2) tot2++;
            if(arr[j]<0) neg++;
        }

        if(neg%2==0){
            if(tot2>best2){
                best2=tot2;
                bx=L;
                by=n-1-R;
            }
        }else{
            int fn=-1,ln=-1;

            for(int j=L;j<=R;j++)if(arr[j]<0){
                fn=j;
                break;
            }
            for(int j=R;j>=L;j--)if(arr[j]<0){
                ln=j;
                break;
            }

            int cutL=0;
            for(int j=L;j<=fn;j++)if(abs(arr[j])==2) cutL++;

            int cutR=0;
            for(int j=ln;j<=R;j++)if(abs(arr[j])==2) cutR++;

            int keepL=tot2-cutL,keepR=tot2-cutR;

            if(keepL>=keepR){
                if(keepL>best2){
                    best2=keepL;
                    bx=fn+1;
                    by=n-1-R;
                }
            }else{
                if(keepR>best2){
                    best2=keepR;
                    bx=L;
                    by=n-ln;
                }
            }
        }
    }
    cout<<bx<<" "<<by<<endl;
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