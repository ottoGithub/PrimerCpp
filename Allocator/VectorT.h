#ifndef _VECTOR_T_H_
#define _VECTOR_T_H_
#include <memory>
#define NULL 0

namespace VectorT
{
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
	private:
		static std::allocator<T> alloc;		//分配和构造元素;
		void reallocate();					//get more space and copy existing elements;
		T* elements;							//指向数组的第一个元素;
		T* first_free;						//指向最后一个实际元素之后的那个元素;
		T* end;								//指向数组本身之后的那个元素;
	};

	template<class T>
	void VectorT<T>::push_back(const T& t)
	{
		if(first_free == end)
		{
			reallocate();
		}
		alloc.construct(first_free, t);
		++first_free;
	}

	template<class T>
	void VectorT<T>::reallocate()
	{
		std::ptrdiff_t size = first_free - elements;
		std::ptrdiff_t newCapacity = 2 * max(size, 1);

		T* newelements = alloc.allocate(newCapacity);

		uninitialized_copy(element, first_free, newelements);

		for(T *p = first_free; p != element;)
		{
			alloc.destroy(--p)
		}

		if(elements)
		{
			alloc.deallocate(elements, end - elements);
		}
		elements = newelements;
		first_free = elements + size;
		end = elements + newCapacity;
	}

}

#endif