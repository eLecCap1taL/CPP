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
#define MAXN 200005
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

int n,m;
vector<int> e[MAXN];

class Dyes{
public:
	int cl;
	int p;
}a[MAXN];

namespace TREE{
	int dfn[MAXN];
	int DFN;
	int sz[MAXN];
	int fa[MAXN];
	int id[MAXN];
	int idt[MAXN];
	int son[MAXN];
	int dep[MAXN];
	int top[MAXN];
	void dfs1(int u,int fath){
		sz[u]=1;
		dfn[u]=++DFN;
		fa[u]=fath;
		dep[u]=dep[fa[u]]+1;
		for(auto v:e[u]){
			if(v==fa[u])	continue;
			dfs1(v,u);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]])	son[u]=v;
		}
	}
	void dfs2(int u,int topf){
		top[u]=topf;
		id[u]=++DFN;
		idt[id[u]]=u;
		if(!son[u])	return ;
		dfs2(son[u],topf);
		for(auto v:e[u]){
			if(v==fa[u] || v==son[u])	continue;
			dfs2(v,v);
		}
	}
	int get_ch(int u,int v){
		int lst=-1;
		while(top[u]!=top[v]){
			lst=top[v];
			v=fa[top[v]];
		}
		if(u==v)	return lst;
		return idt[id[u]+1];
		// while(fa[v]!=u)	v=fa[v];
		// return v;
	}
	bool insub(int u,int v){
		return dfn[u]<=dfn[v] && dfn[v]<=dfn[u]+sz[u]-1;
	}
	int get_close(int u,int v){
		if(insub(u,v))	return get_ch(u,v);
		else	return fa[u];
	}
	void init(){
		dfs1(1,0);
		DFN=0;
		dfs2(1,1);
	}
}
using TREE::dfn;
using TREE::sz;
using TREE::insub;

class Node{
public:
	int L1,L2;
	int R1,R2;
};
ostream& operator << (ostream& os,const Node& x){
	os<<x.L2<<' '<<x.L1<<' '<<x.R1<<' '<<x.R2;
	return os;
}

Node b[MAXN];


class DS{
	class Node{
	public:
		int l,r;
		int mx;
	}tr[MAXN<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return x<<1|1;}
	void push_up(int p){
		tr[p].mx=max(tr[lc(p)].mx,tr[rc(p)].mx);
	}
	void build(int p,int l,int r){
		tr[p].l=l,tr[p].r=r;
		if(l==r){
			tr[p].mx=-1;
			return ;
		}
		int mid=(l+r)>>1;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
		push_up(p);
	}
	void modify(int p,int pos,int k){
		if(tr[p].l==tr[p].r){
			tr[p].mx=k;
			return ;
		}
		int mid=(tr[p].l+tr[p].r)>>1;
		if(pos<=mid)	modify(lc(p),pos,k);
		else	modify(rc(p),pos,k);
		push_up(p);
	}
	int query(int p,int l,int r){
		if(l<=tr[p].l && tr[p].r<=r){
			return tr[p].mx;
		}
		int mid=(tr[p].l+tr[p].r)>>1;
		int ret=-1;
		if(l<=mid)	chkmax(ret,query(lc(p),l,r));
		if(r>mid)	chkmax(ret,query(rc(p),l,r));
		return ret;
	}
public:
	// int d[MAXN];
	void init(){
		// foru(i,1,n){
		// 	d[i]=-1;
		// }
		build(1,1,n);
	}
	void set(int x,int y){
		// d[x]=y;
		modify(1,x,y);
	}
	int qry_mx(int l,int r){
		if(l>r)	return -1;
		return query(1,l,r);
		// int ret=-1;
		// foru(i,l,r){
		// 	chkmax(ret,d[i]);
		// }
		// return ret;
	}
}ds;

void process_L(){
	ds.init();
	
	int lstB=-1;

	foru(i,1,m){
		if(!a[i].cl){
			lstB=i;
			ds.set(dfn[a[i].p],i);
			continue;
		}
		//red
		
		if(lstB==-1){
			b[i].L1=-1;
			b[i].L2=-1;
			continue;
		}
		b[i].L1=lstB;
		
		//check if on the same point
		if(a[b[i].L1].p==a[i].p){
			b[i].L2=-1;
			continue;
		}

		if(insub(a[i].p,a[b[i].L1].p)){
			int x=TREE::get_ch(a[i].p,a[b[i].L1].p);
			int l=dfn[x],r=dfn[x]+sz[x]-1;
			b[i].L2=max(ds.qry_mx(1,l-1),ds.qry_mx(r+1,n));
		}else{
			int l=dfn[a[i].p],r=dfn[a[i].p]+sz[a[i].p]-1;
			b[i].L2=ds.qry_mx(l,r);
		}
	}
}
void process_R(){
	ds.init();

	int lstB=-1;

	ford(i,m,1){
		if(!a[i].cl){
			lstB=i;
			ds.set(dfn[a[i].p],m-i+1);
			continue;
		}
		//red
		
		if(lstB==-1){
			b[i].R1=-1;
			b[i].R2=-1;
			continue;
		}
		b[i].R1=lstB;
		
		//check if on the same point
		if(a[b[i].R1].p==a[i].p){
			b[i].R2=-1;
			continue;
		}

		if(insub(a[i].p,a[b[i].R1].p)){
			int x=TREE::get_ch(a[i].p,a[b[i].R1].p);
			int l=dfn[x],r=dfn[x]+sz[x]-1;
			b[i].R2=max(ds.qry_mx(1,l-1),ds.qry_mx(r+1,n));
		}else{
			int l=dfn[a[i].p],r=dfn[a[i].p]+sz[a[i].p]-1;
			// cerr<<"Yes check under"<<endl;
			b[i].R2=ds.qry_mx(l,r);
		}
		
		if(b[i].R2!=-1)	b[i].R2=m-b[i].R2+1;
	}
}


