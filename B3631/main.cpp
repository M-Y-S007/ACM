#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};

struct node* findNode(struct node* head, int x){
    struct node* current = head;
    while(current != nullptr){
        if(current->data == x){
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


int main(){
    int q;
    cin >> q;
    struct node* head = new node{1, nullptr};
    while(q--){
        int m;
        cin >> m;
        if(m == 1){
            int x, y;
            cin >> x >> y;
            struct node* xNode = findNode(head, x);
            if(xNode != nullptr){
                struct node* newNode = new node{y, nullptr};
                newNode->next = xNode->next;
                xNode->next = newNode;
            }
        }else if(m == 2){
            int x;
            cin >> x;
            struct node* xNode = findNode(head, x);
            if(xNode == nullptr || xNode->next == nullptr){
                cout << 0 << endl;
            }else{
                cout << xNode->next->data << endl;
            }
        }else{
            int x;
            cin >> x;
            struct node* xNode = findNode(head, x);
            if(xNode != nullptr && xNode->next != nullptr){
                struct node* Delete = xNode->next;
                xNode->next = Delete->next;

                delete Delete;
            }
        }

    }
    struct node*current = head;
    while(current != nullptr){
        struct node*next = current->next;
        delete current;
        current = next;
    }
    return 0;
}