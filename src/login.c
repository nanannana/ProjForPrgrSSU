#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"menu.h"
#include"login.h"

static const char* ADMIN_ID = "admin";
static const char* ADMIN_PWD = "lib_admin7";

extern int my_ID;
extern char my_password[50];

int Sign_down(void){
	if (sch_num2keys_on_borrow(NULL, my_ID) == 0)
	{
		remove_client(my_ID);
		file_write_client();
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
	Client client,client_temp;
	const Client *compare = &client_temp;
	char temp[500];

	printf("\n>>회원 가입<<\n");
	printf("학번, 비밀번호, 이름, 주소, 전화번호를 입력하세요\n");
	printf("학번: ");
	scanf("%s",temp);
	getchar();
	
	if (get_client(atoi(temp),&compare) == Success)
	{
		printf("중복된 학번입니다");
		return;
	}
	else
	{
		client.sch_num = atoi(temp);
	}
	
	printf("이름: ");
	scanf("%[^\n]",temp);
	getchar();
	client.name = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
	strcpy(client.name,temp);
	
	printf("비밀번호: ");
	scanf("%[^\n]",temp);
	getchar();
	client.password = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
	strcpy(client.password,temp);
	
	printf("주소: ");
	scanf("%[^\n]",temp);
	getchar();
	client.address = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
	strcpy(client.address,temp);

	printf("전화번호: ");
	scanf("%[^\n]",temp);
	client.phone_num = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
	strcpy(client.phone_num,temp);

	if((append_client(client) == Success))
	{
		printf("회원가입 되셨습니다.\n");
		file_write_client();
	}

	return ;
}


void Revise(void)
{
	int flag;
	printf("비밀번호, 주소, 전화번호 중 어떤것을 바꾸고 싶으십니까?\n");
	printf("비밀번호 = 1\n");
	printf("주소 = 2\n");
	printf("전화번호 = 3\n");
	scanf("%d",&flag);
	const Client *result = NULL;
	Client temp,temp2; 
	char buff[500] = {0},sub_buff[500] = {0},nu_ll[2] = {0};
	while(1){
	switch(flag){
		case 1 :
			if(get_client(my_ID,&result) == Success)
			{
				printf("바꿀 패스워드?");
				while(getchar() != '\n');
				scanf("%[^\n]",buff);
				getchar();
				strcpy(sub_buff,result -> password);
				temp.sch_num = result->sch_num;
				temp.name = (char *)malloc(sizeof(char) * (strlen(result->name) + 1));
				strcpy(temp.name ,result->name);
			
				temp.password = (char *)malloc(sizeof(char) * (strlen(buff) + 1));
				strcpy(temp.password,buff);
				temp.address = (char *)malloc(sizeof(char) * (strlen(result->address) + 1));
				strcpy(temp.address ,result->address);

				temp.phone_num = (char *)malloc(sizeof(char) * (strlen(result->phone_num) + 1));
				strcpy(temp.phone_num , result->phone_num);
				if(!strncmp(buff,nu_ll,1))
				{
					printf("입력은 한개이상입니다\n");
					return; 
				}
				if((flag = replace_client(result,temp)) == Success)
				{
					printf("변경 되었습니다.\n");
					return ;
				}
				else if (flag == Fail_No_Element)
				{
					printf("해당하는 구성요소가 없습니다\n");
					temp2.address = (char *)malloc(sizeof(char) * (strlen(temp.address)+1));
					strcpy(temp2.address,temp.address);
					temp2.password = (char *)malloc(sizeof(char) * (strlen(sub_buff)+1));
					strcpy(temp2.password,sub_buff);
					temp2.sch_num = temp.sch_num;
					temp2.name = (char *)malloc(sizeof(char) * (strlen(temp.name)+1));
					strcpy(temp2.name,temp.name);
					temp2.phone_num = (char *)malloc(sizeof(char) * (strlen(temp.phone_num)+1));
					strcpy(temp2.phone_num,temp.phone_num);
					flag = replace_client(&temp,temp2);
					return;
				}
				
			}
			else printf("잘못된 학번입니다.\n");
			break;
		case 2 :
			if(get_client(my_ID,&result) == Success)
			{
				printf("바꿀 주소?");
				while(getchar() != '\n');
				scanf("%[^\n]",buff);
				getchar();
				strcpy(sub_buff,result -> address);
				temp.sch_num = result->sch_num;
				temp.password = (char *)malloc(sizeof(char) * (strlen(result->password) + 1));
				strcpy(temp.password,result->password);
				temp.address = (char *)malloc(sizeof(char) * (strlen(buff)+1));
				strcpy(temp.address,buff);
				temp.phone_num = (char *)malloc(sizeof(char) * (strlen(result->phone_num) + 1));
				strcpy(temp.phone_num ,result->phone_num);
				temp.name = (char *)malloc(sizeof(char) * (strlen(result->name) + 1));
				strcpy(temp.name, result->name);
				if(!strncmp(buff,nu_ll,1))
				{
					printf("입력은 한개이상입니다\n");
					return; 
				}
				if((flag = replace_client(result,temp)) == Success)
				{
					printf("변경 되었습니다.\n");
					return ;
				}
				else if (flag == Fail_No_Element)
				{
					printf("해당하는 구성요소가 없습니다.\n");
					temp2.address = (char *)malloc(sizeof(char) * (strlen(sub_buff)+1));
					strcpy(temp2.address,sub_buff);
					temp2.password = (char *)malloc(sizeof(char) * (strlen(temp.password)+1));
					strcpy(temp2.password,temp.password);
					temp2.sch_num = temp.sch_num;
					temp2.name = (char *)malloc(sizeof(char) * (strlen(temp.name)+1));
					strcpy(temp2.name,temp.name);
					temp2.phone_num = (char *)malloc(sizeof(char) * (strlen(temp.phone_num)+1));
					strcpy(temp2.phone_num,temp.phone_num);
					flag = replace_client(&temp,temp2);
					return ;
				}
			}
			else printf("잘못된 학번입니다.\n");
			break;
		case 3 :
			if(get_client(my_ID,&result) == Success)
			{
				printf("바꿀 전화번호?");
				while(getchar() != '\n');
				scanf("%[^\n]",buff);
				getchar();
				strcpy(sub_buff,result -> phone_num);
				temp.sch_num = result->sch_num;
				temp.password = (char *)malloc(sizeof(char) * (strlen(result->password) + 1));
				strcpy(temp.password , result->password);
				temp.address = (char *)malloc(sizeof(char) * (strlen(result->address) + 1));
				strcpy(temp.address, result->address);
				temp.phone_num = (char *)malloc(sizeof(char) * (strlen(buff)+1));
				strcpy(temp.phone_num,buff);
				strcpy(sub_buff,result -> phone_num);
				temp.name = (char *)malloc(sizeof(char) * (strlen(result->name)+1));
				strcpy(temp.name ,result->name);
				if(!strncmp(buff,nu_ll,1))
				{
					printf("입력은 한개이상입니다\n");
					return; 
				}
				if((flag = replace_client(result,temp)) ==Success)
				{
					file_write_client();
					printf("변경되었습니다.\n");
					return ;
				}
				else if (flag == Fail_Two_Same_Value)
				{
					printf("같은 번호입니다\n");
					return ;
				}
				else if (flag == Fail_No_Element)
				{
					printf("해당하는 구성요소가 없습니다.");
					temp2.address = (char *)malloc(sizeof(char) * (strlen(temp.address)+1));
					strcpy(temp2.address,buff);
					temp2.password = (char *)malloc(sizeof(char) * (strlen(temp.password)+1));
					strcpy(temp2.password,temp.password);
					temp2.sch_num = temp.sch_num;
					temp2.name = (char *)malloc(sizeof(char) * (strlen(temp.name)+1));
					strcpy(temp2.name,temp.name);
					temp2.phone_num = (char *)malloc(sizeof(char) * (strlen(sub_buff)+1));
					strcpy(temp2.phone_num,sub_buff);
					flag = replace_client(&temp,temp2);
					return ;
				}
			}
			else printf("잘못된 학번입니다.\n");
			break;
		default : 
			printf("1,2,3 만 입력하세요 !!");
	}

		}	 
			
			

return; 

}

int Log_in()
{
	const Client * client = NULL;
	char buff[50];

	
	printf(">> 로그인 <<\n");
	while(getchar() != '\n');
	printf("학번: ");
	scanf("%[^\n]", buff);

	if (!strcmp(buff, ADMIN_ID))
		my_ID = -1;
	else
		my_ID = atoi(buff);
	while(getchar() != '\n');

	printf("비밀번호: ");
	scanf("%[^\n]", my_password);

	if (my_ID == -1 && !strcmp(my_password, ADMIN_PWD))
	{
		return Admin_menu();
	}
	else
		if (get_client(my_ID, &client) == Success && password2keys_on_client(NULL,my_password) != 0)
		{
			printf("로그인 되었습니다.");
			return Member_menu();
		}
		else	 
		{
			printf("로그인에 실패하였습니다.\n");
			return 0;
		}
}


