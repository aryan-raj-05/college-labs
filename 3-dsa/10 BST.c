#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} node;

node *createNode(int val);
node *insert(node *root, int val);
void inOrder(node *root);
void preOrder(node *root);
void postOrder(node *root);
void search(node *root, int val);

int main() {
    int choice;
    node *root = NULL;

    while (1) {
        printf("\n---Menu---\n");
        printf("1. Create a BST\n");
        printf("2. BST Traversal\n");
        printf("3. Search\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                int numNodes, valToInsert;
                printf("Enter Num of Elements: ");
                scanf("%d", &numNodes);
                for (int i = 0; i < numNodes; i++) {
                    printf("Enter Val to Insert: ");
                    scanf("%d", &valToInsert);
                    root = insert(root, valToInsert);
                }
                break;
            case 2:
                printf("Different Traversal of the BST are:\n");
                printf("Inorder: ");     inOrder(root);     printf("\n");
                printf("PostOrder: ");   postOrder(root);   printf("\n");
                printf("PreOrder: ");    preOrder(root);    printf("\n");
                break;
            case 3:
                int valToSearch;
                printf("Enter element to search: ");
                scanf("%d", &valToSearch);
                search(root, valToSearch);
                break;
            default:
                exit(0);
        }
    }
}

node *createNode(int val) {
    node *t = (node *) malloc(sizeof(node));
    t->val = val;
    t->left = NULL;
    t->right = NULL;
    return t;
}

node *insert(node *root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val > root->val) {
        root->right = insert(root->right, val);
    } else if (val < root->val) {
        root->left = insert(root->left, val);
    }

    return root;
}

void inOrder(node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d  ", root->val);
    inOrder(root->right);
}

void preOrder(node *root) {
    if (root == NULL)  return;
    printf("%d  ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root) {
    if (root == NULL)  return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d  ", root->val);
}

void search(node *root, int val) {
    if (root == NULL) {
        printf("Element Doesn't Exist\n");
    } else if (root->val == val) {
        printf("Key is present in BST\n");
    } else if (root->val > val) {
        search(root->left, val);
    } else {
        search(root->right, val);
    }
}