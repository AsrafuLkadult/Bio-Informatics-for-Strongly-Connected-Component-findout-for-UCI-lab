#include<bits/stdc++.h>
using namespace std;
#define MAX 100000 //maximum node
typedef long long ll;
vector <ll> edges[MAX];
vector <ll> cost[MAX]; //parallel vector to store costs;
int main() {
   freopen("s1.txt","r",stdin);
    freopen("outputs1.txt","w",stdout);
  ll numNodes, numEdges,x,y;
  cin>>numNodes;
  while(scanf("%lld%lld",&x,&y)!=EOF) {
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
       cout<<"Nodes \tDegree of Nodes "<<endl;
    for(ll j=0;j<numNodes;j++){
       cout<<j<<"\t\t";
       ll count=0;
  for(ll i=0;i<edges[j].size();i++){
         count+=1;
      }
      cout<<count<<endl;
      }
  return 0;
}
