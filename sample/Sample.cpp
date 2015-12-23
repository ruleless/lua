#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" 
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

#pragma comment(lib, "lua.lib")

int main(int argc, char *argv[])
{
	const char *luaFile = "sample.lua";
	if (argc > 1)
	{
		luaFile = argv[1];
	}

	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	luaL_loadfile(L, luaFile);

	lua_close(L);
	getchar();

	return 0;
}