#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
string op[200003];
int x[200003],y[200003],z[200003];
bitset<2048> f[100003],g[2048];
unsigned zz=114514;
bool RND(){
	zz = (zz ^ (zz >> 16)) * 0x7feb352d;
	zz = (zz ^ (zz >> 15)) * 0x846ca68b;
	return (zz ^ (zz >> 16))&1;
}
signed main(int argc,char *argv[])
{
    registerTestlibCmd(argc,argv);
    int n=inf.readInt(2,2048);
    int m=ouf.readInt(0,200000);
    for(int i=1; i<=m; ++i)
    {
        op[i]=ouf.readToken();
        x[i]=ouf.readInt(0,100000);
        y[i]=ouf.readInt(0,100000);
        z[i]=ouf.readInt(0,100000);
    }
    bitset<2048> one;
    for(int i=0; i<n; ++i) one[i]=1;
    for(int T=0; T<=20; ++T)
    {
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                f[i][j]=g[i][j]=RND();
        for(int i=1; i<=m; ++i)
        {
            if(op[i]=="AND")
            {
                f[x[i]]=f[y[i]]&f[z[i]];
            }
            else if(op[i]=="OR")
            {
                f[x[i]]=f[y[i]]|f[z[i]];
            }
            else if(op[i]=="XOR")
            {
                f[x[i]]=f[y[i]]^f[z[i]];
            }
            else if(op[i]=="SH")
            {
                if(z[i]>=n) quitp(0.0,"Invalid operation(z>=n in SH)");
                f[x[i]]=((f[y[i]]<<z[i])|(f[y[i]]>>(n-z[i])))&one;
            }
            else if(op[i]=="SET")
            {
                if(y[i]>=n) quitp(0.0,"Invalid operation(y>=n in SET)");
                if(z[i]>=2) quitp(0.0,"Invalid operation(z>=2 in SET)");
                f[x[i]][y[i]]=z[i];
            }
            else quitp(0.0,"Invalid operation(unknown operator)");
        }
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(f[i][j]!=g[j][i])
                    quitp(0.0,"Wrong answer on test #%d\n",T);
        for(int i=1; i<=m; ++i) f[x[i]].reset();
    }
    if(n==1)
    {
    	quitp(1.0,"Task [TUTORIAL] accepted.");
    }
    if(n==2)
    {
    	quitp(1.0,"Task [PAST] accepted.");
    }
    if(n==32)
    {
    	quitp(1.0,"Task [PRESENT] accepted.");
    }
    if(n==512)
    {
    	quitp(1.0,"Task [FUTURE] accepted.");
    }
    if(n==2048)
    {
    	if(m<=52000)
    		quitp(1.0,"Task [BEYOND] accepted.");
    	else quitp(0.5*(log(500000.0L/(m-47000))/log(10)),"Task [BEYOND] OK with %d operations.",m);
    }
    quitp(1.0,"Customized task OK with %d operations",m);
    return 0;
}