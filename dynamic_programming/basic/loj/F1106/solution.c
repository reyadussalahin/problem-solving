//problem name: 1106 - Gone Fishing 
//problem link: http://lightoj.com/volume_showproblem.php?problem=1106
//contest link: (?)
//time: (?)
//author: aman

//other_tags: dynamic programming
//difficulty_level: (?)

#include<stdio.h>
#include<string.h>

#define max 30
#define mxtime 200

int dp[max][mxtime];
int trace[max][mxtime];
int n,h;
int f[max],d[max],dist[max];

//Num of fishes caught for a given time and area
int catch (int lake,int time) {
	if (d[lake] > 0)
		if (f[lake]/d[lake]+1 < time)
			time = f[lake]/d[lake]+1;

	int a = (time)*f[lake];
	int b = (time)*(time-1)/2;
	return a - b*d[lake];
}

//print time spent in every lake
void printTrace (int lake,int time) {
	if (lake > n)
		return;

	if (time<0) printf("%d",0 );
	else printf("%d",trace[lake][time]*5 );
	if (lake < n) printf(", ");

	printTrace(lake+1,time-trace[lake][time]-dist[lake]);
}


//Recursive Function calculating max number of fishes caught
int maxfish (int lake,int time)
{
	//printf("%d %d\n",lake,time );
	if (time<0 || lake>n) 
		return 0;

	if (dp[lake][time] != -1)
		return dp[lake][time];

	for (int i=time ;i>=0; i--) {
		int t = catch(lake,i) + maxfish(lake+1,time-i-dist[lake]);
		if (t > dp[lake][time]) {
			 dp[lake][time] = t;
			 trace[lake][time] = i;
		}
	}

	//printf("%d %d %d\n",lake,time,dp[lake][time] );
	return dp[lake][time];
}


int main() 
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);

	for (int c=1; c<=t; c++) {

		for (int i=0; i<max; i++) {
			memset(dp[i],-1,sizeof(dp[i]) );
			memset(trace[i],-1,sizeof(trace[i]) );
		}

		scanf("%d %d",&n,&h);

		for (int i=1; i<=n; i++) scanf("%d",&f[i]);
		for (int i=1; i<=n; i++) scanf("%d",&d[i]);
		for (int i=1; i<n; i++) scanf("%d",&dist[i]);

		h = h*60/5;

		int res = maxfish(1,h);
		printf("Case %d:\n",c);
		printTrace(1,h);
		printf("\n");
		printf("Number of fish expected: %d\n",res );

	}

	return 0;
}