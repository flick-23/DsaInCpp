#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void inserStart(Node** head_ref, int new_data)  //give a value to be added, adds at start
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void append(Node** head_ref, int new_data)  //given a value to be added, adds at end
{
    Node* new_node = new Node();
    Node *last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

void deleteNode(Node** head_ref, int key)   //given a value to be deleted, delete node
{
    Node* temp = *head_ref;
    Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
    else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        delete temp;
    }
}

void display(Node *head){
    if(head == NULL)
        return;
    cout<<head->data<<" ";
    display(head->next);
}

/* Recursively count number of nodes in linked list */
int getCount(Node* head){
    if (head == NULL) {
        return 0;
    }
    return 1 + getCount(head->next);
}

int main() {
    cout<<"Entering insertion : ";
    Node *head = NULL;
    //insert start
    inserStart(&head,1);
    inserStart(&head,2);
    inserStart(&head,3);
    cout<<"Insertion done ";
    cout<<"\nUpdated list - \n";
    display(head);
    //insert end
    append(&head, 6);
    append(&head, 7);
    append(&head, 8);
    cout<<"\nUpdated list - \n";
    display(head);
    //delete
    deleteNode(&head,6);
    cout<<"\nUpdated list - \n";
    display(head);
    cout<<"\nCount : "<<getCount(head);
    return 0;
}
