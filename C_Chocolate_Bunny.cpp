#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
a % b == a if b>a 
else if(a>b):
        it will be less than b, hence less than a too
so i can query both, whenever i get the biggest one, thats the ans?

either a>b or a<b



*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    
    vector<int> perm(n);
    int l=0,r=n-1;
    int idx=-1;
    set<int> st;
    while(r>=l){
        if(r==l){
            idx=r;
            break;
        }
        cout<<"? "<<l+1<<" "<<r+1<<endl;
        cout.flush();
        int a;cin>>a;
        cout<<"? "<<r+1<<" "<<l+1<<endl;
        cout.flush();
        int b;cin>>b;
        
        if(a>b){ // means l was bigger
            st.insert(a);
            perm[l]=a;
            l++;
        }
        else{ // means r was bigger
            st.insert(b);
            perm[r]=b;
            r--;
        }
    }
    if(idx!=-1){
        for(int i=1;i<=n;++i){
            if(st.count(i)==0){
                perm[idx]=i;
                break;
            }
        }
    }
    cout<<"! ";
    for(int v:perm) cout<<v<<" ";
    cout<<endl;
    cout.flush();

}