#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
struct edge{
    ll u,v,p;
};
static bool compare(edge x,edge y){
    return (x.p>y.p);
}
 
class DSU{
    vector<ll> parent,size,f;
    public:
    DSU(ll n){
        parent.resize(n);
        size.resize(n);
        f.resize(n);
        for(ll i=0;i<n;i++){
            parent[i]=i,size[i]=1;
            f[i]=0;
        }
    }
    ll find(ll x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    bool Union(ll a,ll b){
        a=find(a);
        b=find(b);
        if(a==b){
            if(f[b]) return false;
            f[b]=true;
            return true;
        }
        if(f[a]&&f[b]) return false;
        if(size[b]>size[a]) swap(a,b);
        size[a]+=size[b];
        if(f[a]==0 && f[b]==1) f[a]=1;
        parent[b]=a;
        return true;
    }
};
 
int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,r,c;
        cin>>n>>r>>c;
        edge add[n];
        for(ll i=0;i<n;i++){
            cin>>add[i].u>>add[i].v>>add[i].p;
            add[i].u--;
            add[i].v+=(r-1);
        }
        sort(add,add+n,compare);
        ll nodes=r+c;
        DSU dsu(nodes);
        ll ans=0;
        for(auto it: add){
            if(dsu.Union(it.u,it.v)){
                ans+=it.p;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
