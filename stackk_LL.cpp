#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode -> next = top;
        top = newNode;
        cout << data << " Pushed!" << endl;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            cout << temp->data << " Popped!" << endl;
            delete temp;
        }
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {

            Node *temp = top;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display();
    s1.pop();
    s1.display();
    return 0;
}