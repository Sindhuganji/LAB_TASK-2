#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insert(struct Node** head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
        return;
    }
    if (data < (*head)->data) {
        insert(&(*head)->left, data);
    } else {
        insert(&(*head)->right, data);
    }
}
void inorderTraversal(struct Node* head) {
    if (head == NULL) {
        return;
    }
    inorderTraversal(head->left);
    printf("%d ", head->data);
    inorderTraversal(head->right);
}
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        return;
    }
    if (data < (*head)->data) {
        deleteNode(&(*head)->left, data);
    } else if (data > (*head)->data) {
        deleteNode(&(*head)->right, data);
    } else {
        // Node found
        if ((*head)->left == NULL) {
            struct Node* temp = *head;
            *head = (*head)->right;
            free(temp);
        } else if ((*head)->right == NULL) {
            struct Node* temp = *head;
            *head = (*head)->left;
            free(temp);
        } else {
            struct Node* successor = (*head)->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            (*head)->data = successor->data; // Copy successor value
            deleteNode(&(*head)->right, successor->data); // Delete successor
            // ⚠️ DO NOT free(*head) here!
        }
    }
}
int main() {
    struct Node* root = NULL;
    int choice, data;
    while (1) {
        printf("1. Insert\n2. Inorder Traversal\n3. Delete\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&root, data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}