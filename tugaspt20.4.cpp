#include <iostream>
using namespace std;

/* ==========================
   STRUKTUR NODE TREE
========================== */
struct Node {
    int data;
    Node* left;
    Node* right;
};

/* ==========================
   INSERT DATA KE TREE
========================== */
Node* insert(Node* root, int nilai) {
    if (root == NULL) {
        Node* baru = new Node;
        baru->data = nilai;
        baru->left = NULL;
        baru->right = NULL;
        return baru;
    }

    if (nilai < root->data) {
        root->left = insert(root->left, nilai);
    } else {
        root->right = insert(root->right, nilai);
    }

    return root;
}

/* ==========================
   TRAVERSAL
========================== */
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

/* ==========================
   MAIN PROGRAM
========================== */
int main() {
    Node* root = NULL;

    cout << "=== PROGRAM TREE & TRAVERSAL ===\n\n";

    // Data yang dimasukkan ke tree
    int data[] = {50, 30, 70, 20, 40, 60, 80};

    cout << "Data yang dimasukkan ke tree:\n";
    for (int i = 0; i < 7; i++) {
        cout << data[i] << " ";
        root = insert(root, data[i]);
    }

    cout << "\n\nHasil Traversal:\n";

    cout << "Inorder   : ";
    inorder(root);
    cout << endl;

    cout << "Preorder  : ";
    preorder(root);
    cout << endl;

    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    return 0;
}

