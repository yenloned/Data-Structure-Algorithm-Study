//Implementation, Modification, and Deletion of Linked List

#include <iostrem>

using namespace std;

//Implementation
struct Node{
    int value;
    Node *next;
};

class LinkedList{
    private:
        Node *head, *tail;
    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        //Modification

        //Insert the new node at the end of the linked list
        void insert_node_last(int val){
            Node *newNode = node Node();
            newNode->value = val;
            newNode->next = NULL;

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        //Insert the new node at the front of the linked list
        void insert_node_first(int val){
            Node *newNode = node Node();
            newNode->value = val;
            newNode->next = NULL;

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
        }

        //Insert the new node after a specified node.
        void insert_node_between(Node *node, int val){
            Node *newNode = node Node();
            newNode->value = val;
            newNode->next = NULL;

            if(node == NULL){
                cout << "Input node not existed.";
                return;
            }else{
                newNode->next = node->next;
                node->next = newNode;
            }
        }

        //Modify head node value
        void mod_node_first(int val){
            if(head == NULL){
                cout << "head node not existed.";
                return;
            }
            head->value = val;
        }

        //Similar process with modification on between and last

        //Delete head node
        void delete_head_node(){
            if(head == NULL){
                cout << "head node not existed.";
                return;
            }
            Node *temp = head;
            head = head->next;
            free(temp);
        }

        //Similar process with modification on between and last
}
