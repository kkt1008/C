#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode {
    char data;
    struct treeNode* left;
    struct treeNode* right; 
}treeNode;

//data를 루트 노드로 하여 left sub-tree, right sub-tree를 연결
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode){
    treeNode* root  = (treeNode*)malloc(sizeof(treeNode));
    root->data=data;
    root->left=leftNode;
    root->right=rightNode;
    return root;
}

//이진 트리의 전위 순회 연산
void preorder(treeNode* root){
    if(root){
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//이진 트리의 중위 순회 연산
void inorder(treeNode* root){
    if(root){
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

//이진 트리에 대한 후위 순회 연산
void postorder(treeNode* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%c",root->data);
    }
}

int main(){
    treeNode* n7=makeRootNode('d', NULL, NULL);
    treeNode* n6=makeRootNode('c', NULL, NULL);
    treeNode* n5=makeRootNode('b', NULL, NULL);
    treeNode* n4=makeRootNode('a', NULL, NULL);
    treeNode* n3=makeRootNode('/', n6, n7);
    treeNode* n2=makeRootNode('*', n4, n5);
    treeNode* n1=makeRootNode('-', n2, n3);

    printf("\n preorder : ");
    preorder(n1);

    printf("\n inorder : ");
    inorder(n1);

    printf("\n postorder : ");
    inorder(n1);

    return 0;
}