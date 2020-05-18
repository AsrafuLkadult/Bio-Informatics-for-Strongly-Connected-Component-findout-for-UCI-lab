#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Graph
{
	ll  V; // No. of vertices
	list<ll > *adj;
	void DFSUtil(ll  v, bool visited[]);
public:
	Graph(ll  V); // Constructor
	~Graph();
	void addEdge(ll  v, ll  w);
	void connectedComponents();

};


void Graph::connectedComponents()
{     ll  count =0;
	bool *visited = new bool[V];
	for(ll  v = 0; v < V; v++)
		visited[v] = false;

	for (ll  v=0; v<V; v++)
	{
		if (visited[v] == false)
		{   cout << "\n";
			// prll  all reachable vertices
			// from v
			count+=1;
			DFSUtil(v, visited);
			cout << "\n";
		}

	}

   cout<<"\n\nCompute the Number of connected component is : "<<count<<"\n\n";
	delete[] visited;
}

void Graph::DFSUtil(ll  v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	list<ll >::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			DFSUtil(*i, visited);

}

Graph::Graph(ll  V)
{
	this->V = V;
	adj = new list<ll >[V];
}

Graph::~Graph()
{
	delete[] adj;
}

// method to add an undirected edge
void Graph::addEdge(ll  v, ll  w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

// Drive program to test above
int main()

{
   //Console output not possible must needed file from input and output
 freopen("s1.txt","r",stdin);
 freopen("outputs1.txt","w",stdout);
    ll  node,n1,n2;
       cin>>node;
	Graph g(node);
	while(scanf("%lld%lld",&n1,&n2)!=EOF){
	g.addEdge(n1, n2);
}


	cout << "Following are connected components \n\n";
	g.connectedComponents();

	return 0;
}
