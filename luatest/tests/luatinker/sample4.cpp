// sample4.cpp : table ���� ���� �˾ƺ���.
// table �� ���� ������ ���ؼ� stack �� table�� �����ؼ� ���� �ȴ�. 
// Lua ���� ���̺��� ���� �������� �����͸� �ö󰡰� ���� ��ü�� ���ο��� �����ȴ�.
// ���� �߸� ����� ��� ������ ���԰ų� Lua �������� ���� �����鿡 ������ ����ų ���� �ִ�.

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
};

#include "luatinker.h"

//int main()
//{
//	// Lua �� �ʱ�ȭ �Ѵ�.
//	lua_State* L = luaL_newstate();
//
//	// Lua �⺻ �Լ����� �ε��Ѵ�.- print() ���
//    luaL_openlibs(L);
//
//	// Lua ���̺��� �����ϰ� ���ÿ� Ǫ���Ѵ�.
//	luatinker::table haha(L, "haha");
//
//	// haha.value = 1 ���� �ִ´�.
//	haha.set("value", 1);
//
//	// table ���� table�� ����� �ִ´�.
//	haha.set("inside", luatinker::table(L));
//
//	// haha.inside �� �����͸� �������� �����Ѵ�.
//	luatinker::table inside = haha.get<luatinker::table>("inside");
//
//	// inside.value = 2 ���� �ִ´�.
//	inside.set("value", 2);
//
//	// sample4.lua ������ �ε�/�����Ѵ�.
//	luatinker::dofile(L, "sample4.lua");
//
//	// Lua ���� ������ haha.test ���� �д´�.
//	const char* test = haha.get<const char*>("test");
//	printf("haha.test = %s\n", test);
//
//	// ������ ������� �ʰ� Lua ���ÿ� �� ���̺��� �����Ѵ�.(��������)
//	luatinker::table temp(L);
//
//	// �� ���̺�.name �� ���� �ִ´�.
//	temp.set("name", "local table !!");
//
//	// table�� �� ���ڷ� ����Ͽ� print_table �� ȣ���Ѵ�.
//	luatinker::call<void>(L, "print_table", temp);
//
//	// �Լ��� �����ϴ� table�� �޴´�.
//	luatinker::table ret = luatinker::call<luatinker::table>(L, "return_table", "give me a table !!");
//	printf("ret.name =\t%s\n", ret.get<const char*>("name"));
//
//	// ���α׷� ����
//	lua_close(L);
//
//	return 0;
//}
//
