//%^~
#pragma GCC optimize(3)
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
// typedef unsigned short u16;
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
int n,m,q;
char s[3005];
char t[3005];
namespace SUB1{
	int f[605][605];
	void work(){
		while(q--){
			int a=RIN,b=RIN,c=RIN,d=RIN;
			foru(i,a,b){
				f[i][c-1]=0;
			}
			foru(i,c,d){
				f[a-1][i]=0;
			}
			f[a-1][c-1]=0;
			foru(i,a,b){
				foru(j,c,d){
					f[i][j]=max(f[i-1][j],f[i][j-1]);
					if(s[i]==t[j]){
						chkmax(f[i][j],f[i-1][j-1]+1);
					}
				}
			}
			printf("%d\n",f[b][d]);
		}
	}
}

namespace SUB2{
	// #define u16 int
	#define u16 unsigned
	class In{
	public:
		u16 a,b,c,d;
	}in[100005];
	class Q{
	public:
		u16 b,d,ans;
	}qr[100005];
	u16 f[605];
	vector<int> qls[605][605];
	int maxb[605][605];
	int maxd[605][605];
	void work(){
		foru(i,1,q){
			u16 a=RIN,b=RIN,c=RIN,d=RIN;
			// cerr<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
			in[i]={a,b,c,d};
		}

		LL calc1=0;
		foru(i,1,n)	foru(j,1,m)	maxb[i][j]=i,maxd[i][j]=j;
		foru(i,1,q){
			auto [a,b,c,d]=in[i];
			chkmax(maxb[a][c],b);
			chkmax(maxd[a][c],d);
		}
		foru(i,1,n)	foru(j,1,m)	calc1+=(int)(maxb[i][j]-i+1)*(int)(maxd[i][j]-j+1);

		LL calc2=0;
		foru(i,1,n)	foru(j,1,m)	maxb[i][j]=i,maxd[i][j]=j;
		foru(i,1,q){
			auto [a,b,c,d]=in[i];
			a=n-a+1,b=n-b+1;
			c=m-c+1,d=m-d+1;
			swap(a,b),swap(c,d);
			chkmax(maxb[a][c],b);
			chkmax(maxd[a][c],d);
		}
		foru(i,1,n)	foru(j,1,m)	calc1+=(int)(maxb[i][j]-i+1)*(int)(maxd[i][j]-j+1);

		if(calc2<calc1){
			foru(i,1,q){
				auto& [a,b,c,d]=in[i];
				a=n-a+1,b=n-b+1;
				c=m-c+1,d=m-d+1;
				swap(a,b),swap(c,d);
			}
			reverse(s+1,s+1+n);
			reverse(t+1,t+1+m);
		}
		
		foru(i,1,q){
			auto [a,b,c,d]=in[i];
			qr[i]={b,d,0};
			qls[a][c].push_back(i);
		}
		for(u16 a=1;a<=n;a++){
			for(u16 c=1;c<=m;c++){
				if(qls[a][c].empty())	continue;
				sort(All(qls[a][c]),[](int x,int y)->bool{
					return qr[x].b<qr[y].b;
				});
				// cerr<<a<<' '<<c<<' '<<qls[a][c].size()<<endl;
				u16 b=a,d=c;
				for(auto i:qls[a][c]){
					chkmax(b,qr[i].b);
					chkmax(d,qr[i].d);
				}
				for(u16 i=c;i<=d;i++){
					f[i]=0;
				}
				f[c-1]=0;
				size_t ptr=0;
				for(u16 i=a;i<=b;i++){
					u16 lst=0;
					for(u16 j=c;j<=d;j++){
						u16 cur=f[j];
						// cerr<<i<<' '<<j<<' '<<cur<<endl;
						if(s[i]==t[j]){
							chkmax(f[j],lst+1);
						}
						chkmax(f[j],f[j-1]);
						lst=cur;
					}
					while(ptr<qls[a][c].size() && qr[qls[a][c][ptr]].b==i){
						qr[qls[a][c][ptr]].ans=f[qr[qls[a][c][ptr]].d];
						// cerr<<f[qr[qls[a][c][ptr]].d]<<endl;
						ptr++;
					}
				}
			}
		}
		foru(i,1,q){
			printf("%d\n",qr[i].ans);
		}
	}
}
void solve(bool SPE){ 
	n=RIN,m=RIN,q=RIN;
	foru(i,1,n){
		s[i]=RCIN;
	}
	foru(i,1,m){
		t[i]=RCIN;
	}

	if(n<=600 && m<=600 && q<=600){
		SUB1::work();
	}
	if(n<=600 && m<=600 && q<=100000){
		SUB2::work();
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
	// if(freopen("ex_astro1.in","r",stdin));
	if(freopen("astro.in","r",stdin));
	if(freopen("astro.out","w",stdout));
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