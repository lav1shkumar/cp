#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
maybe i can do it with 2 weights if and only if, 2x>y, x is smaller wt
but -- 
then 3x>2y
     4x>3y

     this will continue till m used
     so if i use smaller one in first == either equal or grt by 1
                                         (m+1)/2*x    (m-1)/2*y
                                        
                                         now it depends on m: 
                                            if m==3 then 2x>y
                                            if m==100 then 50x>49y
                                            
                                            but why using 2 optimal??

we only care about prev used and diff:
                                    if m==100 then 50x>49y
                                    what is optimal here, 50 in first and 49 in second one
                                    okay this is wrong anyway

think of some n square * 10 solution
dp?



*/

vector<int> wt;
vector<int> ans;
int m;

bool solve(int i,int diff){
    if(i==m) return true;

    for(int v:wt){
        if(v>diff){
            if(!ans.empty() && v==ans.back()) continue;
            ans.push_back(v);
            if(solve(i+1,v-diff)) return true;
            ans.pop_back();
        }
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
    cin>>m;

    for(int i=0;i<10;++i) if(s[i]=='1') wt.push_back(i+1);


    if(solve(0,0)){
        cout<<"YES\n";
        for(int v:ans) cout<<v<<" ";
    }
    else cout<<"NO";
}