class UnionFind{
private:
    int * fa;
public:
    UnionFind(int n){
        fa = new int[n];
        for (int i = 0; i < n; i++)
            fa[i] = i;
    }
    int find(int i){
        return i == fa[i] ? i : fa[i] = find(fa[i]);
    }
    void unit(int x, int y){
        fa[find(x)] = find(y);
    }
};