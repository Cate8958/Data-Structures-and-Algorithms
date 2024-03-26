#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

bool hasCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;

    if (hasCycle(head)) {
        std::cout << "Linked list has a cycle" << std::endl;
    } else {
        std::cout << "Linked list has no cycle" << std::endl;
    }

    // Clean up memory
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
