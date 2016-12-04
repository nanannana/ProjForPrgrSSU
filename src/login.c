#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"menu.h"
#include"login.h"
int main(void)
{
	// 리스트를 사용할 수 있게 초기화합니다.
	init_all_list();

	// 파일을 읽어들여 전역변수 list를 할당합니다.
    get_all_file_data();

	// 본격적인 프로시저를 시작합니다.
    start_proc();

	// 끝날 때에는 리스트의 값을 파일로 저장시킵니다.
	file_write();
    
	// 리스트의 모든 값을 메모리에서 해제시킵니다.
    free_all_node();

    return 0;
}
void Sign_down(int sch_num){
	int keys[20];
	int cnt;
	

	if ((cnt = sch_num2keys_on_borrow(keys,sch_num)) == 0)
	{
		remove_client(sch_num);
	}
	
	return ;
}


void Sign_up(void)
{
	const Client *compare;
	Client *client, *temp;
	printf(">>회원 가입<<\n");
	printf("학번, 비밀번호, 이름, 주소, 전화번호를 입력하세요\n");
	int i;
	printf("학번: \n");
	scanf("%d",&(client ->sch_num));
	i = get_client(temp ->sch_num,&compare);

	if (i == Success)
	{
		printf("중복된 학번입니다");
		return;
	}
	scanf("%s",temp->name);
	client->name = (char *)malloc(sizeof(char) * (strlen(temp->name) + 1));
	strcpy(client->name,temp->name);
	
	scanf("%s",temp->password);
	client->password = (char *)malloc(sizeof(char) * (strlen(temp->password) + 1));
	strcpy(client->password,temp->password);

	scanf("%s",temp->address);
	client->address = (char *)malloc(sizeof(char) * (strlen(temp->address) + 1));
	strcpy(client->address,temp->address);

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
	int ID,check,i;
	const Client *client;
	extern char my_ID[30];
	extern char my_password[50];
	char admin[6] = {"admin"};
	ID = atoi(my_ID);
	while(1){
		printf("학번 입력");
		scanf("%s",my_ID);
		printf("패스워드 입력");
		scanf("%s",my_password);
		
		if(strcmp(my_ID,admin)==0){
			i = get_client(ID,&client);
			
			if (strcmp(client -> password,my_password)==0) 
				check = Admin_menu();
			else printf("잘못된 비번입니다");
			
		}
		else {
			if ((i = get_client(ID,&client))==Success)
			{
				if (strcmp(client -> password,my_password)==0) 
					check = Member_menu();
				else printf("잘못된 비번입니다");
			}
			else printf("잘못된 학번입니다");
			}
		if (check == 0)
			return;
		}
}


int Log_out(void)
{
	return out;
}







