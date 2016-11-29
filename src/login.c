#include<stdio.h>
#include<stdlib.h>
#include"managedata.h"
#include"login.h"
void Sign_down(int sch_num){
	int* book_nums = (int*)malloc(sizeof(int) * List_Borrow->num_element);
	int cnt;
	Client *element = NULL;

	if ((cnt = book_num2keys(&book_nums,sch_num)) != 0){


}	


int main(void){
 	init_all_list(); 

 	get_all_file_data();

	free_all_node(); 
	return 0;
}

void Sign_up(void)
{
	Client client1;
	printf(">>회원 가입<<\n");
	printf("학번, 비밀번호, 이름, 주소, 전화번호를 입력하세요\n");
	printf("학번: \n");
	scanf("%d",&client1.sch_num);
	printf("비밀번호: \n");
	scanf("%s",client1.password);
	printf("이름: \n");
	scanf("%s",client1.name);
	printf("주소: \n");
	scanf("%s",client1.address);
	printf("전화번호: \n");
	scanf("%s",client1.phone_num);
	append_client(client1);
	printf("학번: ");
	scanf("%d",&info.std_num);
	printf("비밀번호: ");
	scanf("%d",info.password);
	printf("이름: ");
	scanf("%s",info.name);
	printf("주소: ");
	scanf("%s",info.address);
	printf("전화번호: ");
	scanf("%d",info.phone_n);

	append_something(info);

	return ;
}


int Revise(const Client *p_origin,int sch_num)
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
				temp = *result;
				printf("바꿀 패스워드?");
				scanf("%s",(*result).password);
				temp.password = (*result).password;
				Return_Flags flag;
				if((flag = replace_something(result,temp)) == Success)
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
				if((flag = replace_something(result,temp)) == Success)
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
				if((flag = replace_something(result,temp)) ==Success)
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

int Log_in(int sch_num,const Client ** result)
{
	if(get_client(sch_num,result) == Success)
	{
	

	return in;
	}
	else return out;
}


int Log_out(void)
{
	return out;

}






