class MyHashSet {
public:
    /** Initialize your data structure here. */
    int table_size;
    typedef struct node {
        int key;
        node *next;
        node *prev;
    }node;
    
    // void printlist(){
    //     for(int i=0;i<6;i++){
    //         cout<<i<<" : ";
    //         node* pp=table[i].next;
    //         while(pp){
    //             cout<<pp->key<<" ";
    //             pp=pp->next;
    //         }
    //         cout<<endl;
    //     }
    // }
    
    node table[10001];
    node *head ;
    MyHashSet() {
        table_size = 10001;
        for(int i = 0; i<table_size;i++){
                table[i].key = -1;
                table[i].prev = nullptr;
                table[i].next = nullptr;
        }
       head = nullptr;
    }

    node* createnode(int key){
        node *newnode  = new node();
        newnode->key = key;
        newnode->next = nullptr;
        newnode->prev = nullptr;
        return newnode;
        
    }

    node * searchKey(int key){
        int idx = key % table_size;
        node *ptr = table[idx].next;
        while(ptr!=nullptr){
            if(ptr->key == key)
                return ptr;
            ptr = ptr->next;
        }
        return nullptr;
    }

    void add(int key) {
        int idx =  key % table_size;
        node *newnode = createnode(key);
        if(searchKey(key)!=nullptr)
            return;
        if(table[idx].next ==nullptr){
             newnode->next =  table[idx].next;
             newnode->prev = &table[idx];
             table[idx].next = newnode;
        }
        else{
             newnode->next =  table[idx].next;
             table[idx].next->prev = newnode;
             table[idx].next = newnode;
             newnode->prev = &table[idx];
        }
        // cout<<"add"<<endl;
        // printlist();
       
        return;
    }
    
    void remove(int key) {
         int idx = key % table_size;
       node *temp = searchKey(key);
       if(temp==nullptr)
           return;
        
        temp->prev->next = temp->next;
        if(temp->next !=nullptr)
             temp->next->prev = temp->prev;
         
        // cout<<"remove"<<endl;
        // printlist();
        return;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        // cout<<"contains"<<endl;
        // printlist();
        return searchKey(key)!=nullptr;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */