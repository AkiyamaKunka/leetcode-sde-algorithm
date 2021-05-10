
public class myQueque<Item>{
    private int num;
    private class Node{
        Node next;
        Item info;
        public Node(Item item, Node next){
            this.info = item;
            this.next = next;
        }
    }
    private Node head;
    private Node end;
    public boolean isEmpty(){
        return head == end && end == null;
    }
    public int showSize(){
        return num;
    }
    public void push(Item item){

        Node oldEnd = end;

        end = new Node(item,oldEnd);
        if( head == null )
            head = end;
        num++;
    }
    public Item pop(){
        if(isEmpty())
            return null;
        Node temp = head;
        head = head.next;
        num--;
        return temp.info;
    }
}