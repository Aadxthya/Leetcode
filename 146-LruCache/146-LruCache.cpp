// Last updated: 9/16/2025, 9:53:22 AM
class LRUCache {
public:
class Node{
    public:
    int val;
    int key;
    Node* prev;
    Node* next;

    Node( int key , int val){
        this->val = val;
        this->key = key;
    }
};
     
     Node* head = new Node( -1 , -1);
    Node* tail = new Node( -1 , -1);
    int cap;
        unordered_map<int, Node*> m;

    LRUCache(int capacity) {
         cap = capacity;
        head->next = tail;
        tail->prev = tail;
    }
    
    void addnode(Node* delnode){
        Node* temp = head -> next;
        temp -> prev = delnode;
        delnode-> next = temp;
        delnode-> prev = head;
        head->next = delnode;


    }

    void deletenode(Node* delnode){
        Node* nextt = delnode->next;
        Node* prevv = delnode->prev;

        nextt -> prev = prevv;
        prevv-> next = nextt;

    }

    int get(int key) {
        if(m.find(key)!= m.end()){
        Node* resNode = m[key];
        int ans = resNode->val; 
        m.erase(key);
        deletenode(resNode);
        addnode(resNode);
        m[key] = head->next;
        return ans;
        }
    return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!= m.end()){
           Node* resNode = m[key];
           m.erase(key);
            deletenode(resNode);
         }

         if(m.size() == cap){
            m.erase(tail -> prev -> key);
            deletenode(tail->prev);
         }

         addnode(new Node(key, value));
         m[key] = head->next;

         }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */