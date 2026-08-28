#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    string s;cin>>s;

    int open=0,close=0;
    for(char c:s){
        if(c=='(') open++;
        else if(c==')') close++;
    }

    int req = s.size()/2-open;

    open=-1,close=-1;

    for(int i=0;i<s.size();++i){

        if(s[i]=='?'){
            if(req>0){
                s[i]='(';
            }
            else s[i]=')';
            req--;

            if(req==0) open=i;
            if(req==-1) close=i;
        }
    }

    if(open==-1 || close==-1){
        cout<<"YES"<<endl;
        return;
    }

    swap(s[open],s[close]);

    stack<char> st;

    for(int i=0;i<s.size();++i){
        if(!st.empty() && st.top()=='(' && s[i]==')'){
            st.pop();
            continue;
        }
        st.push(s[i]);
    }

    if(st.size()){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;


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