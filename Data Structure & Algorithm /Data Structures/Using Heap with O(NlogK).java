class Solution {
    // https://leetcode-cn.com/problems/top-k-frequent-elements/submissions/
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        HashSet<Integer> set = new HashSet<>();
        for(int it : nums){
            if(!map.containsKey(it)){
                map.put(it, 0);
                set.add(it);
            }
            map.put(it, map.get(it) + 1);
        }
        Queue<int[]> q = new PriorityQueue<>( new Comparator<int[]>(){
            public int compare(int[] e1, int[] e2){
                return e1[1] - e2[1]; // ascending order
            }
        });
        for(int it : set){
            if(q.size() < k){
                q.offer(new int[]{it, map.get(it)});
            }else{
                if(q.peek()[1] < map.get(it)){
                    q.poll();
                    q.offer(new int[]{it, map.get(it)});
                }
            }
        }
        int[] ans = new int [k];
        for(int i = 0; i < k; ++i){
            ans[i] = q.poll()[0];
        }
        return ans;

    }
}