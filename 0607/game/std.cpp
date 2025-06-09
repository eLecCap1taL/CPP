#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10009;
const ll INF=1e18;
ll n,m,q,T,cid,timer,now,L[N],R[N],val[N],h[N],tim[N],ans[N],lstans;
vector<ll> pos[N],vec;
vector<pair<ll,ll> > all;
inline ll findnxt(ll x,ll h){
	return ((x>>h)+1)<<h;
}
namespace SGT{
	const ll N=40009;
	ll lmt[N],mn[N],sum[N],len[N],tag[N],target[N][30];
	vector<pair<ll,ll> > vec[N][30];
	
	inline void pushup(ll u){
		if(len[u]>1){
			mn[u]+=sum[u];
			sum[u]=sum[u*2]+sum[u*2+1];
			mn[u]-=sum[u];
		}
		if(mn[u]<=0) lmt[u]=0;
		else{
			lmt[u]=(mn[u]-1)/len[u]+1;
		}
		if(len[u]>1){
			lmt[u]=min(lmt[u],min(lmt[u*2],lmt[u*2+1]));
		}
	}
	
	
	inline void add(ll u,ll v){
		lmt[u]=max(0ll,lmt[u]-v);
		sum[u]+=len[u]*v;
		mn[u]-=len[u]*v;
		tag[u]+=v;
	}
	
	inline void pushdown(ll u){
		if(len[u]>1&&tag[u]){
			add(u*2,tag[u]);
			add(u*2+1,tag[u]);
			tag[u]=0;
		}
	}
	
	
	inline void build(ll u,ll l,ll r){
		lmt[u]=mn[u]=INF;
		len[u]=r-l+1;
		for(ll i=0;i<30;i++){
			target[u][i]=(1ll<<i);
		}
		if(l==r) return;
		ll mid=(l+r)/2;
		build(u*2,l,mid);
		build(u*2+1,mid+1,r);
	}

	
	inline void modify(ll u,ll l,ll r,ll ql,ll qr,ll v){
		if(ql<=l&&r<=qr) return add(u,v);
		pushdown(u);
		ll mid=(l+r)/2;
		if(ql<=mid) modify(u*2,l,mid,ql,qr,v);
		if(mid<qr) modify(u*2+1,mid+1,r,ql,qr,v);
		pushup(u); 
	}
	
	inline void update(ll u,ll l,ll r){
		pushdown(u);
		if(lmt[u]>0) return;
		mn[u]=INF;
		for(ll i=0;i<30;i++){
			if(target[u][i]<=sum[u]){
				target[u][i]=INF;
				for(auto x:vec[u][i]){
					all.emplace_back(x);
				}
				vec[u][i].clear();
			}
			else{
				mn[u]=min(mn[u],target[u][i]-sum[u]);
			}
		}
		if(l==r) return pushup(u);
		ll mid=(l+r)/2;
		update(u*2,l,mid),update(u*2+1,mid+1,r);
		pushup(u);
	}

	inline void add_alarm(ll u,ll h,pair<ll,ll> p){
		vec[u][h].emplace_back(p);
		target[u][h]=min(target[u][h],findnxt(sum[u],h));
		mn[u]=min(mn[u],findnxt(sum[u],h)-sum[u]);
		pushup(u);
	}
	
	inline void getsum(ll u,ll l,ll r,ll ql,ll qr,vector<ll> &vec){
		//
		pushdown(u);
		if(ql<=l&&r<=qr) return vec.emplace_back(sum[u]),void();
		ll mid=(l+r)/2;
		if(ql<=mid) getsum(u*2,l,mid,ql,qr,vec);
		if(mid<qr) getsum(u*2+1,mid+1,r,ql,qr,vec);
	}
	
	inline void push_alarm(ll u,ll l,ll r,ll ql,ll qr,ll h,pair<ll,ll> p){
		//
		if(ql<=l&&r<=qr) return add_alarm(u,h,p);
		ll mid=(l+r)/2;
		if(ql<=mid) push_alarm(u*2,l,mid,ql,qr,h,p);
		if(mid<qr) push_alarm(u*2+1,mid+1,r,ql,qr,h,p);
		pushup(u);
	}
	#undef lson
	#undef rson
}
using SGT::build;
using SGT::modify;
using SGT::update;
using SGT::push_alarm;
using SGT::getsum;
inline void rebuild(ll x){
	tim[x]=++timer; // 设置当前任务最新时间戳 
	vec.clear(); 
	getsum(1,1,n,L[x],R[x],vec); // 找到x对应的log个任务节点 的当前sum 
	while(h[x]>=0){ // 更新 h[x] 
		ll sum=0;
		for(auto u:vec){
			sum+=findnxt(u,h[x])-1;
		}
		if(sum>=val[x]) h[x]--;
		else break;
	}
	if(h[x]==-1){
		lstans^=L[x]^R[x]^val[x];
		ans[x]=now;
		return;
	}
	push_alarm(1,1,n,L[x],R[x],h[x],make_pair(x,tim[x]));
}
int main(){
	// freopen("game.in","r",stdin);
	// freopen("game.out","w",stdout);1
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(ans,-1,sizeof(ans));
	cin>>n>>m>>q>>T>>cid;
	build(1,1,n);
	for (ll i=1;i<=m;++i){
		cin>>L[i]>>R[i]>>val[i];
		h[i]=29;
		rebuild(i);
	}
	
	for(ll i=1;i<=q;i++){
		ll l,r,v; cin>>l>>r>>v;
		now=i;
		l^=lstans*T,r^=lstans*T,v^=lstans*T;
		modify(1,1,n,l,r,v);
		all.clear();
		update(1,1,n);
		for(auto x:all){
			if(tim[x.first]==x.second){
				rebuild(x.first);
			}
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
	puts("");
	return 0;
}