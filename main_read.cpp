#include <iostream>

std::string exec(const char* cmd) {

	char buffer[1000];
	std::string result = "";
	FILE* pipe = popen(cmd, "r");
	if (!pipe)
		throw std::runtime_error("popen() failed!");
	
	for (int i = 0; i < 10;i++)
	if (fgets(buffer, 1000, pipe) != NULL)
		result += buffer;
	pclose(pipe);

	return result;
}

int main()
{
	std::string str = exec("top");
	std::cout << str << std::endl;
	return (0);
}
