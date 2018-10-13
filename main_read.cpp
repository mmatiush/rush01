#include <iostream>

std::string exec(const char* cmd) {

	char buffer[200];
	std::string result = "";
	FILE* pipe = popen(cmd, "r");
	if (!pipe)
		throw std::runtime_error("popen() failed!");
	
	for (int i = 0; i < 10;i++)
	if (fgets(buffer, 200, pipe) != NULL)
		result += buffer;
	pclose(pipe);

	return result;
}

int main()
{
	std::cout << exec("top") << std::endl;
	return (0);
}
