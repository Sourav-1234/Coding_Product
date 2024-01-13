class DisjointSet{
    vector<int> rank,parent,size;
    public :
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    

    }

    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u ,int v){
        int ulp_u=findUPar(u);
        int vlp_v=findUPar(v);
        if(ulp_u==vlp_v) return;
       if(rank[ulp_u]<rank[vlp_v]){
            parent[ulp_u]=vlp_v;
       }
       else if(rank[vlp_v]>rank[ulp_u]){
        parent[vlp_v]=ulp_u;
       }
       else{
         parent[ulp_u]=vlp_v;
         rank[ulp_u]++;
       }

    }

    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int vlp_v=findUPar(v);

        if(ulp_u==vlp_v) return;
        if(size[ulp_u]<size[vlp_v]){
            parent[ulp_u]=vlp_v;
            size[vlp_v]+= size[ulp_u];
        }
        else{
            parent[vlp_v]=ulp_u;
            size[ulp_u]+=size[vlp_v];
        }
    }

};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        cout<<n;
        int components=n;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1 && ds.findUPar(i)!=ds.findUPar(j)){
                 components--;
                 ds.unionByRank(i,j); 
                }
            }
        }
        return components;

    }
};