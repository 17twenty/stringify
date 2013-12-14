#include <stdio.h>

#define command_build(value) \
void value ##_command() \
{ \
	printf(#value "\n");\
}\

command_build(foo)
command_build(frob)
command_build(faz)
command_build(baz)
command_build(help)
command_build(quit)

struct command {
	char *name;
	void (*function)(void);
};

#define COMMAND(NAME) { \
	#NAME, NAME ## _command \
	}

struct command commands[] = {
	COMMAND(foo),
	COMMAND(frob),
	COMMAND(faz),
	COMMAND(baz),
	COMMAND(quit),
	COMMAND(help),
	{ },
};

int main(void)
{
    struct command *func = commands;
    while(func->name) {
		(func++)->function();
    }
	return 0;
}
