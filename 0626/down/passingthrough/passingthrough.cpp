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

class Edge{
public:
	int u,v,l,r;
	bool operator < (const Edge& x)const{
		return r==x.r?l<x.l:r<x.r;
	}
}eg[3505];


namespace GenEdge{
	vector<pair<int,int>> e[3505];
	struct FindTarget{};
	struct Invalid{};
	vector<int> ls;
	void dfs(int u,int fath,int t,int& l,int& r){
		if(u==t){
			for(auto i:ls){
				chkmin(eg[i].r,r);
				if(eg[i].r<eg[i].l){
					cout<<"-1";
					exit(0);
				}
				chkmax(l,eg[i].l);
			}

			throw FindTarget();
			cerr<<"eee";
		}
		for(auto [v,id]:e[u]){
			if(v==fath)	continue;
			ls+=id;
			dfs(v,u,t,l,r);
			ls.pop_back();
		}
	}
	void work(){
		foru(i,1,n-1){
			auto [u,v,l,r]=eg[i];
			e[u]+=mkp(v,i);
			e[v]+=mkp(u,i);
		}
		foru(i,n,m){
			auto& [u,v,l,r]=eg[i];
			try{
				ls.clear();
				dfs(u,0,v,l,r);
			}catch(FindTarget){

			}
		}
	}
}

int ans[3505];

bool us[3505];
vector<Edge> els;

class DSU{
	int fa[3505];
	class Range{
	public:
		int l,r;
		int operator ()()const{
			return r-l+1;
		}
	}rg[3505];
public:
	int find(int x){
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	void Union(int x,int y){
		x=find(x),y=find(y);
		if(x==y)	return ;
		if(rg[x]()<rg[y]())	swap(x,y);
		fa[y]=x;
		if(rg[x].r+1==rg[y].l){
			rg[x].r=rg[y].r;
		}else{
			rg[x].l=rg[y].l;
			// return ;
			// if(rg[x].l-1==rg[y].r){
			// 	rg[x].l=rg[y].l;
			// }else{
			// 	// cerr<<rg[x].l<<' '<<rg[x].r<<endl;
			// 	// cerr<<rg[y].l<<' '<<rg[y].r<<endl;
			// 	exit(1);
			// }
		}
	}
	void reset(){
		foru(i,1,m){
			fa[i]=i;
			rg[i]={i,i};
		}
	}
	Range operator [](const int& x)const{
		return rg[x];
	}
};

class DS{
	DSU dsu;
	bitset<3505> ac;
	int N=0;
public:
	void reset(){
		// cerr<<"reset"<<endl;
		dsu.reset();
		ac.reset();
		N=0;
	}	
	void append(){
		// cerr<<"append "<<' '<<N+1<<endl;
		N++;
		ac[N]=1;
	}
	int get(int x){
		// assert(x<=N);
		// cerr<<"get "<<x<<endl;
		x=dsu.find(x);
		if(ac[x]){
			// cerr<<"ret1 "<<x<<endl;
			return x;
		}
		if(dsu[x].r==N){
			// cerr<<"ret2 "<<-1<<endl;
			return -1;
		}else{
			// cerr<<"ret3 "<<dsu[x].r+1<<endl;
			return dsu[x].r+1;
		}
	}
	void deactive(int x){
		// cerr<<"deactive "<<x<<endl;
		// assert(x<=N);
		// assert(ac[x]);
		// assert(dsu[x].l==dsu[x].r);
		ac[x]=0;
		int y=0;

		if(x<N){
			y=dsu.find(x+1);
			if(!ac[y]){
				dsu.Union(x,y);
			}
		}
		if(x>1){
			y=dsu.find(x-1);
			if(!ac[y]){
				dsu.Union(x,y);
			}
		}
	}
}ds;

bool check(int o,int l,int r){
	bool uso=0;

	ds.reset();

	int j=0;
	foru(i,1,m){
		ds.append();
		if(us[i])	ds.deactive(i);
		// if(us[i]==0)	st.insert(i);

		if(uso==0 && i==r && (j==sz(els) || els[j].r>i || els[j].l>l)){
			uso=1;
			int x=ds.get(l);
			if(x==-1)	return false;
			ds.deactive(x);
			// auto it=st.lower_bound(l);
			// if(it==st.end())	return false;
			// st.erase(it);
		}
		while(j<sz(els) && els[j].r==i){
			int x=ds.get(els[j].l);
			if(x==-1)	return false;
			ds.deactive(x);
			j++;
			
			if(uso==0 && i==r && (j==sz(els) || els[j].r>i || els[j].l>l)){
				uso=1;
				int x=ds.get(l);
				if(x==-1)	return false;
				ds.deactive(x);
			}
		}
	}

	return true;
}

void solve(bool SPE){ 
	n=RIN,m=RIN;

	foru(i,1,m){
		eg[i]={RIN,RIN,RIN,RIN};
	}

	GenEdge::work();

	// foru(i,1,m){
	// 	cout<<eg[i].l<<' '<<eg[i].r<<endl;
	// }

	foru(i,1,m){
		// cerr<<i<<endl;

		els.clear();
		foru(j,i+1,m){
			els+=eg[j];
		}
		sort(All(els));
		
		int l=eg[i].l;
		int r=eg[i].r;
		ans[i]=-1;

		// cout<<check(i,l,r)<<endl;

		// if(sz(els))ans[i]=els.back().l;

		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,l,mid)){
				ans[i]=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}

		if(ans[i]==-1){
			cout<<"-1";
			return ;
		}

		// cerr<<i<<' '<<ans[i]<<endl;

		us[ans[i]]=1;
	}

	foru(i,1,m){
		cout<<ans[i]-1<<' ';
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
	if(freopen("ex_passingthrough3.in","r",stdin));
	// if(freopen("passingthrough.in","r",stdin));
	if(freopen("passingthrough.out","w",stdout));
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