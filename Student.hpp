//
//  Student.hpp
//  LuaToC
//
//  Created by qixiang on 2018/3/12.
//  Copyright © 2018年 qixiang. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <iostream>
#include <string>

class Student{
    
public:
    Student();
    ~Student();
    
    
    std::string get_name();
    void set_name(std::string name);
    unsigned get_age();
    void set_age(unsigned age);
    
    
    void print();
private:
    std::string _name;
    unsigned _age;

};

#endif /* Student_hpp */
