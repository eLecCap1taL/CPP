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
int n,m;
int a[MAXN];
int b[MAXN];

int ark[MAXN];
vector<pair<int,int>> als;
int aL,aR,mxRound;
bool sml;

void check(bool f){
	if(!f){
		foru(i,1,1000){
			cerr<<"error";
		}
	}
}

void calc_ark(){
	foru(i,1,n){
		als+=mkp(a[i],i);
	}
	sort(All(als));
	for(int i=0;i<n;i++){
		ark[als[i].se]=i+1;
	}
}

int ans=0;
vector<int> fin;
namespace PRO1{
	bool process(){
		aL=mxRound/2+1;
		aR=n-(mxRound+1)/2;

		//chk LR
		// vector<int> ls;
		// foru(i,1,n){
		// 	if(a[i]<als[aL-1].first)	continue;
		// 	if(a[i]>als[aR-1].first)	continue;
		// 	ls+=a[i];
		// }
		// for(size_t i=1;i<ls.size();i++){
		// 	if(ls[i]<ls[i-1]){
		// 		while(1)	cerr<<"ho";
		// 	}
		// }
		// cein<<ls<<endl;
		
		int bg=0,ed=-1;
		int aVL=aL==1?0:als[aL-2].first;
		int aVR=aR==n?n+m+1:als[aR].first;
		foru(i,1,m){
			if(aVL<b[i] && b[i]<aVR){
				if(bg==0)	bg=i;
				ed=i;
			}
		}
		// foru(i,1,m){
		// 	cerr<<b[i]<<endl;
		// }
		
		int num=ed-bg+1;
		// cerr<<aL<<' '<<aR<<' '<<' '<<mxRound<<' '<<num<<endl;
		// cerr<<num<<endl;


		if(num>=mxRound){
			printf("%d\n",mxRound);
			return true;
		}

		static vector<int> na;
		static vector<int> nb;
		foru(i,aL,aR){
			fin+=als[i-1].first;
		}
		foru(i,1,m){
			if(bg<=i && i<=ed){
				fin+=b[i];
			}else{
				nb+=b[i];
			}
		}
		sort(All(fin));

		size_t ptr=0;
		int nl=num/2+1;
		int nr=n-(num+1)/2;
		
		foru(i,1,n){
			if(ark[i]<nl || ark[i]>nr)	continue;
			if(aL<=ark[i] && ark[i]<=aR){
				while(ptr<fin.size()){
					int x=fin[ptr++];
					na+=x;
					if(x==a[i])	break;
				}
			}else{
				na+=a[i];
			}
		}
		while(ptr<fin.size())	na+=fin[ptr++];

		// cein<<fin<<endl;
		check(fin.back()-fin[0]+1==(int)fin.size());

		//chk
		// if(!((int)na.size()==n)){
		// 	while(1)	cerr<<"1";
		// }
		// if(!((int)nb.size()==m-num)){
		// 	while(1)	cerr<<"2";
		// }

		foru(i,1,n){
			a[i]=na[i-1];
		}
		m=m-num;
		foru(i,1,m){
			b[i]=nb[i-1];
		}
		mxRound-=num;
		ans+=num;
		if(num&1)	sml=1;

		// cein<<fin<<endl;
		// cein<<na<<endl<<nb<<endl;
		// cein<<ans<<endl;

		// printf("-1\n");
		return false;
	}
}

// bool chklgL(int amn){
// 	size_t num=0;
// 	int lst=INT_MIN;
// 	foru(i,1,n){
// 		if(a[i]>fin.back())	continue;
// 		if(fin[0]<=a[i] && a[i]<=fin.back()){
// 			num++;
// 			continue;
// 		}
// 		if(a[i]==amn)	continue;
// 		if(num)	return false;
// 		if(a[i]<lst)	return false;
// 		lst=a[i];
// 	}
// 	return true;
// }
// bool chklgR(int amx){
// 	size_t num=0;
// 	int lst=INT_MIN;
// 	foru(i,1,n){
// 		if(a[i]<fin[0])	continue;
// 		if(fin[0]<=a[i] && a[i]<=fin.back()){
// 			num++;
// 			continue;
// 		}
// 		if(a[i]==amx)	continue;
// 		if(num!=fin.size())	return false;
// 		if(a[i]<lst)	return false;
// 		lst=a[i];
// 	}
// 	return true;
// }

