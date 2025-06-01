#include<cstdio>
#include<map>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<unordered_map>
#define reg register
#define EN std::puts("")
#define LL long long
inline int read(){
	register int x=0;register int y=1;
	register char c=std::getchar();
	while(c<'0'||c>'9'){if(c=='-') y=0;c=std::getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c^48);c=std::getchar();}
	return y?x:-x;
}
std::unordered_map<int,int>map;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int BSGS(int a,int n,int p,int ad){
	map.clear();
	reg int m=std::ceil(std::sqrt(p));
	reg int s=1;
	for(reg int i=0;i<m;i++,s=1ll*s*a%p) map[1ll*s*n%p]=i;
	for(reg int i=0,tmp=s,s=ad;i<=m;i++,s=1ll*s*tmp%p)
		if(map.find(s)!=map.end())
			if(1ll*i*m-map[s]>=0) return 1ll*i*m-map[s];
	return -1;
}
inline int exBSGS(int a,int n,int p){
	a%=p;n%=p;
	if(n==1||p==1) return 0;
	reg int cnt=0;
	reg int d,ad=1;
	while((d=gcd(a,p))^1){
		if(n%d) return -1;
		cnt++;n/=d;p/=d;
		ad=(1ll*ad*a/d)%p;
		if(ad==n) return cnt;
	}
//		std::printf("a: %d n: %d p: %d ad:%d\n",a,n,p,ad);
	LL ans=BSGS(a,n,p,ad);
	if(ans==-1) return -1;
	return ans+cnt;
} 
signed main(){
	if(freopen("exbsgs2.in","r",stdin));
	int a=read(),p=read(),n=read();
	while(a||p||n){
		int ans=exBSGS(a,n,p);
		// if(~ans) std::printf("%d\n",ans);
		// else std::puts("No Solution");
		a=read();p=read();n=read();
	}
	return 0;
}