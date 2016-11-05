#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"fileIO.h"
#include<string.h>

int main(void)
{
	Client client;
	Book book;
	Borrow borrow;
	FILE *cfp = fopen("client.txt","r");
	input_data(cfp, &client, &book, &borrow);
	fclose(cfp);
	return 0;
}

void input_data(FILE * cfp,Client *client, Book *book, Borrow *borrow)
{
	int i = 0, end, k;
	char sp = 46;
	char temp[300] = {'\0'};
	
	fseek(cfp , 0 , SEEK_END);
	end = ftell(cfp);
	rewind(cfp);
	
	while(ftell(cfp) < end)
	{
		client -> next = (Client *)malloc(sizeof(Client));
		client = client -> next;
		client -> next = NULL;
		sp =fgetc(cfp);
		while(sp != '\n')
		{
			while(sp == '|' || sp == ' ' )
			{
				sp = fgetc(cfp);
			}
			fseek(cfp, -1, SEEK_CUR);
			fscanf(cfp,"%d",&(client -> sch_num));
			break;
		}
		break;
	}
	printf("%d\n", client -> sch_num);
}

void print_data(Client *client, Book *book, Borrow *borrow)
{
	
	
}
