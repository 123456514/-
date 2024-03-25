#include<cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node * next;
}LinkedNode,*LinkedList;
typedef struct TreeNode{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
}TNode,*TNOde;
//针对线性表 A = (a1,a2,....,am)和 B = (b1,b2,....,bn) 试编写一个线性表合并算法，按照以下要求将A,B合并成一个线性表C 使得C = (a1,b1,.....am,bm,....bn),m <= n
//或者 C = (b1,a1,...,bn,bm,.....am)  m > n 其中，线性表  A,B C 均已带头节点的单链表
int getLinkedListLength(LinkedNode *head){
    Node *cur = head;
    int count = 0;
    while(cur  != nullptr){
        count++;
        cur  = cur ->next;
    }
    return count;
}
LinkedList combine(LinkedList la,LinkedList lb){
    LinkedList  lc;
    Node *p,*q,*r;
    lc = la;
    p = la->next;
    q = lb->next;
    r = lc;
    while(p !=NULL && q != NULL) {
        r->next = p;
        r = p;
        p = p->next;

        r->next = q;
        r = q;
        q = q->next;
    }
    if(p != NULL){
        r->next = p;
    }
    if(q != NULL){
        r->next = q;
    }
    free(lb);
    return lc;
}
LinkedNode * process(LinkedNode *head1,LinkedNode *head2){
    if(head1 == nullptr && head2 == nullptr){
        return nullptr;
    }
    if(head1 == nullptr){
        return head2;
    }
    if(head2 == nullptr){
        return head1;
    }
    int count1 = getLinkedListLength(head1);
    int count2 = getLinkedListLength(head2);
    Node * ret = (Node *) malloc(sizeof (Node));
    if(count1 <= count2){
        ret = combine(head1,head2);
    }else{
        ret = combine(head2,head1);
    }
    return ret;
}
// 这里使用尾插法在链表中添加节点
Node * list_add_trail(LinkedNode * head,int num){
    // 找到链表的尾节点
    Node * cur = head;
    while(cur->next != nullptr){
        cur = cur->next;
    }
    Node * node = (Node *) malloc(sizeof(Node));
    node->data = num;
    node->next = nullptr;
    cur->next = node;
    return head;
}
// 打印
void print(LinkedNode *head){
    Node * cur = head;
    while(cur != nullptr){
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}
// 计算出二叉树的第k层的节点个数是多少
void Print_K(TreeNode* p,int k){
    if(p!=NULL && k==0){
        cout<<p->data<<" ";
    }else if(p!=NULL){
        Print_K(p->left,k-1);
        Print_K(p->right,k-1);
    }
}
void Print_K_Level(TreeNode* p,int k){
    if(p==NULL || k<0){
        return;
    }
    Print_K(p,k);
    cout<<endl;
}

TreeNode * createTree(){
    TreeNode* node1 = (TreeNode *) malloc(sizeof (TreeNode));
    TreeNode* node2 = (TreeNode *) malloc(sizeof (TreeNode));
    TreeNode* node3 = (TreeNode *) malloc(sizeof (TreeNode));
    TreeNode* node4 = (TreeNode *) malloc(sizeof (TreeNode));
    TreeNode* node5 = (TreeNode *) malloc(sizeof (TreeNode));
    TreeNode* node6 = (TreeNode *) malloc(sizeof (TreeNode));
    TreeNode* node7 = (TreeNode *) malloc(sizeof (TreeNode));
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;
    node6->data = 6;
    node7->data = 7;
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node4->left = NULL;
    node5->left = NULL;
    node6->left = NULL;
    node7->left = NULL;
    node4->right = NULL;
    node5->right = NULL;
    node6->right = NULL;
    node7->right = NULL;
    return node1;
}
int main(){
    Node * head1 = (Node *) malloc(sizeof(Node));
    head1->next = nullptr;
    head1->data = 0;
    list_add_trail(head1,1);
    list_add_trail(head1,2);
    list_add_trail(head1,3);
    list_add_trail(head1,4);
    list_add_trail(head1,5);
    print(head1->next);

    Node * head2 = (Node *) malloc(sizeof(Node));
    head2->next = nullptr;
    head2->data = 0;
    list_add_trail(head2,1);
    list_add_trail(head2,2);
    list_add_trail(head2,3);
    print(head2->next);

    Node * cur = process(head1,head2);
    print(cur);
    TreeNode *root = createTree();
    Print_K_Level(root,1);
}