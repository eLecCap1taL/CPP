#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+3;
ll n,m,q,B=50,ans[N],sum[N],add[N],cur[N];
bool vis[N];
struct Nod{ll l,r,len,v,vv;}a[N];
vector<int>ve;
void Build()
{
	ve.clear();
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+add[i];
	for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
	for(int i=1;i<=m;i++)
	{
		cur[i]=a[i].v-(sum[a[i].r]-sum[a[i].l-1]);
	    if(!vis[i]&&B*a[i].len*8>=cur[i])ve.push_back(i);
	}
}
int main()
{
	freopen("game0.in","r",stdin);
	// freopen("game.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;ll typ,sub,las=0;cin>>typ>>sub;
	for(int i=1;i<=m;i++)
	{
		ll l,r,v,vv=0;ans[i]=-1;cin>>l>>r>>v;vv=l^r^v;
		a[i]={l,r,r-l+1,v,vv};
	}
	for(int t=1;t<=q;t++)
	{
		if(t%B==1)Build();
		ll l,r,d;cin>>l>>r>>d;
		if(typ)l^=las,r^=las,d^=las;
		vector<int>del;add[l]+=d;add[r+1]-=d;
		for(int i=0;i<(int)ve.size();i++)
		{
			ll o=ve[i],x=max(0ll,min(r,a[o].r)-max(l,a[o].l)+1);
			cur[o]-=x*d;
			if(cur[o]<=0)vis[o]=1,del.push_back(i),las^=a[o].vv,ans[o]=t;
		}
		for(int i=(int)del.size()-1;i>=0;i--)ve.erase(ve.begin()+del[i]);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}