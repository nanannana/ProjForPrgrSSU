#include<stdio.h>
#include<stdlib.h>
<<<<<<< HEAD
=======
>>>>>>> upstream/master
#include"login.h"
#ifndef main
int main void(){
	int j, k=20162497;
	j = Sign_down(k);
	printf("%d",j);
	Sign_up();
	Revise(k);
	Sign_down(k);
	printf("%d",j);

	return 0;
	}
#endif
int Sign_down(int sch_num){
	int *book_nums = (int*)malloc(sizeof(int) * 40);
	int cnt;

	if ((cnt = sch_num2keys_on_borrow(book_nums,sch_num)) == 0)
	{
		remove_client(sch_num);
	}
	else return 0;
}


void Sign_up(void)
{
	int cnt;
	const Client *compare;
	Client client1;
	printf(">>회원 가입<<\n");
	printf("학번, 비밀번호, 이름, 주소, 전화번호를 입력하세요\n");
	printf("학번: \n");
	scanf("%d",&client1.sch_num);
	if (get_client(client1.sch_num,&compare) != Success)
	{
		printf("중복된 학번입니다");
		exit();
	}
	printf("비밀번호: \n");
	scanf("%s",client1.password);
	printf("이름: \n");
	scanf("%s",client1.name);
	printf("주소: \n");
	scanf("%s",client1.address);
	printf("전화번호: \n");
	scanf("%s",client1.phone_num);
	append_client(client1);

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
	Client temp = *result; 
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

int Log_in(int sch_num,char *password)
{
	const Client *client;
	int cnt = 0;
	int keys[20];
	if (get_client(sch_num,&client)==Success)
	{
		cnt++;
	};
	if (strcmp(client -> password,password)==0) 
	{
		cnt++;
	}
	if(cnt == 2){
	return Success;
	}
	else return 0;
	
}


int Log_out(void)
{
	return out;
}







