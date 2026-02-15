#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void insertAtBeg(int data) {
        ListNode* newNode = new ListNode(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        ListNode* newNode = new ListNode(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPos(int pos, int data) {
        if (pos <= 0) return;
        if (pos == 1) {
            insertAtBeg(data);
            return;
        }
        ListNode* temp = head;
        int count = 1;
        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            insertAtEnd(data);
        } else {
            ListNode* newNode = new ListNode(data);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            } else {
                tail = newNode;
            }
            temp->next = newNode;
        }
    }

    void deleteAtBeg() {
        if (head == nullptr) return;
        ListNode* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void deleteAtEnd() {
        if (tail == nullptr) return;
        ListNode* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void deleteAtPos(int pos) {
        if (pos <= 0 || head == nullptr) return;
        if (pos == 1) {
            deleteAtBeg();
            return;
        }
        ListNode* temp = head;
        int count = 1;
        while (temp != nullptr && count < pos) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) return;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        else tail = temp->prev;
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        else head = temp->next;
        delete temp;
    }

    void displayList() {
        ListNode* ptr = head;
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList D1;
    D1.insertAtBeg(10);
    D1.insertAtBeg(20);
    D1.insertAtEnd(30);
    D1.insertAtPos(2, 15);
    D1.insertAtPos(5, 40);
    D1.displayList();
    D1.deleteAtBeg();
    D1.deleteAtEnd();
    D1.deleteAtPos(2);
    D1.displayList();
    return 0;
}
