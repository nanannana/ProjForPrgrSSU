#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct client
{
	int sch_num;
    char *name;
   	char *password;
    char *address;
    char *phone_num;
    struct client *next;
}Client;

typedef struct book
{
	int book_num; // 7
	int ISBN	// 13
	char *name;
	char *publisher;
	char *author;
	char *owner;
	char borrow_Y_N;
	struct Book *next;
}Book;

typedef struct borrow
{
	int sch_num;
	int book_num;
	time_t borrow_day;
	time_t return_day;
	struct Borrow *next;
}Borrow;

