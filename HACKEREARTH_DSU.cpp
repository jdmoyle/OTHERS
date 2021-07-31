#include<iostream>
#include<algorithm>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int n,m;
 
int find(int x,int parent[]){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x],parent);
}
void Union(int x,int y,int size[],int parent[]){
    x=find(x,parent);
    y=find(y,parent);
    if(x!=y){
    	if(size[x]<size[y]) swap(x,y);
    	parent[y]=x;
    	size[x]+=size[y];
    	size[y]=0;
    }
}
void print(int size[]){
	int a[n+1];
	a[0]=0;
	for(int i=1;i<=n;i++)
	a[i]=size[i];
	sort(a,a+(n+1));
	for(int i=1;i<=n;i++){
		if(a[i]!=0)
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
    fast;
    cin>>n>>m;
    int parent[n+1];
    int size[n+1];
    size[0]=0;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        Union(x,y,size,parent);
        print(size);
    }
    return 0;
}
