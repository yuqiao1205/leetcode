//
//  main.cpp
//  findStartFromCycleLinkedlist
//
//  Created by Yan Peng on 2/18/22.
//

#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<unordered_set>
using namespace std;

struct Node{
    int value;
    Node* next;
    
};

Node* arrayToLinkedList(int arr[], int n) {
    Node* head = NULL;
    Node* tail = NULL;
    
    for(int i = 0; i < n; i++){// 循环每次建立新结点
        Node* temp = new Node;  //新结点放到temp
        temp ->value = arr[i]; // 新结点赋值
        temp->next = NULL; // 下一个结点为null
        
      
        if (head == NULL ){  // 头结点是空，就把新结点赋值给头结点
            head = temp;
        } else {
            tail->next = temp;  //不为空，将结点指向到下一个新结点。
        }
        tail = temp;  //放完后新结点变为尾巴结点 temp赋值给tail指针
    }
    return head;
}

Node* arrayToLinkedListWithoutTemp(int arr[], int n) {
    Node* head = NULL;
    Node* tail = NULL;
    
    for(int i = 0; i < n; i++) {
        if (head == NULL) {
            head = tail = new Node;
        } else {
            Node *temp = tail;
            tail = new Node;
            temp->next = tail;
        }
        tail->value = arr[i];
    }
    return head;
}



void printList(Node* head)
{
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

Node* findLastNode(Node* head)
{
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}


Node* newNode(int data){
        Node* temp = new Node;
        temp->value = data;
        temp->next = NULL;
        return temp;
    }

//map to keep mark of visited node
map<Node*, bool> vis;
bool flag = 0;

void checkCycle(Node* head)
{
    if(head == NULL){
        flag = 0;
        return;
    }
    // Mark the incoming Node as visited if it is not visited yet
    if (!vis[head]){
        vis[head] = true;
        checkCycle(head->next);
    }else{
        flag = 1;
        return;
    }
}
//using set to find a cycle in a linked list
bool detectCycle(Node* head) {
    Node* curr = head;
    unordered_set<Node*> set;
 
    // traverse the list
    while (curr){
        //set.end() means not exist.指针不能重复访问，如果不等于set.end就等于找到，返回true
        if (set.find(curr) != set.end()) {
            return true;
        }
 
        // insert the current node into the set
        set.insert(curr);
 
        // move to the next node
        curr = curr->next;
    }
 
    // we reach here if the list does not contain any cycle
    return false;
}

//int main(int argc, const char * argv[]){
//       // assume :Create a head Node 20->4->54->6->20
//       Node* head = newNode(20);
//
//       // Inserting Node in Linked List
//       head->next = newNode(4);
//       head->next->next = newNode(54);
//       head->next->next->next = newNode(6);
//
//       // Just to make a cycle
//       head->next->next->next->next = head;
//
//       // check cycle in Linked List
//       checkCycle(head);
//
//       if (flag)
//           cout << "Loop is found.";
//
//       else
//           cout << "No Loop Found.";
//       cout << endl;
//
//    return 0;
//}

int main(){
    int arr[] = { 1, 2, 3, 4, 1 };
    
    Node* head = arrayToLinkedList(arr,5);
    Node* tail = findLastNode(head);
    tail->next = head; // make a cycle
    
    if (detectCycle(head)) {
            cout << "Cycle Found";
        }
        else {
            cout << "No Cycle Found";
        }
    return 0;
}
