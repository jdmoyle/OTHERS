#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

vector<int> root,size;
int find(int x){
    return (x==root[x])?x:root[x]=find(root[x]);
}
void Unite(int x,int y){
    x=find(x),y=find(y);
    if(x!=y){
        if(size[x]<size[y]) swap(x,y);
        root[y]=x;
        size[x]+=size[y];
    }
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        root.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++){
            root[i]=i;
            size[i]=1;
        }
        for(int i=0;i<m;i++){
            int l,r;
            cin>>l>>r;
            Unite(l,r);
        }
        ll ans=0,groups=0;
        for(int i=1;i<=n;i++){
            if(root[i]==i){
                //combination of xC1*(n-x)C1;
                ans+=1LL* (n-size[i])*size[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
