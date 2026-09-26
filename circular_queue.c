#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef char element;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} CircularQueue;

CircularQueue* createQueue(){
    CircularQueue*cQ;
    cQ=(CircularQueue*)malloc(sizeof(CircularQueue));
    cQ->front=0;
    cQ->rear=0;
    return cQ;
}

// 원형 큐가 공백 상태인지 확인
int isEmpty(CircularQueue* cQ){
    if(cQ->front==cQ->rear){
        printf("Circular Queue is empty!\n");
        return 1;
    }
    else{
        return 0;
    }

}
// 원형 큐가 포화 상태인지 확인
int isFull(CircularQueue* cQ){
    if((cQ->rear+1) % MAX_QUEUE_SIZE == cQ->front){
        printf("Circular Queue is Full!\n");
        return 1;
    }
    else{
        return 0;
    }

}
// 원형 큐의 rear에 원소 삽입 연산
void enQueue(CircularQueue* cQ, element item){
    if(isFull(cQ)) return;
    else{
        cQ->rear=(cQ->rear+1)%MAX_QUEUE_SIZE;
        cQ->queue[cQ->rear]=item;
    }
}

// 원형 큐의 front에서 원소 삭제 연산
element deQueue(CircularQueue* cQ){
    if(isEmpty(cQ)) exit(1);
    else{
        cQ->front= (cQ->front+1) % MAX_QUEUE_SIZE;
        return cQ->queue[cQ->front];
    }
}

// 원형 큐의 가장 앞에 있는 원소를 검색
element peek(CircularQueue* cQ){
    if(isEmpty(cQ)) exit(1);
    else{
        return cQ->queue[(cQ->front+1) % MAX_QUEUE_SIZE];
    }
}

void printQ(CircularQueue* cQ){
    int i, first, last;
    first = (cQ->front + 1) % MAX_QUEUE_SIZE;
    last = (cQ->rear + 1) % MAX_QUEUE_SIZE;
    printf("Circular Queue : [");
    i=first;
    while(i != last){
        printf("%3c", cQ->queue[i]);
        i = (i+1) % MAX_QUEUE_SIZE;
    }
    printf(" ]\n");
} 

int main(){
    CircularQueue* cQ = createQueue();
    element data;
    printf("----- Circular Queue -----\n");
    printf("\n insert A>>"); enQueue(cQ, 'A'); printQ(cQ);
    printf("\n insert B>>"); enQueue(cQ, 'B'); printQ(cQ);
    printf("\n insert C>>"); enQueue(cQ, 'C'); printQ(cQ);
    data = peek(cQ);
    printf("peek node : %c\n", data);
    printf("\ndelete >>"); data = deQueue(cQ); printQ(cQ);
    printf("deleted node : %c\n", data);
    printf("\ndelete >>"); data = deQueue(cQ); printQ(cQ);
    printf("deleted node : %c\n", data);
    printf("\ndelete >>"); data = deQueue(cQ); printQ(cQ);
    printf("deleted node : %c\n", data);
    printf("\n insert B>>"); enQueue(cQ, 'B'); printQ(cQ);
    printf("\n insert C>>"); enQueue(cQ, 'C'); printQ(cQ);
    
    return 0;
}

