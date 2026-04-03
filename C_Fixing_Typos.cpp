#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
aaa 



*/



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

    if(n<3){
        cout<<s<<endl;
        return 0;
    }   

    string ans="";
    ans.push_back(s[0]);
    ans.push_back(s[1]);
    
    for(int i=2;i<n;++i){
        int x=ans.size();

        if(s[i]==ans[x-1] && s[i]==ans[x-2]){
            continue;
        }

        ans.push_back(s[i]);
    }

    if(ans.size()>3){
        string ans2="";
        ans2.push_back(ans[0]);
        ans2.push_back(ans[1]);
        ans2.push_back(ans[2]);
        for(int i=3;i<ans.size();++i){
            int x=ans2.size();
            if(ans[i]==ans2[x-1] && ans2[x-2]==ans2[x-3]){
                continue;
            }

            ans2.push_back(ans[i]);
        }
        cout<<ans2<<endl;
        return 0;
        
    }

    cout<<ans<<endl;

    
}