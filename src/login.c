#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"login.h"
#ifndef main 
int main (void){
	int j, k=20162497;
	char password[20];
	j = Sign_down(k);
	printf("%d\n",j);
	Sign_up();
	Revise(k);
	Sign_down(k);
	printf("%d\n",j);
	scanf("%s",password);
	Log_in(k,password);

	return 0;
	}
#endif
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
	Client *compare;
	Client *client;
	int i;
	printf(">>회원 가입<<\n");
	printf("학번, 비밀번호, 이름, 주소, 전화번호를 입력하세요\n");
	printf("학번: \n");
	&(client -> sch_num) = (int*)malloc(sizeof(int));
	scanf("%d",&(client -> sch_num))
	if (get_client(client -> sch_num,&compare) != Success)
	{
		printf("중복된 학번입니다");
		return;
	}
	printf("이름을 입력하세요\n");
	scanf("%s",compare -> name);
	i = strlen(compare -> name);
	client -> name = (char*)malloc((i+1)*sizeof(char))
	strcpy(client -> name, compare -> name);
	printf("비밀번호를 입력하세요\n");
	scanf("%s",compare -> password);
	i = strlen(compare -> password);
	client -> password = (char*)malloc((i+1)*sizeof(char))
	strcpy(client -> password, compare -> password);
	printf("주소를 입력하세요\n");
	scanf("%s",compare -> address);
	i = strlen(compare -> address);
	client -> address = (char*)malloc((i+1)*sizeof(char))
	strcpy(client -> address, compare -> address);
	printf("전화번호를 입력하세요\n");
	scanf("%s",compare -> phone_num);
	i = strlen(compare -> phone_num);
	client -> phone_num = (char*)malloc((i+1)*sizeof(char))
	strcpy(client -> phone_num, compare -> phone_num);
	append_client(client);


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
	char *my_ID;
	const Client *client;
	char *my_password;
	scanf("%s",&my_ID);
	scanf("%s",my_password);
	if(strcmp(my_ID,admin)==0){
		if (get_client(my_ID,&client)==Success)
		{
			if (strcmp(client -> password,my_password)==0) 
			check = Admin_menu();
		}
	}
	else {
		ID = atoi(my_ID);
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







