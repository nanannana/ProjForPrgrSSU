#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manageData.h"
#include "menu.h"

extern List_Client *list_client;
extern List_Book * list_book;
extern List_Borrow *list_borrow;

int my_sch_num;
char my_password[50];




void Library_service()
{
	//int i;
	while(1)
	{
		int n;
		printf("***TEST***\n");
		printf("1. 회원 메뉴\t2. 관리자 메뉴\t3. 프로그램 종료\n");
		printf("번호를 선택하세요: ");
		scanf("%d", &n);
		switch (n)
		{
			case 1 : Member_menu(); break;
			case 2 : Admin_menu(); break;
			case 3 : break;

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
	}
}
/*
void Sign_up()
{

}

void Log_in()
{
	   if(mem)
	   {
	   if(Member_menu() == 0)
	   {
	   break;
	   }
	   }
	   if(adm)
	   {
	   if(Admin_nemue() == 0)
	   {
	   break;
	   }


	   }
}


*/

int Member_menu()
{
	int m;
	while(1)
	{
		printf(">> 회원 메뉴 <<\n");
		printf("1. 도서 검색\t\t2. 내 대여 목록\n3. 개인정보 수정\t\t 4.회원 탈퇴\n5. 로그아웃\t\t6. 프로그램 종료\n");
		printf("번호를 선택하세요: ");
		scanf("%d", &m);
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
			case 6 : free_all_node(); exit(0);

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
		if(m == 5)
		{
			break;
		}

	}
	return 1;
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
	char s_temp_c[100];
	printf(">> 도서명 검색 <<\n");
	printf("도서명을 입력하세요 : ");
	scanf("%s", s_temp_c);
	int keys[20];
	int cnt, i, cy=0;
	char yn = 'Y';
	if((cnt = name2keys_on_book(keys, s_temp_c)) != 0)
	{
		const Book * result = NULL;
		if(get_book(keys[0], &result) == Success)
		{
			for(i = 0; i < cnt; i++)
			{
				get_book(keys[i], &result);
				if(result -> borrow_Y_N == 'Y')
				{
					cy++;
				}
			}

			if(cy == 0)
			{
				yn = 'N';
			}

			printf(">> 검색 결과 <<\n");
			printf("도서명: %s\n출판사: %s\n저자명:%s\nISBN: %ld\n소장처: %s\n",\
					s_temp_c, result -> publisher, result -> author, result -> ISBN, result -> owner);
			printf("대여가능 여부 : %c(%d/%d)\n", yn, cy,cnt);
		}
		else
		{
			printf("도서 찾기 실패. \n");
		}
	}
	else
	{
		printf("해당 도서는 존재하지않습니다.\n");
	}


}

void S_by_publisher()
{
	char s_temp_c[100];
	printf(">> 출판사 검색 <<\n");
	printf("출판사명을 입력하세요 : ");
	scanf("%s", s_temp_c);
	int keys[100];
	int cnt_r,cnt_g, i;

	int ratio[50][2];
	if((cnt_r = get_ratio_books_from_publisher(ratio, s_temp_c)) != 0)
	{
		if((cnt_g = publisher2keys_on_book(keys, s_temp_c)) != 0)
		{
			printf(">> 검색 결과 <<\n");
			const Book * result = NULL;
			for(i=0; i<cnt_g; i++)
			{
				if(get_book(keys[i], &result) == Success)
				{
					printf("도서명: %s\n출판사: %s\n저자명: %s\nISBN: %ld\n소장처: %s\n대여가능 여부: %c(%d/%d)", result -> name, result -> publisher, result -> author, result -> ISBN, result -> owner, result -> borrow_Y_N, ratio[i][0], ratio[i][1]);
				}
				else
				{
					printf("Failed to get book info\n");
				}
			}
		}
		else
		{
			printf("Failed to get book list\n");
		}
	}
	else
	{
		printf("해당 출판사의 도서는 존재하지 않습니다.\n");
	}

}


void S_by_ISBN()
{
	int long s_temp_l;
	printf(">> ISBN 검색 <<\n");
	printf("ISBN을 입력하세요 : ");
	scanf("%ld", &s_temp_l);
	int keys[20];
	int cnt, i, cy=0;
	char yn = 'Y';

	if((cnt = ISBN2keys_on_book(keys, s_temp_l)) != 0)
	{
		const Book * result = NULL;
		if(get_book(keys[0], &result) == Success)
		{
			for(i = 0; i< cnt; i++)
			{
				if(get_book(keys[i], &result) == Success)
				{
					if((result -> borrow_Y_N) == 'Y')
					{
						cy++;
					}

					if(cy == 0)
					{
						yn = 'N';
					}

					printf(">> 검색 결과 <<\n");
					printf("도서명: %s\n출판사: %s\n저자명:%s\nISBN: %ld\n소장처: %s\n",\
							result -> name, result -> publisher, result -> author, result -> ISBN, result -> owner);
					printf("대여가능 여부: %c(%d/%d)\n", yn, cy, cnt);
				}
				else
				{
					printf("Failed to read book info\n");
				}
			}
		}
		else
		{
			printf("일치하는 ISBN을 가진 도서가 존재하지않습니다.\n");
		}
	}

}

void S_by_author()
{
	char s_temp_c[100];
	printf(">> 저자명 검색 <<\n");
	printf("저자명을 입력하세요 : ");
	scanf("%s", s_temp_c);
	int keys[100];
	int cnt_r,cnt_g, i;

	int ratio[50][2];
	if((cnt_r = get_ratio_books_from_author(ratio, s_temp_c)) != 0)
	{
		if((cnt_g = author2keys_on_book(keys, s_temp_c)) != 0)
		{
			printf(">> 검색 결과 <<\n");
			const Book * result = NULL;
			for(i=0; i<cnt_g; i++)
			{
				if(get_book(keys[i], &result) == Success)
				{
					printf("도서명: %s\n출판사: %s\n저자명: %s\nISBN: %ld\n소장처: %s\n대여가능 여부: %c(%d/%d)", result -> name, result -> publisher, result -> author, result -> ISBN, result -> owner, result -> borrow_Y_N, ratio[i][0], ratio[i][1]);
				}
				else
				{
					printf("Failed to get book info\n");
				}
			}
		}
		else
		{
			printf("Failed to get book list\n");
		}
	}
	else
	{
		printf("해당 출판사의 도서는 존재하지 않습니다.\n");
	}

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
	int keys[20];
	int cnt, i;
	const Book *  Binfo = NULL;
	const Borrow * result = NULL;
	struct tm *bt;
	struct tm *rt;
	char day[7][15] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};

	//int check = 0;
	printf(">>내 대여 목록 <<\n");

	if((cnt = (sch_num2keys_on_borrow(keys, my_sch_num))) != 0)
	{
		printf(">> 회원의 대여 목록 <<\n");
		for(i = 0; i < cnt; i++)
		{
			if(get_borrow(keys[i], &result) == Success)
			{
				const time_t BT = result -> borrow_day;
				const time_t RT = result -> return_day;
				bt = localtime(&BT);
				rt = localtime(&RT);

				if(get_book(keys[i], &Binfo) == Success)
				{
					printf("도서번호: %d\n도서명: %s\n대여일자: %d년 %d월 %d일 %s\n 반납일자: %d년 %d월 %d일 %s",\
							result -> book_num, Binfo -> name, bt -> tm_year + 1900, bt -> tm_mon + 1, bt -> tm_mday, day[bt -> tm_yday], rt -> tm_year + 1900, (rt -> tm_mon) + 1, rt -> tm_mday, day[rt -> tm_yday]);

				}
				else
				{
					printf("Failed to read book info\n");
				}
			}


			else
			{
				printf("Failed to read borrow list\n");

			}
		}
	}
	else
	{
		printf("대여 목록이 존재하지 않습니다.\n");
	}
}

