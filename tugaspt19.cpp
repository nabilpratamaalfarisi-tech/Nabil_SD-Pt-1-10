#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Prosedur Traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    // Membentuk tree sesuai hasil traversalnya
    struct Node *R = createNode('R');
    struct Node *A = createNode('A');
    struct Node *E = createNode('E');
    struct Node *S = createNode('S');
    struct Node *I = createNode('I');
    struct Node *T = createNode('T');

    // Susunan node (hasil rekonstruksi dari traversal)
    R->left = A;
    R->right = E;

    A->right = S;

    S->left = I;
    S->right = T;

    // OUTPUT
    printf("Tampilan secara PreOrder  : ");
    preorder(R);

    printf("\nTampilan secara InOrder   : ");
    inorder(R);

    printf("\nTampilan secara PostOrder : ");
    postorder(R);

    return 0;
}

