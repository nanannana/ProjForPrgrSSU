#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"login.h"
void Sign_down(int sch_num){
	int *book_nums = (int*)malloc(sizeof(int) * 40);
	int cnt;

	if ((cnt = sch_num2keys_on_borrow(book_nums,sch_num)) == 0)
	{
		remove_client(sch_num);
		return;
	}
	else return ;
}


void Sign_up(void)
{
	char temp[500];
	const Client *client, *compare;
	client = list_client -> current;
	printf(">>회원 가입<<\n");
	printf("학번, 비밀번호, 이름, 주소, 전화번호를 입력하세요\n");
	int i,j;
	char k[20];
	printf("학번: \n");
	scanf("%s",k);
	i = atoi(k);
	j = get_client(i,&compare);

	if (j != Success)
	{
		printf("중복된 학번입니다");
		return;
	}
	client->sch_num = atoi(k);
	client->name = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
	scanf("%s",&(client->name));
	
	client->password = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
	scanf("%s",&(client->password));

	client->address = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
	scanf("%s",&(client->address));

	append_client(*client);


	return ;
}


int Revise(int sch_num)
{
	int k;
	printf("비밀번호, 주소, 전화번호 중 어떤것을 바꾸고 싶으십니까?\n");
	printf("비밀번호 = 1\n");
	printf("주소 = 2\n");
	printf("전화번호 = 3\n");
	scanf("%d",&k);
	const Client *result = NULL;
	Client temp = {0}; 
	switch(k){
		case '1' :
			if(get_client(sch_num,&result) == Success)
			{
				printf("바꿀 패스워드?");
				scanf("%s",(*result).password);
				temp.password = (*result).password;
				Return_Flags flag;
				if((flag = replace_client(result,temp)) == Success)
					return Success;
				else if (flag == Fail_Two_Same_Value)
					return Fail_Two_Same_Value;
				else if (flag == Fail_No_Element)
					return Fail_No_Element;
			}
			break;
		case '2' :
			if(get_client(sch_num,&result) == Success)
			{
				printf("바꿀 주소?");
				scanf("%s",(*result).address);
				strcpy(temp.address,(*result).address);
				Return_Flags flag;
				if((flag = replace_client(result,temp)) == Success)
					return Success;
				else if (flag == Fail_Two_Same_Value)
					return Fail_Two_Same_Value;
				else if (flag == Fail_No_Element)
					return Fail_No_Element;
			}
			break;
		case '3' :
			if(get_client(sch_num,&result) == Success)
			{
				printf("바꿀 전화번호?");
				scanf("%s",(*result).phone_num);
				strcpy(temp.phone_num, (*result).phone_num);
				Return_Flags flag;
				if((flag = replace_client(result,temp)) ==Success)
					return Success;
				else if (flag == Fail_Two_Same_Value)
					return Fail_Two_Same_Value;
				else if (flag == Fail_No_Element)
					return Fail_No_Element;
			}
			break;
		default :
			printf("1,2,3 만 입력하세요 !!");
	}

			 
			
			



	return 0;
}

void Log_in()
{
	int ID,check;
	extern char *my_sch_num;
	extern char *my_password;
	const Client *client;
	printf("학번 입력");
	scanf("%s",my_sch_num);
	printf("패쓰 워드입력");
	scanf("%s",my_password);
	char admin[6] = {"admin"};
	ID = atoi(my_sch_num);
	if(strcmp(my_sch_num,admin)==0){
		if (get_client(ID,&client)==Success)
		{
			if (strcmp(client -> password,my_password)==0) 
			check = Admin_menu();
		}
	}
	else {
		if (get_client(ID,&client)==Success)
		{
			if (strcmp(client -> password,my_password)==0) 
				check = member_menu();
		}
	}
	return ;
	
}


int Log_out(void)
{
	return out;
}







