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

        string s1;cin>>s1;
        string s2;cin>>s2;
        int k;cin>>k;

        int n=s1.size();

        int ans=0;

        unordered_set<int> st;


        int base1=27,base2=28;
        int mod1=1e9+7,mod2=1e9+9;
        

        for(int i=0;i<n;++i){
            int hash1=0,hash2=0;

            int cnt=0;
            for(int j=i;j<n;++j){
                int id = s1[j]-'a'+1;

                hash1 = (hash1*base1+id)%mod1;
                hash2 = (hash2*base2+id)%mod2;

                if(s2[s1[j]-'a']=='0') cnt++;

                int mix = hash1*mod2 + hash2;

                if(st.count(mix)) continue;

                if(cnt<=k) ans++;
                else break;

                st.insert(mix);

            }

        }

        cout<<ans<<endl;

    }