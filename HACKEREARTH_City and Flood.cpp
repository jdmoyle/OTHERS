#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
/*
without using DSU


int main(){
  int n;
  cin>>n;
  int q;
  cin>>q;
  int t=q;
  while(t--){
    int x,y;
    cin>>x>>y;
  }
  int ans=n-q;
  cout<<ans<<endl;
  return 0;
 }


*/


int find(int x,int parent[]){
    return (x==parent[x]?x:parent[x]=find(parent[x],parent));
}
void Union(int x,int y,int rank[],int parent[]){
    x=find(x,parent);
    y=find(y,parent);
    if(x!=y){
        if(rank[x]<rank[y]) swap(x,y);
        parent[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}

int main()
{
    fast;
    int n;
    cin>>n;
    int parent[n+1],rank[n+1];
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        Union(x,y,rank,parent);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
    	if(parent[i]==i)
    	ans++;
    }
    cout<<ans<<endl;
    return 0;
}
