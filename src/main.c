#include"fileIO.h"
#include"login.h"
#include"manageData.h"
#include"menu.h"


/// 프로그램 시작점
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
