#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
3 1 5 3 == YES (sumofpairs== sumofdiff)

2 3 1 

wait i can do sum-2 in one op,, so if sum is even i can make it zero;

1 2 3 4 5 6 == odd
1 2 3 4 == even so , 0 2 2 4 , 0 0 0 0

so sum should be even and?

3 2 7 == 12 even == NO

okay, there could be a single element left hmmm
so any single element should not be greater than sum of the others;






*/



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;++i){
        cin>>arr[i];
        sum+=arr[i];
    }

    for(int i=0;i<n;++i){
        int left=sum-arr[i];
        if(arr[i]>left){
            cout << "NO" <<endl;
            return 0;
        }
    }

    if(sum&1){
        cout << "NO" <<endl;
    }
    else cout << "YES" <<endl;

}