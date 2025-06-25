//%^~
// #pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <limits>
#include <climits>
#include <bitset>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// #include "ext/pb_ds/priority_queue.hpp"
// #include <ext/rope>
// #define PBDS __gnu_pbds
// #include <bits/extc++.h>
#define MAXN 100005
#define eps 1e-10
#define foru(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int a = (b); (a) >= (c); (a)--)
#define uLL unsigned long long
#define LL long long
#define LXF int
#define RIN Cap1taLDebug::read()
#define RSIN Cap1taLDebug::rdstr()
#define RCIN Cap1taLDebug::rdchar()
#define HH printf("\n")
#define All(x) (x).begin(), (x).end()
#define fi first
#define se second
#define CA const auto&
#if defined(__clang__)
#define assume(expr) __builtin_assume(expr)
#elif defined(__GNUC__)
#define assume(expr) if (expr) {} else { __builtin_unreachable(); }
#elif defined(_MSC_VER)
#define assume(expr) __assume(expr)
#endif
#define likely(x) __builtin_expect(!!(x), 1) 
#define unlikely(x) __builtin_expect(!!(x), 0)
#define mkp(x,y) make_pair(x,y)
#define ast(x) if(!(x))	{cerr<<endl<<"err at"<<__LINE__<<endl;exit(1);}
#define sz(x) ((int)(x.size()))
using namespace std;

typedef __int128 i128;
typedef unsigned __int128 u128;
typedef long long i64;
typedef unsigned long long u64;
typedef int i32;
typedef unsigned u32;
typedef short i16;
typedef unsigned short u16;

class Cap1taLDebug{
public:
	// #define DEBUGING

