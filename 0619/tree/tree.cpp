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
int n;
vector<int> e[MAXN];

class QR{
public:
	int l,r;
}qr[500005];
int q;

namespace SLPF{
	int fa[MAXN];
	int id[MAXN];
	int top[MAXN];
	int dep[MAXN];
	int sz[MAXN];
	int son[MAXN];
	int DFN;
	void dfs1(int u,int fath){
		sz[u]=1;
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
		id[u]=++DFN;
		top[u]=topf;
		if(son[u]==0)	return ;
		dfs2(son[u],topf);
		for(auto v:e[u]){
			if(v==fa[u] || v==son[u])	continue;
			dfs2(v,v);
		}
	}
	void findpath(int u,int v,function<void(int,int)> callback){
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]])	swap(u,v);
			callback(id[top[u]],id[u]);
			u=fa[top[u]];
		}
		if(dep[u]>dep[v])	swap(u,v);
		callback(id[u],id[v]);
	}
}

class Range{
public:
	int l,r,c;
	bool operator < (const Range& x)const{
		return l==x.l?r<x.r:l<x.l;
	};
};
ostream& operator << (ostream& os,const Range& x){
	os<<'['<<x.l<<','<<x.r<<','<<x.c<<']';
	return os;
}
class ODT{
	int N;
	// int cl[MAXN];
	set<Range> st;
public:
	void cov(int l,int r,int c,function<void(int,int)> callback){
		// cerr<<"cv "<<l<<' '<<r<<' '<<c<<endl;
		// foru(i,l,r){
		// 	if(cl[i]<c){
		// 		callback(1,cl[i]);
		// 		cl[i]=c;
		// 	}
		// }
		auto it=st.lower_bound(Range{l,l,0});
		while(it->l<=r){
			if(it->r<=r){
				callback(it->r-it->l+1,it->c);
				it=st.erase(it);
				continue;
			}
			callback(r-it->l+1,it->c);
			int R=it->r,C=it->c;
			st.erase(it);
			it=st.insert({r+1,R,C}).fi;
			break;
		}
		it--;
		if(it->r>r){
			callback(r-l+1,it->c);
			int L=it->l,R=it->r,C=it->c;
			st.erase(it);
			st.insert({L,l-1,C});
			st.insert({r+1,R,C});
		}else if(it->r>=l){
			callback(it->r-l+1,it->c);
			int L=it->l,C=it->c;
			st.erase(it);
			st.insert({L,l-1,C});
		}
		st.insert({l,r,c});
		// cein<<st<<endl;
	}
	void init(int _n){
		N=_n;
		st.clear();
		st.insert({0,0,-1});
		st.insert({1,n,1});
		st.insert({n+1,n+1,-1});
		// cein<<st<<endl;
		// foru(i,1,N){
		// 	cl[i]=1;
		// }
	}
}odt;

class DS{
	class Node{
	public:
		int l,r;
		LL s,h;
		LL a,b,c;
	}tr[MAXN<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return x<<1|1;}
	void push_up(int p){
		tr[p].s=tr[lc(p)].s+tr[rc(p)].s;
		tr[p].h=tr[lc(p)].h+tr[rc(p)].h;
	}
	void upd(int p,LL a,LL b,LL c){
		const int L=tr[p].r-tr[p].l+1;
		tr[p].c+=c+tr[p].b*a;
		tr[p].a+=a;
		tr[p].b+=b;
		
		tr[p].h+=a*tr[p].s+c*L;
		tr[p].s+=b*L;
	}
	void push_down(int p){
		if(tr[p].a || tr[p].b || tr[p].c){
			upd(lc(p),tr[p].a,tr[p].b,tr[p].c);
			upd(rc(p),tr[p].a,tr[p].b,tr[p].c);
			tr[p].a=0;
			tr[p].b=0;
			tr[p].c=0;
		}
	}
	void build(int p,int l,int r){
		tr[p].l=l,tr[p].r=r;
		tr[p].s=tr[p].h=0;
		tr[p].a=tr[p].b=tr[p].c=0;
		if(l==r)	return ;
		int mid=(l+r)>>1;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
	}
	void modify(int p,int l,int r,LL k){
		if(l<=tr[p].l && tr[p].r<=r){
			upd(p,0,k,0);
			return ;
		}
		int mid=(tr[p].l+tr[p].r)>>1;
		push_down(p);
		if(l<=mid)	modify(lc(p),l,r,k);
		if(r>mid)	modify(rc(p),l,r,k);
		push_up(p);
	}
	LL query(int p,int l,int r){
		if(l<=tr[p].l && tr[p].r<=r)	return tr[p].h;
		LL ret=0;
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		if(l<=mid)	ret+=query(lc(p),l,r);
		if(r>mid)	ret+=query(rc(p),l,r);
		return ret;
	}
public:
	// int d[MAXN];
	// LL h[MAXN];
	void add(int l,int r,int k){
		modify(1,l,r,k);
		// foru(i,l,r){
		// 	d[i]+=k;
		// }
	}
	void backup(){
		upd(1,1,0,0);
		// foru(i,1,n){
		// 	h[i]+=d[i];
		// }
	}
	LL qry(int l,int r){
		return query(1,l,r);
		// LL ret=0;
		// foru(i,l,r){
		// 	ret+=h[i];
		// }
		// return ret;
	}
	void init(){
		build(1,1,n);
	}
}ds;

vector<int> qls[MAXN];
LL ans[500005];

void process(){
	odt.init(n);
	ds.init();
	foru(u,1,n){
		if(u>1){
			int v=u-1;
			SLPF::findpath(v,u,[&](int l,int r)->void {
				odt.cov(l,r,u,[&](int len,int t)->void {
					ds.add(t,u-1,len);
				});
			});	
			ds.backup();
		}

		// foru(i,1,n){
		// 	cout<<ds.d[i]<<' ';
		// }
		// HH;
		// foru(i,1,n){
		// 	cout<<ds.h[i]<<' ';
		// }
		// HH;
		for(auto i:qls[u]){
			auto [l,r]=qr[i];
			ans[i]=ds.qry(l,r)+r-l+1;
		}
	}
}

void solve(bool SPE){ 
	n=RIN;
	foru(i,1,n-1){
		int u=RIN,v=RIN;
		e[u]+=v;
		e[v]+=u;
	}
	q=RIN;
	foru(i,1,q){
		qr[i]={RIN,RIN};
		qls[qr[i].r]+=i;
	}
	
	SLPF::dfs1(1,0);
	SLPF::dfs2(1,1);

	process();

	foru(i,1,q){
		cout<<ans[i]<<'\n';
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
	if(freopen("tree1.in","r",stdin));
	// if(freopen("tree.in","r",stdin));
	// if(freopen("tree.out","w",stdout));
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