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
    void InsertBetweenNodes(Node* head){
        Node* temp = head;

        while(temp != NULL){
            Node* NextElement = temp->next;
            Node* copy = new Node(temp->val);

            copy->next = NextElement;
            temp->next = copy;
            temp = NextElement;
        }
    }

    void connectRandomPointer(Node* head){
        Node* temp = head;

        while(temp != NULL){
            Node* CopyNode = temp -> next;

            if(temp->random != NULL){
                CopyNode->random = temp->random->next;
            }
            else{
                CopyNode->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node* getCopyList(Node* head){
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while(temp != NULL){
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        Node* clonedHead = dummyNode->next;
        delete dummyNode;

        return clonedHead;
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }

        InsertBetweenNodes(head);
        connectRandomPointer(head);
        return getCopyList(head);

    }
};