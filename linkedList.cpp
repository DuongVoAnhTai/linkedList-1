
#include<linkedList.hpp>
using namespace std;

// khai báo cấu trúc của list 


//================================================

void pushBack(list &l, node *newNode){
    if(l.head == NULL){
        l.head = l.tail = newNode;
    }else{
        l.tail->next = newNode;
        l.tail = newNode;
    }
    l.sizeList++;
}
void add(list &l,node *newNode){
    if(l.head == NULL){
        l.head = l.tail = newNode;
    }else{
        newNode->next = l.head;
        l.head = newNode;
    }
    l.sizeList++;
}
void insertAfterQ(list &l,node *newNode, node *Q){
    if(Q == NULL){
        return;
    }
    if(Q == l.head->next){
        add(l,newNode);
    }else if(Q == l.head){
        node *temp = l.head->next;
        l.head->next = newNode;
        newNode->next = temp;
        l.sizeList++;
    }else{
        for(node *k = l.head; k!= NULL;k = k->next){
            if(k == Q){
                node *temp = k->next;
                k->next = newNode;
                newNode->next = temp;
                break;
            }
        }
        l.sizeList++;
    }
}
void insertBeforeQ(list &l,node *newNode, node *Q){
    if(Q == NULL){
        return;
    }
    if(Q == l.head){
        add(l,newNode);
    }else{
        node *k = l.head;
        node *temp = l.head;
        for(; k!= NULL;k = k->next){
            if(k->next == Q){
                temp->next = newNode;
                newNode->next = Q;
                break;
            }
            temp = temp->next;
        }
        l.sizeList++;
    }
}
void insertAt(list &l, node *newNode, int index){
    if(index < 0){
        add(l,newNode);
    }else if(index > l.sizeList){
        pushBack(l,newNode);
    }else{
        int i = 0;
        for(node *k = l.head; k!= NULL; k = k->next){
            i++;
            if(i == index){
                insertBeforeQ(l,newNode,k);
            }
        }
    }
}

//========================================
void deleteFront(list &l){
    if(l.head == NULL){
        return;
    }else{
        node *temp = l.head->next;
        l.head = NULL;
        l.head = temp;
    }
    l.sizeList--;
}
void deleteBack(list &l){
    if(l.head == NULL){
        return;
    }else{
        for(node *k = l.head; k!= NULL; k = k->next){
            if(k->next == l.tail){
                l.tail = NULL;
                l.tail = k;
                k->next = NULL;
                l.sizeList--;
                break;
            }
        }
    }
}
void deleteAfterQ(list &l,node *Q){
    if(Q == NULL || Q == l.tail){
        return;
    }else{
        for(node *k = l.head; k!= NULL; k = k->next){
            if(k == Q){
                node *temp = k->next;
                k->next = k->next->next;
                temp = NULL;
                l.sizeList--;
                break;
            }
        }
    }
}
void deleteBeforeQ(list &l,node *Q){
    if(Q == NULL || Q == l.head){
        return;
    }else if(Q == l.head->next){
        deleteFront(l);
    }else
    {
        node *k = l.head;
        node *h = new node;
        // 0 2 4 1 5
        //   k  
        // h   q 
        h->next = k;
        for(; k!= NULL; k = k->next){
            if(k->next == Q){
                h->next = Q;
                k = NULL;
                l.sizeList--;
                break;
            }
            h = k;
        }
    }
}
void deleteAt(list &l, int index){
    if(index <= 1){
        deleteFront(l);
    }else if(index > l.sizeList){
        deleteBack(l);
    }else{
        int i = 0;
        for(node *k = l.head;k!= NULL;k= k->next){
            i++;
            if(i == index){
                deleteBeforeQ(l,k->next);
                break;
            }
            
        }
    }
}
void deleteList(list &l){
    node *k = l.head;
    while(k != NULL){
        deleteFront(l);
        k = k->next;
    }
}

node *getNode(list &l,int index){
    if(index < 0){
        return NULL;
    }else if(index < l.sizeList)
    {
        int i = 0;
        node *k = l.head;
        while(k != NULL){
            i++;
            if(i == index){
                return k;
            }
            k = k->next;
        }
    }
    else
    {
        return l.tail;
    }
}
void printList(list l){
    node *k = l.head;
    cout << endl;
    while(k != NULL){
        cout << k->data << " ";
        k = k->next;
    }
}
