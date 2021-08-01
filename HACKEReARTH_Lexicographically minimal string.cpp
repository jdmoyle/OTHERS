#include<iostream>
#include<map>
using namespace std;

char parent[150];
char find(char c){
	if(c==parent[c]) return c;
	return parent[c]=find(parent[c]);
}
void unite(char c,char d){
	c=find(c),d=find(d);
	if(c==d)
	return;
	if(c<d) parent[d]=c;
	else
	parent[c]=d;
}

int main(){
	string A,B,C;
	cin>>A>>B>>C;
	for(char i='a';i<='z';i++){
		parent[i]=i;
	}
	for(int i=0;i<A.size();i++){
		unite(A[i],B[i]);
	}
	for(int i=0;i<C.size();i++){
		cout<<find(C[i]);
	}
	return 0;
}
