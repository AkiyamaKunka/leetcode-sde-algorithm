#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

// BSTree
struct BSNode
{
    int val;
    BSNode *left, *right;

    BSNode(): val(0), left(NULL), right(NULL) {}
};
class BSTree
{
public:
    BSNode *root;
    BSTree() { root = NULL; }

private:
    int findMinMax(BSNode *&u);

    BSNode* searchNode(int x);
    void insertNode(int x);
    void delNode(int x);

public:
    BSNode* search(int x) { return searchNode(x); }
    void insert(int x) { insertNode(x); }
    void del(int x) { delNode(x); }
};
int BSTree::findMinMax(BSNode *&u)
{
    if(u->left == NULL) return u->val;
    BSNode *v = u->left;
    while(v->right != NULL) v = v->right;
    return v->val;
}
BSNode* BSTree::searchNode(int x)
{
    BSNode *v = root;
    while(v->val != x)
    {
        if(v->val > x)
        {
            if(v->left != NULL) v = v->left;
            else return NULL;
        }
        else if(v->val < x)
        {
            if(v->right != NULL) v = v->right;
            else return NULL;
        }
    }
    return v;
}
void BSTree::insertNode(int x)
{
    if(root == NULL)
    {
        root = new BSNode; root->val = x;
        return;
    }
    BSNode *v = root;
    while(v->val != x)
    {
        if(v->val > x)
        {
            if(v->left != NULL) v = v->left;
            else
            {
                v->left = new BSNode, v->left->val = x;
                return;
            }
        }
        else if(v->val < x)
        {
            if(v->right != NULL) v = v->right;
            else
            {
                v->right = new BSNode, v->right->val = x;
                return;
            }
        }
    }
}
void BSTree::delNode(int x)
{
    BSNode *v = root, *fa;

    while(x != v->val)
    {
        if(v->val > x)
        {
            if(v->left == NULL) return;
            else fa = v, v = v->left;
        }
        else if(v->val < x)
        {
            if(v->right == NULL) return;
            else fa = v, v = v->right;
        }
    }

    if(v->left == NULL && v->right == NULL)
    {
        if(v == this->root) root = NULL;
        else
        {
            if(fa->left == v) fa->left = NULL;
            else fa->right = NULL;
        }
    }
    else if(v->left != NULL && v->right == NULL)
    {
        if(v == this->root) root = v->left;
        else
        {
            if(fa->left == v) fa->left = v->left;
            else fa->right = v->left;
        }
    }
    else if(v->left == NULL && v->right != NULL)
    {
        if(v == this->root) root = v->right;
        else
        {
            if(fa->left == v) fa->left = v->right;
            else fa->right = v->right;
        }
    }
    else
    {
        int pre = findMinMax(v);
        delNode(pre); v->val = pre;
    }
}


// AVLTree
struct AVLNode
{
    int val, lh, rh;
    AVLNode *left, *right;

    AVLNode(): val(0), lh(0), rh(0), left(NULL), right(NULL) {}
};
class AVLTree
{
public:
    AVLNode *root;
    AVLTree() { root = NULL; }

private:
    void LL(AVLNode *&u);
    void RR(AVLNode *&u);
    void LR(AVLNode *&u);
    void RL(AVLNode *&u);
    int findMinMax(AVLNode *&u);

