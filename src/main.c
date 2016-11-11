#include<stdio.h>
#include"fileIO.h"
#include"login.h"
#include"manageData.h"
#include"menu.h"

int main(void)
{
	//파일을 읽어들여 전역변수 list를 할당합니다.
    file_read();

	// 본격적인 프로시저를 시작합니다.
    start_proc();

    // 리스트의 모든 값을 메모리에서 해제시킵니다.
    free_all_lists();
    return 0;
}
