#ifndef _MENU_H_//헤드파일 중복 선언 방지
#define _MENU_H_
#include <stdio.h>

/// 프로그램의 본격적인 시작점입니다.
/// 이 함수를 시작으로 메뉴 출력을 포함한 기능이 실행되게 됩니다.
/// 0을 반환하며 정상적으로 종료합니다.
int start_proc(void);

//함수원형
void Library_service();

int Member_menu();

void Search_books();
void S_by_title();
void S_by_publisher();
void S_by_ISBN();
void S_by_author();
void S_total_Search();

void My_BB_list();
void Modi_my_info();
int Withdraw();

int Admin_nemu();
void Register_book();

void Delete_book();
void D_by_title();
void D_by_ISBN();
void delete_book(int *keys, int cnt);

void Lend_book();
void L_by_title();
void L_by_ISBN();
void Return_book();

void Member_list();
void Search_name();
void Search_ID();
void M_total_search();
#endif
