#include "testlib.h"
using namespace std;
int p[100005],a[15][15];
int main(int argc,char** argv)
{
 registerTestlibCmd(argc,argv);
 int N=inf.readInt();
 for(int i=0;i<N;i++)
  p[i]=inf.readInt();
 int cnt=0;
 while(!ouf.eof())
 {
  int st=ouf.readInt();
  ouf.readEoln();
  if(st<=0||cnt>=N)
   break;
  if((((p[cnt]==3)||(p[cnt]>=6))&&(st>=9))||((p[cnt]==5)&&(st>=8)))
   break;
  st--;
  if(p[cnt]==1)
  {
   if(a[8][st])break;
   a[8][st]=2;
  }
  else if(p[cnt]==2)
  {
   if(a[8][st])break;
   a[8][st]=2;
   if(a[7][st])break;
   a[7][st]=2;
  }
  else if(p[cnt]==3)
  {
   if(a[8][st])break;
   a[8][st]=2;
   if(a[8][st+1])break;
   a[8][st+1]=2;
  }
  else if(p[cnt]==4)
  {
   if(a[8][st])break;
   a[8][st]=2;
   if(a[7][st])break;
   a[7][st]=2;
   if(a[6][st])break;
   a[6][st]=2;
  }
  else if(p[cnt]==5)
  {
   if(a[8][st])break;
   a[8][st]=2;
   if(a[8][st+1])break;
   a[8][st+1]=2;
   if(a[8][st+2])break;
   a[8][st+2]=2;
  }
  else if(p[cnt]==6)
  {
   if(a[8][st])break;
   a[8][st]=2;
   if(a[7][st])break;
   a[7][st]=2;
   if(a[7][st+1])break;
   a[7][st+1]=2;
  }
  else if(p[cnt]==7)
  {
   if(a[8][st+1])break;
   a[8][st+1]=2;
   if(a[7][st])break;
   a[7][st]=2;
   if(a[7][st+1])break;
   a[7][st+1]=2;
  }
  else if(p[cnt]==8)
  {
   if(a[8][st])break;
   a[8][st]=2;
   if(a[7][st])break;
   a[7][st]=2;
   if(a[8][st+1])break;
   a[8][st+1]=2;
  }
  else if(p[cnt]==9)
  {
   if(a[8][st])break;
   a[8][st]=2;
   if(a[8][st+1])break;
   a[8][st+1]=2;
   if(a[7][st+1])break;
   a[7][st+1]=2;
  }
  cnt++;
  int A,B,drop=10,temp;
  for(int j=0;j<9;j++)
  {
   A=-1;
   for(int i=8;i;i--)
    if(a[i][j]==2)A=i;
   if(A!=-1)
   {
    B=-1;
    for(int i=0;i<9;i++)
     if(a[i][j]==1)B=i;
    temp=A-B-1;
    if(temp<drop)drop=temp;
   }
  }
  for(int i=0;i<9;i++)
   for(int j=0;j<9;j++)
    if(a[i][j]==2)
    {
     a[i][j]=0;
     a[i-drop][j]=1;
    }
  int i=0;
  while(i<9)
  {
   int line=1;
   for(int j=0;j<9;j++)
    if(a[i][j]==0)
    {
     line=0;
     break;
    }
   if(line)
   {
    for(int j=0;j<9;j++)
     a[i][j]=0;
    for(int x=i+1;x<9;x++)
     for(int y=0;y<9;y++)
     {
      a[x-1][y]=a[x][y];
      a[x][y]=0;
     }
   }
   else i++;
  }
 }
 while(!ouf.eof()) ouf.readInt(),ouf.readEoln();
if (cnt==N) quitf(_ok, "%d\nCorrect answer", 1);
else quitf(_pc(20*(15.0*min(2*cnt,N)/N+5.0*max(2*cnt-N,0)/N)), "%0.3lf\ncnt=%d", (15.0*min(2*cnt,N)/N+5.0*max(2*cnt-N,0)/N)/20, cnt);
}