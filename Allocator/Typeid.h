#ifndef _TYPE_ID_H_
#define _TYPE_ID_H_
#include <iostream>

//只有当typeid的操作数是带虚函数的类类型的对象的时候，才返回动态类型信息。
//测试指针返回指针的静态的编译时的类型
//只有Base含有虚函数是，typeid才会有动态信息.
class BaseClass
{
	//virtual void f(){}
};

class DerivedClass : public BaseClass
{
	//如果仅仅是子类中有虚函数是不行的。typeid不会改变
	//virtual void f(){}
};

void ExampleTypeid()
{
	int flag = 0;
	BaseClass* pBase = new DerivedClass();
	DerivedClass* pDerived = new DerivedClass();
	if(typeid(pBase) == typeid(pDerived))
	{
		flag++;
	}
	if(typeid(*pBase) == typeid(pDerived))
	{
		flag++;
	}
	if(typeid(*pBase) == typeid(*pDerived))
	{
		//相等的情况是BaseClass中含有虚函数
		flag++;
	}
	//typeid返回的是type_info这样一个类
	std::cout<<typeid(pBase).name()<<std::endl;
	std::cout<<typeid(*pBase).name()<<std::endl;
	std::cout<<typeid(pDerived).name()<<std::endl;
	std::cout<<typeid(*pDerived).name()<<std::endl;
}

#endif