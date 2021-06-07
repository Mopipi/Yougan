// sample5.cpp : Defines the entry point for the console application.
//

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
};

#include "luatinker.h"

void show_error(const char* error)
{
	printf("_ALERT -> %s\n", error);
}

//int main()
//{
//	// Lua �� �ʱ�ȭ �Ѵ�.
//	lua_State* L = luaL_newstate();
//
//	// Lua �⺻ �Լ����� �ε��Ѵ�.- print() ���
//    luaL_openlibs(L);
//
//
//	// lua_State* �� �����ִ� ������ ������ �����ش�.
//	printf("%s\n","-------------------------- current stack");
//	luatinker::enum_stack(L);
//
//	// ���ÿ� 1�� �о�ִ´�.
//	lua_pushnumber(L, 1);
//
//	// ���� ������ ������ �ٽ� ����Ѵ�.
//	printf("%s\n","-------------------------- stack after push '1'");
//	luatinker::enum_stack(L);
//
//
//	// sample5.lua ������ �ε�/�����Ѵ�.
//	luatinker::dofile(L, "sample5.lua");
//
//	// test_error() �Լ��� ȣ���Ѵ�.
//	// test_error() �� ������ test_error_3() ȣ���� �õ��ϴ� ������ �߻���Ų��.
//	// �Լ� ȣ���� �߻��� ������ printf()�� ���ؼ� ��µȴ�.
//	printf("%s\n","-------------------------- calling test_error()");
//	luatinker::call<void>(L, "test_error");
//
//	// test_error_3()�� �������� �ʴ� �Լ��̴�. ȣ�� ��ü�� �����Ѵ�.
//	printf("%s\n","-------------------------- calling test_error_3()");
//	luatinker::call<void>(L, "test_error_3");
//
//	// printf() ��� ������ �����ϴ� ���� ��� ��ƾ�� ����� �� �ִ�.
//	// �� ����ó�� �Լ���1���� ��� ���ڿ��� �߻��� ������ �����ϰ� �ȴ�.
//	// C++ ���� ����� ��� void function(const char*) ���°� �����ϴ�.
//	luatinker::def(L, "_ALERT", show_error);
//
//	luatinker::call<void>(L, "_ALERT", "test !!!");
//
//	// test_error() �Լ��� ȣ���Ѵ�.
//	// �Լ� ȣ���� �߻��� ������ Lua�� ��ϵ� _ALERT()�� ���ؼ� ��µȴ�.
//	printf("%s\n","-------------------------- calling test_error()");
//	luatinker::call<void>(L, "test_error");
//
//
//	// ���α׷� ����
//	lua_close(L);
//
//	return 0;
//}

