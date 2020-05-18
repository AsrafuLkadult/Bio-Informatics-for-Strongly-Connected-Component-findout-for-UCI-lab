#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
typedef long long ll;
 ll graph[MAX][MAX];
 ll indegree1[MAX],outdegree1[MAX];
int main()
{
     freopen("n10000.txt","r",stdin);
     freopen("outputn10000.txt","w",stdout);
    ll i,j,vertex,p,x,y,a,q,w;
    scanf("%lld",&vertex);
    while(scanf("%lld%lld",&x,&y)!=EOF){
     graph[x][y]=1;
    }
    printf("\n");
    for(i=0;i<vertex;i++)
    {
         for(j=0;j<vertex;j++)
         {
              if(graph[i][j]==1)
              {
                    outdegree1[i]++;
                    indegree1[j]++;
              }
         }

    }
    printf("Node\tIndegree\n");
    for(p=0;p<vertex;p++)
    {
        printf("%lld\t%lld\n",p,indegree1[p]);
    }
    printf("Node\tOutdegree\n");
    for(a=0;a<vertex;a++)
    {
        printf("%lld\t%lld\n",a,outdegree1[a]);
    }

    return 0;
}
