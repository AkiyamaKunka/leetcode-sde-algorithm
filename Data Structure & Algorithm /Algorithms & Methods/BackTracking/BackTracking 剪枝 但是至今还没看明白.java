class Solution {
    // https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/
    int ans;
    void dfs(int cur, int[] jobs, int[] times, int max, int used){
        if(max >= ans) return;
        if(cur == jobs.length){
            if(max < ans) ans = max;
            return;
        }

        if(used < times.length){
            times[used] += jobs[cur];
            dfs(cur + 1, jobs, times, Math.max(times[used], max), used + 1);
            times[used] -= jobs[cur];
        }

        for(int i = 0; i < used; ++i){

            times[i] += jobs[cur];
            dfs(cur + 1, jobs, times, Math.max(times[i], max), used);
            times[i] -= jobs[cur];
        }
    }

    public int minimumTimeRequired(int[] jobs, int k) {
        int[] times = new int[k];
        ans = 0x3f3f3f3f;
        dfs(0, jobs, times, 0, 0);
        return ans;
    }
}