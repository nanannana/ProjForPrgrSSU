#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"fileIO.h"
#include<string.h>


List_Client *list_client = NULL;
List_Book *list_book = NULL;
List_Borrow *list_borrow = NULL;

char temp[500] = {0};

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
void free_list_node();

/***********************************************************************
	print_XXXX_data( XXXX* current);

	분명히 자료를 출력하는 상황은 탐색을 하는 상황즁에 옵니다. 그래서 		현재 리스트 포인터를 매개변수로 받아줍니다.
	즉 여러분은 탐색하다가 걸린곳에서 포인터를 던져주면 될것 입니다.
	또한 맨 마지막(tail) 혹은 NULL은 자료가 없다고 출력할 것입니다.
  *********************************************************************/
//void print_client_data(Client *current);
//void print_book_data(Book *book);
//void print_borrow_data(Borrow *borrow);


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

/**********************
  리스트 초기화 함수들
   ********************/
void init_all_list()
{
	if(list_client == NULL)
		list_client = (List_Client *)malloc(sizeof(List_Client));
	if(list_book == NULL)
		list_book = (List_Book *)malloc(sizeof(List_Book));
	if(list_borrow == NULL)
		list_borrow = (List_Borrow *)malloc(sizeof(List_Borrow));

	init_client_list();
	init_borrow_list();
	init_book_list();
}

void init_client_list()
{
	list_client -> head = NULL;
	list_client -> current = NULL;
	list_client -> tail = NULL;
}

void init_borrow_list()
{
	list_borrow -> head = NULL;
	list_borrow -> current = NULL;
	list_borrow -> tail = NULL;
}

void init_book_list()
{
	list_book -> head = NULL;
	list_book -> current = NULL;
	list_book -> tail = NULL;
}

/********************************************************************************
	파일 입력 소스코드 부분입니다!
  ******************************************************************************/

char *get_oneWord(FILE **fp)
{
	memset(temp,0,sizeof(temp));
	fgetc(*fp);
	fscanf(*fp ,"%[^|\n]",temp);
	return temp;
}

void get_all_file_data()
{
	FILE *client_fp, *book_fp, *borrow_fp;
	int i =0;
	client_fp = fopen("data/client.txt","r");
	book_fp = fopen("data/book.txt","r");
	borrow_fp = fopen("data/borrow.txt","r");
	
	if(list_client -> head == NULL)
		make_client_node();
	if(list_book -> head == NULL)
		make_book_node();
	if(list_borrow -> head == NULL)
		make_borrow_node();
	
	while(get_client_file_data(client_fp))
	{
		make_client_node();
	}
	while(get_book_file_data(book_fp))
	{
		make_book_node();
	}
	while(get_borrow_file_data(borrow_fp))
	{
		make_borrow_node();
	}
	
	
	fclose(client_fp);
	fclose(book_fp);
	fclose(borrow_fp);
}

int get_client_file_data(FILE *fp)
{
	Client *client;
	client = list_client -> current;

	client -> sch_num = atoi(get_oneWord(&fp));

	get_oneWord(&fp);
	client -> name = (char *)malloc(sizeof(strlen(temp) +1));
	strcpy(client -> name, temp);

	get_oneWord(&fp);
	client -> password = (char *)malloc(sizeof(strlen(temp) +1));
	strcpy(client -> password, temp);

	get_oneWord(&fp);
	client -> address = (char *)malloc(sizeof(strlen(temp) +1));
	strcpy(client -> address, temp);

	get_oneWord(&fp);
	client -> phone_num = (char *)malloc(sizeof(strlen(temp) +1));
	strcpy(client -> phone_num, temp);
	fseek(fp,1,SEEK_CUR);	
	
	if(fgetc(fp) == EOF)
	{	
		return 0;
	}
	else
	{
		return 1;
	}
}