/*list_borrow -> current = list_borrow -> head;
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
  */


void Modi_my_info()//replace 함수?.. 
{
	char m_temp_c[100];
	printf(">> 개인정보 수정 <<\n");

	list_client -> current = list_client -> head;
	while(list_client -> current)
	{
		if((list_client -> current -> sch_num) == my_sch_num)
		{
			printf("수정할 정보를 입력하세요\n");

			printf("이름: ");
			scanf("%s", m_temp_c);
			list_client -> current -> name = (char *)malloc(sizeof(strlen(m_temp_c) + 1));
			strcpy(list_client -> current -> name, m_temp_c);

			printf("비밀번호: ");
			scanf("%s", m_temp_c);
			list_client -> current -> password = (char *)malloc(sizeof(strlen(m_temp_c) + 1));
			strcpy(list_client -> current -> password, m_temp_c);

			printf("주소: ");
			scanf("%[^\n]s", list_client -> current -> address);
			list_client -> current -> address = (char *)malloc(sizeof(strlen(m_temp_c) + 1));
			strcpy(list_client -> current -> address, m_temp_c);

			printf("연락처: ");
			scanf("%s", list_client -> current -> phone_num);
			list_client -> current -> phone_num = (char *)malloc(sizeof(strlen(m_temp_c) + 1));
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
	int w_temp_i;
	printf(">> 회원 탈퇴 <<\n");
	list_client -> current = list_client -> head;
	while(list_client -> current)
	{
		if((list_client -> current -> sch_num) == my_sch_num)
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
					w_temp_i = getchar();
					if(w_temp_i == 'Y')
					{
						remove_client(my_sch_num);
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
		list_client -> current = list_client -> current -> next;
	}
	return -1;
}


int Admin_menu()
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
			case 7 : return 0;
			case 8 : free_all_node(); exit(0);

			default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
		}
	}
}

