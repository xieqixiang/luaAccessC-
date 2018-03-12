local student_obj = Student.create()
student_obj:set_name("Jack")
student_obj:print()

student_obj = nil

--下面的代码也是可行的
--student_obj.set_name(student_obj,"Jack")
--student_obj.print(student_obj)
