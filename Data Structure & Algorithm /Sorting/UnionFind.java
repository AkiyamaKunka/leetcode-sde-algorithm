package wong13626;

public class MySolution {
    int [] size;
    int [] next;
    int NodeNumber;
    int cnt;
    public MySolution(int num){
        NodeNumber = num;
        next = new int[NodeNumber];
        size = new int[NodeNumber];
        for (int i = 0; i < NodeNumber; i++) {
            next[i] = i;
            size[i] = 1;
        }
        cnt = NodeNumber;
    }
    public int findRoot(int num){
        while(num != next[num]) num = next[num];
        return num;
    }
    public int showNum(){
        return cnt;
    }
    public boolean isConnected(int p, int q){
        return findRoot(p)==findRoot(q);
    }
    public void solve(int numLeft , int numRight){
        int rootLeft = findRoot(numLeft);
        int rootRight = findRoot(numRight);
        if(rootLeft == rootRight) return;
        if(size[rootLeft] <= size[rootRight]){
            next[rootLeft] = rootRight;
            size[rootRight] += size[rootLeft];
        }else{
            next[rootRight] = rootLeft;
            size[rootLeft] += size[rootLeft];
        }
        cnt--;
        return ;
    }

}
