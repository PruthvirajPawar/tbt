

#include <iostream>
using namespace std;

class Node
{
        int data, lbit, rbit;
        Node *left, *right;
    public:
        Node() {
            data = 0;
            left = right = nullptr;
            lbit = rbit = 0;        
    }
    friend class TBT;
};

class TBT {
        Node *root, *head;
    public:
        TBT() {
            root = nullptr;
            head = new Node();
            head -> rbit = 1;
            head -> right = head;
            head -> left = head;
        }
        
        void insert(int val, Node *root);
        void insert();
        Node *in_succ(Node* );
        void in_traversal();
};

void TBT::insert(int val, Node* parent) {
    Node* p = new Node();
    p -> data = val;
    
    if(root == nullptr) {
        root = p;
        p -> left = p -> right = head;
        head -> left = p;
        head -> lbit = 1;
        cout << "value added" << endl;
    }
    
    // left
    else if(val < parent -> data) {
        if(parent -> lbit == 0) {
            p -> left = parent -> left;
            p -> right = parent;
            parent -> left = p;
            parent -> lbit = 1;
            cout << "value added " << val << " at left subtree" << endl;
        } 
        else
            insert(val, parent -> left);
    }
    else if(val > parent -> data) {
        if(parent -> rbit == 0) {
            p -> left = parent;
            p -> right = parent -> right;
            parent -> right = p;
            parent -> rbit = 1;
            cout << "value added " << val << " at right subtree" << endl;
        }
        else
            insert(val, parent -> right);
    }
}

void TBT::insert() {
    int val;
    cout << "Enter Value" << endl;
    cin >> val;
    insert(val, root);
}

void TBT::in_traversal() {
    Node* temp = root;
    
    while(temp -> lbit == 1)
        temp = temp -> left;
    while(temp != head) {
        cout << temp -> data << " ";
        temp = in_succ(temp);
    }
    cout << endl;
}

Node* TBT::in_succ(Node* current) {
    if (current -> rbit == 0)
        return current -> right;
    else {
        current = current -> right;
        while(current -> lbit == 1)
            current = current -> left;
        return current;
    }
}

int main() {
    int ch;
    TBT obj;

    do {
        cout << endl << "1.Insert"
             << endl << "2.Display"
             << endl << "3.Exit" << endl
             << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                obj.insert();
                break;
            
            case 2:
                obj.in_traversal();
                break;

            case 3:
                exit(0);
        
            default:
                cout << "Enter Valid Choice! ";
        }
    } while (ch != 3);
    return 0;
}
