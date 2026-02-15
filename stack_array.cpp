#include <bits/stdc++.h>
using namespace std;

class Stack{
    int size;
    int arr[10];
public:
    int top;
    Stack(){
        top = -1;
        size=10;
    }

    void push(int data){
        if(top==size-1)
            cout<<"Stack Overflow"<<endl;
        
        else
            arr[++top] = data;
            cout<<data<<" pushed!"<<endl;
        
    }

    void pop(){
        if(top==-1)
            cout<<"Stack Underflow"<<endl;
        
        else 
            cout<<arr[top]<<" popped!";
            top--;
    }

    void display(){
        if(top==-1)
            cout<<"Stack is empty!"<<endl;
        
        else
        cout<<endl;
            for(int i=top; i>=0; i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
    }

   
};

int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.display();
    s1.pop();
    s1.display();
    return 0;
}