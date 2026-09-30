class LRUCache {
public:

    class Node
    {
        public:
            int key;
            int value;
            Node *next;
            Node *prev;
            Node(int _key, int _value) {
                key=_key;
                value=_value;
                next=NULL;
                prev=NULL;
            }
    };

    unordered_map<int, Node*> mpp;
    int cap;
    Node *head;
    Node *tail;

    LRUCache(int capacity) {
        cap=capacity;
        //dummy nodes
        head=new Node(-1, -1);
        tail=new Node(-1, -1);        head->next=tail;
        tail->prev=head;
    }

    void insertAfterHead(Node* node) {
        Node *temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
    }

    void deleteNode(Node* node) {
        Node *prevNode=node->prev;
        Node *nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())
            return -1;
        Node *node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()) {
            Node* node=mpp[key];
            node->value=value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else {
            if(mpp.size()==cap) {
                Node* node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* newNode=new Node(key, value);
            mpp[key]=newNode;
            insertAfterHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */