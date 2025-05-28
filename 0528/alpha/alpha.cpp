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
const int mod=998244353;
int n,m,k;
int a[155];
class Opt1{
public:
	int c;
}A[155];
class Opt2{
public:
	int l,r,c;
}B[155];


namespace SUBNFRAC{
	int p[15];
	int ls[25];
	unordered_set<u64> st;
	const u64 B1=137;
	const u64 B2=157;
	const u64 mod1=998244853;
	const u64 mod2=1e9+7;
	// u64 dat[4000005],N;
	void work(){
		foru(i,1,m+k){
			p[i]=i;
		}
		do{
			int ct=0;
			foru(i,1,m+k){
				if(p[i]<=m && p[i]!=++ct){
					ct=-1;
					break;
				}
			}
			if(ct==-1)	continue;
			foru(i,1,n){
				ls[i]=a[i];
			}
			foru(i,1,m+k){
				int x=p[i];
				if(x<=m){
					for(int i=1;i<=n;i++){
						chkmin(ls[i],A[x].c);
					}
				}else{
					x-=m;
					for(int i=B[x].l;i<=B[x].r;i++){
						chkmax(ls[i],B[x].c);
					}
				}
			}
			u64 hs1=0;
			u64 hs2=0;
			for(int i=1;i<=n;i++){
				hs1=hs1*B1%mod1+ls[i];
				hs2=hs2*B2+ls[i];
			}
			// if(st.find(hs2*mod1+hs1)==st.end()){
			// for(int i=1;i<=n;i++){
			// 	cout<<ls[i]<<' ';
			// }
			// cout<<endl;
			// }
			// hs1%=mod1,hs2%=mod2;
			// dat[++N]=hs2*mod1+hs1;
			// st.insert(hs2);
			st.insert(hs2*mod1+hs1);
		}while(next_permutation(p+1,p+1+m+k));
		cout<<st.size();
		// cout<<(dat+N+1)-unique(dat+1,dat+1+N);
	}
}

namespace SUBLR{
	unordered_set<int> st;
	void work(){
		LL ans=1;
		foru(i,1,n){
			st.clear();
			if(a[i]>A[1].c)	a[i]=A[1].c;
			foru(j,1,k){
				if(B[j].l!=i)	continue;
				if(B[j].c<=A[1].c){
					chkmax(a[i],B[j].c);
				}
			}

			foru(j,1,k){
				if(B[j].l!=i)	continue;
				if(B[j].c>A[1].c){
					chkmax(a[i],B[j].c);
					st.insert(B[j].c);
				}
			}
			foru(j,1,m){
				if(A[j].c<=a[i])	st.insert(A[j].c);
				else	break;
			}
			ans=ans*(LL)max((int)st.size(),1)%mod;
			// cerr<<i<<" have "<<st.size()<<endl;
		}
		cout<<ans;
	}
}

void solve(bool SPE){
	n=RIN,m=RIN,k=RIN;
	foru(i,1,n){ 
		a[i]=RIN;
	}
	foru(i,1,m){
		A[i].c=RIN;
	}

	sort(A+1,A+1+m,[](Opt1 x,Opt1 y)->bool{
		return x.c<y.c;
	});

	bool LR=1;
	foru(i,1,k){
		B[i]={RIN,RIN,RIN};
		LR&=B[i].l==B[i].r;
	}

	if(LR){
		SUBLR::work();
		return ;
	}

	if(m<=3 && k<=7){
		SUBNFRAC::work();
		return ;
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
	// if(freopen("ex_alpha6.in","r",stdin));
	if(freopen("alpha.in","r",stdin));
	if(freopen("alpha.out","w",stdout));
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