    AVLNode* searchNode(AVLNode *&u, int x);
    void insertNode(AVLNode *&u, int x);
    AVLNode* delNode(AVLNode *&u, AVLNode *&fa, int x);

public:
    AVLNode* search(int x) { return searchNode(root, x); }
    void insert(int x) { insertNode(root, x); }
    AVLNode* del(int x) { AVLNode *fa = new AVLNode; return delNode(root, fa, x); }
};
void AVLTree::LL(AVLNode *&u)
{
    AVLNode *ul = u->left;
    u->left = ul->right; u->lh = ul->rh;
    ul->right = u; ul->rh = max(u->lh, u->rh)+1;
    u = ul;
}
void AVLTree::RR(AVLNode *&u)
{
    AVLNode *ur = u->right;
    u->right = ur->left; u->rh = ur->lh;
    ur->left = u; ur->lh = max(u->lh, u->rh)+1;
    u = ur;
}
void AVLTree::LR(AVLNode *&u)
{
    AVLTree::RR(u->left);
    AVLTree::LL(u);
}
void AVLTree::RL(AVLNode *&u)
{
    AVLTree::LL(u->right);
    AVLTree::RR(u);
}
int AVLTree::findMinMax(AVLNode *&u)
{
    if(u->left == NULL) return u->val;
    AVLNode *v = u->left;
    while(v->right != NULL) v = v->right;
    return v->val;
}
AVLNode* AVLTree::searchNode(AVLNode *&u, int x)
{
    if(u->val == x) return u;
    if(u->val > x && u->left != NULL)
    {
        AVLNode *v = AVLTree::searchNode(u->left, x);
        if(v != NULL) return v;
    }
    if(u->val < x && u->right != NULL)
    {
        AVLNode *v = AVLTree::searchNode(u->right, x);
        if(v != NULL) return v;
    }
    return NULL;
}
void AVLTree::insertNode(AVLNode *&u, int x)
{
    if(u == NULL)
    {
        u = new AVLNode; u->val = x;
        return;
    }
    if(x < u->val)
    {
        if(u->left == NULL)
        {
            AVLNode *v = new AVLNode; v->val = x;
            u->left = v; u->lh = 1;
        }
        else
        {
            insertNode(u->left, x);
            u->lh = max(u->left->lh, u->left->rh) + 1;
            if(u->lh > u->rh + 1)
            {
                if(x > u->left->val) LR(u);
                else if(x < u->left->val) LL(u);
            }
        }
    }
    else if(x > u->val)
    {
        if(u->right == NULL)
        {
            AVLNode *v = new AVLNode; v->val = x;
            u->right = v; u->rh = 1;
        }
        else
        {
            insertNode(u->right, x);
            u->rh = max(u->right->lh, u->right->rh) + 1;
            if(u->rh > u->lh + 1)
            {
                if(x < u->right->val) RL(u);
                else if(x > u->right->val) RR(u);
            }
        }
    }
}
AVLNode* AVLTree::delNode(AVLNode *&u, AVLNode *&fa, int x)
{
    AVLNode *res;
    if(x < u->val)
    {
        if(u->left == NULL) return NULL;
        else
        {
            res = AVLTree::delNode(u->left, u, x);
            if(u->left != NULL) u->lh = max(u->left->lh, u->left->rh) + 1;
            else u->lh = 0;

            if(u->rh - u->lh > 1)
            {
                if(u->right->lh > u->right->rh) RL(u);
                else RR(u);
            }
            return res;
        }
    }
    else if(x > u->val)
    {
        if(u->right == NULL) return NULL;
        else
        {
            res = AVLTree::delNode(u->right, u, x);
            if(u->right != NULL) u->rh = max(u->right->lh, u->right->rh) + 1;
            else u->rh = 0;

            if(u->lh - u->rh > 1)
            {
                if(u->left->rh > u->left->lh) LR(u);
                else LL(u);
            }
            return res;
        }
    }
    else
    {
        res = u;
        if(u->left == NULL && u->right == NULL)
        {
            if(u == this->root) root = NULL;
            else
            {
                if(fa->left == u) fa->left = NULL;
                else fa->right = NULL;
            }
            return res;
        }
        else if(u->left != NULL && u->right == NULL)
        {
            if(u == this->root) root = u->left;
            else
            {
                if(fa->left == u) fa->left = u->left;
                else fa->right = u->left;
            }
            return res;
        }
        else if(u->left == NULL && u->right != NULL)
        {
            if(u == this->root) root = u->right;
            else
            {
                if(fa->left == u) fa->left = u->right;
                else fa->right = u->right;
            }
            return res;
        }
        else
        {
            int pre = findMinMax(u);
            u->val = pre;
            AVLTree::delNode(u->left, u, pre);
            if(u->left != NULL) u->lh = max(u->left->lh, u->left->rh) + 1;
            else u->lh = 0;

            if(u->rh - u->lh > 1)
            {
                if(u->right->lh > u->right->rh) RL(u);
                else RR(u);
            }
            return res;
        }
    }
}


// RBTree
struct RBNode
{
    int val, col;   // 黑色为1，红色为0
    RBNode *left, *right;

