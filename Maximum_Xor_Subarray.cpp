#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
struct Node{
    int cnt;
    Node* arr[2];

    Node(){
        cnt=0;
        arr[0]=arr[1]=NULL;
    }


};

struct Trie{
    Node* root;
    Trie(){
        root=new Node();
    }



    void add(int x){
        Node* cur = root;
        for(int b=32;b>=0;--b){
            int bit = (x>>b)&1;

            if(cur->arr[bit]==NULL){
                cur->arr[bit]=new Node();
            }

            cur=cur->arr[bit];
            cur->cnt++;

        }
    }

    int query(int x){
        int ans=0;

        Node* cur = root;
        for(int b=32;b>=0;--b){
            int bit = (x>>b)&1;

            if(cur->arr[!bit]==NULL || cur->arr[!bit]->cnt<=0){
                cur=cur->arr[bit];
            }
            else{
                cur=cur->arr[!bit];
                ans|=(1<<b);
            }

        }

        return ans;
    }

    void remove(int x){
        Node* cur = root;
        for(int b=32;b>=0;--b){
            int bit = (x>>b)&1;
            cur=cur->arr[bit];
            cur->cnt--;
        }

    }

};


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    // xor at pos, pref xor max
    vector<int> pref(n);
    pref[0]=a[0];
    for(int i=1;i<n;++i) pref[i]= pref[i-1]^a[i];

    Trie trie;
    trie.add(0);

    int maxi=INT_MIN;
    for(int r=0;r<n;++r){
        int x = trie.query(pref[r]);

        trie.add(pref[r]);
        maxi=max(maxi,x);
    }

    cout<<maxi<<endl;




}