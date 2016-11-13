#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*********************************************************************

	사용설명서

	여러분들은 제가 만든 함수로 리스트를 생성후 테스트를 하실
	것 입니다. 
	그거슨 간단히
 	init_all_list(); 로 현재 리스트 포인터들을 초기화해주고

 	get_all_file_data(); 로 파일데이터들을 전부 받아주시고

	free_all_node(); 로 마지막에 동적할당된 모든 메모리를 풀어줍니다.

	즉
	처음 : 	init_all_list();
			get_all_file_data();
	
	마지막:	frea_all_node();

	를 입력해주시면 아무런 문제가 없을것 입니다.


	참고로 모든 만들어진 리스트들은 head 에서 tail까지 빈 노드없이
	꽉차게 만들었습니다.
  *******************************************************************/






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
	long int ISBN;	// 13자리 ISBN 번호 
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
typedef struct 
{
	Client *head;
	Client *current;
	Client *tail;
}List_Client;

typedef struct
{
	Book *head;
	Book *current;
	Book *tail;
}List_Book;

typedef struct
{
	Borrow *head;
	Borrow *current;
	Borrow *tail;
}List_Borrow;

char temp[500] = {0};




/***************************************

	함수 원형들
  ***********************************/

/*************************************************************
	여러분들은 회원가입함수를 만드시거나 뭐 구조체를 건들듯합니다.
	그러면 구조체 건들자마자 바로 파일에 넣어줘야 할 것 입니다
	그걸 위한 함수가 됩니다.

	넣는방식은 기존 .txt파일 초기화후 현재 구조체내용을 넣음으로서
	수정하는 방식임니다.

	만약에 나중에 이방식이 문제가생기면 따로 바꾸겠습니다.

	file_write();

	file_write_xxxx();// xxxx.txt 에 현재 구조체 다 넣을것

  *************************************************************/

void file_write();
void file_write_client();
void file_write_book();
void file_write_borrow();


/**********************************************************************
	make_XXX_node();
 
	중간중간에 노드를 만들일이 생기거나 파일입력받을때는 엄청 쓰일 노드
	를 만들어주는 함수입니다.!
 **********************************************************************/
void make_client_node();
void make_borrow_node();
void make_book_node();



/*********************************************************************
	init_all_list();
 
 처음 혹은 맨 마지맥에 우리는 모든 포인터들을 NULL로 바꿔줄 필요가
	있습니다. 그걸위해 여러분들은 init_all_list();호출만 해주시면
	3개의 리스트 구조체에 있는 head, current, tail은 NULL이 될 것입니다
	또한 맨 처음에는 리스트 구조체가 만들어지지 않았음으로 만들어 져 있
	지가 않다면 만들어 줄 것 입니다.
 *********************************************************************/
void init_all_list();
void init_client_list();
void init_borrow_list();
void init_book_list();

/*******************************************
 free_all_node();
 
 동적할당된 모든 노드들을 풀어 줄 것 입니다.
 
 ******************************************/

void free_all_node();
void free_client_node();
void free_book_node();
void free_borrow_node();


/***********************************************************************
	get_all_file_data();
 
	이함수는 프로그램이 처음 실행 되었을 때 모든 .txt파일로 부터 데이터
 들을 읽어 들여 구조체에다가 저장해 주는 함수로 메인을 짜는 분깨서는
	초기화 후에 이 명령어를 한번 써 주시길 바랍니다.
 *********************************************************************/
void get_all_file_data();
int get_client_file_data(FILE * fp);
int get_book_file_data(FILE *fp);
int get_borrow_file_data(FILE *fp);
char * get_oneWord(FILE **fp);




extern List_Client *list_client;
extern List_Book *list_book;
extern List_Borrow *list_borrow;