    RBNode(): val(0), col(1), left(NULL), right(NULL) {}
};
class RBTree
{
public:
    RBNode *root;
    RBTree() { root = NULL; }

private:
    void LL(RBNode *&u);
    void RR(RBNode *&u);
    void LR(RBNode *&u);
    void RL(RBNode *&u);
    inline bool isBlack(RBNode *&u) { return u == NULL || u->col == 1; }
    inline void r(RBNode *&u) { if(u != NULL) u->col = 0; }
    inline void b(RBNode *&u) { if(u != NULL) u->col = 1; }
    void insertFix(RBNode *&u, RBNode *&pu, RBNode *&gu);
    int findSuf(RBNode *&u);
    int delFix(RBNode *&y, RBNode *&py);   // 如果需要回溯则返回1

    RBNode* searchNode(RBNode *&u, int x);
    void insertNode(RBNode *&u, RBNode *&pu, RBNode *&gu, int x);
    RBNode* delNode(RBNode *&y, RBNode *&py, int x, int &flag);

public:
    RBNode* search(int x) { return searchNode(root, x); }
    void insert(int x) { RBNode *pu = new RBNode, *gu = new RBNode; insertNode(root, pu, gu, x); }
    RBNode* del(int x) { RBNode *py = new RBNode; int flag = 0; return delNode(root, py, x, flag); }
};
void RBTree::LL(RBNode *&u)
{
    RBNode *ul = u->left;
    u->left = ul->right; ul->right = u;
    u = ul;
}
void RBTree::RR(RBNode *&u)
{
    RBNode *ur = u->right;
    u->right = ur->left; ur->left = u;
    u = ur;
}
void RBTree::LR(RBNode *&u)
{
    RBTree::RR(u->left);
    RBTree::LL(u);
}
void RBTree::RL(RBNode *&u)
{
    RBTree::LL(u->right);
    RBTree::RR(u);
}
void RBTree::insertFix(RBNode *&u, RBNode *&pu, RBNode *&gu)
{
    if(isBlack(u) || isBlack(pu)) return;
    if(gu->left == pu)
    {
        if(!isBlack(gu->right))   // LLr和LRr
            r(gu), b(pu), b(gu->right);
        else
        {
            if(pu->left == u)   // LLb
                r(gu), b(pu), LL(gu);
            else   // LRb
                b(u), r(gu), LR(gu);
        }
    }
    else
    {
        if(!isBlack(gu->left))   // RLr和RRr
            r(gu), b(gu->left), b(pu);
        else
        {
            if(pu->left == u)   // RLb
                b(u), r(gu), RL(gu);
            else   // RRb
                r(gu), b(pu), RR(gu);
        }
    }
    if(gu == this->root) b(gu);
}
int RBTree::findSuf(RBNode *&u)
{
    if(u->right == NULL) return u->val;
    RBNode *v = u->right;
    while(v->left != NULL) v = v->left;
    return v->val;
}
int RBTree::delFix(RBNode *&y, RBNode *&py)
{
    if(!isBlack(y)) { b(y); return 0; }
    if(y == py->right)
    {
        RBNode *&v = py->left;
        if(isBlack(v))
        {
            if(isBlack(v->left) && isBlack(v->right))   // Rb0
            {
                if(isBlack(py)) { r(v); return 1; }
                else { r(v); b(py); return 0; }
            }
            else if(isBlack(v->right) && !isBlack(v->left))   // Rb11
            {
                v->col = py->col; b(py); b(v->left);
                LL(py); return 0;
            }
            else   // Rb12和Rb2
            {
                RBNode *&w = v->right; w->col = py->col; b(py);
                LR(py); return 0;
            }
        }
        else
        {
            RBNode *&w = v->right;
            if(isBlack(w->left) && isBlack(w->right))   // Rr0
            {
                b(v); r(w);
                LL(py); return 0;
            }
            else if(isBlack(w->right) && !isBlack(w->left))   // Rr11
            {
                b(w->left);
                LR(py); return 0;
            }
            else   // Rr12和Rr2
            {
                RBNode *&x = w->right; b(x);
                RR(w); RR(v); LL(py); return 0;
            }
        }
    }
    else
    {
        RBNode *&v = py->right;
        if(isBlack(v))
        {
            if(isBlack(v->left) && isBlack(v->right))   // Lb0
            {
                if(isBlack(py)) { r(v); return 1; }
                else { r(v); b(py); return 0; }
            }
            else if(isBlack(v->left) && !isBlack(v->right))   // Lb11
            {
                v->col = py->col; b(v->right); b(py);
                RR(py); return 0;
            }
            else   // Lb12和Lb2
            {
                RBNode *&w = v->left; w->col = py->col; b(py);
                RL(py); return 0;
            }
        }
        else
        {
            RBNode *&w = v->left;
            if(isBlack(w->left) && isBlack(w->right))   // Lr0
            {
                b(v); r(w);
                RR(py); return 0;
            }
            else if(isBlack(w->left) && !isBlack(w->right))   // Lr11
            {
                b(w->right);
                RL(py); return 0;
            }
            else   // Lr12和Lr2
            {
                RBNode *&x = w->left; b(x);
                LL(w); LL(v); RR(py); return 0;
            }
        }
    }
}
RBNode* RBTree::searchNode(RBNode *&u, int x)
{
    if(u->val == x) return u;
    if(u->val > x && u->left != NULL)
    {
        RBNode *v = RBTree::searchNode(u->left, x);
        if(v != NULL) return v;
    }
    if(u->val < x && u->right != NULL)
    {
        RBNode *v = RBTree::searchNode(u->right, x);
        if(v != NULL) return v;
    }
    return NULL;
}
void RBTree::insertNode(RBNode *&u, RBNode *&pu, RBNode *&gu, int x)
{
    if(u == NULL)
    {
        u = new RBNode; u->val = x;
        u->col = u==this->root ? 1 : 0;
        insertFix(u, pu, gu);
        return;
    }
    if(x < u->val)
    {
        insertNode(u->left, u, pu, x);
        insertFix(u, pu, gu);
    }
    else if(x > u->val)
    {
        insertNode(u->right, u, pu, x);
        insertFix(u, pu, gu);
    }
}
RBNode* RBTree::delNode(RBNode *&y, RBNode *&py, int x, int &flag)
{
    RBNode *res;
    if(x < y->val)
    {
        if(y->left == NULL) return NULL;
        res = RBTree::delNode(y->left, y, x, flag);
        if(y == this->root) b(root);
        else if(flag) flag = delFix(y, py);
        return res;
    }
    else if(x > y->val)
    {
        if(y->right == NULL) return NULL;
        res = RBTree::delNode(y->right, y, x, flag);
        if(y == this->root) b(root);
        else if(flag) flag = delFix(y, py);
        return res;
    }
    else
    {
        res = y;
        if(y->left == NULL && y->right == NULL)
        {
            if(isBlack(y))
            {
                if(y == this->root) root = NULL;
                else
                {
                    if(py->left == y) py->left = NULL;
                    else py->right = NULL;
                    flag = delFix(y, py);
                }
            }
            else
            {
                if(py->left == y) py->left = NULL;
                else py->right = NULL;
            }
            return res;
        }
        else if(y->left != NULL && y->right == NULL)
        {
            if(y == this->root) root = y->left, b(root);
            else
            {
                if(py->left == y) py->left = y->left;
                else py->right = y->left;
                if(!isBlack(y)) b(y);
                else flag = delFix(y, py);
            }
            return res;
        }
        else if(y->left == NULL && y->right != NULL)
        {
            if(y == this->root) root = y->right, b(root);
            else
            {
                if(py->left == y) py->left = y->right;
                else py->right = y->right;
                if(!isBlack(y)) b(y);
                else flag = delFix(y, py);
            }
            return res;
        }
        else
        {
            int suf = findSuf(y);
            y->val = suf;
            RBTree::delNode(y->right, y, suf, flag);
            if(y == this->root) b(root);
            else if(flag) flag = delFix(y, py);
            return res;
        }
    }
}


