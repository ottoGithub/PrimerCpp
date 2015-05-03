#ifndef _VECTOR_T_H_
#define _VECTOR_T_H_
#include <memory>

//#define max(a,b) (a>b)?(a):(b)

template<class T>
class VectorT
{
public:
	VectorT()
	{
		elements = 0;
		first_free = NULL;
		end = NULL;
	}
	void push_back(const T&);

	//void* operator new(size_t);
	//void* operator new[](size_t);

	//void operator delete(void*);
	//void operator delete[](void*);

private:
	static std::allocator<T> alloc;		//分配和构造元素;
	void reallocate();					//get more space and copy existing elements;
	T* elements;						//指向数组的第一个元素;
	T* first_free;						//指向最后一个实际元素之后的那个元素;
	T* end;								//指向数组本身之后的那个元素;
};

template<class T> std::allocator<T> VectorT<T>::alloc;

template<class T>
void VectorT<T>::push_back(const T& t)
{
	if(first_free == end)
	{
		reallocate();
	}
	//alloc.construct(first_free, t);
	::new (first_free) T(t);
	++first_free;
}

template<class T>
void VectorT<T>::reallocate()
{
	std::ptrdiff_t size = first_free - elements;
	std::ptrdiff_t newCapacity = 2 * std::max(size,1); // 不用std::max(）会因为类型问题导致数据错误

	T* newelements = alloc.allocate(newCapacity);

	if(elements != 0)
	{
		std::uninitialized_copy(elements, first_free, newelements);
	}
		

	for(T *p = first_free; p != elements;)
	{
		alloc.destroy(--p);
	}

	if(elements)
	{
		alloc.deallocate(elements, end - elements);
	}
	elements = newelements;
	first_free = elements + size;
	end = elements + newCapacity;
}

//template<class T>
//void* VectorT<T>::operator new(size_t size)
//{
//	//size_t newCapacity = 2 * max(size, 1);
//	//elements = alloc.allocate(newCapacity);
//	//first_free = elements + size;
//	//end = elements + newCapacity;
//	//return new(elements) T();

//	void* p = alloc.allocate(20);
//	return p;
//}

//template<class T>
//void* VectorT<T>::operator new[](size_t size)
//{
//	return NULL;
//}

//template<class T>
//void VectorT<T>::operator delete(void* p)
//{
//	//for(T* p = first_free; (T*)p != elements;)
//	//{
//	//	p->~T();
//	//}

//	//if(elements)
//	//{
//	//	alloc.deallocate(elements, end - elements);
//	//}
//}

//template<class T>
//void VectorT<T>::operator delete[](void* p)
//{
//}


void ExampleVectorT()
{
	VectorT<int>* pVec1 = new VectorT<int>();
	pVec1->push_back(0);
	pVec1->push_back(1);
	//std::vector<int>* pVec2 = new std::vector<int>();
	//pVec2->push_back(0);
	//pVec2->push_back(1);
}

#endif