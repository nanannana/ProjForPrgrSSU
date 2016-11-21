#include <stdio.h>
#include "fileIO.h"
#include "manageData.h"


char s_temp_c[100];
int s_temp_i = 0;
int r_temp_i= 0;

void Library_service()
{
	int i;
	while(1)
	{
		printf(">>도서관 서비스<<\n");
		printf("1. 회원 가입\t2. 로그인\t3. 프로그램 종료\n");
		printf("번호를 선택하세요: ");
		scanf("%d", &n);
		switch (n)
		{
			case 1 : Sign_up(); break;
			case 2 : Log_in(); break;
			case 3 : break;

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
		if(i == 3)
		{
			break;
		}
	}
}

void Sign_up()
{

}

void Log_in()
{

}






void Member_menu()
{
	int m;
	while(1)
	{
		printf(">> 회원 메뉴 <<\n");
		printf("1. 도서 검색\t\t2. 내 대여 목록\n3. 개인정보 수정\t\t 4.회원 탈퇴\n5. 로그아웃\t\t6. 프로그램 종료\n");
		printf("번호를 선택하세요: ");
		scanf("%d", m);
		switch (m)
		{
			case 1 : Search_books(); break;
			case 2 : My_BB_list(); break;//My borrowed books list
			case 3 : Modi_my_info(); break;
			case 4 : Withdraw(); break;
			case 5 : break;
			case 6 : break;

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
		if(i == 5)
		{
			break;
		}
		else if(i == 6)
		{
			return -1;
		}
	}
}






void Search_books()
{
	int o;
	while(1)
	{
		printf(">> 도서 검색 <<\n");
		printf("1. 도서명 검색\t\t2. 출판사 검색\n3. ISBN 검색\t\t4. 저자명 검색\n5. 전체 검색\t\t6. 이전메뉴\n");
		printf("번호를 선택하세요: ");
		scanf("%d", &o);

		switch(o)
		{
			case 1 : By_Title(); break;
			case 2 : By_publisher(); break;
			case 3 : By_ISBN(); break;
			case 4 : By_Author(); break;
			case 5 : Total_Search(); break;
			case 6 : break;

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
		if(o == 6)
		{
			break;
		}
	}
}

void By_title()
{
	printf("도서명을 입력하세요 : ");
	gets(s_temp_c);

}

void By_publisher()
{
	printf("출판사명을 입력하세요 : ");

}

void By_ISBN()
{
	printf("ISBN을 입력하세요 : ");
	scanf("%d", &s_temp_i);
}

void By_author()
{
	printf("저자명을  입력하세요 : ");
	gets(s_temp_c);
}

void Total_Search()
{
	printf("책번호\tISBN\t책이름\t저자\t소장처\t대여가능여부");

}

	
void My_BB_list()
{

}

void Modi_my_info()
{

}

void Withdraw()
{

}
void Admin_menu()
{
	int o;
	while(1)
	{
		printf(">> 관리자  메뉴 <<\n");
		printf("1. 도서 등록\t2. 도서 삭제\n3. 도서 대여\t4. 도서 반납\n5. 도서 검색\t6. 회원 목록\n7. 로그아웃\t8. 프로그램 종료\n");
		scanf("%d", &o);

		switch(o)
		{
			case 1 : Register_book();
			case 2 : Delete_book();
			case 3 : Lend_book();
			case 4 : Return_book();
			case 5 : Search_books();
			case 6 : Member_list();
			case 7 : break;
			case 8 : break;

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
		if(o == 7)
		{
			break;
		}
		else if(o == 8)
		{
			return -1;
		}
	}
}

void Register_book()
{

}

void Delete_book()
{
	int p;
	printf(">> 도서 삭제 <<");
	printf("1. 도서명 검색\t\t2. ISBN 검색\n");
	printf("번호를 선택하세요 : ");
	scanf("%d", &p);
	
	switch(p)
	{
		case 1 : By_title(); break;
		case 2 : By_ISBN(); break;

		default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
	}

}

void Lend_book();
{
	int p;
	printf(">> 도서 대여 <<\n");
	printf("1. 도서명 검색\t\t2. ISBN 검색\n");
	printf("번호를 선택하세요: ");
	scanf("%d", &p);

	switch (p)
	{
		case 1 : By_title(); break;
		case 2 : By_ISBN(); break;
		default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
	}
}

void Return_book()
{
	printf("학번을 입력하세요 : ");
	scanf("%d", &r_temp_i);

}

void Member_list()
{
	while(1)
	{
		int  p;
		printf(">> 회원 목록<<\n");
		printf("1. 이름 검색\t2. 학번 검색\n3. 전체 검색\t4. 이전 메뉴\n");
		printf("번호를 선택하세요: ");
		scanf("%d", &p);

		switch (p)
		{
			case 1 : Search_name();
			case 2 : Search_ID();
			case 3 : M_total_search();
			case 4 : break; 

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
	}



