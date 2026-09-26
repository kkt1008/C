#include <stdlib.h>
#include <stdio.h>

//연결 큐 노드 원소 자료형 정의
typedef char element;

//연결 큐 노드 구조체
//배열로 구현한 원형 큐와 달리 구조체 노드를 추가로 정의
typedef struct Qnode{
    element data;
    struct Qnode*link;    
}Qnode;

//연결 큐 포인터 구조체(front & rear)
typedef struct{//포인터만 갖고 노드 구조체는 따로
    Qnode*front;
    Qnode*rear;
}LinkedQueue;

// 공백 연결 큐 생성
LinkedQueue* createLinkedQueue(){
    LinkedQueue* LQ;
    LQ = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    LQ->front=NULL; //초기 생성 연결 큐는 공백상태이므로 null로 초기화
    LQ->rear=NULL;
    return LQ;
}

//연결 큐 공백 상태 확인
int isEmpty(LinkedQueue* LQ){
    if(LQ->front==NULL){
        printf("linked queue is empty\n");
        return 1;
    }
    else return 0;
}

//연결 큐는 포화 상태 확인할 필요 없음
//필요할 때마다 노드가 하나씩 추가되기 때문

//연결 큐 원소 삽입
void enQueue(LinkedQueue*LQ, element item){
    //new node에 대한 메모리 할당 후 데이터(item) 삽입
    Qnode* newNode = (Qnode*)malloc(sizeof(Qnode));
    newNode->data=item;
    newNode->link=NULL; //새 노드는 연결 큐의 마지막이므로 null로 초기화
    
    //연결 큐가 공백이면, 추가 노드가 first node이자 last node 
    if(isEmpty(LQ)){//frot와 rear가 모두 새로 추가한 노드를 가리킴
        LQ->front=newNode;
        LQ->rear=newNode;
    }
    else{//연결 큐가 공백이 아니면 
        LQ->rear->link=newNode; //last node다음에 새 node 삽입
        LQ->rear=newNode; //마지막 노드를 가리키는 rear가 새롭게 삽입한 노드를 가리킴
    }
}

//연결 큐 원소 삭제
element deQueue(LinkedQueue* LQ){
    Qnode* deleteNode = LQ->front; //삭제할 노드는 첫번째 노드
    element item;

    if(isEmpty(LQ)) exit(1);
    else{
        item=deleteNode->data;
        LQ->front = LQ->front->link; //front를 두번째 노드로 변경
        free(deleteNode); //삭제할 노드 메모리 해제
        return item;
    }
}

//연결 큐의 제일 front 원소 검색 
element peek(LinkedQueue*LQ){
    element item;
    if(isEmpty(LQ)) exit(1);
    else{
        item = LQ ->front->data;
        return item;
    }
}

//연결 큐 원소 출력
void printLQ(LinkedQueue* LQ){
    Qnode*temp=LQ->front;
    printf("Linked Queue : [");
    while(temp){
        printf("%3c", temp->data);
        temp=temp->link;
    }
    printf(" ]\n");
}

int main(){
    LinkedQueue*LQ = createLinkedQueue();
    element data;

    printf("-----Linked Queue-----\n");
    printf("\n insert a>>"); enQueue(LQ,'a'); printLQ(LQ);
    printf("\n insert b>>"); enQueue(LQ,'b'); printLQ(LQ);
    printf("\n insert c>>"); enQueue(LQ,'c'); printLQ(LQ);
    
    data = peek(LQ); printf("peek node : %c\n", data);
    printf("\n delete node >>"); data=deQueue(LQ); printLQ(LQ);
    printf("\t delete dtat : %c\n", data);
    printf("\n delete node >>"); data=deQueue(LQ); printLQ(LQ);
    printf("\t delete dtat : %c\n", data);
    printf("\n delete node >>"); data=deQueue(LQ); printLQ(LQ);
    printf("\t delete dtat : %c\n", data);
    
    printf("\n insert d>>"); enQueue(LQ,'d'); printLQ(LQ);
    printf("\n insert e>>"); enQueue(LQ,'e'); printLQ(LQ);
    
    return 0;
}
