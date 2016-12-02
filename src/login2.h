void Log_in();


//로그인할 때 ID, password 입력 받음.
//ID는 my_ID, password는 my_password로 입력.
//먼저 ID가 admin 인지 아닌지 확인(admin 정보는 client 구조체에 이름으로 저장하는게 좋을듯.)
//admin이 아니라면 atoi(my_ID) 변환 후  list_clinet -> current -> sch_num 과 비교
//그 다음 admin, my_ID 의 비밀번호가 일치하는지 검사.
//검사 후 틀렸다면 함수종료 맞다면 admin 은 Admin_menu() 호출, my_ID(학생)은 Member_menu() 호출.
//만약, ID가 존재하지않으면 ID가 없다는 메시지 출력하고 함수 종료
//비밀번호도 마찬가지로 비밀번호가 틀렸다는 메시지를 출력하고 함수 종료
//
//int Member_menu(), int Admin_menu() 에서 리턴값 0 을 받으면 바로 함수 종료.
//
//void Log_in()
//{
//		int check = 1;
//		while(1)
//		{
//			if(check == 0)
//			{
//				return;
//			}
//
//
//			printf(">> 로그인 <<\n");
//		......
//		......
//			check = Member_menu();
//
//		.....
//		......
//		}
//}
//
void sign_in();

//아는 그대로 만들면 됨.




//탈퇴는 나중에 해도 됨.
