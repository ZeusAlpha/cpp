#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void add_to_list(struct node **current_pos, int node_data){
    node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = node_data;
    temp->next = NULL;
    (*current_pos)->next = temp;
    (*current_pos) = temp;
}

void print_list(struct node *head){
    head = head->next;
    while(head->next!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}


int main(){

    node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;
    node *start;
    start = head;
    cout << "Please mention the elements you want to insert into the list. Press 999 to exit" << endl;
    int number;
    cin >> number;
    while(number!=999){
        add_to_list(&head, number);
        cin >> number;
    }
    head = start;
    print_list(head);
    return 0;
}