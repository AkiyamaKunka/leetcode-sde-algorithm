enum RBTColor{RED, BLACK};

class Node{
public:
    RBTColor color;
    int data;
    Node * left;
    Node * right;
    Node * parent;
    Node(int value, RBTColor c, Node * p, Node * l, Node * r)
            :data(value), color(c), parent(p), left(l), right(r) {}

public:
    friend class RBT;
};

class RBT{
    Node * mRoot;
public:

    void rightRotate(Node* & p, Node* y){                  // rotate y point, point below is x
        Node * x = y->left;
        y->left = x->right;
        if(x->right != NULL) x->right->parent = y;         // reconnect x's left to y's left

        if(y->parent == NULL) mRoot = x;                   // reconnect y's father to x
        else if(y->parent->left == y) y->parent->left = x;
        else y->parent->right = x;
        x->parent = y->parent;

        x->right = y;                                      // reconnect x's right to y
        y->parent = x;
    }

    void leftRotate(Node* & p, Node* y){                   // rotate y point, point below is x
        Node * x = y->right;
        y->right = x->left;
        if(x->left != NULL) x->left->parent = y;           // reconnect x's right to y's right

        if(y->parent == NULL) mRoot = x;                   // reconnect y's father to x
        else if(y->parent->right == y) y->parent->right = x;
        else y->parent->left = x;
        x->parent = y->parent;

        x->left = y;                                       // reconnect x's left to y
        y->parent = x;
    }

    void insert(int value){
        cout << "root made";
        Node * temp = new Node(value, BLACK, NULL, NULL, NULL);
        Node * z = temp;                                   // To prevent size allocation failure
        if((z = new Node(value, BLACK, NULL, NULL, NULL)) == NULL) return;

        cout << "root made";
        insert(mRoot, z);
    }

    void insert(Node * &root, Node * insertNode) {
        if (root == NULL) {root = insertNode;        }        // tree is empty
        else {
            Node *x = root;
            Node *y = NULL;                                // y to record x's location
            while (x != NULL) {
                y = x;
                if (x->data == insertNode->data) cout << "Repeated Insertion Error" << endl;
                else if (x->data > insertNode->data) x = x->left;
                else x = x->right;
            }
            insertNode->parent = y;                        // connect node to its y position expected

            if (y->data > insertNode->data) y->left = insertNode;
            else y->right = insertNode;
        }
        insertNode->color = RED;                           // set inserted node to be red
        insertFixUp(root, insertNode);                 // adjustment
    }
    void insertFixUp(Node * &root, Node * insertNode){
        Node * parent, * gParent;

        while((parent = insertNode->parent) && parent->color == RED){
            // only one with red parent need fixup
            gParent = parent->parent;
            if (parent == gParent->left)  {                // when parent is gparent's left
                //case 1: uncle is red
                if(gParent->right != NULL && gParent->right->color == RED){
                    parent->color = BLACK;
                    gParent->right->color = BLACK;
                    gParent->color = RED;
                    insertNode = gParent;
                }
                    //case 2: uncle is null or black
                else {
                    if(parent->left == insertNode) {       // node is parent's right son
                        leftRotate(root, parent);      // need extra operation to convert left codition
                        Node * temp = parent;              // exchange parent and node's pointer
                        parent = insertNode;
                        insertNode = temp;
                    }
                    // now node is parent's left son condition
                    parent->color = BLACK;
                    gParent->color = RED;
                    rightRotate(root, gParent);
                }
            }else{                                         // mirrored operations, p is gp's right
                // case 1, uncle is red
                if(gParent->left != NULL && gParent->left->color == RED){
                    gParent->color = RED;
                    gParent->left->color = BLACK;
                    gParent->right->color = BLACK;
                }
                else {                                     // case 2: uncle is null or black
                    if(parent->right == insertNode){
                        rightRotate(root, parent);
                        Node * temp = parent;
                        parent = insertNode;
                        insertNode = temp;
                    }
                    parent->color = BLACK;
                    gParent->color = RED;
                    leftRotate(root, gParent);
                }
            }
        }
        root->color = BLACK;                               // assure that root is BLACK after adjustment
    }

