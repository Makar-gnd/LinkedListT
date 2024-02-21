#include"../List/List.h"
int main()
{
	List<std::string> list{"a","b","c"};
	std::cout << list.ToString();
	return 0;
}