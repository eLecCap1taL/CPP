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
// const int M=20;
// int ans[6][M][M+1];
// int a[10];
// int V=10;
// unordered_map<int,int> mp;
// void pre(){
// 	foru(i,1,5)	foru(x,0,M-1)	foru(m,1,M)	ans[i][x][m]=-1;

// 	V=50;
// 	mp.clear();
// 	for(a[1]=0;a[1]<=V;a[1]++){
// 		cerr<<a[1]<<endl;
// 		for(a[2]=0;a[2]<=V;a[2]++){
// 			for(a[3]=0;a[3]<=V;a[3]++){
// 				for(a[4]=0;a[4]<=V;a[4]++){
// 					for(a[5]=0;a[5]<=V;a[5]++){
// 						int val=0;
// 						for(int s=0;s<(1<<5);s++){
// 							int x=0;
// 							foru(i,0,4){
// 								if((s>>i)&1)	x^=a[i+1];
// 							}
// 							val+=x;
// 						}
// 						mp[val]++;
// 					}
// 				}
// 			}
// 		}
// 	}

// 	for(auto [k,cnt]:mp){
// 		// cerr<<k<<' '<<cnt<<endl;
// 		for(int i=1;i<=M;i++){
// 			if(ans[5][cnt%i][i]!=-1){
// 				chkmin(ans[5][cnt%i][i],k);
// 				continue;
// 			}
// 			ans[5][cnt%i][i]=k;
// 		}
// 	}

// 	V=40;
// 	mp.clear();
// 	for(a[1]=0;a[1]<=V;a[1]++){
// 		for(a[2]=0;a[2]<=V;a[2]++){
// 			for(a[3]=0;a[3]<=V;a[3]++){
// 				for(a[4]=0;a[4]<=V;a[4]++){
// 					int val=0;
// 					for(int s=0;s<(1<<4);s++){
// 						int x=0;
// 						foru(i,0,3){
// 							if((s>>i)&1)	x^=a[i+1];
// 						}
// 						val+=x;
// 					}
// 					mp[val]++;
// 				}
// 			}
// 		}
// 	}
// 	for(auto [k,cnt]:mp){
// 		// cerr<<k<<' '<<cnt<<endl;
// 		for(int i=1;i<=M;i++){
// 			if(ans[4][cnt%i][i]!=-1){
// 				chkmin(ans[4][cnt%i][i],k);
// 				continue;
// 			}
// 			ans[4][cnt%i][i]=k;
// 		}
// 	}

// 	V=150;
// 	mp.clear();
// 	for(a[1]=0;a[1]<=V;a[1]++){
// 		for(a[2]=0;a[2]<=V;a[2]++){
// 			for(a[3]=0;a[3]<=V;a[3]++){
// 				int val=0;
// 				for(int s=0;s<(1<<3);s++){
// 					int x=0;
// 					foru(i,0,2){
// 						if((s>>i)&1)	x^=a[i+1];
// 					}
// 					val+=x;
// 				}
// 				mp[val]++;
// 			}
// 		}
// 	}
// 	for(auto [k,cnt]:mp){
// 		// cerr<<k<<' '<<cnt<<endl;
// 		for(int i=1;i<=M;i++){
// 			if(ans[3][cnt%i][i]!=-1){
// 				chkmin(ans[3][cnt%i][i],k);
// 				continue;
// 			}
// 			ans[3][cnt%i][i]=k;
// 		}
// 	}

// 	V=1000;
// 	mp.clear();
// 	for(a[1]=0;a[1]<=V;a[1]++){
// 		for(a[2]=0;a[2]<=V;a[2]++){
// 			int val=0;
// 			for(int s=0;s<(1<<2);s++){
// 				int x=0;
// 				foru(i,0,1){
// 					if((s>>i)&1)	x^=a[i+1];
// 				}
// 				val+=x;
// 			}
// 			mp[val]++;
// 		}
// 	}
// 	for(auto [k,cnt]:mp){
// 		// cerr<<k<<' '<<cnt<<endl;
// 		for(int i=1;i<=M;i++){
// 			if(ans[2][cnt%i][i]!=-1){
// 				chkmin(ans[2][cnt%i][i],k);
// 				continue;
// 			}
// 			ans[2][cnt%i][i]=k;
// 		}
// 	}

// 	V=1500000;
// 	mp.clear();
// 	for(a[1]=0;a[1]<=V;a[1]++){
// 		int val=0;
// 		for(int s=0;s<(1<<1);s++){
// 			int x=0;
// 			foru(i,0,1){
// 				if((s>>i)&1)	x^=a[i+1];
// 			}
// 			val+=x;
// 		}
// 		mp[val]++;
// 	}
// 	for(auto [k,cnt]:mp){
// 		// cerr<<k<<' '<<cnt<<endl;
// 		for(int i=1;i<=M;i++){
// 			if(ans[1][cnt%i][i]!=-1){
// 				chkmin(ans[1][cnt%i][i],k);
// 				continue;
// 			}
// 			ans[1][cnt%i][i]=k;
// 		}
// 	}

