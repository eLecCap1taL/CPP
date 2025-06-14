#include"treasure.h"
#include<bits/stdc++.h>
namespace grader_______
{
	using namespace std;
	const int MN=4005,L=30000,R=60000;
	int n,X,Y,tot;
	char a[MN][MN];
	inline double sc(int M)
	{
		if(M<=L)
			return 1;
		return 0.9*(R-M)/(R-L);
	}
	inline char walk(char c)
	{
		tot++;
		if(tot>R)
		{
			puts("Too many steps.");
			exit(0);
		}
		if(c=='^')
		{
			if(X==1)
			{
				puts("You went to the outside of the grid.");
				exit(0);
			}
			X--;
			return a[X][Y];
		}
		if(c=='v')
		{
			if(X==2*n+1)
			{
				puts("You went to the outside of the grid.");
				exit(0);
			}
			X++;
			return a[X][Y];
		}
		if(c=='<')
		{
			if(Y==1)
			{
				puts("You went to the outside of the grid.");
				exit(0);
			}
			Y--;
			return a[X][Y];
		}
		if(c=='>')
		{
			if(Y==2*n+1)
			{
				puts("You went to the outside of the grid.");
				exit(0);
			}
			Y++;
			return a[X][Y];
		}
		puts("Invalid instruction.");
		exit(0);
	}
	int main()
	{
		scanf("%d",&n);
		for(int i=1;i<=n*2+1;i++)
			scanf("%s",a[i]+1);
		X=Y=n+1;
		find_treasure(n);
		if(a[X][Y]!='G')
		{
			puts("You didn't find the treasure.");
			exit(0);
		}
		printf("Number of steps: %d\n",tot);
		printf("Score: %.5f\n",sc(tot));
		return 0;
	}
}
char walk(char c)
{
	return grader_______::walk(c);
}
int main()
{
	return grader_______::main();
}