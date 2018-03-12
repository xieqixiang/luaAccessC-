//
//  main.cpp
//  LuaToC
//
//  Created by qixiang on 2018/3/12.
//  Copyright © 2018年 qixiang. All rights reserved.
//

#include <iostream>

#include "StudentRegFuncs.hpp"

extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

}

static const luaL_Reg lua_reg_libs[] = {
    {"Student",luaopen_student_libs},
    {NULL,NULL},
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    lua_State * luaState = luaL_newstate();
    //luaL_openlibs(luaState);
    
    //注册让lua使用的库
    const luaL_Reg* lua_reg = lua_reg_libs;
    
    for (; lua_reg->func;++lua_reg) {
        luaL_requiref(luaState,lua_reg->name, lua_reg->func,1);
        lua_pop(luaState, 1);
    }
    
    if(luaL_dofile(luaState,"/Users/lijie/C++/luaToC/LuaToC/luaTest.lua")){
        std::cout << lua_tostring(luaState,-1) << std::endl;
    }
    
    
    lua_close(luaState);
    
    
    return 0;
}
