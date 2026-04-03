#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
1, 6, 8, 9

7 14 21 28 35 42 49
7 * n

1000 + 100 + 10 + 1
 6       2     3   1

*/
set<int> st;
vector<int> mods;
string ans;
int need;

long long binpow(long long a, long long b, long long MOD) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) 
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

bool perm(int idx,int mod,string cur){
    if(idx==4){
        if(mod%7==need){
            ans=cur;
            return true;
        }
        return false;
    }

    for(int v:{9,8,6,1}){
        if(st.count(v)) continue;
        st.insert(v);

        if(perm(idx+1,(mod+mods[idx]*v)%7,cur+char('0'+v))) return true;

        st.erase(v);
    }

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

    string s;cin>>s;
    int n=s.size();

    int z=0;
    string res="";

    vector<int> nums;
    for(char c:s){
        if(c=='0') z++;
        nums.push_back(c-'0');
    }

    for(int c:{1,6,8,9}){
        for(int i=0;i<nums.size();++i){
            if(nums[i]==c){
                nums.erase(nums.begin()+i);
                break;
            }
        }
    }

    vector<int> pow10(n);
    for(int i=0;i<n;++i){
        pow10[i] = binpow(10,i,7);
    }

    int idx=z;
    int M=0;
    while(z--) res.push_back('0');

    for(int v:nums){
        if(v==0) continue;
        M = (M+pow10[idx++]*v)%7;
        res.push_back(char(v+'0'));
    }

    mods.resize(4);
    for(int i=0;i<4;i++){
        mods[i] = pow10[idx+i];
    }
    reverse(mods.begin(),mods.end());

    need = (7-M)%7;

    perm(0,0,"");

    reverse(res.begin(),res.end());
    string final = ans+res;
    
    cout<<final;

}