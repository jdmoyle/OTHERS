#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
int find(int x,int parent[]){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x],parent);
}
bool Union(int x,int y,int rank[],int parent[]){
    x=find(x,parent);
    y=find(y,parent);
    if(x==y)
    return true;
    if(rank[x]<rank[y]) swap(x,y);
    parent[y]=x;
    if(rank[x]==rank[y]) rank[x]++;
    return false;
}
 
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<string,int> add;
        int parent[2*n];
        int rank[2*n];
        for(int i=0;i<2*n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        int indx=0,ans=0;
        for(int i=0;i<n;i++){
            string s1,s2;
            cin>>s1>>s2;
            if(add.find(s1)==add.end()) add[s1]=indx++;
            if(add.find(s2)==add.end()) add[s2]=indx++;
            if(s1==s2) continue;
            ans++;
            if(Union(add[s1],add[s2],rank,parent))
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
