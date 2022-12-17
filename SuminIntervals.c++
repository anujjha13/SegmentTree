#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    
    public :
    vector<int> tree;
    vector<int> arr;
    
    int query(int l,int r){
        return query(1,0,arr.size()-1,l,r);
    } 
    
    void update(int pos,int val){
        update(1,0,arr.size()-1,pos,val);
    }
    
    
    SegmentTree(vector<int> num){
        arr=num;
        vector<int> temp(4*num.size(),0);
        tree=temp;
        build(1,0,num.size()-1);
        
    }
    
    
    
    void build(int node,int start ,int end){
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        
        int mid = (start+end)/2;
        
        int left=node*2;//kyunki first node i.e root is marked as 1
        int right=node*2+1;//kyunki first node i.e root is marked as 1
        
        build(left,start,mid);
        build(right,mid+1,end);
        
        //condition
        tree[node]=tree[left]+tree[right];
    }
    
    void update(int node,int start ,int end,int pos,int val){
        if(start==end){
            arr[pos]=val;
            tree[node]=val;
            return;
        }
        
        int mid=(start+end)/2;
        if(start<=pos && pos<=mid){
            update(2*node,start,mid,pos,val);
        }
        else{
            update(2*node+1,mid+1,end,pos,val);
        }
        
        tree[node]=tree[2*node]+tree[2*node+1];
        
    }
    int query(int node,int start,int end,int l,int r){
        if(end<l || r<start){
            return 0;
        }
        
        if(start==end){
            return tree[node];
        }
        else if(l<=start && end<=r){
            return tree[node];
        }
        
        else{
            
            int mid=(start+end)/2;
            int left=query(node*2,start,mid,l,r);
            int right=query(node*2+1,mid+1,end,l,r);
            return left+right;
            
        }
        
    }
    
};

int main() {
 
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    SegmentTree *Arr=new SegmentTree(v);
    int l,r;
    cin>>l>>r;
    cout<<Arr->query(l,r)<<endl;
    int pos,val;
    cin>>pos>>val;
    Arr->update(pos,val);
    
    cout<<Arr->query(l,r);
    
    return 0;
    
}
