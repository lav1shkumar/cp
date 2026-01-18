#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
-- possble freq will be n%freq==0
-- so i can grab all the divisor of n, those are the possible ones

4
5
hello
10
codeforces
5
eevee
6
appall

codeforces = total unique char = codefrs == 7 = max(26) so from 1 to 26
n = 10
possible freq = 1,2,5 
c=2
o=2
e=2
d=1
f=1
r=1
s=1

unchanged+ = min(freq,n/k) 
for k==5, so unchanged = 2,2,2,1,1 == 8 , change need = n - unchanged = 2
correct


*/

int alternatingXOR(vector<int> nums, int target1, int target2) {
    // 1 | 2 | 1 | 2 -- xors
    // if ind i is the partition idx, what will be the ans?
    // can i greedily do this? 
    // find first one, then check for second, i need to count 
    // if a^b^c = x that means?
    // i usually struggle in these prob, need to practice more fukk

    // prefix xor works?? 
    int n=nums.size();
    vector<int> pref(n);
    pref[0]=nums[0];
    for(int i=1;i<n;++i){
        pref[i]=pref[i-1]^nums[i];
    }

    // can use it
    // for some idx, if i found target1,
    // can we use map to count these?
    map<int,int> cnt1;
    map<int,int> cnt2;

    // if cuts at i,j,k
    // pref[i]=target1
    // pref[j]^pref[i]=tyarget2

    cnt2[0]=1;

    int ans =0;

    int x=0;
    for(int val:nums){
        x^=val;

        int end0 = cnt2[x^target1];
        int end1 = cnt1[x^target2];

        cnt1[x] = (cnt1[x]+end0)%MOD;
        cnt2[x] = (cnt2[x]+end1)%MOD;

        ans = (end0+end1)%MOD;
        
    }

    return ans;


    
}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int ans = alternatingXOR({1,1,1,1,1,1},1,0);
    cout<<ans<<endl;

}