class BAN{
	class DS2{
		class Node{
		public:
			int l,r;
			int tg;
			pair<int,int> mn;
		}tr[MAXN<<2];
		inline int lc(int x){return x<<1;}
		inline int rc(int x){return x<<1|1;}
		void upd(int p,int k){
			tr[p].tg+=k;
			tr[p].mn.fi+=k;
		}
		void push_up(int p){
			tr[p].mn=min(tr[lc(p)].mn,tr[rc(p)].mn);
		}
		void push_down(int p){
			if(tr[p].tg==0)	return ;
			upd(lc(p),tr[p].tg);
			upd(rc(p),tr[p].tg);
			tr[p].tg=0;
		}
		void build(int p,int l,int r){
			tr[p].l=l,tr[p].r=r;
			if(l==r){
				tr[p].mn={0,-l};
				return ;
			}
			int mid=(l+r)>>1;
			build(lc(p),l,mid);
			build(rc(p),mid+1,r);
			push_up(p);
		}
		void modify(int p,int l,int r,int k){
			if(l<=tr[p].l && tr[p].r<=r){
				upd(p,k);
				return ;
			}
			push_down(p);
			int mid=(tr[p].l+tr[p].r)>>1;
			if(l<=mid)	modify(lc(p),l,r,k);
			if(r>mid)	modify(rc(p),l,r,k);
			push_up(p);
		}
	public:
		// int d[MAXN];
		void init(){
			build(1,1,m);
		}
		void add(int l,int r,int k){
			// foru(i,l,r){
			// 	d[i]+=k;
			// }
			modify(1,l,r,k);
		}
		pair<int,int> qry_rmn(){
			pair<int,int> ret(tr[1].mn.fi,-tr[1].mn.se);
			// foru(i,1,m){
			// 	if(d[i]<=ret.fi){
			// 		ret.fi=d[i];
			// 		ret.se=i;
			// 	}
			// }
			return ret;
		}
	}ds2;
public:
	int rf[MAXN];
	class Event{
	public:
		int l,r,k;
	};
	vector<Event> els[MAXN];

	void init(){
		ds2.init();
	}
	void append(int xl,int xr,int yl,int yr){
		if(xl>xr)	return ;
		if(yl>yr)	return ;
		els[xl]+=Event{yl,yr,1};
		els[xr+1]+=Event{yl,yr,-1};
	}
	void process(){
		foru(i,1,m){
			for(auto [l,r,k]:els[i]){
				ds2.add(l,r,k);
			}
			auto res=ds2.qry_rmn();
			if(res.fi>0)	rf[i]=i-1;
			else	rf[i]=res.se;
		}
	}
	int qry(int i){
		return rf[i];
	}
}ban;

void solve(bool SPE){ 
	n=RIN;
	foru(i,1,n-1){
		int u=RIN,v=RIN;
		e[u]+=v;
		e[v]+=u;
	}

	m=RIN;
	foru(i,1,m){
		char c=RCIN;
		int p=RIN;
		a[i]={c=='R',p};
	}
	
	TREE::init();

	process_L();
	process_R();

	ban.init();

	foru(i,1,m){
		if(a[i].cl==0)	continue;
		// cerr<<b[i]<<endl;
		auto [L1,L2,R1,R2]=b[i];
		
		{
			//must contain 2 rf
			int l=L1==-1?1:L1+1;
			
			int r=m;
			if(R2!=-1)	r=R2-1;
			if(R1!=-1 && a[R1].p==a[i].p)	r=R1-1;

			ban.append(l,i,i,r);
		}

		if(L1!=-1 && a[L1].p!=a[i].p){
			int l=L2==-1?1:L2+1;

			int x=TREE::get_close(a[i].p,a[L1].p);

			int r=m;
			if(R2!=-1 && (a[R2].p==a[i].p || TREE::get_close(a[i].p,a[R2].p)!=x))	r=R2-1;
			if(R1!=-1 && (a[R1].p==a[i].p || TREE::get_close(a[i].p,a[R1].p)!=x))	r=R1-1;

			ban.append(l,L1,i,r);
		}
	}

	ban.process();

	foru(i,1,m){
		int r=ban.qry(i);
		printf("%d\n",r-i+1);
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
	if(freopen("ex_dye5.in","r",stdin));
	// if(freopen("dye.in","r",stdin));
	// if(freopen("dye.out","w",stdout));
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