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

void * _lalloc(void *ud, void *ptr, size_t osize, size_t nsize) 
{
	if (nsize == 0) {
		free(ptr);
		return NULL;
	} else {
		return realloc(ptr, nsize);
	}
}

int main(int argc, char *argv[])
{
	const char *luaFile = "sample.lua";
	if (argc > 1)
	{
		luaFile = argv[1];
	}

	lua_State *L = lua_newstate(_lalloc, NULL);
	luaL_openlibs(L);

	luaL_loadfile(L, luaFile);

	lua_close(L);
	getchar();

	return 0;
}