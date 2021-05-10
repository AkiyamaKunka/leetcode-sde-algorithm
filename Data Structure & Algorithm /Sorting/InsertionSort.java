package wong13626;

public class InsertionSort {
    private static boolean less(Comparable a, Comparable b){
        return a.compareTo(b) < 0;
    }
    private static void exch(Comparable [] a, int i , int j){
        Comparable t = a[i];
        a[i] =  a[j];
        a[j] = t;
    }

    public static void solution(Comparable [] a){
        int N = a.length;
        for (int i = 0; i < N; ++i) {
            for (int j = i - 1; j >= 0 && less(a[j] , a[j-1]); --j)
                exch(a, j-1, j);

        }
    }


}

