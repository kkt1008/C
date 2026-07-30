#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE]; //1 차원 배열 스택 선언
int top =-1;

//스택이 공백인지 확인하는 함수
static int isEmpty(){
    if(top==-1){ // 스택 비어 있음
        return 1;
    }else{
        return 0;
    }
}

//스택이 포화 상태인지 확인하는 함수 
static int isFull(){
    if(top==STACK_SIZE-1){ //배열 인덱스 0~99까지 100개 이므로
        return 1;
    }else{
        return 0;
    }
}

// 스택의 top에 원소 삽입하는 함수
static void push(element item){
    if(isFull()){// 스택이 포화 상태인 경우
        printf("\n\n stack is full\n");
        return;
    }else{//여유가 있으면 
        stack[++top]=item; //top을 증가시킨 후 현재 top에 원소 삽입
    }
}

//스택의 top에서 원소를 삭제하는 연산
static element pop(){
    if(isEmpty()){//스택 비어 있음
        printf("\n\n stack is empty\n");
        return 0;
    }else{
        return stack[top--];
    }
}

//스택의 top 원소를 검색하는 함수
static element peek(){
    if(isEmpty()){ //스택이 공백일 때
        printf("\n\n stack is empty\n");
        exit(1); //OS에 실패 신호를 보냄--->OS가 없는 MCU에서 사용 불가
    }else{
        return stack[top--]; //현재 top의 원소를 삭제한 후 top 감소
    }
}

//스택의 원소를 출력하는 연산
static void printStack(){
    int i;
    printf("\n STACK[ ");
    for(i=0;i<=top;i++){
        printf("%d", stack[i]);
    }
    printf("] ");
}


int main(){
    printf("test array stack\n");

    element item;
    printStack();
    push(1); printStack(); // 1 삽입
    push(2); printStack(); // 2 삽입
    push(3); printStack(); // 3 삽입
    
    item =peek(); printStack(); // 현재 top 원소 출력
    printf("peek => %d\n", item);

    printf("top 원소 삭제");
    item=pop(); printStack();// top 원소 삭제
    printf("\t pop => %d\n", item);

    printf("top 원소 삭제");
    item=pop(); printStack();// top 원소 삭제
    printf("\t pop => %d\n",item);
    return 0;
}