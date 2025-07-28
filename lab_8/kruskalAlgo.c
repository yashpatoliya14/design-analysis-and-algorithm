#include<stdio.h>

int parent[] = {1,2,3,4,5,6,7};
int rank[] = {0,0,0,0,0,0,0};

struct Edge
{
    int wt;
    int u;
    int v;
};

void sortEdges(struct Edge edges[] , int E){
    
    for (int i = 0; i < E; i++)
    {
        int min = i;
        for (int j = i+1; j < E; j++)
        {
            if(edges[min].wt > edges[j].wt){
                min = j;
            }
        }
        if(i!=min){
            struct Edge temp = edges[min];
            edges[min] = edges[i];
            edges[i] = temp; 
        }
    }
    
}


int findPar(int node){
    if(node ==parent[node]){
        return node;
    }
    parent[node] =  findPar(node);
    return parent[node];
}

void unionByRank(int u,int v){
    int u_parent = parent[u];
    int v_parent = parent[v];

    if(rank[u_parent]<rank[v_parent]){
        parent[u_parent] = parent[v_parent];
    }else if(rank[u_parent]>rank[v_parent]){
        parent[v_parent] = parent[u_parent];
    }else{
        parent[v_parent] = parent[u_parent];
        rank[u_parent]++;
    }
}

int findMst(struct Edge edges[], int u,int v){
    int u_parent = parent[u];
    int v_parent = parent[v];
    int mst = 0;
    if(u_parent!=v_parent){
        mst+= edges[u].wt;
        unionByRank(u,v);
    }
}

void main(){
    struct Edge edges[8] = {
        {0, 1, 10}, {1, 3, 15}, {2, 3, 4}, {2, 0, 6}, {0, 3, 5}
    };
    
}