// BTree
struct BNode
{
    bool leaf; int s;
    int e[600];
    BNode *c[600];

    BNode(): leaf(true), s(0) {}

    void insert_ele(int i, int x, BNode *xr)
    {
        this->s++;
        for(int j = s; j > i; j--) e[j] = e[j-1], c[j] = c[j-1];
        e[i] = x; c[i] = xr;
    }
};
class BTree
{
public:
    int m;   // m阶B树
    BNode *root;
    BTree(int m) { this->m = m; root = NULL; }

private:
    void push_up(BNode *&u, BNode *&fa, int id);   // fa->c[id]=u
    int findPre(BNode *&u);
    void push_down(BNode *&u, BNode *&fa, int id);

    BNode* searchNode(BNode *&u, int x);
    void insertNode(BNode *&u, BNode *&fa, int id, int x);
    void delNode(BNode *&u, BNode *&fa, int id, int x);


public:
    BNode* search(int x) { return searchNode(root, x); }
    void insert(int x) { BNode *fa = new BNode; insertNode(root, fa, 0, x); }
    void del(int x) { BNode *fa = new BNode; delNode(root, fa, 0, x); }
};

void BTree::push_up(BNode *&u, BNode *&fa, int id)
{
    if(u->s < m) return;
    if(u == root)
    {
        BNode *l = new BNode, *r = new BNode, *p = new BNode;
        l->leaf = r->leaf = u->leaf;
        int d = (m-1)/2 + 1;

        l->s = d-1; l->c[0] = u->c[0];
        for(int i = 1; i <= d-1; i++) l->e[i] = u->e[i], l->c[i] = u->c[i];
        r->s = m-d; r->c[0] = u->c[d];
        for(int i = 1; i <= m-d; i++) r->e[i] = u->e[d+i], r->c[i] = u->c[d+i];

        p->leaf = false; p->s = 1;
        p->e[1] = u->e[d]; p->c[0] = l; p->c[1] = r;
        root = p;
    }
    else
    {
        BNode *l = new BNode, *r = new BNode;
        l->leaf = r->leaf = u->leaf;
        int d = (m-1)/2 + 1;

        l->s = d-1; l->c[0] = u->c[0];
        for(int i = 1; i <= d-1; i++) l->e[i] = u->e[i], l->c[i] = u->c[i];
        r->s = m-d; r->c[0] = u->c[d];
        for(int i = 1; i <= m-d; i++) r->e[i] = u->e[d+i], r->c[i] = u->c[d+i];
        int x = u->e[d]; u = l;

        fa->insert_ele(id+1, x, r);
    }
}
int BTree::findPre(BNode *&u)
{
    if(u->leaf) return u->e[u->s];
    else return findPre(u->c[u->s]);
}
void BTree::push_down(BNode *&u, BNode *&fa, int id)
{
    int d = (m-1)/2 + 1;
    if(u == root || u == NULL || fa == NULL || u->s >= d-1) return;

    BNode *&v = id==0 ? fa->c[id+1] : fa->c[id-1];
    if(v->s > d-1)
    {
        if(id)
        {
            u->s++;
            for(int j = u->s; j > 1; j--) u->e[j] = u->e[j-1], u->c[j] = u->c[j-1];
            u->e[1] = fa->e[id]; u->c[1] = u->c[0]; u->c[0] = v->c[v->s];
            fa->e[id] = v->e[v->s];
            v->c[v->s] = NULL; v->e[v->s] = 0; v->s--;
        }
        else
        {
            u->s++;
            u->e[u->s] = fa->e[id+1]; u->c[u->s] = v->c[0];
            fa->e[id+1] = v->e[1];
            v->c[0] = v->c[1];
            for(int j = 1; j < v->s; j++) v->e[j] = v->e[j+1], v->c[j] = v->c[j+1];
            v->e[v->s] = 0; v->c[v->s] = NULL; v->s--;
        }
    }
    else
    {
        if(id)
        {
            BNode *w = new BNode;
            w->leaf = v->leaf;

            w->s = v->s + 1 + u->s; w->c[0] = v->c[0];
            for(int i = 1; i <= v->s; i++) w->e[i] = v->e[i], w->c[i] = v->c[i];
            w->e[v->s+1] = fa->e[id]; w->c[v->s+1] = u->c[0];
            for(int i = 1; i <= u->s; i++) w->e[v->s+1+i] = u->e[i], w->c[v->s+1+i] = u->c[i];

            for(int j = id; j < fa->s; j++) fa->e[j] = fa->e[j+1], fa->c[j] = fa->c[j+1];
            fa->e[fa->s] = 0; fa->c[fa->s] = NULL; fa->s--; fa->c[id-1] = w;

            if(fa == root && fa->s == 0) root = w;
        }
        else
        {
            BNode *w = new BNode;
            w->leaf = u->leaf;

            w->s = u->s + 1 + v->s; w->c[0] = u->c[0];
            for(int i = 1; i <= u->s; i++) w->e[i] = u->e[i], w->c[i] = u->c[i];
            w->e[u->s+1] = fa->e[id+1]; w->c[u->s+1] = v->c[0];
            for(int i = 1; i <= v->s; i++) w->e[u->s+1+i] = v->e[i], w->c[u->s+1+i] = v->c[i];

            for(int j = id+1; j < fa->s; j++) fa->e[j] = fa->e[j+1], fa->c[j] = fa->c[j+1];
            fa->e[fa->s] = 0; fa->c[fa->s] = NULL; fa->s--; fa->c[id] = w;

            if(fa == root && fa->s == 0) root = w;
        }
    }
}
BNode* BTree::searchNode(BNode *&u, int x)
{
    for(int i = 1; i <= u->s; i++)
    {
        if(u->e[i] == x) return u;
        else if(u->e[i] > x && u->c[i-1] != NULL) return searchNode(u->c[i-1], x);
    }
    if(u->e[u->s] < x && u->c[u->s] != NULL) return searchNode(u->c[u->s], x);
    return NULL;
}
void BTree::insertNode(BNode *&u, BNode *&fa, int id, int x)
{
    if(u == NULL)
    {
        u = new BNode; u->s = 1; u->e[1] = x;
        return;
    }
    for(int i = 1; i <= u->s; i++)
    {
        if(u->e[i] == x) return;
        else if(u->e[i] > x)
        {
            if(u->leaf) { u->insert_ele(i, x, NULL); push_up(u, fa, id); }
            else { insertNode(u->c[i-1], u, i-1, x); push_up(u, fa, id); }
            return;
        }
    }
    if(u->e[u->s] < x)
    {
        if(u->leaf) { u->insert_ele(u->s+1, x, NULL); push_up(u, fa, id); }
        else { insertNode(u->c[u->s], u, u->s, x); push_up(u, fa, id); }
    }
}
void BTree::delNode(BNode *&u, BNode *&fa, int id, int x)
{
    if(u == NULL) return;
    for(int i = 1; i <= u->s; i++)
    {
        if(u->e[i] == x)
        {
            if(!u->leaf)
            {
                int pre = findPre(u->c[i-1]); u->e[i] = pre;
                delNode(u->c[i-1], u, i-1, pre);
                push_down(u, fa, id);
            }
            else
            {
                for(int j = i; j < u->s; j++) u->e[j] = u->e[j+1];
                u->e[u->s] = 0; u->s--;
                push_down(u, fa, id);
            }
            if(u == root && u->s == 0) root = NULL;
            return;
        }
        else if(u->e[i] > x)
        {
            if(u->leaf) return;
            else
            {
                delNode(u->c[i-1], u, i-1, x); push_down(u, fa, id);
                if(u == root && u->s == 0) root = NULL;
                return;
            }
        }
    }
    if(u->e[u->s] < x)
    {
        if(u->leaf) return;
        else
        {
            delNode(u->c[u->s], u, u->s, x);
            push_down(u, fa, id);
            return;
        }
    }
}

