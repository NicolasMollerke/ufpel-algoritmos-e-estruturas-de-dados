#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if ( (p == NULL && q != NULL ) ||  (p != NULL && q == NULL ) ){
        return false;
    }

    if ( p == NULL && q == NULL ){
        return true;
    }

    bool verifEsq, verifDir;

    if ( p->val != q->val ){
        return false;
    }

    verifEsq = isSameTree( p->left, q->left );
    verifDir = isSameTree( p->right, q->right );

    if (verifDir && verifEsq) {
        return true;
    } else {
        return false;
    }
}