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
#define ford(a, b, c) for (int a = (b); (a) >= (c); (a)++)
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
using namespace std;
// const int RANDOM = time(0);
// template<class T1,class T2>
// class tr1::hash<pair<T1,T2>>{
// public:
	// size_t operator () (pair<T1,T2> x)const{
		// tr1::hash<T1> H1;
		// tr1::hash<T2> H2;
		// return H1(x.fi)^H2(x.se)^RANDOM;
	// }
// };
typedef __int128 i128;
typedef unsigned __int128 u128;
typedef long long i64;
typedef unsigned long long u64;
typedef int i32;
typedef unsigned u32;
typedef short i16;
typedef unsigned short u16;
typedef char i8;
int ID;
class Cap1taLDebug{
	#ifdef LXF
	#define READTYPE LXF
	#else
	#define READTYPE int
	#endif
	#define DEBUGING
private:
	ostream& buf;
	#ifndef DEBUGING
	static char fbuf[1<<21],*p1,*p2;
	#define getchar() (Cap1taLDebug::p1==p2&&(p1=(p2=fbuf)+fread(fbuf,1,1<<21,stdin),p1==p2)?EOF:*p2++)
	#endif
public:
	Cap1taLDebug(ostream& out=cout):buf(out){}
	~Cap1taLDebug(){
		#ifdef DEBUGING
		buf.flush();
		#endif
	}
	static READTYPE read(){
		READTYPE x=0,w=1;char ch=0;
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
template<typename T>
class Stack : public stack<T>{
public:
	void clear(){
		while(!this->empty())	this->pop();
	}
	void popuntil(const function<bool(T)>& func){
		while(!this->empty() && !func(this->top()))	this->pop();
	}
};
template<typename T>
vector<T>& operator += (vector<T>& x,const T& y){
	x.push_back(y);
	return x;
}
template<typename T1,typename T2>
inline bool chkmax(T1& x,const T2& y){return (T1)x<y?x=(T1)y,true:false;}
template<typename T1,typename T2>
inline bool chkmin(T1& x,const T2& y){return (T1)y<x?x=(T1)y,true:false;}
class TIMECHKER{
	public:
		~TIMECHKER(){
			cerr<<endl<<clock()*1.0/CLOCKS_PER_SEC<<endl;
		}
	}TIMECHECKER;
/*

*/
int mod=998244353;

void mdd(int &x,int y){
	x+=y;
	if(x>=mod)	x-=mod;
}
void mmv(int &x,int y){
	x-=y;
	if(x<0)	x+=mod;
}
int mul(int x){return x;}
template<class ... T>
inline int mul(const int& x,const T& ... xr){
	return (LL)x*mul(xr...)%mod;
}
int add(int x){return x;}
template<class ... T>
inline int add(int x,const T& ... xr){
	x+=add(xr...);
	if(x>=mod)	x-=mod;
	return x;
}

int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1) ret=mul(ret,x);
		x=mul(x,x),y>>=1;
	}
	return ret;
}

int inv;
int n;
int a[MAXN];
int fac[MAXN];
int ifac[MAXN];
int C(int n,int m){
	if(n<m)	return 0;
	return mul(fac[n],ifac[m],ifac[n-m]);
}
void solve(bool SPE){ 
	n=RIN;
	inv=qpow(n-1,mod-2);
	fac[0]=1;
	foru(i,1,n){
		fac[i]=mul(fac[i-1],i);
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--){
		ifac[i]=mul(ifac[i+1],i+1);
	}

	foru(i,1,n){
		a[i]=RIN;
	}

	int f=0;
	foru(i,2,n){
		mdd(f,mul(max(a[1]-a[i],0),qpow(inv,2),i-1));
		int N=0;
		foru(j,2,i-1){
			N+=a[j]>=a[i];
		}
		foru(j,i+1,n){
			N+=a[j]>a[i];
		}
		foru(k,0,N){
			mdd(f,mul(min(a[1],a[i]),qpow(inv,k+2),C(N,k)));
		}
	}
	foru(i,2,n){
		foru(j,i+1,n){
			for(int k=0;k<=j-i-1;k++){
				mdd(f,mul(max(a[1]-a[i],0),qpow(inv,k+3),j-1,C(j-i-1,k)));
			}
		}
	}
	cout<<f<<'\n';

	foru(o,2,n){
		int F=0;

		//pass, return
		for(int S=1;S<(1<<(n-1));S++){
			if(!((S>>(o-2))&1))	continue;
			int mn=INT_MAX;
			int lst=-1;
			foru(i,2,n){
				if((S>>(i-2))&1){
					chkmin(mn,a[i]);
					lst=i;
				}
			}
			if(lst<=o)	continue;
			int pc=__builtin_popcount(S);
			mdd(F,mul(min(a[1],mn),qpow(inv,pc)));
		}

		// cerr<<F<<' ';

		// come to o
		for(int T=0;T<(1<<(o-2));T++){
			int a1=min(a[1],a[o]);
			foru(i,2,o-1){
				if((T>>(i-2))&1)	chkmin(a1,a[i]);
			}
			int P=qpow(inv,__builtin_popcount(T)+1);

			foru(i,2,o-1){
				if((T>>(i-2))&1)	continue;
				mdd(F,mul(max(a1-a[i],0),P,inv));
			}

			foru(i,o+1,n){
				int N=0;
				foru(j,o+1,i-1){
					N+=a[j]>=a[i];
				}
				foru(j,i+1,n){
					N+=a[j]>a[i];
				}
				foru(k,0,N){
					mdd(F,mul(min(a1,a[i]),qpow(inv,k+2),P,C(N,k)));
				}

				mdd(F,mul(max(a1-a[i],0),qpow(inv,2),P,i-1));
			}
			foru(i,o+1,n){
				foru(j,i+1,n){
					for(int k=0;k<=j-i-1;k++){
						mdd(F,mul(max(a1-a[i],0),qpow(inv,k+3),P,j-1,C(j-i-1,k)));
					}
				}
			}
		}

		cout<<F<<'\n';
	}
	
	#ifdef DEBUGING
	if(SPE){
		
	}
	#endif
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
	// #define TESTCASEID
	
	#ifndef ONLINE_JUDGE
	#ifndef CPEDITOR
	if(freopen("bottle3.in","r",stdin));
	// if(freopen("bottle.in","r",stdin));
	// if(freopen("bottle.out","w",stdout));
	#endif
	#endif
	
	#ifdef MULTITEST
	int T=RIN;
	#else
	int T=1;
	#endif
	
	#ifdef TESTCASEID
	ID=RIN;
	#endif
	
	for(int i=1;i<=T;i++) solve(i==0);
	return 0;
}