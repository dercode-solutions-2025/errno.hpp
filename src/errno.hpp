#ifndef ERRNO_HPP
#define ERRNO_HPP

#include <cstdio>
#include <cstring>

void error(const int exit_code=0, const char filename[]="errno.h", const int lineno=1, const int col=1, const char line[]="", const char errtype[]= "SyntaxError", const char err[]= "") {
	
	std::printf("\033[1m%s\033[0m (using script '%s'):", errtype, filename);
	std::printf("\n\tLine %d", lineno);
	std::printf(", column %d:\n\t\t\033[1m%s\033[0m\n\t\t", col, line);
	unsigned int ptr = 0;
	while (ptr <= std::strlen(line)) {
		if (ptr == (col - 2)) {
			std::printf("\033[1m ^ \033[0m");
			ptr += 4;
		}
		std::printf("\033[91m~\033[0m");
		ptr++;
	}
	std::printf("\n[\033[1mExit Code\033[0m]: %d\n", exit_code);
}
#endif