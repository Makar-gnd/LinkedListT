#include"../List/List.h"
int main()
{
	List<std::string> list{"a", "b", "c"};
	List<std::string> list1{"a", "b", "c"};
	list1 == list;
	return 0;
}