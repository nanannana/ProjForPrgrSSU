	Success = 1,					// 성공했을 때 반환합니다. 비교할 때 반드시 이 값과 비교해야 성공함을 알 수 있습니다. 
	Fail_Two_Same_Value = -1, 		// 같아서는 안되는 값이 두 개 이상 같을 때 반환합니다.
	Fail_No_Element = -2			// 해당하는 원소가 존재하지 않을 경우 반환합니다.
} Return_Flags;

/***********************************************************************
  int append_something(struct something sth)
  이 함수는 전역변수로 선언된 구조체 리스트에 입력된 구조체를 추가합니다.
  이 함수들은 그저 간단하게 추가만 하는 역할만 맡는 것이 아니라,
  학번 순서대로 제자리에 맞추어 삽입(정렬은 이 때문에 필요하지 않습니다)
  학번(도서번호) 충돌 판단 및 명세서에 쓰여 있는대로(1 - 9), 
  리스트에 추가 후 바로 파일쓰기 함수 호출 등을 담당하고 있습니다.

  동적할당은 이 함수내에서 일어납니다. 
  파일의 저장도 이 함수내에서 일어납니다.
  따라서 그냥 구조체만 넘겨주시면 됩니다.

  반환 가능 값 : 
  Success
  Fail_Two_Same_Value
***********************************************************************/

int append_client(Client client);

int append_book(Book book);

int append_borrow(Borrow borrow);

/***********************************************************************
  int remove_something(int some_key)
  이 함수는 특정 원소를 결정할 수 있는 키(학번, 도서번호)를 가지고,
  그 원소를 찾아내 메모리를 해제한 후, 끊어진 리스트를 다시 연결시킵니다.

  리스트에 있는 원소삭제는 이 함수를 통해서만 일어나야 합니다.
  그 외의 경우엔 불허합니다.

  파일의 저장은 자동으로 이 함수 내에서 처리합니다.

  반환 가능 값 : 
  Success
  Fail_No_Element
***********************************************************************/

int remove_client(int sch_num);

int remove_book(int book_num);

int remove_borrow(int book_num);

/***********************************************************************
  int get_something(int some_key, const struct something ** sth)
  이 함수는 특정 원소를 결정할 수 있는 키(학번, 도서번호)를 가지고,
  그 원소를 찾아내, const struct something ** sth가 가리키는
  주소에 집어넣습니다.

  만약 원소를 출력하고 싶다면 이 함수를 이용하면 됩니다.
  만약 원소를 변경하고 싶다면 이 함수로 받아온 포인터를
  변수에 할당하고 수정한 후, replace_something 함수를 이용하여 주십시오.
  굳이 const 포인터를 반환하고 replace함수를 따로 두는 이유는
  key 충돌 문제, 리스트가 변경되었음에도 불구하고 저장을 하지 않을 수 있는
  문제를 해결하기 위함입니다.

  const struct something * sth = NULL;
  if (get_something(4, &sth) == success)
  {
  	printf("출력: %d \n", sth->first_one);
  }
  else
  //실패

  반환 가능 값 : 
  Success
  Fail_No_Element
***********************************************************************/

int get_client(int sch_num, const Client ** result);

int get_book(int book_num, const Book ** result);

int get_borrow(int book_num, const Borrow ** result);

/***********************************************************************
  int replace_something(const struct something* const p_origin, struct something sth)
  이 함수는 존재하는 구조체(p_origin)를 변경하고자 하는 구조체로 바꿉니다.
  굳이 번거롭게 이 함수를 쓰는 이유는, 양립 불가능한 데이터 중복 확인(학번 등)
  변경 후 파일 저장 (잊어버릴 가능성)을 고려하여 사용합니다.
  일반적인 사용 방법은 다음과 같습니다.

  const struct something * sth = NULL;
  if (get_something(2, &sth) == success)
  { // 찾는데 성공했다면
  	struct something temp = *sth;
  	temp.first_one = 2; //내용 변경
	Return_Flags flag;

  	if ((flag = replace_something(sth, temp)) == Success)
  	// 변환 성공
  	else if (flag == Fail_Two_Same_Value)
  	// 실패
	else
	// 실패2
  }

  반환 가능 값 : 
  Success
  Fail_Two_Same_Value
  Fail_No_Element
***********************************************************************/

int replace_client(const Client* p_origin, Client client);

int replace_book(const Book* p_origin, Book book);

int replace_borrow(const Borrow* p_origin, Borrow borrow);


/// 리스트들의 모든 원소를 메모리에서 해제해버립니다.
/// 프로그램 종료하기 직전에 호출되어야만 합니다.

void free_all_lists(void);
