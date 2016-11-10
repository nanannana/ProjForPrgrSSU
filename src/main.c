#include<stdio.h>
#include"fileIO.h"
#include"login.h"
#include"manageData.h"
#include"menu.h"

int main(void)
{
	file_read();

	// 리스트의 모든 값을 메모리에서 해제시킵니다.
	free_all_lists();
    return 0;
}
