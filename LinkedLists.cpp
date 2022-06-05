#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void inserStart(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void append(Node** head_ref, int new_data)
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

void display(Node *head){
    if(head == NULL)
        return;
    cout<<head->data<<" ";
    display(head->next);
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
    return 0;
}
