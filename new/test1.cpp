#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void push(int new_data, node **ref){
    node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    (*ref)->next = new_node;
    (*ref) = new_node;
}

void print_list(node *head){
    node *ref = head;
    ref = ref->next;
    while(ref->next!=NULL)
    {
        cout << ref->data << " -> ";
        ref=ref->next;
    }
    cout << ref->data << endl;
}

int main(){
    node *head;
    node *start;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;
    start = head;
    int input;
    cout << "Please mention the nodes you want to enter. Press 999 to exit" << endl;
    cin >> input;
    while(input!=999)
    {
        push(input, &head);
        cin >> input;
    }
    head = start;
    print_list(head);
    print_list(head);
    return 0;
}