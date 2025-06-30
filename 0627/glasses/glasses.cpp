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

int mod;
// constexpr int mod=1e9+7;

int& mdd(int& x){return x;}
template<class T1,class ...T2>
int& mdd(int& x,const T1& y,const T2& ...xr){
	x+=y;
	if(x>=mod)	x-=mod;
	return mdd(x,xr...);
}
int& mmv(int& x){return x;}
template<class T1,class ...T2>
int& mmv(int& x,const T1& y,const T2& ...xr){
	x-=y;
	if(x<0)	x+=mod;
	return mmv(x,xr...);
}
int& mll(int& x){return x;}
template<class T1,class ...T2>
int& mll(int& x,const T1& y,const T2& ...xr){
	x=(LL)x*y%mod;
	return mll(x,xr...);
}
int add(const int& x){return x;}
template<class ...T>
int add(const int& x,const T& ...xr){
	int ret=x+add(xr...);
	if(ret>=mod)	ret-=mod;
	return ret;
}
int mul(const int& x){return x;}
template<class ...T>
int mul(const int& x,const T& ...xr){
	return (LL)x*mul(xr...)%mod;
}
int rmv(int x,int y){
	x-=y;
	if(x<0)	x+=mod;
	return x;
}
int mev(const int& x){return mod-x;}

int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)	mll(ret,x);
		mll(x,x),y>>=1;
	}
	return ret;
}

/*

令 M=2^m-1

我要计算 f[n] 表示，选出来一个大小为 n 的集合，异或和为 0 的方案数

对于所有大小为 n-1 的集合，我可以尝试往它里面加一个等于它异或和的数，这样新集合异或和为 0

方案数是 C(M,n-1)。一个集合可以被这样生成 n 次，再除以 n

然后要去掉一些情况

C(M,n-1) 里，有些集合的异或和是 0，因为元素不能是 0,没法加入新的数，需要去掉。方案数是 f[n-1]

一些集合，它的异或和就在它的集合里。这个情况下无法加入等于它异或和的数。

剩下的都可以搞

问题变成计算 g[n] 表示，选出来一个大小为 n 的集合，这个集合的异或和是这个集合的元素

考虑把那个元素去掉，那么一定得到了一个大小为 n-1 的异或和为 0 的集合，和 f[n-1] 有联系。考虑怎么构建映射关系。

g[n] 的每个方案，按照上述规则，每人严格对应一个 f[n-1] 的方案

f[n-1] 内的每个方案，可以生成 M-(n-1) 个 g[n] 的方案

转移系数直接是 M-(n-1)

*/

int type,n,m;

namespace SUB1{
	int fac[1000005];
	int ifac[1000005];
	int C(int n,int m){
		return mul(fac[n],ifac[m],ifac[n-m]);
	}
	// int f[45][1000005];
	int f[1000005];
	void work(){
		fac[0]=1;
		foru(i,1,1000000){
			fac[i]=mul(fac[i-1],i);
		}
		ifac[1000000]=qpow(fac[1000000],mod-2);
		ford(i,1000000-1,0){
			ifac[i]=mul(ifac[i+1],i+1);
		}

		int M=rmv(qpow(2,m),1);

		f[0]=1;
		f[1]=0;
		
		int mi=1;
		foru(i,2,n){
			mi=mul(mi,M-i+2);

			f[i]=mul(mi,ifac[i-1]);
			mmv(f[i],f[i-1]);
			mmv(f[i],mul(f[i-2],rmv(M,i-2)));
			mll(f[i],qpow(i,mod-2));

			// cout<<i<<' '<<f[i]<<endl;
		}

		cout<<f[n];


		// f[0][1]=1;
		// // cerr<<n<<' '<<m<<endl;
		// // exit(0);
		// foru(i,0,m-1){
		// 	foru(j,1,n){
		// 		if(f[i][j]==0)	continue;
		// 		cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
		// 		foru(x,0,j){
		// 			int nj=x*2+(j-x);
		// 			if(nj>n)	break;
		// 			for(int y=0;y<=j-x;y++){
		// 				if((y+x)&1)	continue;
		// 				mdd(f[i+1][nj],mul(f[i][j],C(j-x,y)));
		// 				// cerr<<j-x<<' '<<y<<endl;
		// 			}
		// 		}
		// 	}
		// }

		// cout<<f[m][n];
	}
}

namespace SUB0{
	int ans=0;
	int a[1000];
	void dfs(int u,int pre,int xs){
		if(u==n+1){
			if(xs==0){
				foru(i,1,n){
					cout<<a[i]<<' ';
				}
				HH;
				ans++;
			}
			return ;
		}
		for(int i=pre+1;i<(1<<m);i++){
			a[u]=i;
			dfs(u+1,i,xs^i);
		}
	}
	void work(){
		dfs(1,0,0);
		cout<<ans%mod;
	}
}

void solve(bool SPE){ 
	type=RIN,n=RIN,m=RIN,mod=RIN;

	// if(type==1 && n<=5 && m<=5){
	// 	SUB0::work();
	// 	return ;
	// }
	if(type==1 && n<=1000000 && m<=45){
		SUB1::work();
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
	if(freopen("glasses2.in","r",stdin));
	#ifdef ONLINE_JUDGE
	if(freopen("glasses.in","r",stdin));
	if(freopen("glasses.out","w",stdout));
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