void Register_book()
{
	Book *Btemp = NULL;
	Book add;
	Btemp = &add;
	int Y_N;

	char input[30];
	printf("도서명: ");
	scanf("%[^\n]s", input);
	Btemp -> name = (char *)malloc(sizeof(char) * (strlen(input) + 1));
	strcpy(Btemp -> name, input);

	printf("출판사: ");
	scanf("%[^\n]s", input);
	Btemp -> publisher = (char *)malloc(sizeof(char) * (strlen(input) +1));
	strcpy(Btemp -> publisher, input);

	printf("저자명: ");
	scanf("%[^\n]s", input);
	Btemp -> author = (char *)malloc(sizeof(char) * (strlen(input)+1));
	strcpy(Btemp -> author, input);

	printf("ISBN: ");
	scanf("%ld", &add.ISBN);

	printf("소장처: ");
	scanf("%[^/n]s", input);
	Btemp -> owner = (char *)malloc(sizeof(char) * (strlen(input) +1));
	strcpy(Btemp -> owner, input);

	add.book_num = ++(list_book -> last_book_num);
	add.borrow_Y_N = 'Y';


	printf("등록하시겠습니까? (등록하려면 Y입력) ");
	Y_N = getchar();
	if(Y_N == 'Y')
	{
		add.book_num = ++(list_book -> last_book_num);
		add.borrow_Y_N = 'Y';
		if(append_book(add) == Success)
		{
			printf("도서등록이 완료되었습니다.\n");
		}
		else
		{
			printf("도서등록을 실패하였습니다.\n");
			list_book -> last_book_num = (list_book -> last_book_num);
		}
	}
}




void Delete_book()
{
	int p;
	printf(">> 도서 삭제 <<");
	printf("1. 도서명 검색\t\t2. ISBN 검색\n");
	printf("검색 번호를 입력하세요: ");
	scanf("%d", &p);

	switch(p)
	{
		case 1 : D_by_title(); break;
		case 2 : D_by_ISBN(); break;

		default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
	}

}

void D_by_title()
{
	char d_temp_c[50];
	printf("도서명을 입력하세요 : ");
	scanf("%s", d_temp_c);
	int keys[20];
	int cnt;
	if((cnt = name2keys_on_book(keys, d_temp_c)) != 0)
	{
		delete_book(keys, cnt);
	}
	else
	{
		printf("존재하지 않는 도서명입니다.\n");

	}	
}

void D_by_ISBN()
{
	int long d_temp_l;
	printf("ISBN 값을 입력하세요 : ");
	scanf("%ld", &d_temp_l);
	int keys[20];
	int cnt;

	if((cnt = ISBN2keys_on_book(keys, d_temp_l)) != 0)
	{
		delete_book(keys, cnt);
	}
	else
	{
		printf("존재하지 않는 도서명입니다.\n");
	}
}	



void delete_book(int *keys, int cnt)
{
	const Book * result = NULL;
	int innum;
	int i;
	if(get_book(keys[0], &result) == Success)
	{
		printf(">> 검색 결과 <<\n");
		printf("도서번호: ");
		printf("%d(삭제 가능 여부 : %c)", result -> book_num, result -> borrow_Y_N);
		for(i = 1; i < cnt; i++)
		{
			if(get_book(keys[i], &result) == Success)
			{
				{
					printf(", %d(삭제 가능 여부 : %c)", result -> book_num, result -> borrow_Y_N);
				}
			}
		}
	}
	printf("도서명: %s\n출판사: %s\n저자명: %s\nISBN: %ld\n소장처: %s\n", result  -> name, result -> publisher, result -> author, result -> ISBN, result -> owner);

	printf("삭제할 도서의 번호를 입력하세요: ");
	scanf("%d", &innum);
	if(get_book(innum, &result) == Success)
	{
		if((result -> borrow_Y_N) == 'Y')
		{
			remove_book(innum);
			printf("도서가 삭제되었습니다.\n");
		}
		else if((result -> borrow_Y_N) == 'N')
		{
			printf("이 도서는 삭제할 수 없습니다.\n");
		}
	}
}