BSTree *bs;
AVLTree *avl;
RBTree *rb;
BTree *bt;

const int ms = 1000;
const int maxn = 500005;
int in[maxn], de[maxn], se[ms], key[maxn], rd[maxn];

bool cmp(const int i, const int j) { return rd[i] < rd[j]; }

int n = 500000;

clock_t s, sse;
double ein[52], ese[52], ede[52];

void solve()
{
    s = clock();
    for(int i = 0; i < n; i++)
    {
        bs->insert(in[i]);
        if((i+1) % 10000 == 0)
        {
            ein[(i+1)/10000] = (double)(clock()-s) / CLOCKS_PER_SEC;
            s = clock();
            sse = clock();
            for(int j = 0; j < ms; j++)
                bs->search(se[j]);
            ese[(i+1)/10000] = (double)(clock()-sse) / CLOCKS_PER_SEC;
        }
    }
    for(int i = 1; i <= 50; i++)
        ein[i] += ein[i-1];
    s = clock();
    for(int i = 0; i < n; i++)
    {
        bs->del(de[key[i]]);
        if((i+1) % 10000 == 0) ede[(i+1)/10000] = (double)(clock()-s) / CLOCKS_PER_SEC;
    }
    for(int i = 0; i <= 50; i++)
        printf("%.6lf,%.6lf,%.6lf\n", ein[i], ese[i], ede[50]-ede[50-i]);
    cout << endl;

    s = clock();
    for(int i = 0; i < n; i++)
    {
        avl->insert(in[i]);
        if((i+1) % 10000 == 0)
        {
            ein[(i+1)/10000] = (double)(clock()-s) / CLOCKS_PER_SEC;
            s = clock();
            sse = clock();
            for(int j = 0; j < ms; j++)
                avl->search(se[j]);
            ese[(i+1)/10000] = (double)(clock()-sse) / CLOCKS_PER_SEC;
        }
    }
    for(int i = 1; i <= 50; i++)
        ein[i] += ein[i-1];
    s = clock();
    for(int i = 0; i < n; i++){
        avl->del(de[key[i]]);
        if((i+1) % 10000 == 0) ede[(i+1)/10000] = (double)(clock()-s) / CLOCKS_PER_SEC;
    }
    for(int i = 0; i <= 50; i++)
        printf("%.6lf,%.6lf,%.6lf\n", ein[i], ese[i], ede[50]-ede[50-i]);
    cout << endl;
    s = clock();

    for(int i = 0; i < n; i++)
    {
        rb->insert(in[i]);
        if((i+1) % 10000 == 0)
        {
            ein[(i+1)/10000] = (double)(clock()-s) / CLOCKS_PER_SEC;
            s = clock();
            sse = clock();
            for(int j = 0; j < ms; j++)
                rb->search(se[j]);
            ese[(i+1)/10000] = (double)(clock()-sse) / CLOCKS_PER_SEC;
        }
    }
    for(int i = 1; i <= 50; i++)
        ein[i] += ein[i-1];
    s = clock();
    for(int i = 0; i < n; i++)
    {
        rb->del(de[key[i]]);
        if((i+1) % 10000 == 0) ede[(i+1)/10000] = (double)(clock()-s) / CLOCKS_PER_SEC;
    }

    for(int i = 0; i <= 50; i++)
        printf("%.6lf,%.6lf,%.6lf\n", ein[i], ese[i], ede[50]-ede[50-i]);
    cout << endl;

    s = clock();
    for(int i = 0; i < n; i++)
    {
        bt->insert(in[i]);
        if((i+1) % 10000 == 0)
        {
            ein[(i+1)/10000] = (double)(clock()-s) / CLOCKS_PER_SEC;
            s = clock();
            sse = clock();
            for(int j = 0; j < ms; j++)
                bt->search(se[j]);
            ese[(i+1)/10000] = (double)(clock()-sse) / CLOCKS_PER_SEC;
        }
    }
    for(int i = 1; i <= 50; i++)
        ein[i] += ein[i-1];
    s = clock();
    for(int i = 0; i < n; i++)
    {
        bt->del(de[key[i]]);
        if((i+1) % 10000 == 0) ede[(i+1)/10000] = (double)(clock()-s) / CLOCKS_PER_SEC;
    }
    for(int i = 0; i <= 50; i++)
        printf("%.6lf,%.6lf,%.6lf\n", ein[i], ese[i], ede[50]-ede[50-i]);
    cout << endl;
}

