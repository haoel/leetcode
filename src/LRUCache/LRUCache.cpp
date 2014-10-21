// Source : https://oj.leetcode.com/problems/lru-cache/
// Author : Hao Chen
// Date   : 2014-10-12

/********************************************************************************** 
* 
* Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
* 
* get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
* set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
* 
*               
**********************************************************************************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <map>
using namespace std;


class Node {
    public:
        int key;
        int value;
        Node *next, *prev;
        Node(int k, int v) { key=k; value=v; next = prev = NULL; }
        //Node(int k, int v, Node* n=NULL, Node* p=NULL): key(k), value(v), next(n), prev(p) {}
};

class DoubleLinkedList {

    private:

        Node *pHead, *pTail;
        int size;


    public:

        DoubleLinkedList(){
            pHead = pTail = NULL;
            size = 0;
        }
        ~DoubleLinkedList() {
            while(pHead!=NULL){
                Node*p = pHead;
                pHead = pHead->next;
                delete p;
            }
        }

        int Size() const {
            return size;
        }

        Node* NewAtBegin(int key, int value) {
            Node *n = new Node(key, value);
            return AddAtBegin(n);
        }

        Node* NewAtEnd(int key, int value) {
            Node *n = new Node(key, value);
            return AddAtEnd(n);
        }

        Node* AddAtBegin(Node* n){
            size++;

            if (pHead==NULL) { 
                pHead = pTail = n; 
                return n; 
            }

            n->next = pHead;
            n->prev = NULL;
            pHead->prev = n;
            pHead = n;
            return n;
        }

        Node* AddAtEnd(Node* n) {
            size++;

            if (pHead==NULL) { 
                pHead = pTail = n; 
                return n; 
            }

            pTail->next = n;
            n->prev = pTail;
            n->next = NULL;
            pTail = n;
        }

        void Unlink(Node* n){
            Node* before = n->prev;
            Node* after = n->next;

            if (before){
                before->next = after;  
            }

            if (after){ 
                after->prev = before;
            }

            if(pHead == n){
                pHead = pHead->next;
            }else if(pTail == n) {
                pTail = pTail->prev;
            }

            size--;
        }

        void Delete(Node* n){
            Unlink(n);
            delete n;
        }

        void TakeToBegin(Node* n){
            Unlink(n);
            AddAtBegin(n);
        } 

        Node* GetTailNode() {
            return pTail;
        } 

        void DeleteLast() {
            Delete(pTail);
        } 

        void Print(){
            Node* p = pHead;
            while(p!=NULL) {
                cout << "(" << p->key << "," << p->value << ") ";
                p = p->next;
            }
            cout << endl;
        }
};



class LRUCache{

    private:
        DoubleLinkedList cacheList;
        map<int, Node*> cacheMap;
        int capacity;

    public:
        LRUCache(int capacity) {
            this->capacity = capacity;    
        }
        void print(){
            cacheList.Print();
        }

        int get(int key) {
            if (cacheMap.find(key) != cacheMap.end() ){
                cacheList.TakeToBegin(cacheMap[key]);
                return cacheMap[key]->value;
            }
            return -1;

        }

        void set(int key, int value) {
            if (cacheMap.find(key) != cacheMap.end() ){
                Node *p = cacheMap[key];
                p->value = value;
                cacheList.TakeToBegin(cacheMap[key]);
            }else{
                cacheMap[key] = cacheList.NewAtBegin(key, value);
                if( cacheList.Size() > capacity) {
                    int key = cacheList.GetTailNode()->key; 
                    cacheMap.erase(key);
                    cacheList.DeleteLast();
                }
            }
        }
};


int main(int argc, char** argv) 
{

    /*
    LRUCache c(2);
    c.set(2,1);
    c.print();
    c.set(2,2);
    c.print();
    c.get(2);
    c.print();
    c.set(1,1);
    c.print();
    c.set(4,1);
    c.print();
    c.get(2);
    c.print();

    cout << "---------" << endl;
    */
    srand(time(0));

    int capacity = 5;
    int test_loop_times = 10;
    if (argc>1){
        capacity = atoi(argv[1]);
    }
    if (argc>2){
        test_loop_times = atoi(argv[1]);
    }

    LRUCache cache(capacity);

    int v; 
    for(int i=0; i<test_loop_times; i++) {
        v = i;//rand() % capacity;
        cout << "set " << v << ": ";
        cache.set(v, v);
        cache.print();

        v = rand() % capacity;
        cout << "get " << v << ": " << cache.get(v);
        cache.print();

        cout << endl;
    }
    return 0;
}
