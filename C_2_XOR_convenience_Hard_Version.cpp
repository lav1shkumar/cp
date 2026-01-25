    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    const int MOD = 1e9+7;


    // Observations
    /*
    pi = pj^i
    pi^i = pj
    p == 1 to n

    x^i == y
    y after x




    011111111

    1 1 
    2 3 = 1
    3 2 = 1
    4 5 = 1
    5 4 = 1

    then put 1 to the end
    4 3 2 5 1 

    1 
    2 3
    3 2
    4 

    1 3 2 4 , swap
    4 3 2 1


    hard ver:
    if i xor x^1 ==  011010 ^ 000001 == 011011, flip last bit
    0100 ^ 0001 == 0101 = 5, even == +1 , odd == -1

    1 
    2 3
    3 2
    4 
    4 3 2 1

    if perm[0]==n and even then not pos?
    wait its wrong fore n==6
    6 3 2 5 4 1 and 3 6 2 5 1 4 both true for easy version
    if(perm[0]==n && !(n&1)) we try something:
                                    can we find it a diff position where its xor reduces to good range
                                    n ^ x = less than n
                                    110 ^ 010 done
                                    100 ^ 001 101 nope
                                    110
                                    wait if n has 2 or more bits i can do it

                                    110 ^ 100 = 010 == 2
                                    if i put 010 to pos 100 then their xor will be 110
                                    wait i need to make sure, 

                                    110 ^ 010 = 100 ,
                                    wait in this way, it works
                                    xor will be grater than i



                                    
                    

    */


    void solve(){
        int n;cin>>n;
        vector<int> perm(n);
        for(int i=1;i<=n;++i) perm[i-1]=i;

        for(int i=1;i<(n-1);i+=2) swap(perm[i],perm[i+1]);
        swap(perm[0],perm[n-1]);

        if(perm[0]==n && !(n&1)){
            int b = __builtin_popcountll(n);
            if(b==1){
                cout<<-1<<endl;
                return;
            }
            int lsb=0;
            for(int i=0;i<32;++i){
                if(n&(1<<i)){
                    lsb=(1<<i);
                    break;
                }
            }
            swap(perm[0],perm[lsb-1]);
        }
        for(int val:perm) cout<< val<< " ";
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