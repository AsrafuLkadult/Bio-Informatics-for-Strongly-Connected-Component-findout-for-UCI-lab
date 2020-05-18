#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Graph
{
	ll  V; // No. of vertices
	list<ll > *adj; // An array of adjacency lists

	// Fills Stack with vertices (in increasing order of finishing
	// times). The top element of stack has the maximum finishing
	// time
	void fillOrder(ll  v, bool visited[], stack<ll > &Stack);

	// A recursive function to prll  DFS starting from v
	void DFSUtil(ll  v, bool visited[]);
public:
	Graph(ll  V);
	void addEdge(ll  v, ll  w);

	// The main function that finds and prll s strongly connected
	// components
	void printSCCs();

	// Function that returns reverse (or transpose) of this graph
	Graph getTranspose();
};

Graph::Graph(ll  V)
{
	this->V = V;
	adj = new list<ll >[V];
}

// A recursive function to prll  DFS starting from v
void Graph::DFSUtil(ll  v, bool visited[])
{
	// Mark the current node as visited and prll  it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	list<ll >::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (ll  v = 0; v < V; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<ll >::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(ll  v, ll  w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(ll  v, bool visited[], stack<ll > &Stack)
{
	// Mark the current node as visited and prll  it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<ll >::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			fillOrder(*i, visited, Stack);

	// All vertices reachable from v are processed by now, push v
	Stack.push(v);
}

// The main function that finds and prll s all strongly connected
// components
void Graph::printSCCs()
{  ll  count =0;
	stack<ll > Stack;

	// Mark all the vertices as not visited (For first DFS)
	bool *visited = new bool[V];
	for(ll  i = 0; i < V; i++)
		visited[i] = false;

	// Fill vertices in stack according to their finishing times
	for(ll  i = 0; i < V; i++)
		if(visited[i] == false)
			fillOrder(i, visited, Stack);

	// Create a reversed graph
	Graph gr = getTranspose();

	// Mark all the vertices as not visited (For second DFS)
	for(ll  i = 0; i < V; i++)
		visited[i] = false;

	// Now process all vertices in order defined by Stack
	while (Stack.empty() == false)
	{
		// Pop a vertex from stack
		ll  v = Stack.top();
		Stack.pop();
		// Prll  Strongly connected component of the popped vertex
		if (visited[v] == false)
		{   count+=1;
			gr.DFSUtil(v, visited);
			cout << endl;
		}
	}
	cout<<"\nCompute the Number of Strongly Connected component is :  "<<count<<"\n\n";
}

// Driver program to test above functions
int  main()

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


	cout << "Following are Strongly Connected  components \n\n";
	g.printSCCs();

	return 0;
}

