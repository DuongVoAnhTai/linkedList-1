/*
*       LinkedList
*
*       code by vuong :>/
*/
#include <iostream>
using namespace std;
int sizeList = 0;
// khai báo cấu trúc của list 
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
struct list{
    node *head;
    node *tail;
};
typedef struct list list;
//================================================
// khởi tạo danh sách
void createList(list &l){
    l.head = NULL;
    l.tail = NULL;
}
// khởi tạo một node mới
node *createNode(int data){
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//================================================
// thêm vào cuối danh sách
void pushBack(list &l, node *newNode);

// thêm vào đầu danh sách
void add(list &l,node *newNode);

//chèn sau một node Q biết trước
void insertAfterQ(list &l,node *newNode, node *Q);

// chèn trước một node Q biết trước
void insertBeforeQ(list &l,node *newNode, node *Q);

// chèn sau một node tại vị trí bất kì
void insertAt(list &l, node *newNode, int index);
//================================================

// xóa đầu danh sách
void deleteFront(list &L);

// xóa cuối danh sách
void deleteBack(list &l);

// xóa sau một node Q biết trước
void deleteAfterQ(list &l,node *Q);

// xóa trước một node Q biết trước
void deleteBeforeQ(list &l,node *Q);

// xóa một node tại vị trí bất kì
void deleteAt(list &l, int index);

// xóa tất cả list
void deleteList(list &l);

//================================================


//lấy node tại index cho trước
node *getNode(list &l,int index);

//in danh sách ra
void printList(list l);

//================================================
int main()
{
    int n;
    cin>>n;
    list l;
    createList(l);
    for(int i = 0;i <n;i++){
        int data;cin>>data;
        node *newNode = createNode(data);
        
        pushBack(l,newNode);
        
    }
    printList(l);
    deleteList(l);
    return 0;
}



void pushBack(list &l, node *newNode){
    if(l.head == NULL){
        l.head = l.tail = newNode;
    }else{
        l.tail->next = newNode;
        l.tail = newNode;
    }
    sizeList++;
}
void add(list &l,node *newNode){
    if(l.head == NULL){
        l.head = l.tail = newNode;
    }else{
        newNode->next = l.head;
        l.head = newNode;
    }
    sizeList++;
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
        sizeList++;
    }else{
        for(node *k = l.head; k!= NULL;k = k->next){
            if(k == Q){
                node *temp = k->next;
                k->next = newNode;
                newNode->next = temp;
                break;
            }
        }
        sizeList++;
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
        sizeList++;
    }
}
void insertAt(list &l, node *newNode, int index){
    if(index < 0){
        add(l,newNode);
    }else if(index > sizeList){
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
    sizeList--;
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
                sizeList--;
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
                sizeList--;
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
                sizeList--;
                break;
            }
            h = k;
        }
    }
}
void deleteAt(list &l, int index){
    if(index <= 1){
        deleteFront(l);
    }else if(index > sizeList){
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
//=======================================================
node *getNode(list &l,int index){
    if(index < 0){
        return NULL;
    }else if(index < sizeList)
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