	ostream& buf;
	#ifndef DEBUGING
	static char fbuf[1<<21],*p1,*p2;
	#define getchar() (Cap1taLDebug::p1==p2&&(p1=(p2=fbuf)+fread(fbuf,1,1<<21,stdin),p1==p2)?EOF:*p2++)
	#endif
	Cap1taLDebug(ostream& out=cout):buf(out){}
	~Cap1taLDebug(){
		#ifdef DEBUGING
		buf.flush();
		#endif
	}
	static LXF read(){
		LXF x=0,w=1;char ch=0;
		while(!isdigit(ch)){
		if(ch=='-')	w=-1;
		ch=getchar();
		}
		while(isdigit(ch))	x=x*10+(ch^48),ch=getchar();
		return x*w;
	}
	static string rdstr(){
		string s;char c=getchar();
		while(c==' ' || c=='\r' || c=='\n')	c=getchar();	
		while(c!=' ' && c!='\r' && c!='\n' && c!=EOF)	s+=c,c=getchar();
		return s;
	}
	static char rdchar(){
		char c=getchar();
		while(c==' ' || c=='\r' || c=='\n')	c=getchar();
		return c;
	}
	static string i128ToString(i128 x){
		if(x==0)	return "0";
		string s="",w="";
		if(x<0)	w="-",x*=-1;
		while(x) s+=(char)('0'+(int)(x%10)),x/=10;
		reverse(All(s));
		return w+s;
	}
	static string u128ToString(u128 x){
		if(x==0)	return "0";
		string s="",w="";
		while(x) s+=(char)('0'+(int)(x%10)),x/=10;
		reverse(All(s));
		return w+s;
	}
	Cap1taLDebug& operator<<(const string val){
		#ifdef DEBUGING
		buf<<val;
		#endif
		return *this;
	}
	template<typename T1,typename T2>
	Cap1taLDebug& operator<<(const pair<T1,T2>& val){
		#ifdef DEBUGING
		(*this)<<"("<<val.first<<","<<val.second<<")";
		#endif
		return *this;
	}
	template<typename T,template<typename,typename...>class Container,typename...Args>
	Cap1taLDebug& operator<<(const Container<T, Args...>& container){
		#ifdef DEBUGING
		buf<<"{";
		bool fst=0;
		for(const auto& val:container){
			if(!fst)	fst=true;
			else	buf<<",";
			(*this)<<val;	
		}
		buf<<"}";
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(const i128& val){
		#ifdef DEBUGING
		buf<<i128ToString(val);
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(const u128& val){
		#ifdef DEBUGING
		buf<<u128ToString(val);
		#endif
		return *this;
	}
	template<typename T>
	Cap1taLDebug& operator<<(const T& val){
		#ifdef DEBUGING
		buf<<val;
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(ostream& (*manip)(ostream&)){
		#ifdef DEBUGING
		buf<<manip;
		#endif
		return *this;
	}
};
#ifndef DEBUGING
char Cap1taLDebug::fbuf[1<<21],*Cap1taLDebug::p1=nullptr,*Cap1taLDebug::p2=nullptr;
#endif
Cap1taLDebug cein(cout);
// Cap1taLDebug cein(cerr);
ostream& operator<<(ostream& os,i128 val){
	os<<Cap1taLDebug::i128ToString(val);
	return os;
}
ostream& operator<<(ostream& os,u128 val){
	os<<Cap1taLDebug::u128ToString(val);
	return os;
}

#define OPERATOR_FOR_PUSHBACK(pb)\
template<typename T1,typename T2>\
pb<T1>& operator += (pb<T1>& x,const T2& y){x.push_back((T1)y);return x;}

#define OPERATOR_FOR_PUSH(p)\
template<typename T1,typename T2>\
p<T1>& operator += (p<T1>& x,const T2& y){x.push((T1)y);return x;}

#define OPERATOR_FOR_INSERT(i)\
template<typename T1,typename T2>\
i<T1>& operator += (i<T1>& x,const T2& y){x.insert((T1)y);return x;}

OPERATOR_FOR_PUSHBACK(vector)
OPERATOR_FOR_PUSHBACK(deque)
OPERATOR_FOR_PUSH(stack)
OPERATOR_FOR_PUSH(queue)
OPERATOR_FOR_PUSH(priority_queue)
OPERATOR_FOR_INSERT(set)
OPERATOR_FOR_INSERT(unordered_set)
OPERATOR_FOR_INSERT(multiset)
OPERATOR_FOR_INSERT(unordered_multiset)

template<typename T1,typename T2>
inline bool chkmax(T1& x,const T2& y){return x<(T1)y?x=(T1)y,true:false;}
template<typename T1,typename T2>
inline bool chkmin(T1& x,const T2& y){return (T1)y<x?x=(T1)y,true:false;}

class TIMECHKER{
public:
	~TIMECHKER(){
		cerr<<endl<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	}
}TIMECHECKER;

constexpr int mod=998244353;
// constexpr int mod=1e9+7;

constexpr int& mdd(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mdd(int& x,const T1& y,const T2& ...xr){
	x+=y;
	if(x>=mod)	x-=mod;
	return mdd(x,xr...);
}
constexpr int& mmv(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mmv(int& x,const T1& y,const T2& ...xr){
	x-=y;
	if(x<0)	x+=mod;
	return mmv(x,xr...);
}
constexpr int& mll(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mll(int& x,const T1& y,const T2& ...xr){
	x=(LL)x*y%mod;
	return mll(x,xr...);
}
constexpr int add(const int& x){return x;}
template<class ...T>
constexpr int add(const int& x,const T& ...xr){
	int ret=x+add(xr...);
	if(ret>=mod)	ret-=mod;
	return ret;
}
constexpr int mul(const int& x){return x;}
template<class ...T>
constexpr int mul(const int& x,const T& ...xr){
	return (LL)x*mul(xr...)%mod;
}
constexpr int rmv(int x,int y){
	x-=y;
	if(x<0)	x+=mod;
	return x;
}
constexpr int mev(const int& x){return mod-x;}

constexpr int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)	mll(ret,x);
		mll(x,x),y>>=1;
	}
	return ret;
}

/*

*/
bool m_begin;
int n,m;
vector<int> e[MAXN];
vector<int> g[MAXN];
int fa[MAXN];
int dfn[MAXN];
int idfn[MAXN];
int sz[MAXN];
int DFN;

void prefetch(int u,int fath){
	fa[u]=fath;
	sz[u]=1;
	dfn[u]=++DFN;
	idfn[dfn[u]]=u;
	for(auto v:e[u]){
		if(v==fa[u])	continue;
		prefetch(v,u);
		sz[u]+=sz[v];
	}
}
bool insub(int u,int v){
	return dfn[u]<=dfn[v] && dfn[v]<=dfn[u]+sz[u]-1;
}

int ans=INT_MAX;

struct Edge{
	int u,v;
}eg[MAXN*2];

int deg[MAXN];
int degsz[MAXN];
void pulldeg(int u){
	degsz[u]=deg[u];
	for(auto v:e[u]){
		if(v==fa[u])	continue;
		pulldeg(v);
		degsz[u]+=degsz[v];
	}
	chkmin(ans,degsz[u]);
}

pair<int,int> pullleaf(int u){
	if(sz(e[u])==0){
		return mkp(deg[u],INT_MAX);
	}
	pair<int,int> ret(INT_MAX,INT_MAX);
	auto upd=[&](const int& x){
		if(x<ret.fi){
			ret.se=ret.fi;
			ret.fi=x;
		}else if(x<ret.se){
			ret.se=x;
		}
	};
	for(auto v:e[u]){
		if(v==fa[u])	continue;
		auto res=pullleaf(v);
		upd(res.fi);
		upd(res.se);
	}
	return ret;
}

namespace SLPF{
	int id[MAXN];
	int iid[MAXN];
	int DFN;
	int son[MAXN];
	int top[MAXN];
	void dfs1(int u){
		// cout<<"?"<<u<<endl;
		for(auto v:e[u]){
			if(v==fa[u])	continue;
			dfs1(v);
			if(sz[v]>sz[son[u]])	son[u]=v;
		}
	}
	void dfs2(int u,int topf){
		top[u]=topf;
		id[u]=++DFN;
		// cout<<u<<'~'<<topf<<' '<<id[u]<<endl;
		iid[id[u]]=u;
		if(!son[u])	return ;
		dfs2(son[u],topf);
		for(auto v:e[u]){
			if(v==fa[u] || v==son[u])	continue;
			dfs2(v,v);			
		}
	}
	void init(){
		dfs1(1);
		dfs2(1,1);
		// exit(0);
	}
	void to_root(int u,function<void(int,int)> callback){
		while(u){
			callback(id[top[u]],id[u]);
			u=fa[top[u]];
		}
	}
}

inline int lc(int x){return x<<1;}
inline int rc(int x){return x<<1|1;}

namespace BASE{
	int bmn[100005<<2];
	void build(int p,int l,int r){
		if(l==r){
			// cout<<l<<' '<<SLPF::iid[l]<<' '<<degsz[SLPF::iid[l]]<<endl;
			bmn[p]=degsz[SLPF::iid[l]];
			return ;
		}
		int mid=(l+r)>>1;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
		bmn[p]=min(bmn[lc(p)],bmn[rc(p)]);
	}
}

class Node{
public:
	int lc,rc;
	int add;
	int mn;
}tr[100005*17*14];

class My_Alloc{
	int pcnt;
	int stk[100005*17*14];
	int tp;
public:
	int operator () (){
		if(tp)	return stk[--tp];
		// if(pcnt==100005*17*14-1)	exit(1);
		return ++pcnt;
	}
	void clear(){
		pcnt=0;
		tp=0;
	}
	void trash(int x){
		stk[tp++]=x;
	}
}alloc;

void init_node(int p,int sp){
	tr[p].lc=tr[p].rc=tr[p].add=0;
	tr[p].mn=BASE::bmn[sp];
}
void fetch(int &p,int sp){
	if(!p){
		p=alloc();
		init_node(p,sp);
	}
}
int fetch_mn(int p,int sp){
	if(p==0)	return BASE::bmn[sp];
	else	return tr[p].mn;
}
void upd(int p,int k){
	tr[p].add+=k;
	tr[p].mn+=k;
}
void push_down(int p,int sp){
	if(tr[p].add==0)	return ;
	fetch(tr[p].lc,lc(sp));
	fetch(tr[p].rc,rc(sp));
	upd(tr[p].lc,tr[p].add);
	upd(tr[p].rc,tr[p].add);
	tr[p].add=0;
}
void push_up(int p,int sp){
	tr[p].mn=min(fetch_mn(tr[p].lc,lc(sp)),fetch_mn(tr[p].rc,rc(sp)));
}
void modify(int &p,int sp,int l,int r,int nl,int nr){
	fetch(p,sp);
	// cout<<p<<' '<<sp<<' '<<l<<' '<<r<<' '<<nl<<' '<<nr<<endl;
	if(nl<=l && r<=nr){
		upd(p,-2);
		return ;
	}
	push_down(p,sp);
	int mid=(l+r)>>1;
	if(nl<=mid)	modify(tr[p].lc,lc(sp),l,mid,nl,nr);
	if(nr>mid)	modify(tr[p].rc,rc(sp),mid+1,r,nl,nr);
	push_up(p,sp);
}
void merge(int p1,int p2,int sp){
	// cout<<"merge "<<p1<<' '<<p2<<' '<<sp<<endl;
	// cout<<tr[p1].lc<<' '<<tr[p1].rc<<endl;
	// cout<<tr[p2].lc<<' '<<tr[p2].rc<<endl;
	// if(p1==p2){
	// 	exit(1);
	// }

	// if(!p1)	return ;
	// if(!p2)	return ;
	if(tr[p2].add!=0){
		upd(p1,tr[p2].add);
	}

	bool to_l=tr[p1].lc && tr[p2].lc;
	bool to_r=tr[p1].rc && tr[p2].rc;

	if(!tr[p1].lc)	tr[p1].lc=tr[p2].lc;
	if(!tr[p1].rc)	tr[p1].rc=tr[p2].rc;

	if(!tr[p1].lc && !tr[p1].rc){
		// alloc.trash(p2);
		return ;
	}

	push_down(p1,sp);

	// cout<<"going to"<<endl;
	// cout<<tr[p1].lc<<' '<<tr[p1].rc<<endl;
	// cout<<tr[p2].lc<<' '<<tr[p2].rc<<endl;
	if(to_l)	merge(tr[p1].lc,tr[p2].lc,lc(sp));
	if(to_r)	merge(tr[p1].rc,tr[p2].rc,rc(sp));

	push_up(p1,sp);

	// alloc.trash(p2);
}

void ptree(int p,int l,int r){
	if(!p)	return ;
	printf("tr[%d](%d,%d)={lc=%d,rc=%d,add=%d,mn=%d}\n",p,l,r,tr[p].lc,tr[p].rc,tr[p].add,tr[p].mn);
	int mid=(l+r)>>1;
	ptree(tr[p].lc,l,mid);
	ptree(tr[p].rc,mid+1,r);
}
void printtree(int rt){
	printf("TREE rt=%d ~~~~~~~~~~~~~~~~~~~\n",rt);
	ptree(rt,1,n);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int squery(int p,int l,int r,int nl,int nr){
	if(nl<=l && r<=nr)	return BASE::bmn[p];
	int mid=(l+r)>>1;
	if(nr<=mid)	return squery(lc(p),l,mid,nl,nr);
	if(nl>mid)	return squery(rc(p),mid+1,r,nl,nr);
	return min(squery(lc(p),l,mid,nl,nr),squery(rc(p),mid+1,r,nl,nr));
}
int query(int p,int sp,int l,int r,int nl,int nr){
	if(!p)	return squery(sp,l,r,nl,nr);
	if(nl<=l && r<=nr)	return tr[p].mn;
	push_down(p,sp);
	int mid=(l+r)>>1;
	if(nr<=mid)	return query(tr[p].lc,lc(sp),l,mid,nl,nr);
	if(nl>mid)	return query(tr[p].rc,rc(sp),mid+1,r,nl,nr);
	return min(query(tr[p].lc,lc(sp),l,mid,nl,nr),query(tr[p].rc,rc(sp),mid+1,r,nl,nr));
}

int rt[MAXN];
int eL,eR;

void pull(int u){
	// cerr<<"vis "<<u<<endl;
	bool fst=0;
	for(auto v:g[u]){
		// cout<<"~"<<v<<endl;
		SLPF::to_root(v,[&](const int& l,const int& r)->void {
			// cout<<"do -2 "<<l<<' '<<r<<endl;
			modify(rt[u],1,1,n,l,r);
		});
		fst=1;
	}

	if(SLPF::son[u]){
		int v=SLPF::son[u];
		pull(v);
		if(!fst && rt[v]!=0){
			rt[u]=rt[v];
			fst=1;
		}else{
			merge(rt[u],rt[v],1);
		}
	}

	for(auto v:e[u]){
		if(v==fa[u] || v==SLPF::son[u])	continue;
		pull(v);
		if(!fst && rt[v]!=0){
			rt[u]=rt[v];
			fst=1;
			continue;
		}
		merge(rt[u],rt[v],1);
	}

	// printf("%d aft merge\n",u);
	// printtree(rt[u]);
	// cout<<BASE::bmn[1].fi<<endl;

	// if(u!=2)	return ;

	int res=INT_MAX;

	if(2<eL && rt[u])	chkmin(res,query(rt[u],1,1,n,2,eL-1));
	if(n>eR && rt[u])	chkmin(res,query(rt[u],1,1,n,eR+1,n));	
	
	// cout<<' '<<l<<' '<<r<<endl;
	// res=query(rt[u],1,1,n,1,1);
	// res=squery(1,1,n,1,1);
	// cout<<res.fi<<' '<<SLPF::iid[res.se]<<endl;
	// cout<<u<<' '<<degsz[u]<<endl;
	// cout<<endl;

	// cout<<u<<' '<<degsz[u]<<' '<<res<<'\n';
	
	// if(res==INT_MAX)	return ;

	chkmin(ans,degsz[u]+res);
}

void solve(bool SPE){ 
	n=RIN;
	m=RIN-(n-1);
	bool chain=1;
	foru(i,1,n-1){
		int u=RIN,v=RIN;
		e[u]+=v;
		e[v]+=u;
		chain&=(u==i && v==i+1);
	}
	foru(i,1,m){
		int u=RIN,v=RIN;
		eg[i]={u,v};
		g[u]+=v;
		g[v]+=u;
	}

	prefetch(1,0);

	// load deg
	foru(i,1,m){
		auto [u,v]=eg[i];
		deg[u]++;
		deg[v]++;
	}

	//subtree disconnect answer
	pulldeg(1);

	if(chain){
		foru(u,2,n){
			for(auto v:e[u]){
				if(v==fa[u])	continue;
				chkmin(ans,degsz[u]-degsz[v]);
			}
		}
		cout<<ans;
		return ;
	}

	//same subtree answer
	// for(auto v:e[1]){
	// 	auto res=pullleaf(1);
	// 	if(res.se!=INT_MAX){
	// 		chkmin(ans,res.fi+res.se);
	// 	}
	// }
	// this is fucking useless
	// fkts

	SLPF::init();
	BASE::build(1,1,n);

	// foru(i,1,n){
	// 	cout<<SLPF::id[i]<<"->"<<i<<endl;
	// }

	// pull(4);
	// exit(0);

	if(sz(e[1])>1)	for(auto v:e[1]){
		alloc.clear();
		// cerr<<"~"<<v<<endl;
		eL=SLPF::id[v];
		eR=eL+sz[v]-1;
		pull(v);
		// exit(0);
		// break;
	}

	// for(auto rt:e[1]){
	// 	foru(x,dfn[rt],dfn[rt]+sz[rt]-1){
	// 		static int d[MAXN];
	// 		int nd=idfn[x];
	// 		foru(i,1,n){
	// 			d[i]=0;
	// 		}
	// 		foru(i,1,m){
	// 			auto [u,v]=eg[i];
	// 			if(insub(nd,v))	swap(u,v);
	// 			if(insub(nd,u)){
	// 				d[dfn[v]]++;
	// 			}
	// 		}
	// 		foru(i,1,n){
	// 			d[i]+=d[i-1];
	// 		}
	// 		foru(i,2,n){
	// 			if(insub(rt,i))	continue;
	// 			chkmin(ans,degsz[nd]+degsz[i]-2*(d[dfn[i]+sz[i]-1]-d[dfn[i]-1]));
	// 		}
	// 	}
	// }

	foru(u,2,n){
		for(auto v:e[u]){
			if(v==fa[u])	continue;
			chkmin(ans,degsz[u]-degsz[v]);
		}
	}


	cerr<<ans<<endl;
	cout<<ans;
	
	return ;
}
/*
检查文件读写
检查多测清空
检查数组大小
*/
bool m_end;
signed main()
{
	// #define MULTITEST
	
	#ifndef CPEDITOR
	#ifndef ONLINE_JUDGE
	// if(freopen("a.in","r",stdin));
	if(freopen("commodity8.in","r",stdin));
	// if(freopen("commodity.in","r",stdin));
	// if(freopen("commodity.out","w",stdout));
	#endif
	#endif
	
	#ifdef MULTITEST
	int T=RIN;
	#else
	int T=1;
	#endif

	cerr<<"static memory: "<<(&m_begin-&m_end)/1024/1024<<endl;
	
	for(int i=1;i<=T;i++){
		solve(i==0);
	}
	return 0;
}