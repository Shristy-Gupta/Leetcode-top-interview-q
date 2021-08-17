class Node{
    //Doubly liked list
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int item){
        val=item;
        next=NULL;
        prev=NULL;
    }
};
class MyLinkedList {
public:
    /** Initialize your data structure here. */
        int length;
        Node* head;
        Node* tail;
    MyLinkedList() {
      length=0;
      head=new Node(-1);
      tail=head;  
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=length){
            return -1;
        }
        Node* ith_node=getNode(index);
        return ith_node->val;
        
    }
    Node* getNode(int index){
        if(index>=length){
            return NULL;
        }
        Node* node=head;
        int i=0;
        while(i!=index){
            node=node->next;
            i++;
        }
        return node;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(length==0 && head!=NULL && head->val==-1){
            head->val=val;
            length++;
        }
        else{
            Node* new_node =new Node(val);
            new_node->next=head;
            if(head!=NULL){
                head->prev=new_node;
            }
            head=new_node;
            length++;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
         if(length==0 && tail!=NULL && tail->val==-1){
            tail->val=val;
             length++;
        }
        else{
            Node* new_node =new Node(val);
            new_node->prev=tail;
            if(tail!=NULL){
                tail->next=new_node;
            }
            tail=new_node;
            length++;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
       if(index>length){
           return;
       }
        if(index==length){
            addAtTail(val);
            return;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* ith_node=getNode(index);
        Node* new_node=new Node(val);
        new_node->next=ith_node;
        if(ith_node!=NULL && ith_node->prev!=NULL){
           new_node->prev=ith_node->prev;
           ith_node->prev->next=new_node; 
        }
        if(ith_node!=NULL){
           ith_node->prev= new_node;
        }
        length++;
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=length){
           return;
       } 
        Node* ith_node=getNode(index);
        if(ith_node!=NULL && ith_node->prev!=NULL){
            ith_node->prev->next=ith_node->next;
        }
        if(ith_node!=NULL && ith_node->next!=NULL){
            ith_node->next->prev=ith_node->prev;
        }
        if(index==0){
            head=ith_node->next;
        }
        if(index==length-1){
            tail=ith_node->prev;
        }
        ith_node->next=NULL;
        ith_node->prev=NULL;
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
