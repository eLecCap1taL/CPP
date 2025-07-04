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

bool m_begin;

class ACAM{
public:
	class Node{
		int ch[26];
	public:
		int fail;
		int& operator [] (const int& idx){
			return ch[idx];
		}
	}tr[1000005];
	int N,rt;

	int fetch(int& p,int i,const string& s){
		if(!p)	p=++N;
		if(i==sz(s))	return p;
		return fetch(tr[p][s[i]-'a'],i+1,s);
	}

	void build(){
		tr[0].fail=tr[1].fail=0;
		for(int i=0;i<26;i++)	tr[0][i]=1;

		queue<int> q;
		q.push(1);
		
		while(!q.empty()){
			int p=q.front();
			q.pop();
			for(int i=0;i<26;i++){
				if(tr[p][i]){
					tr[tr[p][i]].fail=tr[tr[p].fail][i];
					q.push(tr[p][i]);
				}else{
					tr[p][i]=tr[tr[p].fail][i];
				}
			}
		}
	}

	Node& operator [] (const int& idx){
		return tr[idx];
	}
}acam,acam_rev;

int n,m;
string s[500005];
string t[500005];
u64 w[500005];

u64 A[1000005];
u64 B[1000005];
int dfnA[1000005];
int dfnB[1000005];
int szA[1000005];
int szB[1000005];

vector<int> e[1000005];
void gen(ACAM& ac,int* dfn,int* sz){
	static int DFN;

	int N=ac.N;

	foru(i,1,N){
		e[i].clear();
	}
	DFN=0;

	auto dfs=[&](auto& dfs,int u)->void {
		dfn[u]=++DFN;
		sz[u]=1;
		for(auto v:e[u])	dfs(dfs,v),sz[u]+=sz[v];
	};

	foru(i,2,N){
		e[ac[i].fail]+=i;
	}

	dfs(dfs,1);
}

class RecDS{
	int N,M;
	u64 Bsum=0;
	class Node{
	public:
		int l,r;
		int mn;
		int tg;
		u64 s;
	}tr[1000005<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return x<<1|1;}
	void push_up(int p){
		if(tr[lc(p)].mn<tr[rc(p)].mn){
			tr[p].mn=tr[lc(p)].mn;
			tr[p].s=tr[lc(p)].s;
		}else if(tr[rc(p)].mn<tr[lc(p)].mn){
			tr[p].mn=tr[rc(p)].mn;
			tr[p].s=tr[rc(p)].s;
		}else{
			tr[p].mn=tr[lc(p)].mn;
			tr[p].s=tr[lc(p)].s+tr[rc(p)].s;
		}
	}
	void upd(int p,int k){
		tr[p].tg+=k;
		tr[p].mn+=k;
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
			tr[p].mn=0;
			tr[p].s=B[l];
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
	u64 qry(){
		return Bsum-(tr[1].mn==0)*tr[1].s;
	}
public:
	void init(){
		N=acam.N;
		M=acam_rev.N;
		foru(i,1,N){
			A[i]+=A[i-1];
		}
		foru(i,1,M){
			Bsum+=B[i];
		}
		build(1,1,M);
		// cout<<qry()<<endl;
	}

	class Event{
	public:
		int x,l,r;
		bool ty;
		bool operator < (const Event& o)const{
			if(x==o.x)	return ty<o.ty;
			else	return x<o.x;
		}
	};
	vector<Event> els;

	// vector<pair<int,int>> ls;
	void clear(){
		// ls.clear();
		els.clear();
		// build(1,1,M);
	}
	void add_rec(int xl,int xr,int yl,int yr){
		els+=Event{xl,yl,yr,0};
		els+=Event{xr+1,yl,yr,1};
		// foru(i,xl,xr){
		// 	foru(j,yl,yr){
		// 		ls+=mkp(i,j);
		// 	}
		// }
	}
	u64 calc(){
		u64 ret=0;

		sort(All(els));
		for(int i=0;i<sz(els);i++){
			auto [x,l,r,ty]=els[i];
			if(ty==0){
				modify(1,l,r,1);
			}else{
				modify(1,l,r,-1);
			}
			if(i+1<sz(els) && els[i+1].x>els[i].x){
				ret+=qry()*(A[els[i+1].x-1]-A[els[i].x-1]);
			}
		}

		// assert(qry()==0);

		// ret=0;
		// sort(All(ls));
		// ls.erase(unique(All(ls)),ls.end());
		// for(auto [x,y]:ls){
		// 	// cerr<<x<<' '<<y<<' '<<(A[x]-A[x-1])*B[y]<<endl;
		// 	// cerr<<(A[x]-A[x-1])<<' '<<B[y]<<endl;
		// 	ret+=1ull*(A[x]-A[x-1])*B[y];
		// }

		// cerr<<ret<<endl;
		// exit(0);

		return ret;
	}
}rec;

int rf[1000005];
void solve(bool SPE){ 
	n=RIN,m=RIN;
	foru(i,1,m){
		t[i]=RSIN;
		w[i]=RIN;
	}
	foru(i,1,n){
		s[i]=RSIN;
	}

	//add t
	foru(i,1,m){
		acam.fetch(acam.rt,0,t[i]);
		reverse(All(t[i]));
		acam_rev.fetch(acam_rev.rt,0,t[i]);
		reverse(All(t[i]));
	}

	acam.build();
	acam_rev.build();

	gen(acam,dfnA,szA);
	gen(acam_rev,dfnB,szB);

	foru(i,1,n){
		A[dfnA[acam.fetch(acam.rt,0,s[i])]]++;
		reverse(All(s[i]));
		B[dfnB[acam_rev.fetch(acam_rev.rt,0,s[i])]]++;
		reverse(All(s[i]));
	}

	//calc
	u64 ans=0;
	rec.init();

	foru(o,1,m){
		int N=sz(t[o]);

		rf[N]=acam_rev.rt;
		for(int i=N-1;i>=0;i--){
			rf[i]=acam_rev[rf[i+1]][t[o][i]-'a'];
		}

		rec.clear();

		int lf=acam.rt;
		for(int i=0;i+1<N;i++){
			lf=acam[lf][t[o][i]-'a'];

			rec.add_rec(dfnA[lf],dfnA[lf]+szA[lf]-1,dfnB[rf[i+1]],dfnB[rf[i+1]]+szB[rf[i+1]]-1);
		}

		ans+=w[o]*rec.calc();
	}
	
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
	if(freopen("eden2.in","r",stdin));
	// if(freopen("eden.in","r",stdin));
	// if(freopen("eden.out","w",stdout));
	#endif
	#endif
	
	#ifdef MULTITEST
	int T=RIN;
	#else
	int T=1;
	#endif

	cerr<<"static memory:"<<(&m_begin-&m_end)/1024/1024<<endl;

	for(int i=1;i<=T;i++){
		solve(i==0);
	}
	return 0;
}