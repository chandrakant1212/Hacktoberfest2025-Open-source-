class Solution {
public:
    int find(int x, vector<int>& parent) {
    if (parent[x] != x)
        parent[x] = find(parent[x], parent); // Path compression
    return parent[x];
}
    int makeConnected(int n, vector<vector<int>>& connections) {
     if (connections.size() < n - 1) return -1;

       vector<int>parent(n,0);
       for(int i=0;i<n;i++) parent[i]=i;
        int components = n;
        for (auto& conn : connections) {
            int a = find(conn[0], parent);
            int b = find(conn[1], parent);
            if (a != b) {
                parent[a] = b;
                components--;
            }
        }
        return components - 1; 
    }
};
