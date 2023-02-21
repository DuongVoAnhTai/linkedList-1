#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include <iostream>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;
struct list{
    node *head;
    node *tail;
    int sizeList = 0;
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

//lấy node tại index cho trước
node *getNode(list &l,int index);

//in danh sách ra
void printList(list l);

#endif