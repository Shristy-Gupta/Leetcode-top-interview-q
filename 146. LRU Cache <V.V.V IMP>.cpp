struct Node{
    //need doubly linked list
    int key;
    int val;
    Node *prev;
    Node *next;
};
class LRUCache {
public:
    unordered_map<int,Node*> cache;
    Node *head;
    Node *tail;
    int capacity;
    LRUCache(int capacity) {
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
        this->capacity=capacity;
        
    }
    
    int get(int key) {
        int result=-1;
        if(cache.find(key)!=cache.end()){
            result=cache[key]->val;
            remove_Node(cache[key]);
            add_node(cache[key]);
            
        }
        return result;
    }
    
    void put(int key, int value) {
        Node* node;
        if(cache.find(key)!=cache.end()){
            node=cache[key];
            node->val=value;
            remove_Node(node);
            //this is done to move it to the front
            add_node(node);
        }else{
            if(cache.size()==this->capacity){
                //evict check this
                cache.erase(tail->prev->key);
                remove_Node(tail->prev);
            }
            Node* new_node=new Node();
            new_node->key=key;
            new_node->val=value;
            cache[key]=new_node;
            add_node(new_node);
        }
        
        
    }
    void remove_Node(Node* node){
        Node* next_node=node->next;
        Node* prev_node=node->prev;
        node->next=NULL;
        node->prev=NULL;
        //delete node;
        next_node->prev=prev_node;
        prev_node->next=next_node; 
    }
    void add_node(Node* node){
        Node* next_node=head->next;
        head->next=node;
        node->prev=head;
        node->next=next_node;
        if(next_node!=NULL){
            next_node->prev=node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
