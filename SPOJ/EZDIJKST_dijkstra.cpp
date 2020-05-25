/*
	Author : Surya Kant 
	Date : 25-05-2020
	
	EZDIJKST - Easy Dijkstra Problem 
	Directed graph, source, destination, find minimum distance between source and destination
	Problem Statement : https://www.spoj.com/problems/EZDIJKST/
*/

#include<bits/stdc++.h>
using namespace std;
 
void set_distance(int distance[],int n,int src)
{
    for(int i=1;i<=n;++i)
        distance[i]=INT_MAX;
    distance[src]=0;
}
 
int min_dis_index(int distance[],int n,bool done[])
{
    int min_index,min_dis;
    min_dis=INT_MAX-2;
    for(int i=1;i<=n;++i)
    {
        if(done[i])
            continue;
        if(min_dis>distance[i])
        {
            min_dis=distance[i];
            min_index=i;
        }
    }
    return min_index;
}
void dijkstra(vector<vector<pair<int,int>>>graph,int n,int src,int dest)
{
    bool done[n+1]={false};
    int distance[n+1]={0};
    set_distance(distance,n,src);
    for(int i=0;i<n;++i)
    {
        int u=min_dis_index(distance,n,done);
        done[u]=true;
 
        for(auto x:graph[u])
        {
            int v=x.first;
            int cost=x.second;
 
            if(distance[v]>distance[u]+cost)
            {
                distance[v]=distance[u]+cost;
            }
        }
        if(done[dest]==true)
        {
            cout<<distance[dest]<<"\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main()
{
    int t;
    cin>>t;
 
    while(t--)
    {
        int n,e;
        cin>>n>>e;
 
        vector<vector<pair<int,int>>>graph(n+1);
 
        for(int i=0;i<e;++i)
        {
            int u,v,w;
            cin>>u>>v>>w;
 
            graph[u].push_back(make_pair(v,w));
        }
 
        int src,dest; 
        cin>>src>>dest;
        dijkstra(graph,n,src,dest);
    }
} 
