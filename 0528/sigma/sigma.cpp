//%^~
// #pragma GCC optimize(3)
// #pragma GCC optimize("O3")
#pragma GCC optimize("O3,tree-vectorize,unroll-loops")
// #pragma GCC target("native")
// #pragma GCC target("avx2")
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
#define MAXN 250005
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
	// #define DEBUGING
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
int n,q;
u32 a[MAXN];
class OPT{
public:
	int ty;
	int x,y;
}op[100005];

namespace SUB1{
	void work(){
		foru(o,1,q){
			auto [ty,x,y]=op[o];
			if(ty==1){
				#define BL 32
				#define NUM 4
				static u32 val[NUM];
				while(1){
					if(y-BL*NUM<x)	break;
					val[0]=a[y-BL*1];
					val[1]=a[y-BL*2];
					val[2]=a[y-BL*3];
					val[3]=a[y-BL*4];
					for(size_t i=0;i<=27;i+=2){
						u64* ptr1=(u64*)&a[y-BL*0-i-1];
						u64* ptr2=(u64*)&a[y-BL*1-i-1];
						u64* ptr3=(u64*)&a[y-BL*2-i-1];
						u64* ptr4=(u64*)&a[y-BL*3-i-1];
						*ptr1=(*ptr1)^(*((u64*)&a[y-BL*0-i-2]));
						*ptr2=(*ptr2)^(*((u64*)&a[y-BL*1-i-2]));
						*ptr3=(*ptr3)^(*((u64*)&a[y-BL*2-i-2]));
						*ptr4=(*ptr4)^(*((u64*)&a[y-BL*3-i-2]));
					}
					a[y-BL*1+4]^=a[y-BL*1+3];
					a[y-BL*2+4]^=a[y-BL*2+3];
					a[y-BL*3+4]^=a[y-BL*3+3];
					a[y-BL*4+4]^=a[y-BL*4+3];

					a[y-BL*1+3]^=a[y-BL*1+2];
					a[y-BL*2+3]^=a[y-BL*2+2];
					a[y-BL*3+3]^=a[y-BL*3+2];
					a[y-BL*4+3]^=a[y-BL*4+2];

					a[y-BL*1+2]^=a[y-BL*1+1];
					a[y-BL*2+2]^=a[y-BL*2+1];
					a[y-BL*3+2]^=a[y-BL*3+1];
					a[y-BL*4+2]^=a[y-BL*4+1];
					
					a[y-BL*1+1]^=val[0];
					a[y-BL*2+1]^=val[1];
					a[y-BL*3+1]^=val[2];
					a[y-BL*4+1]^=val[3];
					y-=BL*NUM;
				}
				for(size_t i=y;i>x;i--){
					a[i]^=a[i-1];
				}
			}else{
				printf("%u\n",a[x]);
			}
		}
		foru(i,1,n){
			printf("%u\n",a[i]);
		}
	}
}

namespace SUBZR{
	u64 d[MAXN/64+5];
	#define gb(x,y) (((x)>>(y))&1)
	#define sb(x,y)	((x)|=(1ull<<(y)))
	#define cb(x,y)	((x)&=(~(1ull<<(y))))
	#define hb(x)	((x>>63)&1)
	void processMid(u64& x,u32 l,u32 r,bool apd){
		const u64 lf=x&((1ull<<l)-1);
		const u64 rf=r==63?0:(x&(~((1ull<<(r+1))-1)));
		x^=lf|rf;
		x^=x<<1;
		// cerr<<x<<endl;
		if(r<63)	x&=((1ull<<(r+1))-1);
		// cerr<<x<<endl;
		if(apd)	x^=1ull<<l;
		x|=lf|rf;
	}
	void work(){
		foru(i,0,n-1){
			if(a[i+1]){
				sb(d[i>>6],i&63);
			}
		}
		foru(i,1,q){
			auto [ty,l,r]=op[i];
			l--,r--;
			if(ty==1){
				u32 L=(l>>6),lid=l&63;
				u32 R=(r>>6),rid=r&63;
				
				if(L==R){
					processMid(d[L],lid,rid,0);
					continue;
				}
				processMid(d[R],0,rid,hb(d[R-1]));
				for(u32 i=R-1;i>L;i--){
					d[i]^=d[i]<<1;
					d[i]^=hb(d[i-1]);
				}
				processMid(d[L],lid,63,0);

			}else{
				printf("%u\n",(u32)gb(d[l>>6],l&63));
				// printf("%u\n",a[l+1]);
			}
		}
		foru(i,0,n-1){
			printf("%u\n",(u32)gb(d[i>>6],i&63));
		}
	}
}

namespace SUBZR1{
	u64 d[MAXN/64+5];
	#define gb(x,y) (((x)>>(y))&1)
	#define sb(x,y)	((x)|=(1ull<<(y)))
	#define cb(x,y)	((x)&=(~(1ull<<(y))))
	#define hb(x)	((x>>63)&1)
	void processMid(u64& x,u32 l,u32 r,bool apd){
		const u64 lf=x&((1ull<<l)-1);
		const u64 rf=r==63?0:(x&(~((1ull<<(r+1))-1)));
		x^=lf|rf;
		x^=x<<1;
		// cerr<<x<<endl;
		if(r<63)	x&=((1ull<<(r+1))-1);
		// cerr<<x<<endl;
		if(apd)	x^=1ull<<l;
		x|=lf|rf;
	}
	void work(){
		u32 mul=a[1];
		if(a[1]){
			sb(d[0>>6],0&63);
		}
		foru(i,1,q){
			auto [ty,l,r]=op[i];
			l--,r--;
			if(ty==1){
				u32 L=(l>>6),lid=l&63;
				u32 R=(r>>6),rid=r&63;
				
				if(L==R){
					processMid(d[L],lid,rid,0);
					continue;
				}
				processMid(d[R],0,rid,hb(d[R-1]));
				for(u32 i=R-1;i>L;i--){
					d[i]^=d[i]<<1;
					d[i]^=hb(d[i-1]);
				}
				processMid(d[L],lid,63,0);

			}else{
				printf("%u\n",(u32)(gb(d[l>>6],l&63))*mul);
				// printf("%u\n",a[l+1]);
			}
		}
		foru(i,0,n-1){
			printf("%u\n",(u32)(gb(d[i>>6],i&63))*mul);
		}
	}
}


void solve(bool SPE){ 
	int T=RIN;
	n=RIN,q=RIN;
	foru(i,1,n){
		a[i]=RIN;
		assume(a[i]<(1u<<30));
	}
	foru(i,1,q){
		op[i].ty=RIN;
		if(op[i].ty==1){
			op[i].x=RIN,op[i].y=RIN;
		}else{
			op[i].x=RIN;
		}
	}

	if(T==2){
		SUBZR1::work();
		return ;
	}
	if(T==3){
		SUBZR::work();
		return ;
	}

	// if(n<=2000 && q<=2000){
		SUB1::work();
		return ;
	// }
	
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
	// if(freopen("ex_sigma3.in","r",stdin));
	if(freopen("sigma.in","r",stdin));
	if(freopen("sigma.out","w",stdout));
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