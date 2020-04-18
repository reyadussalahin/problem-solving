// problem name: Air Ports
// problem link: http://lightoj.com/volume_showproblem.php?problem=1059
// contest link: (?)
// time: (?)
// author: aman 


// other_tags: (?)



#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define mx 10010
#define f first	
#define s second

typedef pair<int,int> pii;

int visited[mx];

class compare {
public:
	bool operator() (pii a,pii b) {
		return a.s > b.s;
	}
};


//return cost of MST
int prims(int node,vector<pii > (&adjList)[mx])
{
	int min_cost = 0;
	priority_queue< pii, vector<pii >, compare> pr;

	pr.push(make_pair(node,0) );

	while(!pr.empty()) {
		pii tp = pr.top();	
		int curr = tp.f;
		pr.pop();

		if(visited[curr] != -1)
			continue;

		min_cost += tp.s;
		visited[curr] = 1;

		for(int i=0 ; i<adjList[curr].size() ; i++) {
			if(visited[adjList[curr][i].f] == -1)
				pr.push(adjList[curr][i]);
		}
	}

	return min_cost;
} 

int main()
{
	//freopen("input.txt","r",stdin);
	int n,m,A;
	int t;
	cin>>t;

	for (int k=1 ; k<=t ; k++) {
		memset(visited,-1,sizeof(visited));

		vector<pii > graph[mx];
		int totCost=0,ports=0;
		cin>>n>>m>>A;

		for (int i=0 ; i<m ; i++) {
			int x,y,c;
			cin>>x>>y>>c;
			if(c<A) {								//Eliminate edge >= aiport cost
				graph[x].push_back(make_pair(y,c));
				graph[y].push_back(make_pair(x,c));
			}
		}

		//Run MST on each disjoint graph
		for (int i=1 ; i<=n ; i++) {
			if(visited[i]==-1) {
				int res = prims(i,graph);
				totCost += res+A;
				ports++;
			}
		}
		cout<<"Case "<<k<<": "<<totCost<<" "<<ports<<endl;
	}
	return 0;
}