int get_book_file_data(FILE *fp)
{
	Book *book;
	book = list_book -> current;
	
	book -> book_num = atoi(get_oneWord(&fp));
	book -> ISBN = atoi(get_oneWord(&fp));
	
	get_oneWord(&fp);
	book -> name = (char *)malloc(sizeof(strlen(temp) + 1));
	strcpy(book -> name,temp);

	get_oneWord(&fp);
	book -> name = (char *)malloc(sizeof(strlen(temp) + 1));
	strcpy(book -> name,temp);

	get_oneWord(&fp);
	book -> name = (char *)malloc(sizeof(strlen(temp) + 1));
	strcpy(book -> name,temp);

	get_oneWord(&fp);
	book -> name = (char *)malloc(sizeof(strlen(temp) + 1));
	strcpy(book -> name,temp);

	get_oneWord(&fp);
	book -> name = (char *)malloc(sizeof(strlen(temp) + 1));
	strcpy(book -> name,temp);
	fseek(fp,1,SEEK_CUR);	
	
	if(fgetc(fp) == EOF)
	{	
		return 0;
	}
	else
	{
		return 1;
	}
}
	
int get_borrow_file_data(FILE *fp)
{
	return 0;
}

/*********************************************************
	node free 소스코드	
 *************************************************************/


void free_all_node()
{
	free_client_node();
	free_book_node();
	free_borrow_node();
	free_list_node();
}

void free_client_node()
{
	list_client -> current = list_client -> head;
	while(list_client -> current)
	{
		free(list_client -> current -> name);
		free(list_client -> current -> password);
		free(list_client -> current -> address);
		free(list_client -> current -> phone_num);
		free(list_client -> current);
		list_client -> current = list_client -> current -> next;
	}
}

void free_book_node()
{
	list_book -> current = list_book -> head;
	while(list_book -> current)
	{
		free(list_book -> current -> name);
		free(list_book -> current -> publisher);
		free(list_book -> current -> author);
		free(list_book -> current -> owner);
		free(list_book -> current -> borrow_Y_N);
		free(list_book -> current);
		list_book -> current = list_book -> current -> next;
	}
}
void free_borrow_node()
{
	list_borrow -> current = list_borrow -> head;
	while(list_borrow -> current)
	{
		free(list_borrow -> current);
		list_borrow -> current = list_borrow -> current ->next;
	}
}
void free_list_node()
{
	free(list_client);
	free(list_book);
	free(list_borrow);
}



/********************************************************************************
	node생성 소스코드 부분
  ******************************************************************************/
void make_client_node()
{
	if(list_client -> head == NULL)
	{
		list_client -> tail = (Client *)malloc(sizeof(Client));
		list_client -> head = list_client -> tail;
		list_client -> current = list_client -> tail;
		list_client -> tail -> next = NULL;
		list_client -> tail -> last = NULL;
	}
	else
	{
		list_client -> tail = (Client *)malloc(sizeof(Client));
		list_client -> current -> next = list_client -> tail;
		list_client -> tail -> last = list_client -> current;
		list_client -> current = list_client -> tail;
		list_client -> tail -> next = NULL;
	}
}
void make_borrow_node()
{
	if(list_borrow -> head == NULL)
	{
		list_borrow -> tail = (Borrow *)malloc(sizeof(Borrow));
		list_borrow -> head = list_borrow -> tail;
		list_borrow -> current = list_borrow ->tail;
		list_borrow -> tail -> next = NULL;
		list_borrow -> tail -> last = NULL;
	}
	else
	{
		list_borrow -> tail = (Borrow *)malloc(sizeof(Borrow));
		list_borrow -> current -> next = list_borrow -> tail;
		list_borrow -> tail -> last = list_borrow -> current;
		list_borrow -> current = list_borrow ->tail;
		list_borrow -> tail -> next = NULL;
	}
}
void make_book_node()
{
	if(list_book -> head == NULL)
	{
		list_book -> tail = (Book *)malloc(sizeof(Book));
		list_book -> head = list_book -> tail;
		list_book -> current = list_book -> tail;
		list_book -> tail -> next = NULL;
		list_book -> tail -> last = NULL;
	}
	else
	{
		list_book -> tail = (Book *)malloc(sizeof(Book));
		list_book -> tail -> last = list_book -> current;
		list_book -> current -> next = list_book -> tail;
		list_book -> current = list_book -> tail;
		list_book -> tail -> next = NULL;
	}
}

int main()
{
	init_all_list();
	get_all_file_data();
	free_all_node();
	return 0;
} 

