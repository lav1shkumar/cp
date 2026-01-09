#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
op -- 
    pick i where i<=i+1
    okay so i cant pick the last element at n-1
    i can increase

5 6
1 3 6 5 1

1 3 6 5 1
can i pick 5 no, 4 yes make it 6 = 2 operation

1 3 6 5 1
1 7 6 5 1 === 4op k==0 now , max==7


5 6
6 5 4 1 5

basically pick the largest element which is not the first == 5 and 5
1 to 6 in 5 op
if(i<=i+1) i can be at max i+1+1


so basically you try to equalize them and spread
7 6 5 4 5 

5 6

can we make 7
6 5 4 1 5 
7 6 5 4 3   diff = 1+1+1+3+0 = 6<=k done
we can try for all positions as the time limit is larger n square , popb n^2logn is good
make 8


1 to 6, or just do 1 to 4
can be make some ans, thats the question then we can bs



*/
vector<int> arr;

bool check(int x,int k){
    int maxi = *max_element(arr.begin(),arr.end());
    if(x<=maxi) return true;

    int n=arr.size();
    for(int i=0;i<n;++i){
        // make arr[i]==x rest x-2,x-2,x-3 and so on
        int req_k=0;
        for(int j=i,y=x;j<n;++j,y--){
            if(arr[j]>=y) break;
            req_k+=y-arr[j];
            if(j==n-1) req_k+=1e9;
        }
        if(req_k<=k) return true;
    }
    
    return false;
}


void solve(){
    int n,k;cin>>n>>k;
    arr.assign(n,0);
    for(int i=0;i<n;++i) cin>>arr[i];
    
    int i=1,j=2*(1e8+1);

    while(j>i){
        int mid=(i+j+1)/2;
        if(check(mid,k)) i=mid;
        else j=mid-1;
    }

    cout<<j<<endl;
    //wrong answer 30th numbers differ - expected: '100000001', found: '100000000'

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}