void solve(bool SPE){ 
	n=RIN,m=RIN;
	foru(i,1,n){
		a[i]=RIN;
	}
	foru(i,1,m){
		b[i]=RIN;
	}

	sort(b+1,b+1+m);

	calc_ark();

	//calc maxRound
	for(int i=0;i+1<n;i++){
		if(als[i+1].se<als[i].se){
			int round=0;
			int rf=n-(i+1);
			int lf=i+1;
			if(rf>lf)	round=2*lf;
			else	round=2*rf-1;
			chkmax(mxRound,round);
		}
	}

	if(mxRound>m){
		printf("-1");
		return ;
	}

	// 先处理掉答案下界
	if(PRO1::process())	return ;

	int aLnum=0;
	int aRnum=0;
	foru(i,1,n){
		if(a[i]<fin[0])	aLnum++;
		if(a[i]>fin.back())	aRnum++;
	}

	int amx=INT_MIN;
	int amn=INT_MAX;
	foru(i,1,n){
		chkmax(amx,a[i]);
		chkmin(amn,a[i]);
	}

	int finL=0,finR=0;
	foru(i,1,n){
		if(a[i]==fin[0])	finL=i;
		if(a[i]==fin.back())	finR=i;
	}
	
	static vector<pair<int,int>> alls;
	static vector<pair<int,int>> arls;
	foru(i,1,n){
		if(a[i]<fin[0])	alls+=mkp(a[i],i);
		if(a[i]>fin.back())	arls+=mkp(a[i],i);
	}

	int delLnum=0;
	int delL=INT_MIN;
	// cein<<finL<<' '<<finR<<endl;
	if(true){
		int lst=finL;
		sort(All(alls));
		for(auto it=alls.rbegin();it!=alls.rend();it++){
			// cerr<<"v "<<it->first<<" at "<<it->second<<endl;
			if(it->se>lst){
				delL=it->fi;
				delLnum=alls.rend()-it;
				break;
			}
			lst=it->se;
		}
	}

	int delRnum=0;
	int delR=INT_MAX;
	if(true){
		int lst=finR;
		sort(All(arls));
		for(auto it=arls.begin();it!=arls.end();it++){
			if(it->se<lst){
				delR=it->fi;
				delRnum=arls.end()-it;
				break;
			}
			lst=it->se;
		}
	}

	// cein<<delL<<' '<<delR<<endl;
	// vector<int> chk;
	// foru(i,1,n){
	// 	if(delL<a[i] && a[i]<delR)	chk+=a[i];
	// }
	// cein<<chk<<endl;

	// bool lgL=chklgL(amn);
	// bool lgR=chklgR(amx);

	int bLnum=0;
	int bMnum=0;
	int bRnum=0;
	foru(i,1,m){
		if(b[i]<=delL)	bLnum++;
		else	if(b[i]>=delR)	bRnum++;
		else	bMnum++;
		// if(b[i]<fin[0])	bLnum++;
		// else if(b[i]>fin.back())	bRnum++;
		// else check(0);
	}

	#define FAILRETURN printf("-1");return ;

	if(!sml){
		sml=1;
		swap(delLnum,delRnum);
		swap(bLnum,bRnum);
	}
	if(sml){
		// cerr<<delLnum<<' '<<delRnum<<" "<<bLnum<<' '<<bMnum<<' '<<bRnum<<endl;
		int rf=delRnum;
		while(delLnum>0 && rf>0){
			delLnum--;
			ans++;
			if(bMnum)	bMnum--;
			else if(bLnum && delLnum==0)	bLnum--;
			else if(bRnum)	bRnum--,rf++;
			else{
				FAILRETURN;
			}

			rf--;
			ans++;
			if(bLnum && delLnum==0)	bLnum--;
			else if(bMnum)	bMnum--;
			else if(bRnum)	bRnum--,rf++;
			else{
				FAILRETURN;
			}
			chkmax(rf,0);
		}
		while(rf>0){
			ans++;
			if(bLnum)	bLnum--;
			else	if(bMnum)	bMnum--;
			else{
				FAILRETURN;
			}

			rf--;
			ans++;
			if(bMnum)	bMnum--;
			else if(bLnum)	bLnum--;
			else{
				FAILRETURN;
			}
		}
		while(delLnum>0){
			delLnum--;
			ans++;
			if(bMnum)	bMnum--;
			else if(bRnum)	bRnum--;
			else{
				FAILRETURN;
			}
			if(delLnum==0)	break;

			ans++;
			if(bMnum)	bMnum--;
			else if(bRnum)	bRnum--;
			else{
				FAILRETURN;
			}
		}
		printf("%d",ans);
		return ;
	}

	// cerr<<delLnum<<' '<<delRnum<<' '<<m<<' '<<sml<<endl;
	cout<<ans;
	// check(lgL||lgR);

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
	// if(freopen("ex_hiero3.in","r",stdin));
	if(freopen("hiero.in","r",stdin));
	if(freopen("hiero.out","w",stdout));
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