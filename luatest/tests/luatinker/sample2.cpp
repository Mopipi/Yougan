// sample2.cpp : C++ �� Lua ��ȣ���� ���� ������ �˾ƺ���.
//

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
};

#include "luatinker.h"

static int cpp_int = 100;

//int main()
//{
//	// Lua �� �ʱ�ȭ �Ѵ�.
//	lua_State* L = luaL_newstate();
//
//	// Lua �⺻ �Լ����� �ε��Ѵ�.- print() ���
//    luaL_openlibs(L);
//
//	// LuaTinker �� �̿��ؼ� cpp_int �� Lua�� ����
//    luatinker::set(L, "cpp_int", cpp_int);
//
//	// sample1.lua ������ �ε�/�����Ѵ�.
//    luatinker::dofile(L, "sample2.lua");
//
//	// sample1.lua �� �Լ��� ȣ���Ѵ�.
//	int lua_int = luatinker::get<int>(L, "lua_int");
//
//	// lua_int �� ���
//	printf("lua_int = %d\n", lua_int);
//
//	// ���α׷� ����
//	lua_close(L);
//
//	return 0;
//}
