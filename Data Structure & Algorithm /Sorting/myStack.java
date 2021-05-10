

public class myStack<Item> {
    private int num;
    private Node first;
    private class Node{
        private Item info;
        private Node next;
        public Node(Item item, Node next){
            this.info = item;
            this.next = next;
        }
    }
    public boolean isEmpty(){
        return first == null;
    }
    public int showSize(){
        return num;
    }

    public void push(Item item){
        Node oldFirst = first;
        Node temp = new Node( item,oldFirst);
        first = temp;
        num++;
    }
    public Item pop(){
        if( isEmpty() )
            return null;
        Node temp = first;
        first = first.next;
        num--;
        return temp.info;
    }

}

