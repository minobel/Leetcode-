//TC - O(N)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
void copy_in_between(Node* head){ 
    Node* temp = head;
        while( temp != NULL ){
            Node* cpynode = new Node( temp -> val );
            cpynode -> next = temp -> next;
            temp -> next = cpynode;
            temp = temp -> next -> next;
        }
}
void connect_random_pointer(Node* head){
    Node* temp = head;
    while( temp != NULL ){
        Node* cpynode = temp -> next;
        if( temp -> random ){
            cpynode -> random = temp -> random -> next;
        }
        else {
            cpynode -> random = nullptr;
        }
        temp = temp -> next -> next;
    }
}
Node* deepcopy(Node* head){
    Node* dHead = new Node(-1);
    Node* res = dHead;
    Node* temp = head;
    while( temp != NULL ){
        res -> next = temp -> next;
        temp -> next = temp -> next -> next;
        res = res -> next;
        temp = temp -> next;
    }
    return dHead -> next;
}
    Node* copyRandomList(Node* head) {
        copy_in_between(head);
        connect_random_pointer(head);
        return deepcopy(head);
    }
};
