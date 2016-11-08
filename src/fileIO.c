#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"fileIO.h"
#include<string.h>

char temp[200];

void client_f_s_word(FILE *client_fp, Client *client)
{
	char trash = '\n';
	int i = 0;
	trash = fgetc(client_fp);
	while(trash == '|')
	{
		trash = fgetc(client_fp);
	}
	while(trash != '|')
	{
		temp[i++] = trash;
		trash = fgetc(client_fp);
	}
}

void book_f_s_word(FILE *book_fp ,Book * book)
{
	char trash = '\n';
	int i = 0;
	trash = fgetc(book_fp);
	while(trash == '|')
	{
		trash = fgetc(book_fp);
	}
	while(trash != '|')
	{
		temp[i++] = trash;
		trash = fgetc(book_fp);
	}
}
void borrow_f_s_word(FILE *borrow_fp, Borrow *borrow)
{
	printf("borrow\n");
}

int book_f_s_sentence(FILE *book_fp, Book *book)
{
	int i;
	char a;
	FILE *fp = book_fp;
	Book *sp = book;
	for(i=0; i<7; i++)
	{
		memset(temp,0,sizeof(temp));
		book_f_s_word(fp,sp);
		
		switch(i)
		{
			case 0:
			/*	if(strlen(temp) != 7)
					printf("Data eorror!!\n");
				else*/
					sp -> book_num = atoi(temp);
				break;
			case 1:
			/*	if(strlen(temp) != 13)
					printf("Data eorror!!\n");
				else*/
					sp -> ISBN = atoi(temp);
				break;
			case 2:
				sp -> name = malloc( strlen(temp) + 1 );
				strcpy(sp -> name, temp);
				break;
			case 3:
				sp -> publisher = malloc( strlen(temp) + 1 );
				strcpy(sp -> publisher, temp);
				break;
			case 4:
				sp -> author = malloc( strlen(temp) + 1 );
				strcpy(sp -> author, temp);
				break;
			case 5:
				sp -> owner = malloc( strlen(temp) + 1 );
				strcpy(sp -> owner, temp);
			case 6:
				sp -> borrow_Y_N = malloc( strlen(temp) + 1 );
				strcpy(sp -> borrow_Y_N, temp);
				a = fgetc(fp);
				fseek(fp,-1, SEEK_CUR);
		}
	}
	
	if(a == EOF)
	{
		return a;
	}
	else
		fseek(fp , 1 , SEEK_CUR);
	
	return a;
}

int client_f_s_sentence(FILE *client_fp, Client *client)
{
	int i;
	char a;
	FILE * fp = client_fp;
	Client *sp = client;
	for(i=0; i<5; i++)
	{
		memset(temp,0,sizeof(temp));
		client_f_s_word(fp,sp);
		switch(i)
		{
			case 0:
				sp -> sch_num = atoi(temp);
				break;
			case 1:
				sp -> name = malloc( strlen(temp) + 1 );
				strcpy(sp -> name, temp);
				break;
			case 2:
				sp -> password = malloc( strlen(temp) + 1 );
				strcpy(sp -> password, temp);
				break;
			case 3:
				sp -> address = malloc( strlen(temp) + 1 );
				strcpy(sp -> address, temp);
				break;
			case 4:
				sp -> phone_num = malloc( strlen(temp) + 1 );
				strcpy(sp -> phone_num, temp);
				a = fgetc(fp);
				fseek(fp,-1, SEEK_CUR);
				break;
					break;
		}
	}

	if(a == EOF)
	{
		return a;
	}
	else
		fseek(fp,1,SEEK_CUR);
	return a;
	
}

int what_struct(void *fp ,void * vsp, int n)
{
	int i =0;
	char a;
	if(n==1)
	{
		return client_f_s_sentence(fp,vsp);
	}
	else if(n==2)
	{
		//return borrow_f_s_sentence(fp,vsp);
	}
	else if(n==3)
	{
		return book_f_s_sentence(fp,vsp);
	}
	else
	{
		printf("ERORR!!!\n");
		return 0;
	}
	return 0;
}

void file_data_struct(Client *client, Book *book, Borrow *borrow)
{
	FILE *client_fp, *borrow_fp, *book_fp; // 순서대로 client. borrow, book
	Client *client_current;
	Book *book_current;
	Borrow *borrow_current;
	int check = 1;	
	
	client_fp = fopen("data/client.txt", "r");
	borrow_fp = fopen("data/borrow.txt", "r");
	book_fp = fopen("data/book.txt", "r");
	
	client_current = client;
	while(check != -1)
	{
		client_current -> next = (Client *)malloc(sizeof(Client));
		client_current = client_current -> next;
		check =what_struct((void *)client_fp ,(void *)client_current, 1) ;
	}
	check = 1;

	borrow_current = borrow;
	while(ftell(borrow_fp) > EOF)
	{
		
		break;	
	}
	check = 1;

	book_current = book;
	while(check != -1)
	{
		book_current -> next = (Book *)malloc(sizeof(Book));
		book_current -> next -> last = book_current;
		book_current = book_current -> next;
		check = what_struct((void *)book_fp ,(void *)book_current, 3);
	}
	check = 1;



	fclose(client_fp);
	fclose(borrow_fp);
	fclose(book_fp);
	
}

void client_struct_data_monitor(Client *client)
{
	Client *current;
	current = client -> next;
	int i = 1;
	while(1)
	{
		printf("%d번쨰 데이터\n",i++);
		printf("|%d|%s|%s",current -> sch_num, current -> name, current -> password);
		printf("|%s|%s|\n",current -> address, current -> phone_num);
	
		if(current -> next)
			current= current -> next;
		else
			break;
	}
}

int main(void)
{
	Client client;
	Book book;
	Borrow borrow;
	file_data_struct(&client, &book, &borrow);
	client_struct_data_monitor(&client);
	return 0;
}
