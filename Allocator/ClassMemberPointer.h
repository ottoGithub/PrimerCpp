#ifndef _CLASS_MEMBER_POINTER_H_
#define _CLASS_MEMBER_POINTER_H_
//成员指针
//成员指针只应用于类的非static成员。static类成员不是任何对象的组成部分，所以不需要特殊语法来指向static成员，static成员指针是普通指针。

//函数指针和成员函数指针的一个公共用途是，将它们存储在函数表中。函数表是函数指针的集合，在运行时从中选择给定调用
//虚函数占用一个指针大小
class Screen
{
public:
	typedef std::string::size_type index;
	char get() const{ return '\0'; }
	char get(index ht, index wd) const{ return '\0'; }

	Screen& home(){}
	Screen& forward(){}
	Screen& back(){}
	Screen& up(){}
	Screen& down(){}

	typedef Screen& (Screen::*Action)();
	static Action Menu[];

public:
	enum Directions { HOME, FORWARD, BACK, UP, DOWN};
	Screen& move(Directions);

//private:
public:
	std::string contents;
	index cursor;
	index height, width;
};


Screen& Screen::move(Directions cm)
{
	(this->*Menu[cm])();
	return *this;
}

Screen::Action Screen::Menu[] = 
{
	&Screen::home,
	&Screen::forward,
	&Screen::back,
	&Screen::up,
	&Screen::down
};

//使用别名
typedef char (Screen::*Action)(Screen::index, Screen::index) const;



//可以使用成员指针函数类型来声明函数形参和函数返回类型
//可以通过传递Screen类中适当成员函数的指针或者地址调用action函数
//Screen& action(Screen&, Action = &Screen::get);

Screen& action(Screen& s, Action get  = &Screen::get)
{
	return s;
}

void ExampleClassMemberPointer()
{
	std::string Screen::* ps_Screen = &Screen::contents;
	Screen::index Screen::* pIndex;
	pIndex = &Screen::width;

	//char (Screen::*ptr)() const; // get()成员函数的指针类型
	char (Screen::*pmf)() const = &Screen::get;

	char (Screen::*pmf2)(Screen::index, Screen::index) const;
	pmf2 = &Screen::get;


	Screen myScreen;
	action(myScreen);
	action(myScreen, pmf2);
	action(myScreen, &Screen::get);

	char c1 = myScreen.get();
	char c2 = (myScreen.*pmf)(); //通过函数指针调用get函数;
	Screen* pScreen = &myScreen;
	c1 = pScreen->get();
	c2 = (pScreen->*pmf)();

	//使用数据成员函数指针
	Screen::index ind1 = myScreen.width;
	Screen::index ind2 = myScreen.*pIndex;

	ind1 = pScreen->width;
	ind2 = pScreen->*pIndex;

	myScreen.move(Screen::HOME);
	myScreen.move(Screen::DOWN);
}

#endif