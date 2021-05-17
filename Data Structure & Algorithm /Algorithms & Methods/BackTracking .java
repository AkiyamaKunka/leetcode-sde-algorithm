class Solution {
    // https://leetcode.com/problems/permutations-ii/submissions/
    // Java grammar and these methods of using is the key
    // just make repeation and it will be fine 
    protected void backTrack(
            LinkedList<Integer> comb,
            Integer N,
            HashMap<Integer, Integer> counter,
            List<List<Integer>> ans){
        if(comb.size() == N){
            ans.add(new ArrayList<Integer>(comb));
            return;
        }
        for(Map.Entry<Integer, Integer> entry : counter.entrySet()){
            Integer num = entry.getKey();
            Integer count = entry.getValue();
            if(count == 0){
                continue;
            }
            counter.put(num, count - 1);
            comb.addLast(num);
            backTrack(comb, N, counter, ans);
            comb.removeLast();
            counter.put(num, count);
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        HashMap<Integer, Integer> counter = new HashMap();
        LinkedList<Integer> comb = new LinkedList<>();
        for(int num : nums){
            if(!counter.containsKey(num)){
                counter.put(num, 0);
            }
            counter.put(num, counter.get(num) + 1);
        }
        backTrack(comb, nums.length, counter, ans);
        return ans;

    }
}