void Lend_book()
{
	int p;
	printf(">> 도서 대여 <<\n");
	printf("1. 도서명 검색\t\t2. ISBN 검색\n");
	printf("번호를 선택하세요: ");
	scanf("%d", &p);

	switch (p)
	{
		case 1 : L_by_title(); break;
		case 2 : L_by_ISBN(); break;
		default : printf("잘못 입력했습니다. 다시 입력해 주세요.");
	}
}

void L_by_title()
{
	char l_temp_c[100];
	int sch_id, book_n;
	int YorN;
	printf("도서명을 입력하세요: ");
	scanf("%s", l_temp_c);
	int keys[20];
	int cnt, i;
	if((cnt = name2keys_on_book(keys, l_temp_c)) != 0)
	{
		const Book * result = NULL;
		Borrow btemp;
		Borrow * binput = &btemp;
		if(get_book(keys[0], &result) == Success)
		{
			printf(">>검색 결과 <<\n");
			for(i = 0; i<cnt; i++)
			{
				if(get_book(keys[i], &result) == Success)
				{
					printf("도서번호: %d(대여가능 여부 : %c)\n도서명: %s\n출판사: %s\n저자명: %s\nISBN: %ld\n소장처: %s\n\n", \
							result -> book_num, result -> borrow_Y_N, result -> name, \
							result -> publisher, result -> author, result -> ISBN, result -> owner);
				}
			}
			printf("학번을 입력하세요: ");
			scanf("%d", &sch_id);
			binput -> sch_num = sch_id;

			printf("도서번호를 입력하세요: ");
			scanf("%d", &book_n);
			binput -> book_num = book_n;

			printf("이 도서를 대여합니까? ");
			YorN = getchar();
			if(YorN == 'Y');
			{
				struct tm *t;
				time_t now;
				now  = time(NULL);
				t = localtime(&now);
				binput -> borrow_day = now;
				if(( t -> tm_wday) == 0)
				{
					binput -> return_day = (now +  2678400);
				}
				else
				{
					binput -> borrow_day = (now  + 2592000);
				}

				if(get_book(book_n, &result) == Success)
				{

					Book modi = *result;
					/////////////const 포인터임 바꿔줘야함 append 라던가
					modi.borrow_Y_N = 'N';
					Return_Flags flag;

					if((flag = replace_book(result, modi)) == Success)
					{
						printf("도서가 대여 되었습니다.\n");
					}
					else if(flag == Fail_Two_Same_Value)
					{
						printf("Fail. there is same value\n");
					}
					else  if(flag == Fail_No_Element)
					{
						printf("There is no element\n");
					}
				}
				else
				{
					printf("failed finding book.\n");
				}
			}
		}
	}
}

