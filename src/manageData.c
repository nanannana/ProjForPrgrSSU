#include<stdlib.h>
#include"manageData.h"

#define CODE(Sth, sth, key) 									\
/* 이 c 파일에서만 사용되는 get함수입니다. 성공을 확인한 후 리스트의 current*/\
/* 가져다 이용하시면 됩니다.												*/\
int private_get_##sth(int key)									\
{																\
	/* 리스트의 current 초기화 */								\
	list_##sth->current = list_##sth->head;						\
	/* 리스트가 오름차순으로 정렬 되어 있으므로 자신보다 작은 값을 가진 원소까지 */\
	/* 검사하면 충분합니다. key값이 같거나 클 경우 반복문에서 빠져나옵니다. */\
	while(list_##sth->current->key < key || list_##sth->current->next != NULL)\
		list_##sth->current = list_##sth->current->next;		\
																\
	/* 열심히 찾았는데 없을경우 실패를 반환합니다. */			\
	if (list_##sth->current->key != key)						\
		return Fail_No_Element;									\
																\
	return Success;												\
}																\
																\
int append_##sth(Sth sth)										\
{																\
	/* 리스트에 추가할 원소를 동적할당하여 공간을 만듭니다.*/	\
	Sth * element = (Sth *)malloc(sizeof(Sth));					\
	*element = sth; 											\
    															\
	if (private_get_##sth(element->key) == Success)				\
	{/* 중복이라면 오류 반환 */									\
		return Fail_Two_Same_Value;								\
	}/* 현재 리스트의 current 는 삽입하기 적당한 위치 */		\
																\
	if (list_##sth->current->next == NULL)						\
	{/* 마지막 원소일 때 */										\
		list_##sth->tail = element;								\
																\
		list_##sth->current->next = element;					\
		element->last = list_##sth->current;					\
		element->next = NULL;									\
	}															\
	else if (list_##sth->current->last == NULL)					\
	{/* 첫번째 원소일 때 */										\
		list_##sth->head = element;								\
																\
		list_##sth->current->last = element;					\
		element->next = list_##sth->current;					\
		element->last = NULL;									\
	}															\
	else														\
	{/* 중간 원소일 때 */										\
		Sth *last = list_##sth->current->last, *current = list_##sth->current;\
		/* 요소 연결 */											\
		last->next = element;									\
		element->last = last;									\
																\
		current->last = element;								\
		element->next = current;								\
	}															\
																\
    file_write_##sth();											\
																\
	return Success;												\
}																\
																\
int remove_##sth(int key)										\
{																\
	/* 원하는 원소를 얻어내지 못했다면, 해당하는 원소는 없다. 에러반환 */\
	if (private_get_##sth(key) != Success)						\
		return Fail_No_Element;									\
	/* 현재 리스트의 current는 지워야할 원소이다. */			\
																\
	if (list_##sth->current->next == NULL)						\
	{/* 마지막 원소 */											\
		list_##sth->tail = list_##sth->current->last;			\
		list_##sth->tail->next = NULL;							\
																\
		free(list_##sth->current);								\
	}															\
	else if (list_##sth->current->last == NULL)					\
	{/* 첫번째 원소 */											\
		list_##sth->head = list_##sth->current->next;			\
		list_##sth->head->last = NULL;							\
																\
		free(list_##sth->current);								\
	}															\
	else														\
	{/* 중간 원소 */											\
		Sth *last = list_##sth->current->last, *next = list_##sth->current->next;\
																\
		last->next = next;										\
		next->last = last;										\
																\
		free(list_##sth->current);								\
	}															\
																\
	file_write_##sth();											\
																\
	return Success;												\
}																\
																\
int get_##sth(int key, const Sth** result)						\
{																\
	/* 접근성을 제한하기 위해 const에 할당 후 그 주소를 이용합니다 */\
	if (private_get_##sth(key) == Success)						\
	{															\
		const Sth temp = *(list_##sth->current);				\
		*result = &temp;										\
		return Success;											\
	}															\
	else														\
		return Fail_No_Element;									\
}																\
																\
int replace_##sth(const Sth* p_origin, Sth sth)					\
{																\
	Sth *element = (Sth*)malloc(sizeof(Sth));					\
	*element = sth;												\
																\
	/* 예외 검사 */												\
	if(private_get_##sth(element->key) == Success)				\
		return Fail_Two_Same_Value;								\
	if(private_get_##sth(p_origin->key) != Success)				\
		return Fail_No_Element;									\
																\
	/* 원소를 바꿔치기 합니다. */								\
	Sth *last = p_origin->last, *next = p_origin->next;			\
																\
	last->next = element;										\
	next->last = element;										\
																\
	element->last = last;										\
	element->next = next;										\
																\
	free((void *)p_origin);												\
																\
	file_write_##sth();											\
																\
	return Success;												\
}																

CODE(Client, client, sch_num)
CODE(Book, book, book_num)
CODE(Borrow, borrow, book_num)

#ifdef DEBUG
int main(void)
{
	while(1)
	{
		printf("디버깅 모드입니다.\n");
	}

	return 0;
}
#endif
