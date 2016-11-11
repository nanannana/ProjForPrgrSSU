#include"manageData.h"
#include"fileIO.h"

/// Client

/// result can has NULL value, 
/// that means this fuction just checks whether there is element you need or not.
int private_get_client(int sch_num, Client** result)
{
    if (result != NULL)
}

int append_client(Client client)
{
    Client* client_element = (Client*)malloc(sizeof(Client));
    Client* element = list_clients.next; // First element of list
    int present_sch_num = client.sch_num;
    do
    {
	if (element->
    }
    while((element = element->next)->sch_num != EOL);

    


    file_write_client();
}

int remove_client(int sch_num)
{

}

int get_client(int sch_num, const Client** result)
{

}

int replace_client(const Client* p_origin, Client client)
{

}

/// Book

int private_get_book(int sch_num, Book** result)
{
}

int append_book(Book book)
{

}

int remove_client(int book_num)
{

}

int get_book(int book_num, const Book** result)
{
}

int replace_client(const Book* p_origin, Book book)
{

}

/// Borrow

int private_get_borrow(int sch_num, Borrow** result)
{
}

int append_borrow(Borrow borrow)
{

}

int remove_borrow(int book_num)
{
}

int get_borrow(int book_num, const Borrow** result)
{

}

int replace_borrow(const Borrow* p_origin, Borrow borrow)
{
}