void order()   // 插入n个数，查找ms个，顺序删除
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        in[i] = rand();
    sort(in, in+n);
    for(int i = 0; i < n; i++)
        de[i] = in[i], key[i] = i;
    for(int i = 0; i < ms; i++)
        se[i] = rand();

    solve();
}

void invorder()   // 插入n个数，查找ms个，逆序删除
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        in[i] = rand();
    sort(in, in+n);
    for(int i = 0; i < n; i++)
        de[i] = in[i], key[i] = n-i-1;
    for(int i = 0; i < ms; i++)
        se[i] = rand();

    solve();
}

void rdorder()   // 插入n个数，查找ms个，随机删除
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        in[i] = rand();
    for(int i = 0; i < n; i++)
        de[i] = in[i], key[i] = i, rd[i] = rand();
    sort(key, key+n, cmp);
    for(int i = 0; i < ms; i++)
        se[i] = rand();

    solve();
}


signed main()
{
    bs = new BSTree; avl = new AVLTree; rb = new RBTree; bt = new BTree(512);

    freopen("1/1-1.csv", "w", stdout);
    order();
//    freopen("1/1-2.csv", "w", stdout);
//    order();
//    freopen("1/1-3.csv", "w", stdout);
//    order();
//
//    freopen("2/2-1.csv", "w", stdout);
//    invorder();
//    freopen("2/2-2.csv", "w", stdout);
//    invorder();
//    freopen("2/2-3.csv", "w", stdout);
//    invorder();
//
//    freopen("3/3-1.csv", "w", stdout);
//    rdorder();
//    freopen("3/3-2.csv", "w", stdout);
//    rdorder();
//    freopen("3/3-3.csv", "w", stdout);
//    rdorder();
}