// 	ofstream fout("dat",ios::out);
// 	foru(n,1,5){
// 		foru(x,0,4){
// 			foru(m,1,5){
// 				fout<<"g["<<n<<"]["<<x<<"]["<<m<<"]="<<ans[n][x][m]<<";\n";
// 			}
// 		}
// 	}
// 	fout.close();
// }
int g[7][7][7];
void solve(bool SPE){ 


g[1][0][1]=0;
g[1][0][2]=-1;
g[1][0][3]=-1;
g[1][0][4]=-1;
g[1][0][5]=-1;
g[1][1][1]=-1;
g[1][1][2]=0;
g[1][1][3]=0;
g[1][1][4]=0;
g[1][1][5]=0;
g[1][2][1]=-1;
g[1][2][2]=-1;
g[1][2][3]=-1;
g[1][2][4]=-1;
g[1][2][5]=-1;
g[1][3][1]=-1;
g[1][3][2]=-1;
g[1][3][3]=-1;
g[1][3][4]=-1;
g[1][3][5]=-1;
g[1][4][1]=-1;
g[1][4][2]=-1;
g[1][4][3]=-1;
g[1][4][4]=-1;
g[1][4][5]=-1;
g[2][0][1]=0;
g[2][0][2]=2002;
g[2][0][3]=2;
g[2][0][4]=2002;
g[2][0][5]=2014;
g[2][1][1]=-1;
g[2][1][2]=0;
g[2][1][3]=0;
g[2][1][4]=0;
g[2][1][5]=0;
g[2][2][1]=-1;
g[2][2][2]=-1;
g[2][2][3]=2016;
g[2][2][4]=2016;
g[2][2][5]=14;
g[2][3][1]=-1;
g[2][3][2]=-1;
g[2][3][3]=-1;
g[2][3][4]=2;
g[2][3][5]=2;
g[2][4][1]=-1;
g[2][4][2]=-1;
g[2][4][3]=-1;
g[2][4][4]=-1;
g[2][4][5]=6;
g[3][0][1]=0;
g[3][0][2]=604;
g[3][0][3]=604;
g[3][0][4]=640;
g[3][0][5]=604;
g[3][1][1]=-1;
g[3][1][2]=0;
g[3][1][3]=0;
g[3][1][4]=0;
g[3][1][5]=0;
g[3][2][1]=-1;
g[3][2][2]=-1;
g[3][2][3]=-1;
g[3][2][4]=604;
g[3][2][5]=4;
g[3][3][1]=-1;
g[3][3][2]=-1;
g[3][3][3]=-1;
g[3][3][4]=4;
g[3][3][5]=28;
g[3][4][1]=-1;
g[3][4][2]=-1;
g[3][4][3]=-1;
g[3][4][4]=-1;
g[3][4][5]=12;
g[4][0][1]=0;
g[4][0][2]=328;
g[4][0][3]=8;
g[4][0][4]=328;
g[4][0][5]=8;
g[4][1][1]=-1;
g[4][1][2]=0;
g[4][1][3]=0;
g[4][1][4]=0;
g[4][1][5]=0;
g[4][2][1]=-1;
g[4][2][2]=-1;
g[4][2][3]=384;
g[4][2][4]=384;
g[4][2][5]=-1;
g[4][3][1]=-1;
g[4][3][2]=-1;
g[4][3][3]=-1;
g[4][3][4]=8;
g[4][3][5]=-1;
g[4][4][1]=-1;
g[4][4][2]=-1;
g[4][4][3]=-1;
g[4][4][4]=-1;
g[4][4][5]=376;
g[5][0][1]=0;
g[5][0][2]=656;
g[5][0][3]=656;
g[5][0][4]=688;
g[5][0][5]=656;
g[5][1][1]=-1;
g[5][1][2]=0;
g[5][1][3]=0;
g[5][1][4]=0;
g[5][1][5]=0;
g[5][2][1]=-1;
g[5][2][2]=-1;
g[5][2][3]=-1;
g[5][2][4]=656;
g[5][2][5]=-1;
g[5][3][1]=-1;
g[5][3][2]=-1;
g[5][3][3]=-1;
g[5][3][4]=16;
g[5][3][5]=-1;
g[5][4][1]=-1;
g[5][4][2]=-1;
g[5][4][3]=-1;
g[5][4][4]=-1;
g[5][4][5]=-1;


	int n=RIN,x=RIN,m=RIN;
	cout<<g[n][x][m]<<endl;
	
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
	#define MULTITEST
	// #define TESTCASEID
	
	// pre();

	#ifndef ONLINE_JUDGE
	#ifndef CPEDITOR
	if(freopen("b0.in","r",stdin));
	// if(freopen("b.in","r",stdin));
	// if(freopen("b.out","w",stdout));
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