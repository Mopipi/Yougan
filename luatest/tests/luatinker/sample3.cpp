// sample3.cpp : LuaTinker �� Ŭ���� ����� �˾ƺ���.
//

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
};

#include "luatinker.h"

struct A
{
	A(int v) : value(v) {}
	int value;
};

struct base
{
	base() {}

	const char* is_base(){ return "this is base"; }
};

class test : public base
{
public:
	test(int val) : _test(val) {}
	~test() {}

	const char* is_test(){ return "this is test"; }

	void ret_void() {}
	int ret_int()				{ return _test;			}
	int ret_mul(int m) const	{ return _test * m;		}
	A get()						{ return A(_test);		}
	void set(A a)				{ _test = a.value;		}

	int _test;
};

test g_test(11);

//int main()
//{
//	// Lua �� �ʱ�ȭ �Ѵ�.
//	lua_State* L = luaL_newstate();
//
//	// Lua �⺻ �Լ����� �ε��Ѵ�.- print() ���
//    luaL_openlibs(L);
//	// Lua ���ڿ� �Լ����� �ε��Ѵ�.- string ���
//	luaopen_string(L);
//
//	// base Ŭ������ Lua �� �߰��Ѵ�.
//    luatinker::class_add<base>(L, "base");
//	// base �� �Լ��� ����Ѵ�.
//    luatinker::class_def<base>(L, "is_base", &base::is_base);
//
//	// test Ŭ������ Lua �� �߰��Ѵ�.
//    luatinker::class_add<test>(L, "test");
//	// test �� base �� ��� �޾����� �˷��ش�.
//    luatinker::class_inh<test, base>(L);
//	// test Ŭ���� �����ڸ� ����Ѵ�.
//    luatinker::class_con<test>(L, luatinker::constructor<test,int>);
//	// test �� �Լ����� ����Ѵ�.
//    luatinker::class_def<test>(L, "is_test", &test::is_test);
//    luatinker::class_def<test>(L, "ret_void", &test::ret_void);
//    luatinker::class_def<test>(L, "ret_int", &test::ret_int);
//    luatinker::class_def<test>(L, "ret_mul", &test::ret_mul);
//    luatinker::class_def<test>(L, "get", &test::get);
//    luatinker::class_def<test>(L, "set", &test::set);
//    luatinker::class_mem<test>(L, "_test", &test::_test);
//	
//	// Lua ���� ����ȣ g_test �� �����͸� ����Ѵ�.
//    luatinker::set(L, "g_test", &g_test);
//
//	// sample3.lua ������ �ε�/�����Ѵ�.
//    luatinker::dofile(L, "sample3.lua");
//
//	// ���α׷� ����
//	lua_close(L);
//
//	return 0;
//}
//
