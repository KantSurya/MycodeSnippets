int hMax;
vector<int>depth;
vector<vector<int>>up;

TreeAncestor(int n, vector<int>& parent) {
    hMax = 0 ; 
    while( (1<<hMax) <= n)hMax++;
    parent[0] = 0;
    up = vector<vector<int>>(n,vector<int>(hMax,0));
    depth = vector<int>(n,0);
    for(int i = 0 ; i < n ; ++i) up[i][0] = parent[i];
    for(int j = 1 ; j < hMax ; ++j){
        for(int i = 1 ; i < n ; ++i){
            depth[i] = depth[up[i][0]] + 1;
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

int getKthAncestor(int node, int k) {
    if(depth[node]<k)return -1;
    for(int j = 0 ; j < hMax ; ++j){
        if( k & (1<<j) ){
            node = up[node][j];
        }
    }
    return node;
}