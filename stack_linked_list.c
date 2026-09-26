#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element; //스택 자료구조 int로 정의

//단일 연결 리스트로 스택의 각 요소 데이터를 구조체로 정의
typedef struct stackNode{ 
    element data;
    struct stackNode* link;
}stackNode;

stackNode* top = NULL; //스택 top노드 지정 포인터

//스택이 공백인지 확인하는 함수
int isEmpty(void){
    if(top==NULL){//스택 비어 있음
        return 1; 
    }else{
        return 0;
    }
}

//스택 top에 원소를 삽입하는 함수
void push(element item){
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
    if (temp == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    temp->data=item;
    temp->link=top; //top다음 노드로 추가 노드 연결
    //top은 항상 스택의 맨 위를 가리켜야함
    top=temp; // top이 이전 스택의 맨 위 노드를 가리켜서 변경 필요
}

element pop(void){
    stackNode* temp;
    element item;

    if (isEmpty()) {
        fprintf(stderr, "stack is empty\n");
        exit(EXIT_FAILURE);
    }

    temp = top;
    item = temp->data;
    top = temp->link;
    free(temp);
    return item;
}

void printStack(void){
    stackNode* current = top;

    printf("STACK[ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("]\n");
}

void clearStack(void){
    while (!isEmpty()) {
        (void)pop();
    }
}

int main(void){
    printf("test linked-list stack\n");

    push(1);
    push(2);
    push(3);
    printStack();

    printf("pop => %d\n", pop());
    printStack();

    clearStack();
    return 0;
}

