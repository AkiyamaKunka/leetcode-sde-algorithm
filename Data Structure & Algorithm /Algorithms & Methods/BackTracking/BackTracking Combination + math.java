class Solution {
    // https://leetcode-cn.com/problems/count-sorted-vowel-strings/


    // C(n + m - 1, n - 1);

    private static long comb(int m,int n){
        if(n==0)
            return 1;
        if (n==1)
            return m;
        if(n>m/2)
            return comb(m,m-n);
        else
            return comb(m-1,n-1)+comb(m-1,n);
    }

    public int countVowelStrings(int n) {
        return (int) comb(n + 5 - 1, 5 - 1);
    }
}