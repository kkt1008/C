#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	struct ListNode* llink; //왼쪽
	struct ListNode* rlink; //오른쪽
	char data[4];
}listNode;

typedef struct {
	listNode* head;
}linkedList_h;

//공백 이중 연결 리스트 생성 함수
linkedList_h* createLinkedList_h(void) {
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

//이중 연결 리스트 순서대로 출력 함수
void printList(linkedList_h* DL) {
	listNode* p;
	printf("DL = (");
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) {
			printf(", ");
		}
	}
	printf(") \n");
}

//pre뒤에 노드 삽입 함수
void insertNode(linkedList_h* DL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (DL->head == NULL) { //헤더가 없으면 헤더를 추가한다
		newNode->llink = NULL;
		newNode->rlink = NULL;
		DL->head = newNode;
	}
	else {//새로운 노드 추가
		if (pre->rlink == NULL)
		{//pre가 가장 마지막인 경우
			newNode->llink = pre;
			pre->rlink = newNode;
			newNode->rlink = NULL;
		}
		else
		{//pre가 중간에 있는 경우
			newNode->llink = pre;
			pre->rlink = newNode;
			newNode->rlink = pre->rlink;
		}
	}
}

//이중 연결 리스트에서 특정 노드 탐색 함수
listNode* searchNode(linkedList_h* DL, char* x) {
	listNode* temp;
	temp = DL->head; //제일 먼저 헤더를 연결
	while (temp != NULL) {//리스트 전체를 순회
		if (strcmp(temp->data, x) == 0) {
			return temp; //찾았을 때 노드 반환
		}
		else {//못찾으면 다음 노드 이동
			temp = temp->rlink;
		}
	}
	//리스트 전체를 순회 했는데 못찾으면 null 반환
	return NULL;
}

//이중 연결 리스트에서 특정 노드 삭제 함수
//searchNode함수에서 삭제할 노드를 탐색한 뒤 전달
void deleteNode(linkedList_h* DL, listNode* target) {
	if (DL == NULL || target == NULL) {
		return; //헤더와 타겟 노드가 비정상일 때 종료
	}
	//중간, 맨앞, 맨뒤
	if (target->llink != NULL) {//삭제 노드 왼쪽에 노드 존재
		target->llink->rlink = target->rlink;
	}
	else {//삭제 노드 왼쪽에 노드 없음. target이 헤더 노드
		DL->head = target->rlink; //헤더를 다음 노드로 변경
	}

	if (target->rlink != NULL) {//삭제 노드 오른쪽에 노드 존재
		target->rlink->llink = target->llink;
	}
	free(target);
}

int main(void) {
	linkedList_h* DL;
	listNode* p;

	//공백 리스트 생성
	DL = createLinkedList_h();
	printf("이중 연결 리스트 생성\n");
	putchar('\n');

	printf("리스트에 노드 추가\n");
	insertNode(DL, NULL, "월");
	printList(DL); putchar('\n');

	p = searchNode(DL, "월"); insertNode(DL, p, "화");
	printList(DL); putchar('\n');

	p = searchNode(DL, "화"); insertNode(DL, p, "수");
	printList(DL); putchar('\n');

	//노드 삭제
	printf("리스트에 노드 삭제\n");
	p = searchNode(DL, "화"); deleteNode(DL, p);
	printList(DL); putchar('\n');


	return 0;
}