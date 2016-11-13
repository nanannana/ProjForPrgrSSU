#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/************************************************************
	아래 3개의 구조체가 각각의 .txt파일로부터 데이터를 받아와
	저장시킬 구조체 입니다.
	또한 .txt파일에서 한줄이 하나의 구조체에 들어간다고 봅니다.
	또한 저장시킬때도 한 구조체 맴버들 전부를 한줄에 넣고 엔터(\n)
	시켜줄 것 입니다.
  ***********************************************************/
typedef struct client
{
	int sch_num; // 학번
    char *name; // 이름 
   	char *password; // 비밀번호 
    char *address; // 주소
    char *phone_num; // 연락처 
    struct client *next; // 연결리스트 다음 노드를 가리킬 것임
	struct client *last;
}Client;

typedef struct book
{
	int book_num; // 7자리 책 번호
	int ISBN;	// 13자리 ISBN 번호 
	char *name; // 책 이름 
	char *publisher; // 출판사 
	char *author; // 저자
	char *owner; // 소장처
	char *borrow_Y_N; // 대여 가능여부
	struct book *next; // 다음 노드
	struct book *last; // 이전 노드
}Book;

typedef struct borrow
{
	int sch_num; // 빌린사람 학번
	int book_num; // 빌려간 책
	time_t borrow_day; // 빌린날
	time_t return_day; // 반날해야 하는 날
	struct borrow *next; // 다음 노드
	struct borrow *last;
}Borrow;
/*********************************************************
	아래 3개의 구조체들은 각각의
	구조체 리스트에서 처음,현재,끝
	를 가리키게 됩니다.
  ********************************************************/
typedef struct list_client
{
	Client *head;
	Client *current;
	Client *tail;
}List_Client;

typedef struct list_book
{
	Book *head;
	Book *current;
	Book *tail;
}List_Book;

typedef struct list_borrow
{
	Borrow *head;
	Borrow *current;
	Borrow *tail;
}List_Borrow;

extern List_Client *list_client;
extern List_Book *list_book;
extern List_Borrow *list_borrow;

void file_write_client(void);
void file_write_book(void);
void file_write_borrow(void);
