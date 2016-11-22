#include<stdio.h>
#include<stdlib.h>
#include"managedata.h"
void Sign_down(int sch_num){
	int* book_nums = (int*)malloc(sizeof(int) * List_Borrow->num_element);
	int cnt;
	Client *element = NULL;

	if ((cnt = sch_num2keys(&
}	


int main(void){
 	init_all_list(); 

 	get_all_file_data();

	free_all_node(); 
	return 0;
}

