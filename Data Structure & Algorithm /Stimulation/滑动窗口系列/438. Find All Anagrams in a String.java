class Solution {
    // https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        int m = p.length();
        int n = s.length();
        if(m > n) return ans;
        HashMap<Character, Integer> map = new HashMap<>();
        int l = 0;
        int r = m - 1;
        for(int i = 0; i < m; ++i){
            char ch = p.charAt(i);
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }
        HashMap<Character, Integer> sub_map = new HashMap<>();
        for(int k = 0; k < m; ++k){

            char ch = s.charAt(k);
            sub_map.put(ch, sub_map.getOrDefault(ch, 0) + 1);
        }
        while(r < n){
            boolean isValid = true;
            Iterator it = sub_map.entrySet().iterator();
            while (it.hasNext()) {
                Map.Entry mapElement = (Map.Entry)it.next();
                if((int)map.getOrDefault(mapElement.getKey(), 0) != (int)mapElement.getValue()){
                    isValid = false;
                    break;
                }
            }
            if(isValid) ans.add(l);
            char ch = s.charAt(l);
            sub_map.put(ch, sub_map.getOrDefault(ch, 0) - 1);
            l++;
            r++;
            if(r < n){
                ch = s.charAt(r);
                sub_map.put(ch, sub_map.getOrDefault(ch, 0) + 1);
            }
        }
        return ans;
    }
}