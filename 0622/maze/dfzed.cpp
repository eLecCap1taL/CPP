//%^~
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
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
#define LXF LL
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
	#define DEBUGING

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
int n,q;

vector<pair<int,int>> e[MAXN];

int a[MAXN];

class QRY{
public:
	int x;
	LL t;
	int p;
	int ans;
}qr[MAXN];

namespace SUB1{
	int dfs(int u,int fath,LL t,int ban){
		t+=a[u];
		int ret=1;
		for(auto [v,w]:e[u]){
			if(v==fath)	continue;
			if(v==ban)	continue;
			if(w>t)	continue;
			ret+=dfs(v,u,t-w,ban);
		}
		return ret;
	}
	void work(){
		foru(o,1,q){
			auto [x,t,p,ans]=qr[o];
			cout<<dfs(x,0,t,p)<<'\n';
		}
	}
}

vector<int> qls[MAXN];

//dfz
bool vis[MAXN];

int sz[MAXN];
int fa[MAXN];
int dfn[MAXN],DFN;
int bl[MAXN],bl_id;

LL up[MAXN];
LL upsum[MAXN];
LL dn[MAXN];

void upd(int u,int fath,int meta,LL dnsum){
	sz[u]=1;
	fa[u]=fath;
	dfn[u]=++DFN;
	bl[u]=meta;
	for(auto [v,w]:e[u]){
		if(v==fa[u] || vis[v])	continue;
		upsum[v]=a[v]-w+upsum[u];
		up[v]=a[v]-w+min(0ll,up[u]);
		dn[v]=min(dn[u],dnsum+a[u]-w);
		upd(v,u,meta,dnsum+a[u]-w);
		sz[u]+=sz[v];
	}
}

bool insub(int u,int v){
	return dfn[u]<=dfn[v] && dfn[v]<=dfn[u]+sz[u]-1;
}

int tot;
pair<int,int> findroot(int u){
	pair<int,int> ret(INT_MAX,0);
	int mx=INT_MIN;
	for(auto [v,w]:e[u]){
		if(v==fa[u] || vis[v])	continue;
		auto res=findroot(v);
		chkmin(ret,res);
		chkmax(mx,sz[v]);
	}
	chkmax(mx,tot-sz[u]);
	chkmin(ret,mkp(mx,u));
	return ret;
}

class DS{
public:
	vector<pair<int,LL>> ls;
	void insert(int id,LL dn){
		ls+=mkp(id,dn);
	}
	void clear(){
		ls.clear();
	}
	void qry(LL k,int l,int r,int& store){
		for(auto [id,dn]:ls){
			if(l<=id && id<=r && dn>=k){
				store++;
			}
		}
	}
}ds;

int bl_L,bl_R;

void load(int u){
	ds.insert(dfn[u],dn[u]);
	for(auto [v,w]:e[u]){
		if(v==fa[u] || vis[v])	continue;
		load(v);
	}
}

int a_L;
int a_R;
void answer(int u){
	for(auto qid:qls[u]){
		auto& [x,t,p,ans]=qr[qid];
		
		if(bl[p]==bl_L){
			//p is dfz root
			continue;
		}
		if(t+up[u]<0){
			//dead
			continue;
		}

		LL T=t+upsum[u];

		if(bl_L<=bl[p] && bl[p]<=bl_R){
			// need to avoid
			if(dfn[p]<a_L){
				ds.qry(-T,1,dfn[p]-1,ans);
				ds.qry(-T,dfn[p]+sz[p],a_L-1,ans);
				ds.qry(-T,a_R+1,DFN,ans);
			}else if(dfn[p]>a_R){
				ds.qry(-T,1,a_L-1,ans);
				ds.qry(-T,a_R+1,dfn[p]-1,ans);
				ds.qry(-T,dfn[p]+sz[p],DFN,ans);
			}else if(!insub(p,u)){
				ds.qry(-T,1,a_L-1,ans);
				ds.qry(-T,a_R+1,DFN,ans);
			}
		}else{
			ds.qry(-T,1,a_L-1,ans);
			ds.qry(-T,a_R+1,DFN,ans);
		}
	}
	for(auto [v,w]:e[u]){
		if(v==fa[u] || vis[v])	continue;
		answer(v);
	}
}

void dfz(int u){
	vis[u]=1;

	bl_L=bl_id+1,bl_R=0;

	DFN=0;

	up[u]=upsum[u]=0;
	dn[u]=0;
	dfn[u]=++DFN;
	bl[u]=++bl_id;
	sz[u]=0;

	for(auto [v,w]:e[u]){
		if(vis[v])	continue;

		up[v]=a[v]-w;
		upsum[v]=a[v]-w;
		dn[v]=a[u]-w;

		upd(v,u,++bl_id,a[u]-w);

		sz[u]+=sz[v];
	}

	bl_R=bl_id;

	//load
	ds.clear();
	ds.insert(dfn[u],dn[u]);
	for(auto [v,w]:e[u]){
		if(vis[v])	continue;
		load(v);
	}

	//answer querys
	// answer u
	for(auto qid:qls[u]){
		auto& [x,t,p,ans]=qr[qid];
		if(bl_L<=bl[p] && bl[p]<=bl_R){
			// need to avoid
			ds.qry(-t,1,dfn[p]-1,ans);
			ds.qry(-t,dfn[p]+sz[p],DFN,ans);
		}else{
			ds.qry(-t,1,DFN,ans);
		}
	}
	for(auto [v,w]:e[u]){
		if(vis[v])	continue;
		a_L=dfn[v];
		a_R=dfn[v]+sz[v]-1;
		answer(v);
	}


	for(auto [v,w]:e[u]){
		if(vis[v])	continue;
		tot=sz[v];
		int rt=findroot(v).se;
		dfz(rt);
	}
}

void solve(bool SPE){ 
	n=RIN,q=RIN;
	foru(i,1,n-1){
		int u=RIN,v=RIN,w=RIN;
		e[u]+=mkp(v,w);
		e[v]+=mkp(u,w);
	}

	foru(i,1,n){
		a[i]=RIN;
	}

	foru(i,1,q){
		qr[i]={(int)RIN,RIN,(int)RIN,0};
		qls[qr[i].x]+=i;
	}

	// if(n<=2000 && q<=2000){
	// 	SUB1::work();
	// 	return ;
	// }

	upd(1,0,0,0);
	tot=n;
	int rt=findroot(1).se;
	dfz(rt);

	foru(i,1,q){
		printf("%d\n",qr[i].ans);
	}

	return ;
}
/*
检查文件读写
检查多测清空
检查数组大小
*/
signed main()
{
	// #define MULTITEST
	
	#ifndef CPEDITOR
	#ifndef ONLINE_JUDGE
	if(freopen("maze1.in","r",stdin));
	// if(freopen("maze.in","r",stdin));
	// if(freopen("maze.out","w",stdout));
	#endif
	#endif
	
	#ifdef MULTITEST
	int T=RIN;
	#else
	int T=1;
	#endif
	
	for(int i=1;i<=T;i++){
		solve(i==0);
	}
	return 0;
}