void L_by_ISBN()
{
	int sch_id, book_n;
	int YorN;
	long int l_temp_l;
	int keys[20];
	int cnt, i;
	Borrow *btemp = NULL;
	Borrow add;
	btemp = &add;
	const Book * result = NULL;

	printf("ISBN을 입력하세요: ");
	scanf("%ld", &l_temp_l);
	if((cnt = ISBN2keys_on_book(keys, l_temp_l)) == Success)
	{
		printf(">> 검색 결과 <<\n");
		for(i = 0; i < cnt; i++)
		{
			if(get_book(keys[i], &result) == Success)
			{
				printf("도서번호: %d(대여가능 여부 : %c)\n도서명: %s\n출판사: %s\n저자명: %s\nISBN: %ld\n소장처: %s\n\n", \
						result -> book_num, result -> borrow_Y_N, result -> name, \
						result -> publisher, result -> author, result -> ISBN, result -> owner);
			}
			else
			{
				printf("Failed to read book list\n");

			}
		}
		printf("학번을 입력하세요: ");
		scanf("%d", &sch_id);
		btemp -> sch_num = sch_id;

		printf("도서번호를 입력하세요: ");
		scanf("%d", &book_n);
		btemp -> book_num = book_n;

		printf("이 도서를 대여합니까? ");
		YorN = getchar();
		if(YorN == 'Y');
		{
			struct tm *t;
			time_t now;
			now  = time(NULL);
			t = localtime(&now);
			btemp -> borrow_day = now;
			if(( t -> tm_wday) == 0)
			{
				btemp -> return_day = (now +  2678400);
			}
			else
			{
				btemp -> borrow_day = (now  + 2592000);
			}

			if(get_book(book_n, &result) == Success)
			{
				Book modi = *result;
				modi.borrow_Y_N = 'N';
				Return_Flags flag;

				if((flag = replace_book(result, modi)) == Success)
				{
					printf("도서가 대여 되었습니다.\n");
				}
				else if(flag == Fail_Two_Same_Value)
				{
					printf("Fail. there is same value\n");
				}
				else  if(flag == Fail_No_Element)
				{
					printf("There is no element\n");
				}
			}
			else
			{
				printf("Failed to read book info\n");
			}
		}
	}
	else
	{
		printf("Failed to convert\n");

	}
}


void Return_book()////
{
	int r_temp_i;
	int keys[20];
	int cnt, i;
	char day[7][15] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
	const Borrow *result = NULL;
	const Book * Binfo = NULL;
	struct tm *bt;
	struct tm *rt;
	int book_n;
	char YorN;

	printf(">> 도서 반납 <<\n");
	printf("학번을 입력하세요 : ");
	scanf("%d", &r_temp_i);

	if((cnt = sch_num2keys_on_borrow(keys, r_temp_i)) != 0)
	{
		printf(">> 회원의 대여 목록 <<\n");
		for(i = 0; i < cnt; i++)
		{
			if(get_borrow(keys[i], &result) == Success)
			{
				const time_t BT = result -> borrow_day;
				const time_t RT = result -> return_day;
				bt = localtime(&BT);
				rt = localtime(&RT);

				if(get_book(keys[i], &Binfo) == Success)
				{
					printf("도서번호: %d\n도서명: %s\n대여일자: %d년 %d월 %d일 %s\n 반납일자: %d년 %d월 %d일 %s",\
							result -> book_num, Binfo -> name, bt -> tm_year + 1900, bt -> tm_mon + 1, bt -> tm_mday, day[bt -> tm_yday], rt -> tm_year + 1900, rt -> tm_mon + 1, rt -> tm_mday, day[rt -> tm_yday]);

					printf("반납할 도서번호를 입력하세요: ");
					scanf("%d", &book_n);

					printf("도서 반납처리를 할까요? ");
					scanf("%c", &YorN);

					if(YorN == 'Y');
					{
						if(remove_borrow(book_n) == Success)
						{
							printf("반납이 완료되었습니다.\n");
						}
						else
						{
							printf("반납 실패 (Fail_No_element)\n");
						}
					}

				}

				else
				{
					printf("Failed to read book info\n");
				}
			}
			else
			{
				printf("Failed to read borrow list\n");

			}
		}
	}
	else
	{
		printf("Failed to convert");
	}
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

void Search_name()
{
	char s_temp_c[30];
	printf(">> 이름 검색 <<\n");
	printf("이름을 입력하세요 : ");
	scanf("%s", s_temp_c);
	int keys[20];
	int cnt, i;
	if((cnt = name2keys_on_client(keys, s_temp_c)) != 0)
	{
		const Client * result = NULL;
		printf(">> 회원 목록 <<\n");
		for(i = 0; i < cnt; i++)
			if(get_client(keys[i], &result) == Success)
			{
				printf("학번: %d\n이름: %s\n주소: %s\n전화번호: %s\n", result -> sch_num, result -> name, result -> address, result -> phone_num);
			}
			else
			{
				printf("Failed to get client info\n");
			}
	}
	else
	{
	printf("존재하지 않는 이름입니다.\n");
	}

}



void Search_ID()
{
	int s_temp_i;
	printf("학번을 입력하세요 : ");
	scanf("%d", &s_temp_i);
	const Client * picker = NULL;
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
		printf("%d\t%s\t%s\t%s\n", list_client -> current -> sch_num, list_client -> current -> name, list_client -> current -> address, list_client -> current -> phone_num);
		list_client -> current = list_client -> current -> next;
	}
}




int start_proc()
{
	Library_service();
	return 0;
}
