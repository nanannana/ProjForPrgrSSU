#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"menu.h"
#include"login.h"

static const char* admin_id = "admin";
static const char* admin_pwd = "lib_admin7";

extern int my_ID;
extern char my_password[50];

int Sign_down(void){
	if (sch_num2keys_on_borrow(NULL, my_ID) == 0)
	{
		remove_client(sch_num);
		printf("\n회원 탈퇴가 성공적으로 실행되었습니다.\n다시 로그인 해주십시오.\n");
		return -2;
	}
	else
	{
		printf("\n대여한 도서가 있어, 탈퇴가 불가능합니다.\n");
		return 0;
	}
}


void Sign_up(void)
{
	Client client, temp,copy_client;
	const Client *compare = &temp;
	printf(">>회원 가입<<\n");
	printf("학번, 비밀번호, 이름, 주소, 전화번호를 입력하세요\n");
	printf("학번: ");
	scanf("%d",&(client.sch_num));

	if (get_client(client.sch_num,&compare) == Success)
	{
		printf("중복된 학번입니다");
		return;
	}
	printf("이름: ");
	scanf("%s",copy_client.name);
	client.name = (char *)malloc(sizeof(char) * (strlen(copy_client.name) + 1));
	strcpy(client.name,copy_client.name);
	
	printf("전화번호: ");
	scanf("%s",copy_client.password);
	client.password = (char *)malloc(sizeof(char) * (strlen(copy_client.password) + 1));
	strcpy(client.password,copy_client.password);

	printf("주소: ");
	scanf("%s",copy_client.address);
	client.address = (char *)malloc(sizeof(char) * (strlen(copy_client.address) + 1));
	strcpy(client.address,copy_client.address);

	append_client(client);
	printf("회원가입 되셨습니다.");


	return ;
}


int Revise(int sch_num)
{
	int flag;
	printf("비밀번호, 주소, 전화번호 중 어떤것을 바꾸고 싶으십니까?\n");
	printf("비밀번호 = 1\n");
	printf("주소 = 2\n");
	printf("전화번호 = 3\n");
	scanf("%d",&flag);
	const Client *result = NULL;
	while(1){
	switch(flag){
		case '1' :
			if(get_client(sch_num,&result) == Success)
			{
				Client temp = *result; 
				printf("바꿀 패스워드?");
				scanf("%s",temp.password);
				if((flag = replace_client(result,temp)) == Success)
					return Success;
				else if (flag == Fail_No_Element)
					printf("비밀번호는 한글자 이상입니다");
					return Fail_No_Element;
			}
			else printf("잘못된 학번입니다.\n");
			break;
		case '2' :
			if(get_client(sch_num,&result) == Success)
			{
				Client temp = *result; 
				printf("바꿀 주소?");
				scanf("%s",temp.address);
				if((flag = replace_client(result,temp)) == Success)
					return Success;
				else if (flag == Fail_No_Element)
					printf("잘못된 주소입니다" );
					return Fail_No_Element;
			}
			else printf("잘못된 학번입니다.\n");
			break;
		case '3' :
			if(get_client(sch_num,&result) == Success)
			{
				Client temp = *result; 
				printf("바꿀 전화번호?");
				scanf("%s",temp.phone_num);
				if((flag = replace_client(result,temp)) ==Success)
					return Success;
				else if (flag == Fail_Two_Same_Value)
					printf("같은 번호입니다");
					return Fail_Two_Same_Value;
				else if (flag == Fail_No_Element)
					printf("번호를 입력하세요");
					return Fail_No_Element;
			}
			else printf("잘못된 학번입니다.\n");
			break;
		default :
			printf("1,2,3 만 입력하세요 !!");
	}

		}	 
			
			



}

int Log_in()
{
	const Client * client = NULL;
	char buff[50];
	int rtnvalue = 0;

	
	printf(">> 로그인 <<\n");


	printf("학번: ");
	scanf("%s", buff);
	
	if (!strcmp(buff, ADMIN_ID))
		my_ID = -1;
	else
		my_ID = atoi(buff);


	printf("비밀번호: ");
	scanf("%s", my_password);

	if (my_ID == -1 && !strcmp(my_password, ADMIN_PWD))
	{
		return Admin_menu();
	}
	else
	{
		printf("로그인에 실패하였습니다.\n");
		return 0;
	}
	
	if (get_client(ID, &client) == Success && password2keys_on_client(NULL,my_password) != 0)
	{
		return Membermenu();
	}
	else 
	{
		printf("로그인에 실패하였습니다.\n");
		return 0;
	}
		
}


int Log_out(void)
{
	return out;
}
