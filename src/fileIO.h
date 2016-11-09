#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct client
{
	int sch_num; // 학번
    char *name; // 이름 
   	char *password; // 비밀번호 
    char *address; // 주소
    char *phone_num; // 연락처 
    struct client *next; // 연결리스트 다음 노드를 가리킬 것임
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
}Borrow;

extern Client client;
extern Book book;
extern Borrow borrow;
