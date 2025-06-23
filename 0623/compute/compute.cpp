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
#define MAXN 500005
#define eps 1e-10
#define foru(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int a = (b); (a) >= (c); (a)--)
#define uLL unsigned long long
// #define LL long long
#define LL __int128
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

int n,Q;
LL a[MAXN];
LL k[MAXN];

vector<int> e[MAXN];

namespace SUB1{
	void upd_time(int t){
		static int T=0;
		foru(i,1,n){
			a[i]+=(t-T)*k[i];
		}
		T=t;
	}
	LL sz[MAXN];
	LL dfs(int u,int fath,LL tot){
		LL ret=0;
		sz[u]=a[u];
		for(auto v:e[u]){
			if(v==fath)	continue;
			ret+=dfs(v,u,tot);
			sz[u]+=sz[v];
			ret+=min(sz[v],tot-sz[v]);
		}
		return ret;
	}
	// LL pull(int u,int fath){
	// 	LL ret=0;
	// 	sz[u]=a[u];
	// 	for(auto v:e[u]){
	// 		if(v==fath)	continue;
	// 		ret+=pull(v,u);
	// 		sz[u]+=sz[v];
	// 		ret+=sz[v];
	// 	}
	// 	return ret;
	// }
	void work(){
		while(Q--){
			int opt=RIN;
			if(opt==1){
				int x=RIN,u=RIN,v=RIN,w=RIN;
				upd_time(x);
				k[u]-=w;
				k[v]+=w;
			}else{
				int x=RIN;
				upd_time(x);
				LL tot=0;
				foru(i,1,n){
					tot+=a[i];
				}
				LL ans=dfs(1,0,tot);
				// ans=LLONG_MAX;
				// foru(i,1,n){
				// 	chkmin(ans,pull(i,0));
				// }
				cout<<ans<<'\n';
			}
		}
	}
}

int fa[MAXN];
int sz[MAXN];
LL ks[MAXN];
LL as[MAXN];
void prefetch(int u,int fath){
	fa[u]=fath;
	sz[u]=1;
	ks[u]=k[u];
	as[u]=a[u];
	for(auto v:e[u]){
		if(v==fa[u])	continue;
		prefetch(v,u);
		sz[u]+=sz[v];
		ks[u]+=ks[v];
		as[u]+=as[v];
	}
}

class QR{
public:
	int opt,x,u,v,w;
}qr[MAXN];
LL ans[MAXN];

class DS{
	// LL d[MAXN];
	class Event{
	public:
		int t;
		int ty;
		LL a;
		LL k;
		LL* store;
		bool operator < (const Event& x)const{
			if(t==x.t)	return ty<x.ty;
			return t<x.t;
		}
	};
	vector<Event> els;
public:
	void add(int l,int r,LL a,LL k){
		els+=Event{l,1,a,k,nullptr};
		els+=Event{r,3,a+k*(r-l),k,nullptr};
		// foru(i,l,r){
		// 	d[i]+=a+k*(i-l);
		// }
	}
	void process(){
		sort(All(els));
		LL A=0,K=0;
		int T=0;
		for(auto& [t,ty,a,k,store]:els){
			A+=K*(t-T);
			T=t;

			if(ty==1){
				A+=a;
				K+=k;
			}else if(ty==3){
				A-=a;
				K-=k;
			}else{
				(*store)+=A;
			}
		}
	}
	void qry(int x,LL* store){
		els+=Event{x,2,0,0,store};
		// (*store)+=d[x];
	}
}ds;

class Event{
public:
	int t;
	int w;
};
vector<Event> els[MAXN];
// a node recieve W from father at T

void pushSeg(LL a,LL k,int l,int r){
	if(l>r)	return ;

	ds.add(l,r,a,k);
	// foru(i,1,Q){
	// 	if(qr[i].x<l)	continue;
	// 	if(qr[i].x>r)	break;
	// 	if(qr[i].opt==1)	continue;
	// 	ans[i]+=a+k*(qr[i].x-l);
	// }
}
void pushSeg(LL a1,LL k1,LL a2,LL k2,int l,int r){
	if(l>r)	return ;
	if(a1>a2)	swap(a1,a2),swap(k1,k2);

	int L=l,R=r,p=l;
	while(L<=R){
		int mid=(L+R)>>1;
		if(a1+k1*(mid-l)<=a2+k2*(mid-l)){
			p=mid;
			L=mid+1;
		}else{
			R=mid-1;
		}
	}

	pushSeg(a1,k1,l,p);
	pushSeg(a2+k2*(p+1-l),k2,p+1,r);	
}

void process(int u){
	LL asub=as[u];
	LL ksub=ks[u];
	LL aout=as[1]-as[u];
	LL kout=ks[1]-ks[u];
	for(int o=0;o+1<sz(els[u]);o++){
		int lt=els[u][o].t;
		int rt=els[u][o+1].t;

		pushSeg(asub+ksub,ksub,aout+kout,kout,lt+1,rt-1);

		asub+=ksub*(rt-lt);
		aout+=kout*(rt-lt);

		ksub+=els[u][o+1].w;
		kout-=els[u][o+1].w;
	}
}


void solve(bool SPE){ 
	n=RIN,Q=RIN;
	foru(i,1,n){
		k[i]=RIN;
	}
	foru(i,1,n){
		a[i]=RIN;
	}
	foru(i,2,n){
		int u=RIN,v=RIN;
		e[u]+=v;
		e[v]+=u;
	}

	// if(n<=5000 && Q<=5000){
	// 	SUB1::work();
	// 	return ;
	// }

	foru(i,1,Q){
		qr[i].opt=RIN;
		qr[i].x=RIN;
		if(qr[i].opt==1){
			qr[i].u=RIN;
			qr[i].v=RIN;
			qr[i].w=RIN;
		}
	}

	prefetch(1,0);
	// exit(0);

	foru(i,2,n){
		els[i]+=Event{0,0};
	}
	foru(o,1,Q){
		auto [opt,x,u,v,w]=qr[o];
		if(opt==1){
			if(u==fa[v]){
				els[v]+=Event{x,w};
			}else{
				els[u]+=Event{x,-w};
			}
		}
	}
	foru(i,2,n){
		els[i]+=Event{qr[Q].x+1,0};
	}


	foru(u,2,n){
		process(u);
	}

	foru(i,1,Q){
		if(qr[i].opt==2){
			ds.qry(qr[i].x,&ans[i]);
		}
	}

	ds.process();

	foru(i,1,Q){
		if(qr[i].opt==2){
			cout<<ans[i]<<'\n';
			// printf("%lld\n",ans[i]);
		}
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
	// if(freopen("compute3.in","r",stdin));
	if(freopen("compute.in","r",stdin));
	if(freopen("compute.out","w",stdout));
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