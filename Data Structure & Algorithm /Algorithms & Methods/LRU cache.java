import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

class LRU<K, V>{
    class Node{
        K key;
        V val;
        Node next;
        Node pre;
        Node(){}
        Node(K key, V val){
            this.key = key; this.val = val;
            next = null; pre = null;
        }
    }
    private Map<K, Node> m = new HashMap<>();   // HashMap, Integer means "Index"
    private int capacity;                       // store the capacity of the Cache
    private int size;                           // store actual numbers in HashMap
    private Node head, tail;                    // not real head and tail of elements, way to implement 2-d list

    public LRU(int c){
        size = 0;
        capacity = c;
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.pre = head;
    }
    public void put(K k, V v){
        Node node = m.get(k);
        if(node == null){                       // the k-v not in Map
            node = new Node(k, v);
            setHead(node);
            m.put(k, node);
            size++;
        }else{                                  // k-v in map, update the value, then move it to head
            node.val = v;
            moveToHead(node);
        }
        if(size > capacity){                    // reach the top of capacity, then remove the tail element
            removeTail();
        }
    }
    public V get(K k){
        Node node = m.get(k);
        if(node == null) return null;
        else{
            moveToHead(node);
            return node.val;
        }
    }
    private void setHead(Node node){
        node.pre = head;
        node.next = head.next;
        head.next.pre = node;
        head.next = node;
    }
    private void delete(Node node){
        node.next.pre = node.pre;
        node.pre.next = node.next;
    }
    private void moveToHead(Node node){
        delete(node);
        setHead(node);
    }
    private void removeTail(){
        Node deleted = tail.pre;
        delete(deleted);
        m.remove(deleted.key);
        size--;
    }
}

public class JavaGo {
    //static private final String INPUT = "/Users/robertwong/IdeaProjects/DataStructure/src/input.txt";
    //static private final String OUTPUT = "/Users/robertwong/IdeaProjects/DataStructure/src/output.txt";
    public static void main(String[] args){
        //FileInputStream instream = null;
        //PrintStream outstream = null;
//        try {
//            instream = new FileInputStream(INPUT);
//            outstream = new PrintStream(new FileOutputStream(OUTPUT));
//            System.setIn(instream);
//            System.setOut(outstream);
//        } catch (Exception e) {
//            System.err.println("Error Occurred.");
//        }
        Scanner in = new Scanner(System.in); // freopen() on
        int n = in.nextInt();
        int m = in.nextInt();
        in.nextLine();
        //System.out.println(n + " " + m);
        LRU<Integer, String> cache = new LRU<>( n /* capacity */ );
        for (int i = 0; i < m; i++) {
            String input = in.nextLine();
            //System.out.println(input);
            if(input.charAt(0) == 'p'){
                input = input.replaceAll("put ", "");
                String [] tempInput = input.split(";");
                for(String it : tempInput){
                    String [] key_val = it.split(",");
                    cache.put(Integer.parseInt(key_val[0]), key_val[1]);
                }
            }else{
                input = input.replaceAll("get ", "");
                String [] tempInput = input.split(";");
                for(String it : tempInput){
                    System.out.print(cache.get(Integer.parseInt(it)) + ";");
                }
                System.out.println();
            }
        }
    }
}
