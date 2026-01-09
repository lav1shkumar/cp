#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
dacb == dacb+acb+ab+a 


dacb == d>a? remove acb , a>c NO c>b YEs remove ==> ab after checking all just pop last char



abdb ==  abd
aacb = aab 

cab == cab+ab+a == len+len-1+len-2...1= (n*(n+1))/2;


*/


void solve(){
    string s;cin>>s;
    int pos;cin>>pos;

    int n=s.size();
    if(n>=pos){
        cout<<s[pos-1];
        return;
    }
    int seq=0; // 1 + 2 + 3 + 4 ... n
    while(pos>0){
        pos-=(n-seq);
        seq++;
    }
    seq--;
    pos=abs(pos);
    // we have to remove seq numbers from s
    // abs(pos)==position from last ==> (n-seq-1)-abs(pos)
    // find in which string it lies
    // total = n(n+1)/2 >=pos
    // cab  remove 2 elements = pick smallest
    // dacb == remove one element = acb , (4-1)-1-1 = 1 == c
    // to remove seq elements, stack
    stack<char> st;
    for(int i=0;i<n;++i){
        while(!st.empty() && s[i]<st.top() && seq>0){
            st.pop();
            seq--;
        }
        st.push(s[i]);
    }

    while(seq!=0 && !st.empty()){
        st.pop();
        seq--;
    }
    while(pos!=0 && !st.empty()){
        st.pop();
        pos--;
    }
    cout<<st.top();
   

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}