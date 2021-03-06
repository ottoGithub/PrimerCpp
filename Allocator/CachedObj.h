#ifndef _CACHED_OBJ_H_
#define _CACHED_OBJ_H_

#include <memory>


template <class T>
class CachedObj
{
public:
	void* operator new(std::size_t);
	void operator delete(void*, std::size_t t);
	virtual ~CachedObj(){}
protected:
	T* next;
private:
	static void add_to_freelist(T*);
	static std::allocator<T> alloc_mem;
	static T* freeStore;
	static const std::size_t chunk;
};

template<class T>
void* CachedObj<T>::operator new(std::size_t sz)
{
	if(sz != sizeof(T))
	{
		throw std::runtime_error("error");
	}
	if(!freeStore)
	{
		T* array = alloc_mem.allocate(chunk);
		for(size_t i = 0; i != chunk; ++i)
		{
			add_to_freelist(&array[i]);
		}
	}
	T* p = freeStore;
	freeStore = freeStore->CachedObj<T>::next;
	return p;
}

template<class T>
void CachedObj<T>::operator delete(void* p, size_t sz)
{
	if(p!=0)
	{
		add_to_freelist(static_cast<T*>(p));
	}
}

template<class T>
void CachedObj<T>::add_to_freelist(T* p)
{
	p->CachedObj<T>::next = freeStore;
	freeStore = p;
}

template<class T> std::allocator<T> CachedObj<T>::alloc_mem;
template<class T> T* CachedObj<T>::freeStore = 0;
template<class T> const size_t CachedObj<T>::chunk = 24;

class MyArray : public CachedObj<MyArray>
{

};

void ExampleCachedObj()
{
	MyArray* pS = new MyArray();
	delete pS;
}
#endif