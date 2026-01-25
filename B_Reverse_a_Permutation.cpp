#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
3 2 1 4

4 1 2 3 

one operation only
just see start and end
wait we search idx n and put it to the front
if already their then next
4 3 2 1

*/


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    int idx=-1;
    for(int i=0;i<n;++i){
        if(arr[i]!=(n-i)){
            idx=i;
            break;
        }
    }

    if(idx!=-1){
        int j;
        // we search for n-i?
        for(int i=0;i<n;++i){
            if(arr[i]==n-idx){
                j=i;
                break;
            }
        }

        if(idx>j) swap(idx,j);
        while(j>idx){
            swap(arr[j],arr[idx]);
            idx++;
            j--;
        }
    }

    for(int val:arr) cout<<val<<" ";
    cout<<endl;






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