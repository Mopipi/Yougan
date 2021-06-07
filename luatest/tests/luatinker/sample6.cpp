// sample3.cpp : LuaTinker �� Ŭ���� ����� �˾ƺ���.
//

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
};

#include "luatinker.h"

// �Լ� ���°� int(*)(lua_State*) �Ǵ� int(*)(lua_State*,T1) �� ��츸 lua_yield() �� �� �� �ִ�.
// �Լ� ���ڰ� �� �ʿ��� ��� luatinker.h �� "functor (non-managed)" �ڸ�Ʈ �κ��� �����ؼ� ���� �߰��� ��
int TestFunc(lua_State* L)
{
	printf("# TestFunc ������\n");
	return lua_yield(L, 0);
}

int TestFunc2(lua_State* L, float a)
{
	printf("# TestFunc2(L,%f) ������\n", a);
	return lua_yield(L, 0);
}

class TestClass
{
public:

	// �Լ� ���°� int(T::*)(lua_State*) �Ǵ� int(T::*)(lua_State*,T1) �� ��츸 lua_yield() �� �� �� �ִ�.
	// �Լ� ���ڰ� �� �ʿ��� ��� luatinker.h �� "class member functor (non-managed)" �ڸ�Ʈ �κ��� �����ؼ� ���� �߰��� ��
	int TestFunc(lua_State* L)
	{
		printf("# TestClass::TestFunc ������\n");
		return lua_yield(L, 0);
	}

	int TestFunc2(lua_State* L, float a)
	{
		printf("# TestClass::TestFunc2(L,%f) ������\n", a);
		return lua_yield(L, 0);
	}
};

int main()
{
	// Lua �� �ʱ�ȭ �Ѵ�.
	lua_State* L = luaL_newstate();

	// Lua �⺻ �Լ����� �ε��Ѵ�.- print() ���
    luaL_openlibs(L);
	// Lua ���ڿ� �Լ����� �ε��Ѵ�.- string ���
	luaopen_string(L);

	// TestFunc �Լ��� Lua �� ����Ѵ�.
	luatinker::def(L, "TestFunc", &TestFunc);
	luatinker::def(L, "TestFunc2", &TestFunc2);

	// TestClass Ŭ������ Lua �� �߰��Ѵ�.
	luatinker::class_add<TestClass>(L, "TestClass");
	// TestClass �� �Լ��� ����Ѵ�.
	luatinker::class_def<TestClass>(L, "TestFunc", &TestClass::TestFunc);
	luatinker::class_def<TestClass>(L, "TestFunc2", &TestClass::TestFunc2);

	// TestClass �� ���� ������ �����Ѵ�.
	TestClass g_test;
	luatinker::set(L, "g_test", &g_test);

	// sample3.lua ������ �ε��Ѵ�.
	luatinker::dofile(L, "sample6.lua");

	// Thread �� �����Ѵ�.
	lua_newthread(L);
    {//pixs alter:
        //lua_pushstring(L, "ThreadTest");
        //lua_gettable(L, LUA_GLOBALSINDEX);

        lua_getglobal(L, "ThreadTest");
    }


	// Thread �� �����Ѵ�.
	printf("* lua_resume() ȣ��\n");
    /*pixs alter*/lua_resume(L, 0, 0); //lua_resume(L, 0);

	// Thread �� �ٽ� �����Ѵ�.
	printf("* lua_resume() ȣ��\n");
    /*pixs alter*/lua_resume(L, 0, 0); //lua_resume(L, 0);

	// Thread �� �ٽ� �����Ѵ�.
	printf("* lua_resume() ȣ��\n");
    /*pixs alter*/lua_resume(L, 0, 0); //lua_resume(L, 0);

	// Thread �� �ٽ� �����Ѵ�.
	printf("* lua_resume() ȣ��\n");
    /*pixs alter*/lua_resume(L, 0, 0); //lua_resume(L, 0);

	// Thread �� �ٽ� �����Ѵ�.
	printf("* lua_resume() ȣ��\n");
    /*pixs alter*/lua_resume(L, 0, 0); //lua_resume(L, 0);

	// ���α׷� ����
	lua_close(L);

	return 0;
}

