#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {

        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
         postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
       
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
         inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
       
    }
}

int main()
{
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createnode(4);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(5);
    struct node *p4 = createnode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("\n\n-------------------------\n");
    printf("preorder\n");
    printf("--------------------------\n");
    preorder(p);
    printf("\n");
     printf("\n\n-------------------------\n");
    printf("\t\tpostorder\n");
    printf("--------------------------\n");
    postorder(p);
    printf("\n");
     printf("\n\n-------------------------\n");
    printf("\tinorder\n");
    printf("--------------------------\n");
    inorder(p);
    return 0;
}