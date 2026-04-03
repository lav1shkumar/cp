#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
struct SegmentTree{
    int n;
    vector<int> tree,lazy,lazyset;

    SegmentTree(vector<int> &arr){
        n=arr.size();
        tree.assign(4*n,0);
        lazy.assign(4*n,0);
        lazyset.assign(4*n,-1);
        build(1,0,n-1,arr);
    }

    void applyset(int node,int i,int j,int val){
        tree[node]=val*(j-i+1);
        lazyset[node]=val;
        lazy[node]=0;
    }


    void applyadd(int node,int i,int j,int val){
        tree[node]+=val*(j-i+1);
        lazy[node]+=val;
    }
    

    void push(int node,int i,int j){

        if(i==j){
            lazyset[node]=-1;
            lazy[node]=0;
            return;
        }
        int mid=(i+j)/2;

        if(lazyset[node]!=-1){
            applyset(2*node,i,mid,lazyset[node]);
            applyset(2*node+1,mid+1,j,lazyset[node]);
        }

        if(lazy[node]!=0){
            applyadd(2*node,i,mid,lazy[node]);
            applyadd(2*node+1,mid+1,j,lazy[node]);
            
        }
        lazy[node]=0;
        lazyset[node]=-1;

        return;
    }


    void build(int node,int l,int r,vector<int> &arr){
        if(l==r){
            tree[node]=arr[l];
            return;
        }
        
        int mid = (l+r)/2;

        build(2*node,l,mid,arr);
        build(2*node+1,mid+1,r,arr);

        tree[node] = tree[2*node] + tree[2*node+1];

    }

    void update(int node,int i,int j,int l,int r,int val){
        push(node,i,j);

        if(l>j || i>r) return;

        if(i>=l && r>=j){
            applyadd(node,i,j,val);
            return;
        }

        int mid = (i+j)/2;


        update(2*node,i,mid,l,r,val);
        update(2*node+1,mid+1,j,l,r,val);
        
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update_set(int node,int i,int j,int l,int r,int val){
        push(node,i,j);

        if(l>j || i>r) return;

        if(i>=l && r>=j){
            applyset(node,i,j,val);
            return;
        }

        int mid = (i+j)/2;


        update_set(2*node,i,mid,l,r,val);
        update_set(2*node+1,mid+1,j,l,r,val);
        
        tree[node] = tree[2*node] + tree[2*node+1];
    }


    int query(int node,int i,int j,int l,int r){
        push(node,i,j);
        
        if(l>j || i>r) return 0;

        if(i>=l && r>=j){
            return tree[node];
        }


        int mid = (i+j)/2;

        return query(2*node,i,mid,l,r) + query(2*node+1,mid+1,j,l,r);
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

    int n,q;cin>>n>>q;


    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    SegmentTree seg(arr);

    for(int i=0;i<q;++i){
        int t;cin>>t;

        if(t==1){
            int a,b,c;cin>>a>>b>>c;
            a--,b--;
            seg.update(1,0,n-1,a,b,c);
        }

        if(t==2){
            int a,b,c;cin>>a>>b>>c;
            a--,b--;
            seg.update_set(1,0,n-1,a,b,c);

        }

        if(t==3){
            int a,b;cin>>a>>b;
            a--,b--;
            cout<<seg.query(1,0,n-1,a,b)<<endl;
        }

    }
}

