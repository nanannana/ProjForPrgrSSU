/*******************************************************
|						login.h                        |
|******************************************************|
  로그인, 회원가입, 회원 정보 관련된 함수는 이 파일에서
  다루게 됩니다.
  menu.c 파일에서 이 파일의 함수를 사용할 것으로 예상
  되오니, 가독성 좋은 프로그램 짜시길 바래요.

  login, sign_up, 회원 탈퇴 함수 등이 필요할 것 같습니다.
  menu 프로그래머와 상의하세요.
*******************************************************/

#include "manageData.h"
#include <string.h>

/*****************************************************************
 * enum path 로그인,가입 = 1 리턴   로그아웃, 회원탈퇴 = -1 리턴* 
 *****************************************************************/

 enum path
{
	 in = 1,
	 out = -1,
};



/*******************************************
* struct info
********************************************
* 회원가입 정보의 임시 저장소입니다
********************************************/

<<<<<<< HEAD
=======
struct sti
{
	int std_num;
	char *password;
	char *name;
	char *address;
	char *phone_n;
}info;
>>>>>>> upstream/master



/************************************************
 * Sign_up client에 회원가입 내용을 등록합니다.
 * 중복되는 학번 검사후 처리도 여기서 합니다.
 ************************************************/

void Sign_up(void)
{
	Client client1;
	printf(">>회원 가입<<\n");
	printf("학번, 비밀번호, 이름, 주소, 전화번호를 입력하세요\n");
<<<<<<< HEAD
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
=======
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

>>>>>>> upstream/master
	return ;
}





<<<<<<< HEAD
/*****************************************************************************************************
 * Sign_down 그냥 sign_up의 반대라 down이라 적었습니다 말그대로 회원탈퇴
 * 학번을 입력받아 대여중인 도서가 없으면 회원탈퇴시킵니다 
 *****************************************************************************************************/

//void Sign_down(int sch_num)
//{
//	if(

	
	
	
	
	
	
	
//	remove_client(sch_num);
//	return ;
//}
=======
/******************************************************************************
* Sign_down 그냥 sign_up의 반대라 down이라 적었습니다 말그대로 회원탈퇴
* book과 borrow구조체를 읽어들여 대여중인 도서가 없으면 회원탈퇴시킨다 
******************************************************************************/

void Sign_down(int k, int k)
{

	return ;
}
>>>>>>> upstream/master





/********************************************************************
 * Revise client 구조체를 받아서 학번 이름을 제외한 정보를 수정합니다
*********************************************************************/

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





/***********************************************************************
 * Login client에 있는 내용을 받아서 학번과 비밀번호가 일치하는지 확인후
 * 일치하면 1을 아니면 -1을 출력합니다
 ***********************************************************************/

int Log_in(int sch_num,const Client ** result)
{
	if(get_client(sch_num,result) == Success)
	{
	

	return in;
	}
	else return out;
}





/****************************************************************
 * Log_out 도서관 서비스 초기화면으로 이동합니다.
 ****************************************************************/
int Log_out(void)
{
	return out;
}




