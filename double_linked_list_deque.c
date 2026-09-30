#include <stdio.h>
#include <stdlib.h>

typedef char element;   //데크 원소의 자료형을 char로 정의
typedef struct DQNode{  //이중 연결 리스트 데크의 노드 구조를 구조체로 정의
    element data;
    struct DQNode *llink;
    struct DQNode *rlink;
}DQNode;

typedef struct{     //데크에서 사용하는 포인터 front, rear를 구조체로 정의
    DQNode *front;
    DQNode *rear;
}DQueType;

//공백 데크 생성
DQueType *createDQue(){
    DQueType *DQ;
    DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->front=NULL;
    DQ->rear=NULL;
    return DQ;
}

//데크가 공백인지 확인
int isEmpty(DQueType*DQ){
    if(DQ->front==NULL){
        printf("\n linked queue is empty!!\n");
        return 1;
    }else{
        return 0;
    }
}

//데크의 front 앞에 원소 삽입 : 데크가 공백인 경우 / 공백이 아닌 경우 존재
void insertFront(DQueType*DQ, element item){
    DQNode*newNode=(DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    if(DQ->front ==NULL){//데크가 공백인 경우
        DQ->front = newNode;
        DQ->rear = newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    }else{//데크가 공백이 아닐 때
        DQ->front->llink = newNode;     //기존에 맨 앞에 존재하는 노드의 왼쪽에 새로운 노드 할당
        newNode->rlink = DQ->front;     //새로운 노드의 오른쪽은 기존의 맨 앞 노드를 가리키도록 연결
        newNode->llink = NULL;          //맨앞에 할당된 노드의 왼쪽은 비어 있으므로 NULL
        DQ->front=newNode;              //노드 추가 이후에는 노드의 front 포인터 변경
    }
}

//데크의 rear에 원소 삽입 : 데크가 공백인 경우 / 공백이 아닌 경우 존재
void insertRear(DQueType *DQ, element item){
    DQNode*newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    if(DQ->rear==NULL){//데크가 공백일 때 
        DQ->front=newNode;
        DQ->rear=newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    }else{//데크가 공백이 아닐때
        DQ->rear->rlink=newNode;    //기존에 맨 뒤에 존재하는 노드의 오른쪽에 새로운 노드 할당
        newNode->rlink=NULL;        //맨뒤에 할당된 노드의 오른쪽은 비어 있으므로 NULL
        newNode->llink=DQ->rear;    //새로운 노드의 왼쪽은 기존의 맨 뒤 노드를 가리키도록 연결
        DQ->rear=newNode;           //노드 추가 이후에는 노드의 rear 포인터 변경
    }
}

//데크의 front 노드를 삭제하고 반환하는 연산
element deleteFront(DQueType *DQ){
    DQNode* old = DQ->front; //삭제할 현재 front 노드
    element item;
    if(isEmpty(DQ)){//데크가 공백일 때
        return 0;
    }else{//데크가 공백이 아닐 때 : 노드 1개 or 노드 2개 이상
        item = old->data;    //삭제할 노드의 data값을 다른곳에 보관. 보관하지 않으면 free와 동시에 data값 유실됨
        if(DQ->front->rlink==NULL){//맨 앞의 노드의 오른쪽이 비어있을 때-->노드가 1개만 있는 경우
            DQ->front=NULL; 
            DQ->rear=NULL;
        }else{//노드가 1개 이상 존재하는 경우
            DQ->front = DQ->front->rlink;   //front 노드를 맨 앞의 바로 뒤에 노드로 변경
            DQ->front->llink = NULL;        //front 노드는 맨 앞이므로 왼쪽은 NULL
        }
        free(old);  //front 노드를 변경한 이후에는 기존의 front 노드의 메모리 해제
        return item;    //따로 보관중이던 이전 front 노드의 data
    }
}

//데크의 rear 노드를 삭제하고 반환하는 연산
element deleteRear(DQueType*DQ){
    DQNode*old = DQ->rear;  //삭제할 현재의 rear 노드
    element item;
    if(isEmpty(DQ)){//데크가 공백일 때
        return 0;
    }else{//데크가 공백이 아닐 때 : 노드 1개 or 노드 2개 이상
        item = old->data;   //삭제할 노드의 data값을 다른곳에 보관. 보관하지 않으면 free와 동시에 data값 유실됨
        if(DQ->front->rlink==NULL){//맨 앞의 노드의 오른쪽이 비어있을 때-->노드가 1개만 있는 경우
            DQ->front=NULL;
            DQ->rear=NULL;
        }else{//노드가 1개 이상 존재하는 경우
            DQ->rear = DQ->rear->llink;     //rear 노드를 맨 뒤 노드의 한 칸 앞의 노드로 변경 
            DQ->rear->rlink=NULL;
        }
        free(old);
        return item;
    }
}

//데크의 front 노드의 데이터 필드를 반환하는 연산(노드 해제 X, data값만 반환)
element peekFront(DQueType*DQ){
    element item;
    if(isEmpty(DQ)){//데크가 공백인 경우
        return 0;
    }else{
        item=DQ->front->data;
        return item;
    }
}

//데크의 rear 노드의 데이터 필드를 반환하는 연산(노드 해제 X, data값만 반환)
element peekRear(DQueType*DQ){
    element item;
    if(isEmpty(DQ)){//데크가 공백인 경우
        return 0;
    }else{
        item=DQ->rear->data;
        return item;
    }
}

//데크의 front~rear까지 출력하는 연산
void printDQ(DQueType*DQ){
    DQNode*temp=DQ->front;
    printf("DeQue : [");
    while(temp){//temp의 rlink가 null일 때까지 순회하며 출력
        printf("%3c",temp->data); //노드의 data출력
        temp=temp->rlink; //출력 뒤에는 temp를 rlink로 옮김
    }
    printf("]");
}

int main(){
    DQueType*testDQ=createDQue();   //데크 생성
    element data;
    printf("\n==== calculate DeQue ====\n");
    printf("\n front insert a >> "); insertFront(testDQ, 'a'); printDQ(testDQ);
    printf("\n front insert b >> "); insertFront(testDQ, 'b'); printDQ(testDQ);
    printf("\n front insert c >> "); insertFront(testDQ, 'c'); printDQ(testDQ);
    
    printf("\n front delete >> "); data = deleteFront(testDQ); printDQ(testDQ);
    printf("\tdelete data : %c",data);
    
    printf("\n rear insert d >> "); insertRear(testDQ,'d'); printDQ(testDQ);
    printf("\n front insert e >> "); insertFront(testDQ,'e'); printDQ(testDQ);
    printf("\n front insert f >> "); insertFront(testDQ,'f'); printDQ(testDQ);

    data=peekFront(testDQ); printf("\n peek front item : %c \n",data);
    data=peekRear(testDQ); printf("peek rear item : %c \n",data);
    
    return 0;
}



















