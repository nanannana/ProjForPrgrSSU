#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileIO.h"
#include "manageData.h"
#include "menu.h"

extern List_Client *list_client;
extern List_Book * list_book;
extern List_Borrow *list_borrow;

int my_sch_num;
char my_password[50];

char s_temp_c[100];
int s_temp_i = 0;
int s_temp_l = 0;
int r_temp_i= 0;
char d_temp_c[100];
int d_temp_l = 0;
char m_temp_c[500];
char w_temp_c;

List_Book *list_book = NULL;

struct tm *bt;
struct tm *rt;

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
			case 3 : exite;

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
		if(i == 3,)
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
	if(Member_menu() == 0);
	{
		break;
	}

}






int Member_menu()
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
			case 4 : if(Withdraw() == 0)
					 {
						 return 0;
					 }
					 else
					 {
						 break;
					 }
			case 5 : return 0;
			case 6 : exit(0);

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
		if(i == 5)
		{
			break;
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
			case 1 : S_by_title(); break;
			case 2 : S_by_publisher(); break;
			case 3 : S_by_ISBN(); break;
			case 4 : S_by_author(); break;
			case 5 : S_total_Search(); break;
			case 6 : break;

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
		if(o == 6)
		{
			break;
		}
	}
}

void S_by_title()
{
	printf(">> 도서명 검색 <<\n");
	printf("도서명을 입력하세요 : ");
	gets(s_temp_c);

}

void S_by_publisher()
{
	printf(">> 출판사 검색 <<\n");
	printf("출판사명을 입력하세요 : ");
	gets(s_temp_c);

}

void S_by_ISBN()
{
	printf(">> ISBN 검색 <<\n");
	printf("ISBN을 입력하세요 : ");
	scanf("%d", &s_temp_l);
	get_book(s_temp_l, );

}

void S_by_author()
{
	printf(">> 저자명 검색\n");
	printf("저자명을  입력하세요 : ");
	gets(s_temp_c);
}

void S_total_Search()
{
	printf(">> 전체 검색 <<\n");
	printf("책번호\tISBN\t책이름\t출판사\t저자\t소장처\t대여가능여부");
	list_book -> current = list_book -> head;
	while(list_book -> current)
	{
		printf("%d %ld %s %s %s %s %c\n", list_book -> current -> book_num, list_book -> current -> ISBN, list_book -> current -> name, list_book -> current -> publisher, list_book -> current -> author, list_book -> current -> owner, list_book -> current -> borrow_Y_N);
		list_book -> current = list_book -> current -> next;

	}

}


void My_BB_list()//need to modify.(at if)
{
	int check = 0;
	printf(">>내 대여 목록 <<\n");

	list_borrow -> current = list_borrow -> head;
	while(list_borrow -> current)
	{
		list_book -> current = book_client 
			while(list_book -> current)
			{
				if(my_sch_num == (list_borrow -> current -> sch_num) && (strcmp((list_borrow -> current -> book_num, list_book -> current -> name))))
				{
					bt = list_borrow -> current -> borrow_day;
					rt = list_borrow -> current -> return_day;

					printf("도서번호\t도서명\t대여일자\t반납일자\n");	
					printf("%d %s %d/%d %d/%d\n" list_book -> current -> book_num, list_book -> current -> name, (bt -> mon) + 1, bt -> mday, (rt -> mon) + 1, rt -> mday);
					check = 1;
				}
				list_book -> current = list_book -> current -> next;
			}
	}
	if(check != 1)
	{
		printf("대여 목록이 존재하지 않습니다.\n");
	}
}


void Modi_my_info()//replace 함수?.. 
{
	printf(">> 개인정보 수정 <<\n");

	list_client -> current = list_client -> head;
	while(list_client -> current)
	{
		if((list_client -> current -> sch_num) == my_sch_num)
		{
			printf("수정할 정보를 입력하세요\n");

			printf("이름: ");
			scanf("%s", m_temp_c);
			list_clinet -> current -> name = (char *)malloc(sizeof(strlen(m_temp_c) + 1));
			strcpy(list_client -> current -> name, m_temp_c);

			printf("비밀번호: ");
			scanf("%s", m_temp_c);
			list_clinet -> current -> password = (char *)malloc(sizeof(strlen(m_temp_c) + 1));
			strcpy(list_client -> current -> password, m_temp_c);

			printf("주소: ");
			scanf("%[^\n]s", list_client -> current -> address);
			list_clinet -> current -> address = (char *)malloc(sizeof(strlen(m_temp_c) + 1));
			strcpy(list_client -> current -> address, m_temp_c);

			printf("연락처: ");
			scanf("%s", list_client -> current -> phone_num);
			list_clinet -> current -> phone_num = (char *)malloc(sizeof(strlen(m_temp_c) + 1));
			strcpy(list_client -> current -> phone_num, m_temp_c);

			file_write_client();

			printf("개인정보가 수정되었습니다.\n");

			break;
		}

		list_client -> current = list_client -> current -> next;
	}
}




