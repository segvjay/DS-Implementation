#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;

    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};


class BST{
public:
    Node*root;
    BST(){
        root=nullptr;
    }

    Node* Insert(Node* root, int data){
         if(root==nullptr){
            return new Node(data);
         }

         else if(data <root->data){
            root->left = Insert(root->left, data);
         }

         else{
            root->right = Insert(root->right,data);
         }

        return root;
    }
    

    Node* deleteBST(Node* root, int key){
    if(root == nullptr){
        return root;
    }

    if(key < root->data){
        root->left = deleteBST(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteBST(root->right, key);
    }

    
    else{
        // Case 1: Node with 0 children (leaf)
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        // Case 2: Node with only left child
        else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node with only right child
        else if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 4: Node with two children
        else{
            Node* temp = minNode(root->right);  
            root->data = temp->data;             
            root->right = deleteBST(root->right, temp->data);
        }
    }
    return root;   
}


    Node* search(Node* root, int key){
        if(root==nullptr || root->data == key){
            return root;
        }
        else{
            if(key < root->data){
                return search(root->left, key);
            }
            else{
                return search(root->right,key);
            }
        }
    }

    Node* minNode(Node* root){
        Node* temp = root;
        while(temp->left!=nullptr){
            temp=temp->left;
        }
        return temp;
    }

    Node* maxNode(Node* root){
        Node* temp = root;
        while(temp->right!=nullptr){
            temp = temp->right;
        }

        return temp;
    }

    void inOrder(Node* root){
        if(root==nullptr){
            return;
        }

        else{
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
        
    }

    void preOrder(Node* root){
        if(root==nullptr){
            return;
        }

        else{
            cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }

    }

    void postOrder(Node* root){
        if(root==nullptr){
            return;
        }
        
        else{-
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }
    }
};

int main(){
    BST b1;
    b1.root = b1.Insert(b1.root,50);
    b1.root = b1.Insert(b1.root,20);
    b1.root = b1.Insert(b1.root,70);
    b1.root = b1.Insert(b1.root,10);
    b1.root = b1.Insert(b1.root,90);
    b1.preOrder(b1.root);
    cout<<endl;
    b1.inOrder(b1.root);
    cout<<endl;
    b1.postOrder(b1.root);
    cout<<endl;
    int key = 50;
    Node* ptr = b1.search(b1.root,key);
    if(ptr!=nullptr){
        cout<<"Key "<<key<<" present"<<endl;
    }
    else{
        cout<<"Key "<<key<<" not present"<<endl;
    }

    Node* min = b1.minNode(b1.root);
    cout<<"Minimum Node value: "<<min->data<<endl;

    Node* max = b1.maxNode(b1.root);
    cout<<"Maximum Node value: "<<max->data<<endl;

}