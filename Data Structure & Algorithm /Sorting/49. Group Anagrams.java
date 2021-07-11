class Solution {
    // https://leetcode-cn.com/problems/group-anagrams/
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();
        for(String str : strs){
            char[] chs = str.toCharArray();
            Arrays.sort(chs);
            String sorted_str = String.valueOf(chs);
            //System.out.println(sorted_str);
            List<String> words;
            if(map.containsKey(sorted_str)){
                words = map.get(sorted_str);
                //System.out.println("contains!");
            }else{
                words = new LinkedList<>();
            }
            words.add(str);
            map.put(sorted_str, words);
        }
        List<List<String>> ans = new ArrayList<List<String>>(map.values());
        return ans;
    }
}