int Withdraw() 
{
	printf(">> 회원 탈퇴 <<\n");
	list_client -> current = list_client -> head;
	while(list_client -> current)
	{
		if((list_clinet -> current -> sch_num) == my_sch_num)
		{
			list_borrow -> current = list_borrow -> head;
			while(list_borrow -> current)
			{
				if((list_borrow -> current -> sch_num) == my_sch_num)
				{
					printf("대여된 도서가 존재하여 탈퇴가 불가능합니다.\n");
					return 1;
				}
				else
				{
					printf("회원 탈퇴를 합니까? (탈퇴하시려면 Y입력) : ");
					scanf(" %c", &w_temp_c);
					if(w_temp_c == 'Y')
					{
						remove_clinet(my_sch_num);
						printf("탈퇴가 완료되었습니다.\n");
						return 0;
					}
					else
					{
						return 1;
					}

				}

				list_borrow -> current = list_borrow -> current -> next;
			}
		}
		list_client -> current = list_clinet -> current -> next;


	}
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
			case 1 : Register_book(); break;
			case 2 : Delete_book(); break;
			case 3 : Lend_book(); break;
			case 4 : Return_book(); break;
			case 5 : Search_books(); break;
			case 6 : Member_list(); break;
			case 7 : break;
			case 8 : exit(0);

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
		if(o == 7)
		{
			break;
		}
	}
}

void Register_book()////
{
	Client add;
	printf("도서명: ");
	scanf("%[^\n]s", add.name);
	printf("출판사: ");
	scanf("%[^\n]s", add.publisher);
	printf("저자명: ");
	scanf("%[^\n]s", add.author);
	printf("ISBN: ");
	scanf("%ld", &add.ISBN);
	printf("소장처: ");
	scanf("%[^/n]s", add.owner);

	append_book(


			}

			void Delete_book()////
			{
			int p;
			printf(">> 도서 삭제 <<");
			printf("1. 도서명 검색\t\t2. ISBN 검색\n");
			printf("번호를 선택하세요 : ");
			scanf("%d", &p);

			switch(p)
			{
			case 1 : D_by_title(); break;
			case 2 : D_by_ISBN(); break;

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
			}

			}

void D_by_title()////
{		
	printf("도서명을 입력하세요 : ");
	scanf("%s", d_temp_c);
}	

void D_by_ISBN()////
{
	printf("ISBN 값을 입력하세요 : ");
	scanf("%ld", &d_temp_l);
}



void Lend_book();////
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

void Return_book()////
{
	printf(">> 도서 반납 <<\n");
	printf("학번을 입력하세요 : ");
	scanf("%d", &r_temp_i);
	const struct borrow * ib = NULL;
	const struct book * ik = NULL;
	if (get_borrow(r_temp_i, &ib) == success)
	{
		printf("도서번호\t도서명\t대여일자\t반납일자\n");

		printf("%d %s %d/%d %d/%d\n", ret -> 

				printf("%d %s %d/%d %d/%d\n" list_book -> current -> book_num, list_book -> current -> name, (bt -> mon) + 1, bt -> mday, (rt -> mon) + 1, rt -> mday);
				c

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
				}

		void Search_name();////
		{
			printf("이름을 입력하세요 : ");
			scanf("%s", s_temp_c);
		}

		void Search_ID()
		{
			printf("학번을 입력하세요 : ");
			scanf("%d", &s_temp_i);
			const struct Client * picker = NULL;
			if(get_client(s_temp_i, &picker) == Success)
			{
				printf("학번\t이름\t주소\t전화번호\n");
				printf("%d\t%s\t%s\t%s\n", picker -> sch_num, picker -> name, picker -> address, picker -> phone_num);
			}
			else
			{
				printf("회원이 존재하지 않습니다.\n");
			}
		}


		void M_total_search()
		{
			list_client -> current = list_client -> head;
			printf("학번\t이름\t주소\t전화번호\n");
			while(list_client->current)
			{
				printf("%d\t%s\t%s\t%s\n", list_clinet -> current -> sch_num, list_client -> current -> name, list_client -> current -> address, list_client -> current -> phone_num);
				list_client -> current = list_client -> current -> next;
			}
		}




		int main()
		{
			init_all_list();
			get_all_file_data();
			Library_service();
			free_all_node();
			return 0;
		}	
