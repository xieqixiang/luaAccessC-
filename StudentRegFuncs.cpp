//
//  StudentRegFuncs.cpp
//  LuaToC
//
//  Created by qixiang on 2018/3/12.
//  Copyright © 2018年 qixiang. All rights reserved.
//

#include "StudentRegFuncs.hpp"


int lua_create_new_student(lua_State * L)
{
    
    Student ** s = (Student**)lua_newuserdata(L, sizeof(Student*));
    
    *s = new Student();
    
    //lua->stack ,得到全局元表位置-1，userdata位置-2
    luaL_getmetatable(L,"StudentClass");
    
    //将元表赋值给位置-2的userdata,并弹出-1的元表
    lua_setmetatable(L,-2);
    
    return 1;
}


int lua_get_name(lua_State * L)
{
    Student ** s = (Student**)luaL_checkudata(L, 1,"StudentClass");
    
    luaL_argcheck(L,s != NULL,1,"invalid user data");
    
    lua_settop(L,0);
    
    lua_pushstring(L,(*s)->get_name().c_str());
    
    return  1;
}


int lua_set_name(lua_State* L)
{
    
    Student ** s = (Student**)luaL_checkudata(L, 1,"StudentClass");
    luaL_argcheck(L,s != NULL,1, "invalid user data");
    
    
    luaL_checktype(L,-1,LUA_TSTRING);
    
    
    std::string name = lua_tostring(L,-1);
    
    (*s)->set_name(name);
    
    return  0;
}


int lua_get_age(lua_State * L)
{
    Student ** s = (Student**)luaL_checkudata(L, 1,"StudentClass");
    luaL_argcheck(L,s != NULL,1,"invalid user data");
    
    lua_pushinteger(L,(*s)->get_age());
    
    return  1;

}

int lua_set_age(lua_State* L)
{
    Student ** s = (Student**)luaL_checkudata(L, 1,"StudentClass");
    luaL_argcheck(L,s != NULL,1, "invalid user data");
    
     luaL_checktype(L,-1,LUA_TNUMBER);
    
    (*s)->set_age((unsigned)lua_tointeger(L, -1));
                  
    return 0;
}

int lua_auto_gc(lua_State* L)
{
    Student** s = (Student**)luaL_checkudata(L,1,"StudentClass");
    luaL_argcheck(L, s!= NULL, 1,"invalid user data");
    
    if (s) {
        delete *s;
    }
    
    return 0;
}

int lua_print(lua_State* L)
{
     Student ** s = (Student**)luaL_checkudata(L, 1,"StudentClass");
    luaL_argcheck(L,s != NULL, 1, "invalid user data");
    
    (*s)->print();
    
    return 0;
}

int luaopen_student_libs(lua_State* L)
{
    luaL_newmetatable(L,"StudentClass");
    
    //将元表作为一个副本压栈到位置-1,原元表位置-2
    lua_pushvalue(L,-1);
    
    
    //设置-2位置元表的_index索引的值为位置-1的元表，并弹出位置-1的元表，原元表的位置为-1
    lua_setfield(L,-2,"__index");
    
    
    //将成员函数注册到元表中（到这里，全局元表的设置就全部完成了）
    luaL_setfuncs(L,lua_reg_student_member_funcs,0);
    
    
    luaL_newlib(L, lua_reg_student_constructor_funcs);
    
    return 1;
}





















