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

const int INT_INF=1e8;
int n,m;

class Edge{
public:
	int v,id,w;
};
vector<Edge> e[MAXN];

int dis[MAXN];
queue<int> q;
void access(int ban,int tar){
	dis[n]=0;
	if(n==tar)	return ;
	
	foru(i,1,n-1){
		dis[i]=INT_INF;
	}

	while(!q.empty())	q.pop();
	q.push(n);

	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto [v,id,w]:e[u]){
			if(id==ban)	continue;
			if(dis[v]==INT_INF){
				dis[v]=dis[u]+1;
				if(v==tar)	return ;
				q.push(v);
			}
		}
	}
}

int ndis[MAXN];
void predis(){
	access(-1,-1);
	foru(i,1,n){
		ndis[i]=dis[i];
	}
}

bool ont[MAXN];
void gen(int u){
	static bool vis[MAXN];
	
	vis[u]=1;
	for(auto [v,id,w]:e[u]){
		if(vis[v])	continue;
		if(dis[v]!=dis[u]+1)	continue;

		ont[id]=1;
		gen(v);
	}
}

int sz[MAXN];
int dfn[MAXN];
int DFN;
int fa[MAXN];
int* dep=ndis;
void dfs1(int u,int fath){
	fa[u]=fath;
	dfn[u]=++DFN;
	sz[u]=1;
	for(auto [v,id,w]:e[u]){
		if(!ont[id])	continue;
		if(v==fa[u])	continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}

bool inrange(int l,int x,int r){
	return l<=x && x<=r;
}

class DS{
	class Point{
	public:
		int c,w;
	};
	vector<Point> ls[MAXN];
	
	class QRY{
	public:
		int l,r;
		int& store;
	};

	vector<QRY> lf[MAXN];
	vector<QRY> rf[MAXN];

	class ScanDS{
		class Node{
		public:
			int l,r;
			int mn;
		}tr[MAXN<<2];
		inline int lc(int x){return x<<1;}
		inline int rc(int x){return x<<1|1;}
		void push_up(int p){
			tr[p].mn=min(tr[lc(p)].mn,tr[rc(p)].mn);
		}
		void build(int p,int l,int r){
			tr[p].l=l,tr[p].r=r;
			if(l==r){
				tr[p].mn=INT_INF;
				return ;
			}
			int mid=(l+r)>>1;
			build(lc(p),l,mid);
			build(rc(p),mid+1,r);
			push_up(p);
		}
		void modify(int p,int pos,int k){
			if(tr[p].l==tr[p].r){
				chkmin(tr[p].mn,k);
				return ;
			}
			int mid=(tr[p].l+tr[p].r)>>1;
			if(pos<=mid)	modify(lc(p),pos,k);
			else	modify(rc(p),pos,k);
			push_up(p);
		}
		int query(int p,int l,int r){
			if(l<=tr[p].l && tr[p].r<=r){
				return tr[p].mn;
			}
			int ret=INT_INF;
			int mid=(tr[p].l+tr[p].r)>>1;
			if(l<=mid)	chkmin(ret,query(lc(p),l,r));
			if(r>mid)	chkmin(ret,query(rc(p),l,r));
			return ret;
		}
	public:
		// int d[MAXN];
		void init(){
			// foru(i,1,n){
			// 	d[i]=INT_INF;
			// }
			build(1,1,n);
		}
		void add(int x,int y){
			if(x<1 || x>n)	return ;
			// chkmin(d[x],y);
			modify(1,x,y);
		}
		int qry(int l,int r){
			if(l>r)	return INT_INF;
			return query(1,l,r);
			// int ret=INT_INF;
			// foru(i,l,r){
			// 	chkmin(ret,d[i]);
			// }
			// return ret;
		}
	}ds;

public:

	void append(int x,int y,int w){
		ls[x]+=Point{y,w};
		ls[y]+=Point{x,w};
	}
	void add_qry(int l,int r,int& w){
		if(l>1){
			lf[l-1]+=QRY{l,r,w};
		}
		if(r<n){
			rf[r+1]+=QRY{l,r,w};
		}
		// for(auto [x,y,z]:ls){
		// 	if(inrange(l,x,r)^inrange(l,y,r)){
		// 		chkmin(w,z);
		// 	}
		// }
	}
	void process(){
		ds.init();
		foru(i,1,n){
			for(auto [y,z]:ls[i]){
				ds.add(y,z);
			}
			for(auto& [l,r,w]:lf[i]){
				chkmin(w,ds.qry(l,r));
			}
		}

		ds.init();
		ford(i,n,1){
			for(auto [y,z]:ls[i]){
				ds.add(y,z);
			}
			for(auto& [l,r,w]:rf[i]){
				chkmin(w,ds.qry(l,r));
			}
		}
	}
}ds;

void processW(){
	gen(n);
	dfs1(n,0);

	foru(u,1,n){
		for(auto& [v,id,w]:e[u]){
			if(ont[id])	continue;
			if(v<u)	continue;
			ds.append(dfn[u],dfn[v],dep[u]+dep[v]);
		}
	}

	foru(u,1,n){
		for(auto& [v,id,w]:e[u]){
			if(ndis[u]+1==ndis[v]){
				w=ndis[u]+ndis[u]-1;
				continue;
			}
			if(!ont[id]){
				w=ndis[u]+ndis[u]-1;
				continue;
			}
			assert(ndis[u]==ndis[v]+1);
			
			int L=dfn[u],R=dfn[u]+sz[u]-1;

			w=INT_INF;

			ds.add_qry(L,R,w);
			// access(id,u);
			// w=dis[u];
		}
	}

	ds.process();

	foru(u,1,n){
		for(auto& [v,id,w]:e[u]){
			if(w!=INT_INF)	w+=-ndis[u]+1;
		}
	}
}

bool check(int lm){
	while(!q.empty())	q.pop();
	foru(i,1,n){
		dis[i]=INT_INF;
	}
	
	q.push(1);
	dis[1]=0;
	
	while(!q.empty()){
		int u=q.front();
		q.pop();

		for(auto& [v,id,w]:e[u]){
			if(dis[u]+w>lm)	continue;
			if(dis[v]==INT_INF){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}

	return dis[n]!=INT_INF;
}

void solve(bool SPE){ 
	n=RIN,m=RIN;
	foru(i,1,m){
		int u=RIN,v=RIN;
		e[u]+=Edge{v,i,0};
		e[v]+=Edge{u,i,0};
	}

	predis();
	processW();

	int l=0,r=2*n,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}

	cout<<ans;

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
	// if(freopen("ex_city0.in","r",stdin));
	if(freopen("city.in","r",stdin));
	if(freopen("city.out","w",stdout));
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