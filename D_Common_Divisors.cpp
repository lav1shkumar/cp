#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1,s2;cin>>s1>>s2;
    if(s1.size()>s2.size()) swap(s1,s2);

    int n=s1.size();
    int m=s2.size();

    vector<int> div;

    for(int i=1;i*i<=n;++i){

        if(n%i==0){
            if(m%i==0) div.push_back(i);
            if(i*i!=n){
                int t=n/i;
                if(m%t==0) div.push_back(t);
            }

        }
    }



    int cnt=0;

    for(auto n:div){
        //cout<<n<<" ";

        string pat;
        for(int i=0;i<n;++i){
            pat.push_back(s1[i]);
        }

        int times = s1.size()/n;
        
        string t;
        for(int i=0;i<times;++i){
            t+=pat;
        }

        if(t!=s1){
            continue;
        }

        if(s2.size()%n==0){
            int times = s2.size()/n;

            string t;
            for(int i=0;i<times;++i){
                t+=pat;
            }

            if(t==s2) cnt++;

        }


    }

   cout<<cnt<<endl;

}