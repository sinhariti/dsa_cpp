// C++ Program to find decimal value of 
// binary linked list 
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

/* Link list Node */
class Node 
{ 
    public:
    bool data; 
    Node* next; 
}; 

/* Returns decimal value of binary linked list */
int decimalValue(Node *head) 
{ 
    // Initialized result 
    int res = 0; 

    // Traverse linked list 
    while (head != NULL) 
    { 
        // Multiply result by 2 and add 
        // head's data 
        
        res = (res << 1) + head->data; 
        cout<< "res"<< res<<endl;
        // Move next 
        head = head->next; 
    } 
    return res; 
} 

// Utility function to create a new node. 
Node *newNode(bool data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->next = NULL; 
    return temp; 
} 

/* Driver program to test above function*/
int main() 
{ 
    /* Start with the empty list */
    Node* head = newNode(1); 
    head->next = newNode(0); 
    head->next->next = newNode(0); 


    cout << "Decimal value is "
        << decimalValue(head)<< endl; 

    return 0; 
} 

// This is code is contributed by rathbhupendra