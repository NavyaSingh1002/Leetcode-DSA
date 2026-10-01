class LFUCache {
public:

    class Node {
        public:
            int key, value, freq;
            Node *next;
            Node *prev;
            Node(int _key, int _value) {
                key=_key;
                value=_value;
                freq=1;
                next=NULL;
                prev=NULL;
            }
    };

    class List {
        public:
            int size;
            Node *head;
            Node *tail;
            List() {
                head=new Node(-1, -1);
                tail=new Node(-1, -1);
                head->next=tail;
                tail->prev=head;
                size=0;
            }

            void addFront(Node *node) {
                Node *temp=head->next;
                head->next=node;
                node->prev=head;
                node->next=temp;
                temp->prev=node;
                size++;
            }

            void removeNode(Node *node) {
                Node *prevNode=node->prev;
                Node *nextNode=node->next;
                prevNode->next=nextNode;
                nextNode->prev=prevNode;
                size--;
            }
    };

    unordered_map<int, Node*>keyNode;
    unordered_map<int, List*>freqList;
    int cap;
    int minFreq;
    int currSize;

    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
        currSize=0;
    }

    void updateFreq(Node *node) {
        int currFreq=node->freq;
        freqList[currFreq]->removeNode(node);
        if(currFreq==minFreq && freqList[currFreq]->size==0)
            minFreq++;
        node->freq+=1;
        //create new if it does not exist
        if(freqList.find(node->freq)==freqList.end())
            freqList[node->freq]=new List();
        freqList[node->freq]->addFront(node);
    }      
    
    int get(int key) {
        if(keyNode.find(key)==keyNode.end())
            return -1;
        Node *node=keyNode[key];
        updateFreq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cap==0)
            return ;
        if(keyNode.find(key)!=keyNode.end()) {
            Node *node=keyNode[key];
            node->value=value;
            updateFreq(node);
        }
        else {
            if(currSize==cap) {
                List *minList=freqList[minFreq];
                Node *node=minList->tail->prev;

                keyNode.erase(node->key);
                minList->removeNode(node);
                delete node;
                currSize--;
            }
            currSize++;
            minFreq=1;
            Node *newNode=new Node(key, value);
            keyNode[key]=newNode;
            if(freqList.find(1)==freqList.end())
                freqList[1]=new List();
            freqList[1]->addFront(newNode);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */