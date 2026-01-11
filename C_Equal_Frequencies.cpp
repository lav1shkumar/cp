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


void solve(){
    int n;cin>>n;
    string s;cin>>s;

    vector<int> freq(26,0);
    for(char c:s) freq[c-'a']++;
    // now i have freq
    vector<pair<int,int>> mp;
    for(int i=0;i<26;++i){
        mp.push_back({freq[i],i});
    }
    sort(mp.begin(),mp.end(),[](auto &a,auto &b){
        if(a.first!=b.first) return a.first>b.first;
        else return b.second>a.second;
    });

    int unique_ele=0;
    int change = 0;
    int prev=0;
    for(int i=1;i<=26;++i){
        if(n%i) continue;
        int curr=0;
        for(int j=0;j<i;++j){
            curr+=min(n/i,mp[j].first);
        }
        if(curr>prev){
            unique_ele=i;
            prev=curr;
            change=n-curr;
        }
    }
    // now we have needed unique elements
    cout<<change<<endl;
    int size = n/unique_ele;

    map<char,int> mp1;
	for (int i=0;i<unique_ele;++i) mp1[char(mp[i].second+'a')]=size;

    string ans(n,' ');
    for(int i=0;i<n;++i){
        if(mp1[s[i]]>0){
            ans[i]=s[i];
            mp1[s[i]]--;
        }
    }
    // now assign
    for(char &c:ans){
        if(c==' '){
            while(!mp1.empty() && (*mp1.begin()).second==0) mp1.erase(mp1.begin());
            char newc=(*mp1.begin()).first;
            c=newc;
            mp1[c]--;
        }
        cout<<c;
    }
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