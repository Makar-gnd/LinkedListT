#include"../List/List.h"
int main()
{
	List<std::string> list{"a","b","c"};
	//list.PopFront();
	//list.PushBack("r");
	//list.PushFront("t");
	list.PopBack();
	std::cout << list.ToString();
	return 0;
}