    void removeFixUp(Node * &root, Node * node, Node * parent){
        Node * brother;

        while((!node || node->color == BLACK ) && node != root){
            if(parent->left == node){                      // node is located at the left side
                brother = parent->right;
                // case 1: brother is red
                if(brother && brother->color == RED){
                    brother->color = BLACK;
                    parent->color = RED;
                    leftRotate(root, parent);
                    brother = parent->right;
                }
                // case 2: brother is black
                if((!brother->left || brother->left->color == BLACK)
                   && (!brother->right || brother->right->color == BLACK)){ // case 2.1 sons are 2 black
                    brother->color = RED;
                    node = parent;
                    parent = node->parent;
                }else{
                    if(!brother->right || brother->right->color == BLACK){ // case 2.2
                        brother->left->color = BLACK;   // brother's left is red
                        brother->color = RED;
                        rightRotate(root, brother);
                        brother = parent->right;
                    }                                   // case 2.3 brother's right is red
                    brother->color = parent->color;
                    parent->color = BLACK;
                    brother->right->color = BLACK;
                    leftRotate(root, parent);
                    node = root; // prevent breaking down?
                    break;
                }
            }else {
                brother = parent->left;
                if (brother->color == RED)
                {

                    brother->color = BLACK;
                    parent->color = RED;
                    rightRotate(root, parent);
                    brother = parent->left;
                }
                if ((!brother->left || brother->left->color == BLACK) &&
                    (!brother->right || brother->right->color == BLACK))
                {

                    brother->color = RED;
                    node = parent;
                    parent = node->parent;
                }
                else
                {
                    if (!brother->left || brother->left->color == BLACK)
                    {

                        brother->right->color = BLACK;
                        brother->color = RED;
                        leftRotate(root, brother);
                        brother = parent->left;
                    }

                    brother->color = parent->color;
                    parent->color = BLACK;
                    brother->left->color = BLACK;
                    rightRotate(root, parent);
                    node = root;
                    break;
                }
            }
            if(node) node->color = BLACK;
        }
    }
    Node * search(Node * &root, int value){

    }
    void remove(Node * &root, Node * node){
        Node * child, * parent;
        RBTColor color;

        if(node->left && node->right){                     // removed node left and right are both not empty

            Node * replace = node->right;
            while(replace->left) replace = replace->left;   // find the decedent node to replace it
            if(node == root) root = replace;                // special condition: removed node is root
            else{
                if(node->parent->left == node){             // reconnect replace and node's parent
                    node->parent->left = replace;
                }else{
                    node->parent->right = replace;
                }
            }
            color = replace->color;                     // remember to store replace's color, right son and father for further usage
            child = replace->right;
            parent = replace->parent;
            if(parent == node){                         // node and replace is just adjacent
                parent = replace;
            }else {
                if(child){
                    child->parent = parent;
                    parent->left = child;               // reconnect replace's parent and right child
                    replace->right = node->right;
                    node->right->parent = replace;
                }
            }
            replace->parent = node->parent;
            replace->color = node->color;
            replace->left = node->left;
            node->left->parent = replace;

            if(color == BLACK) removeFixUp(root, child, parent);
            delete node;
            return ;
        }
        if(node->left) child = node->left;
        else child = node->right;
        parent = node->parent;
        if(child)
            child->parent = parent;

        // node is not root
        if(parent){
            if(parent->left == node) parent->left = child;
            else parent->right = child;
        }
        else
            root = child;
        if(color == BLACK)
            removeFixUp(root, child, parent);
        delete node;
    }
    void remove(int value){
        Node * node;
        if((node = search(mRoot, value))) remove(mRoot, node);
    }

};
