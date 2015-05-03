#ifndef _CLASS_MEMBER_POINTER_H_
#define _CLASS_MEMBER_POINTER_H_
//��Աָ��
//��Աָ��ֻӦ������ķ�static��Ա��static���Ա�����κζ������ɲ��֣����Բ���Ҫ�����﷨��ָ��static��Ա��static��Աָ������ָͨ�롣

//����ָ��ͳ�Ա����ָ���һ��������;�ǣ������Ǵ洢�ں������С��������Ǻ���ָ��ļ��ϣ�������ʱ����ѡ���������
//�麯��ռ��һ��ָ���С
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

//ʹ�ñ���
typedef char (Screen::*Action)(Screen::index, Screen::index) const;



//����ʹ�ó�Աָ�뺯�����������������βκͺ�����������
//����ͨ������Screen�����ʵ���Ա������ָ����ߵ�ַ����action����
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

	//char (Screen::*ptr)() const; // get()��Ա������ָ������
	char (Screen::*pmf)() const = &Screen::get;

	char (Screen::*pmf2)(Screen::index, Screen::index) const;
	pmf2 = &Screen::get;


	Screen myScreen;
	action(myScreen);
	action(myScreen, pmf2);
	action(myScreen, &Screen::get);

	char c1 = myScreen.get();
	char c2 = (myScreen.*pmf)(); //ͨ������ָ�����get����;
	Screen* pScreen = &myScreen;
	c1 = pScreen->get();
	c2 = (pScreen->*pmf)();

	//ʹ�����ݳ�Ա����ָ��
	Screen::index ind1 = myScreen.width;
	Screen::index ind2 = myScreen.*pIndex;

	ind1 = pScreen->width;
	ind2 = pScreen->*pIndex;

	myScreen.move(Screen::HOME);
	myScreen.move(Screen::DOWN);
}

#endif