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
#define MAXN 55
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

// constexpr int mod=998244353;
constexpr int mod=1e9+7;

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
int n,p;
LL k,m;
class OPT{
public:
	LL l,r,b,a;
}op[MAXN];
namespace SUB1{
	void work(){
		int ans=0;
		foru(o,1,n){
			auto [l,r,b,a]=op[o];

			mdd(ans,mul((r-l+1)%mod,a));
		}
		cout<<ans;
	}
}
namespace SUB2{
	LL d[1000005];
	int F[2][105][2];
	void work(){
		foru(o,1,n){
			auto [l,r,b,a]=op[o];
			foru(j,l,r){
				d[(k*j+b)%m]+=a;
			}
		}
		F[0][0][0]=1;
		foru(i,1,m){
			auto f=F[i&1];
			auto g=F[(i-1)&1];

			foru(j,0,p)	f[j][0]=f[j][1]=0;

			d[i-1]%=mod;
			foru(j,0,p){
				f[j][0]=add(g[j][0],g[j][1]);
				if(j>0){
					f[j][1]=mul(g[j-1][0],d[i-1]);
				}
			}
		}
		cout<<add(F[m&1][p][0],F[m&1][p][1]);
	}
}

namespace SUB3{
	map<LL,int> mp;
	
	int fac[105];
	int ifac[105];

	int C(LL N,int M){
		if(N<M)	return 0;
		int ret=1;
		for(LL x=N;x>(N-M);x--)	mll(ret,x%mod);
		return mul(ret,ifac[M]);
	}
	int calc(LL N,int M){
		if(N<0 || M<0)	return 0;
		return C(N-M+1,M);
	}

	int f[105][2],g[105][2];
	void work(){
		fac[0]=1;
		foru(i,1,100){
			fac[i]=mul(fac[i-1],i);
		}
		foru(i,0,100){
			ifac[i]=qpow(fac[i],mod-2);
		}

		// cout<<calc(3,2)<<endl;


		mp[m]=0;
		foru(o,1,n){
			auto [l,r,b,a]=op[o];
			LL L=(l+b)%m;
			LL R=(r+b)%m;
			if(L<=R){
				mdd(mp[L],a);
				mmv(mp[L+1],a);
			}else{
				mdd(mp[L],a);
				mmv(mp[m],a);
				mdd(mp[0],a);
				mmv(mp[R+1],a);
			}
		}

			// cerr<<calc(7,0)<<endl;
		f[0][0]=1;
		auto process=[&](LL N,int v){
			foru(i,0,p){
				g[i][0]=f[i][0];
				g[i][1]=f[i][1];
				f[i][0]=f[i][1]=0;
			}

			static int val[105][2][2];

			int top=min((LL)p,(N+1)/2);
			if(N==1){
				val[0][0][0]=val[0][1][1]=1;
				val[0][0][1]=val[0][1][0]=0;

				val[1][0][0]=val[1][1][1]=v;
				val[1][0][1]=val[1][1][0]=0;
			}else{
				int V=1;
				foru(i,0,top){
					val[i][0][0]=mul(calc(N-2,i),V);
					val[i][0][1]=val[i][1][0]=mul(calc(N-3,i-1),V);
					val[i][1][1]=mul(calc(N-4,i-2),V);
					
					mll(V,v);
				}
			}
			cerr<<N<<'~'<<v<<endl;
			// cerr<<val[1][1][1]<<endl;
			foru(i,0,p){
				foru(j,0,min(top,p-i)){
					// if(g[i])
					// cerr<<g[i][0]<<"~"<<' '<<valendl;
					mdd(f[i+j][1],mul(g[i][0],val[j][0][1]));
					mdd(f[i+j][1],mul(g[i][0],val[j][1][1]));

					mdd(f[i+j][1],mul(g[i][1],val[j][0][1]));
					
					mdd(f[i+j][0],mul(g[i][0],val[j][0][0]));
					mdd(f[i+j][0],mul(g[i][0],val[j][1][0]));

					mdd(f[i+j][0],mul(g[i][1],val[j][0][0]));
				}
			}

			// cout<<f[1][0]<<' '<<f[1][1]<<endl;
			// cout<<val[0][0][0]<<endl;
			// foru(i,0,p){
			// 	cout<<f[i][0]<<' '<<f[i][1]<<endl;
			// }
			// cout<<endl;
			// exit(0);
		};
		int x=0;
		int i=0;
		for(auto it=mp.begin();it->fi<m;it++){
			mdd(x,it->se);
			process(next(it)->fi-it->fi,x);
			// break;
			// i++;
			// if(i==2)	break;
		}

		cout<<add(f[p][0],f[p][1]);
	}
}

void solve(bool SPE){ 
	n=RIN,k=RIN,m=RIN,p=RIN;

	foru(i,1,n){
		op[i]={RIN,RIN,RIN,RIN};
	}

	if(p==1){
		SUB1::work();
		return ;
	}
	// if(m<=1000000){
	// 	SUB2::work();
	// 	return ;
	// }
	if(k==1){
		SUB3::work();
		return ;
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
	if(freopen("count3.in","r",stdin));
	#ifdef ONLINE_JUDGE
	if(freopen("count.in","r",stdin));
	if(freopen("count.out","w",stdout));
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