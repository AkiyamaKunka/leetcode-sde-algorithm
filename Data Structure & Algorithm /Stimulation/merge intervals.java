class Solution {
    // https://leetcode-cn.com/problems/merge-intervals/submissions/
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int [] e1, int [] e2){
                return e1[0] - e2[0];
            }
        }); // Java里override sort函数
        List<int[]> pre_ans = new LinkedList<>();
        int i = 0;
        while(i < intervals.length){
            int l = intervals[i][0];
            int r = intervals[i][1];
            while(i + 1 < intervals.length && intervals[i + 1][0] <= r){
                r = Math.max(intervals[i + 1][1], r);
                i++;
            }
            i++;
            pre_ans.add(new int[]{l, r});
        }

        return pre_ans.toArray(new int[pre_ans.size()][]);
    }
}