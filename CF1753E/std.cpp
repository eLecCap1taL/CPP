#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e6+5;
int n,m,o,A,B,C,all;
int a[N],b[N];
map<int,int> id;
vector<int> v1[100],v2[100];
vector<ll> s[100];
int mark[N];
int cnt;ll sum,ans;
void check(ll X){
	ll now=all;
	cnt=sum=0;
	for(int i=0;i<=m;i++){
		if(i&&!mark[i])now/=b[i];
		if(all==now)continue;
		int l=0,r=v2[i].size()-1,mid;
		while(l<=r){
			mid=l+r>>1;
			if(1ll*v2[i][mid]*(all-now)>=X)l=mid+1;
			else r=mid-1;
		}
		cnt+=l;if(l>0)sum+=s[i][l-1]*(all-now);
	}
}
void calc(int D){
	ll l=0,r=1e18,mid,res;
	D/=A;
	int now=all;res=all;
	for(int i=0;i<=m;i++){
		if(i&&!mark[i])now/=b[i];
		if(s[i].size()){
			res+=s[i].back()*now;
		}
	}
	while(l<=r){
		mid=l+r>>1;
		check(mid);
		if(cnt<=D)r=mid-1;
		else l=mid+1;
	}
	check(r);
	res+=sum-max(0,cnt-D)*r;
	ans=max(ans,res);
}
void dfs(int x,int y){
	if(1ll*y*B>C)return;
	if(x==o+1){
		calc(C-y*B);
		return;		
	}
	dfs(x+1,y);
	for(int p:v1[x]){
		y++;
		mark[p]=1;
		dfs(x+1,y);
	}
	for(int p:v1[x])mark[p]=0;
}
int main(){
	n=in(),C=in(),A=in(),B=in();
	ans=1,all=1;
	for(int i=1;i<=n;i++){
		char op=getchar();
		while(op!='*'&&op!='+')op=getchar();
		scanf("%d",&a[i]);
		if(op=='*'){
			if(a[i]>1){
				ans*=a[i];
				if(!id[a[i]])id[a[i]]=++o;
				m++;b[m]=a[i];all*=b[m];
				v1[id[a[i]]].push_back(m);
			}
		}else ans+=a[i],v2[m].push_back(a[i]);
	}
	for(int i=0;i<=m;i++){
		sort(v2[i].begin(),v2[i].end(),greater<int>());
		s[i]=vector<ll>(v2[i].size(),0);
		for(int j=0;j<s[i].size();j++){
			s[i][j]=v2[i][j];
			if(j)s[i][j]+=s[i][j-1];
		}
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
