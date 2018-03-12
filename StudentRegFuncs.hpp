//
//  StudentRegFuncs.hpp
//  LuaToC
//
//  Created by qixiang on 2018/3/12.
//  Copyright © 2018年 qixiang. All rights reserved.
//

#ifndef StudentRegFuncs_hpp
#define StudentRegFuncs_hpp

#include "Student.hpp"

extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}


int lua_create_new_student(lua_State * L);

int lua_get_name(lua_State* L);
int lua_set_name(lua_State* L);
int lua_get_age(lua_State* L);
int lua_set_age(lua_State* L);

int lua_print(lua_State * L);
int lua_auto_gc(lua_State* L);

int luaopen_student_libs(lua_State* L);

static const luaL_Reg lua_reg_student_constructor_funcs[] = {
    {"create",lua_create_new_student},
    {NULL,NULL},
};

static const luaL_Reg lua_reg_student_member_funcs[] = {
    {"get_name",lua_get_name},
    {"set_name",lua_set_name},
    {"get_age",lua_get_age},
    {"set_age",lua_set_age},
    {"__gc",lua_auto_gc},
    {"print",lua_print},
    {NULL,NULL},
};


#endif /* StudentRegFuncs_hpp */
