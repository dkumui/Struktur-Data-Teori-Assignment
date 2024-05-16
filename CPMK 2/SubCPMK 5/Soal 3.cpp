#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

bool isPalindromeUtil(Node** left, Node* right) {
    if (right == NULL)
        return true;
    bool isp = isPalindromeUtil(left, right->next);
    if (isp == false)
        return false;
    bool isp1 = (right->data == (*left)->data);
    *left = (*left)->next;
    return isp1;
}

bool isPalindrome(Node* head) {
    return isPalindromeUtil(&head, head);
}

void push(Node** head_ref, char new_data) {
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
    push(&head, 'r');
    push(&head, 'a');
    push(&head, 'd');
    push(&head, 'a');
    push(&head, 'r');

    cout << "Linked list: \n";
    printList(head);

    if (isPalindrome(head))
        cout << "\nLinked list adalah palindrom\n";
    else
        cout << "\nLinked list bukan palindrom\n";

    return 0;
}