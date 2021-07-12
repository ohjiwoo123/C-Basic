#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int item; // 넣을 자료 값 
	struct node* llink; // llink 값
	struct node* rlink; // rlink 값 
};

struct node* avail = NULL; // avail 가용공간 = NULL로 지정

void addq(struct node*, int);	// 데이터 입력하는 함수 
void deleteq(struct node*);		// 데이터 지우는 함수 
void listprintf(struct node*);	// 데이터 출력하는 함수 
void erase(struct node*, struct node*);	// 실행 종료 함수 

// main 함수 
int main()
{
	struct node* head;	// 헤드의 값
	int cond, item;		// cond와 item int형으로 고정.


	// dummy-node 생성
	head = (struct node*)malloc(sizeof(struct node));	// head에 메모리값 할당 
	if (head == NULL)	// head가 NULL이면
	{
		fprintf(stderr, "The memory is full\n");	// 모니터에 The memory is full 출력
		exit(1);	// 나가기 
	}

	//Queue 초기화
	head->llink = head;		// 헤드 초기화
	head->rlink = head;
	/*head->item = 0;*/

	while (1)	// 무조건 참임. 참인 동안 반복하시오.
	{
		printf("1:insert\t2:delete\t3:output\t4:exit\n"); // 1번은 데이터 입력, 2번은 데이터 삭제, 3번은 데이터 출력, 4번은 실행 종료
		scanf("%d", &cond);		// 1, 2, 3, 4 번중에 입력!
		if (cond == 1)			// 1인 경우 데이터 삽입한다.
		{
			printf("Input Item\n");
			scanf("%d", &item);
			addq(head, item);
		}
		else if (cond == 2)		// 2인 경우 데이터를 지운다.
			deleteq(head);
		else if (cond == 3)		// 3인 경우 데이터를 출력한다.
			listprintf(head);
		else if (cond == 4)		// 4인 경우 실행을 종료한다.
		{
			erase(head, avail);
			break;
		}

		else
		{
			printf("Wrong Input\n");	// 1, 2, 3, 4 말고 다른 값이 입력되면 Wrong Input을 출력한다.
			exit(1);
		}
	}


	return 0;
}

void listprintf(struct node* ptr)
{
	struct node* init_position = ptr;	// ?
	ptr = ptr->rlink;	// 포인터가 rlink로 이동.
	printf("-----------list---------------\n"); // list 출력

	for (; init_position != ptr; ptr = ptr->rlink)// ; 이닛포지션이 ptr과 같지 않다면 ; ptr은 rlink로 이동. for 반복
	{
		printf("%4d", ptr->item);	// ptr이 item으로 이동된 값을 출력한다.
	}
	printf("\n");
}

void addq(struct node* ptr, int item)
{
	//struct node* l_ptr = ptr->llink;
	struct node* r_ptr = ptr->rlink;	// r_ptr (포인터를 rlink로 이동하고 이름을 r_ptr이라고 한다.
	struct node* temp = NULL;	// 임시저장소는 NULL로 지정한다.

	if (avail)	// NULL이면 
	{
		temp = avail;	// NULL = NULL;
		avail = avail->rlink;	// 가용공간이 rlink로 이동한다.
		/*temp->llink = NULL;
		temp->rlink = NULL;*/
	}
	else
		temp = (struct node*)malloc(sizeof(struct node));	// NULL이 아니면 임시공간(temp)에 메모리를 할당한다.


	if (temp == NULL)	// 만약 temp가 NULL이면 
	{
		fprintf(stderr, "The memory is full\n");	// The memory is full을 출력 
		exit(1);
	}
	temp->item = item;	// avail,temp가 NULL이 아니라면 temp를 item으로 이동한다. 그리고 그 값을 item으로 지정한다.

	temp->llink = ptr; // temp가 link로 이동한다. 그 llink 값은 ptr로 지정한다. 
	temp->rlink = ptr->rlink;	// temp를 rlink로 이동한다. 그 값은 포인터가 rlink로 이동한 값과 같다.
	ptr->rlink->llink = temp;	// ?
	ptr->rlink = temp;	// ?

	/*temp->llink = ptr->llink;
	temp->rlink = ptr;
	ptr->llink = temp;
	if (ptr->rlink == ptr)
		ptr->rlink = temp;
	else
		l_ptr->rlink = temp;*/

}

void deleteq(struct node* ptr)
{
	//struct node* delete_node = ptr->rlink;
	struct node* delete_node = ptr->llink;
	if (ptr->llink == ptr)
	{
		printf("No Data\n");
		return;
	}
	else
	{
		delete_node->llink->rlink = delete_node->rlink;
		delete_node->rlink->llink = delete_node->llink;


		/*ptr->rlink = delete_node->rlink;
		if (ptr->llink == delete_node)
			ptr->llink = ptr;
		else
			delete_node->rlink->llink = ptr;*/

	}

	printf("deleted data: %d\n", delete_node->item);
	delete_node->llink = NULL;
	delete_node->rlink = NULL;
	if (avail)
		delete_node->rlink = avail;
	else
		avail = delete_node;
}

void erase(struct node* head, struct node* avail)
{
	printf("실행");
	struct node* temp;
	while (head != (head->rlink))
		deleteq(head);

	while (avail != NULL)
	{
		temp = avail;
		avail = avail->rlink;
		free(avail);
	}

	free(head);

}