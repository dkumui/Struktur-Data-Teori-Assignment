#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteMiddleNode(Node* head) {
    if (head == NULL || head->next == NULL)
        return;
    Node *slow = head, *fast = head, *prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    delete slow;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    cout << "Linked list sebelum menghapus node tengah: \n";
    printList(head);

    deleteMiddleNode(head);

    cout << "\nLinked list setelah menghapus node tengah: \n";
    printList(head);

    return 0;
}