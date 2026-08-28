#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

abs a-b min
b should only contain these two dig given

dig by dig, i will try to pick the dig closer to a[i] right?

len of b can be equal to a, or +-1
yep

if(len-1) then pick the max dig
if(len+1) pick the min dig

if equal, then check: go for closest possible available dig ig
but what if there are two numbers both side, 2 -- 1and3, gotta check both then
poss comb = 2*18 hmmm 

okay, so get closed smaller and rest biggest
else closest bigger and rest smaller

so can we check all like this?
maybe i can start from a and go like both dir to find suitable b



maybe i can do dp here? hmm can solve c2 with it ig too


*/
int len;
string s;
int ans;
int a;
vector<int> d;

void update(string s){
    if(s.empty()) return;

    __int128 val = 0;
    for(char c:s){
        val = val*10 + (c-'0');
    }

    __int128 res = a;
    __int128 diff = val>res? val-res : res-val;

    if(diff<ans) ans = diff;
}


void samelen(int idx,string num){
    if(idx==len){
        if(num=="") return;
        update(num);
        return;
    }

    int x = s[idx]-'0';

    int smaller =-1;
    int bigger =-1;

    for(int v:d){
        if(idx==0 && len>1 && v==0) continue;

        if(v<x) smaller = v;
        if(v>x && bigger==-1) bigger=v;
    }

    if(smaller!=-1){
        string temp = num;
        temp.push_back(smaller+'0');

        while(temp.size()<len){
            temp.push_back(d.back()+'0');
        }

        update(temp);
    }

    if(bigger!=-1){
        string temp = num;
        temp.push_back(bigger+'0');

        while(temp.size()<len){
            temp.push_back(d[0]+'0');
        }

        update(temp);
    }

    bool same=false;

    for(int v:d){
        if(v==x) same=true;
    }

    if(idx==0 && len>1 && x==0) same=false;

    if(same){
        num.push_back(x+'0');
        samelen(idx+1,num);
        num.pop_back();
    }
}



void solve(){
    int n;cin>>a>>n;

    ans=LLONG_MAX;
    
    d.assign(n,0);
    for(int i=0;i<n;++i) cin>>d[i];

    s = to_string(a);
    len=s.size();

    string biggest = "",smallest="";

    for(int i=0;i<len-1;++i) biggest.push_back(d.back()+'0');
    
    int dig=-1;

    for(int v:d){
        if(v!=0) {
            dig=v;
            break;
        }
    }

    if(dig!=-1) {
        smallest.push_back(dig+'0');
        while(smallest.size()<len+1) {
            smallest.push_back(d[0]+'0');
        }
    }


    update(smallest);
    update(biggest);

    samelen(0,"");

    cout<<ans<<endl;


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