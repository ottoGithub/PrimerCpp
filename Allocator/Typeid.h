#ifndef _TYPE_ID_H_
#define _TYPE_ID_H_
#include <iostream>

//ֻ�е�typeid�Ĳ������Ǵ��麯���������͵Ķ����ʱ�򣬲ŷ��ض�̬������Ϣ��
//����ָ�뷵��ָ��ľ�̬�ı���ʱ������
//ֻ��Base�����麯���ǣ�typeid�Ż��ж�̬��Ϣ.
class BaseClass
{
	//virtual void f(){}
};

class DerivedClass : public BaseClass
{
	//������������������麯���ǲ��еġ�typeid����ı�
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
		//��ȵ������BaseClass�к����麯��
		flag++;
	}
	//typeid���ص���type_info����һ����
	std::cout<<typeid(pBase).name()<<std::endl;
	std::cout<<typeid(*pBase).name()<<std::endl;
	std::cout<<typeid(pDerived).name()<<std::endl;
	std::cout<<typeid(*pDerived).name()<<std::endl;
}

#endif