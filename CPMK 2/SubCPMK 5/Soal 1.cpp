#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void removeDuplicates(Node* head) {
    unordered_set<int> seen;
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) {
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete current;
        } else {
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
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
    push(&head, 10);
    push(&head, 20);
    push(&head, 10);
    push(&head, 30);
    push(&head, 40);
    push(&head, 30);

    cout << "Linked list sebelum duplikasi dihilangkan: \n";
    printList(head);

    removeDuplicates(head);

    cout << "\nLinked list setelah duplikasi dihilangkan: \n";
    printList(head);

    return 0;
}