#ifndef ITERATORS_HPP
#define ITERATORS_HPP
#include "franklist.h"

//BASE ITERATOR
template <typename T>
FrankList<T>::base_iterator::base_iterator(Node* ptr)
    : ptr(ptr) {}

template<typename T>
bool FrankList<T>::base_iterator::operator==(const base_iterator& rhv) const
{
    return this -> ptr == rhv.ptr;
}

template<typename T>
bool FrankList<T>::base_iterator::operator!=(const base_iterator& rhv) const
{
    return !(operator==(rhv));
}

template <typename T>
FrankList<T>::base_iterator::~base_iterator()
{ 
    ptr = nullptr;
}

//CONST ITERATOR
template<typename T>
FrankList<T>::const_iterator::const_iterator(Node* rhv) 
    :base_iterator(rhv) {}

template<typename T>
FrankList<T>::const_iterator::const_iterator(const base_iterator& rhv) 
    :base_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::const_iterator::const_iterator(base_iterator&& rhv) 
    :base_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
const T& FrankList<T>::const_iterator::operator*() const
{
    return this -> ptr -> val;
}

template<typename T>
const T* FrankList<T>::const_iterator::operator->() const
{
    return this -> ptr;
}

template<typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator++()
{
    this -> ptr = this -> ptr -> next;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator++(value_type)
{
    const_iterator new_ptr = const_iterator(this -> ptr);
    ++(*this);
    return new_ptr;
}

template<typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator--()
{
    this -> ptr = this -> ptr -> prev;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator--(value_type)
{
    const_iterator new_ptr = const_iterator(this -> ptr);
    --(*this);
    return new_ptr;
}

//ITERATOR
template<typename T>
FrankList<T>::iterator::iterator(Node* rhv) 
    :const_iterator(rhv) {}

template<typename T>
FrankList<T>::iterator::iterator(const base_iterator& rhv) 
    :const_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::iterator::iterator(base_iterator&& rhv) 
    :const_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
typename FrankList<T>::reference FrankList<T>::iterator::operator*() 
{
    return this -> ptr -> val;
}

template<typename T>
typename FrankList<T>::pointer FrankList<T>::iterator::operator->() 
{
    return this -> ptr;
}

//CONST REVERSE ITERATOR
template<typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(Node* rhv) 
    :base_iterator(rhv) {}

template<typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv) 
    :base_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv) 
    :base_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
const T& FrankList<T>::const_reverse_iterator::operator*() const
{
    return this -> ptr -> val;
}

template<typename T>
const T* FrankList<T>::const_reverse_iterator::operator->() const
{
    return this -> ptr;
}

template<typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator++()
{
    this -> ptr = this -> ptr -> prev;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator++(value_type)
{
    const_reverse_iterator new_ptr = const_reverse_iterator(this -> ptr);
    ++(*this);
    return new_ptr;
}

template<typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator--()
{
    this -> ptr = this -> ptr -> next;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator--(value_type)
{
    const_reverse_iterator new_ptr = const_reverse_iterator(this -> ptr);
    --(*this);
    return new_ptr;
}

//REVERSE ITERATOR
template<typename T>
FrankList<T>::reverse_iterator::reverse_iterator(Node* rhv) 
    :const_reverse_iterator(rhv) {}

template<typename T>
FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator& rhv) 
    :const_reverse_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::reverse_iterator::reverse_iterator(base_iterator&& rhv) 
    :const_reverse_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
T& FrankList<T>::reverse_iterator::operator*() 
{
    return this -> ptr -> val;
}

template<typename T>
T* FrankList<T>::reverse_iterator::operator->() 
{
    return this -> ptr;
}

//CONST ASC ITERATOR
template<typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(Node* rhv) 
    :base_iterator(rhv) {}

template<typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator& rhv) 
    :base_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator&& rhv) 
    :base_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
const T& FrankList<T>::const_asc_iterator::operator*() const
{
    return this -> ptr -> val;
}

template<typename T>
const T* FrankList<T>::const_asc_iterator::operator->() const
{
    return this -> ptr;
}

template<typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator++()
{
    this -> ptr = this -> ptr -> asc;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator++(value_type)
{
    const_asc_iterator new_ptr = const_asc_iterator(this -> ptr);
    ++(*this);
    return new_ptr;
}

template<typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator--()
{
    this -> ptr = this -> ptr -> desc;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator--(value_type)
{
    const_asc_iterator new_ptr = const_asc_iterator(this -> ptr);
    --(*this);
    return new_ptr;
}

//ASC ITEARTOR
template<typename T>
FrankList<T>::asc_iterator::asc_iterator(Node* rhv) 
    :const_asc_iterator(rhv) {}

template<typename T>
FrankList<T>::asc_iterator::asc_iterator(const base_iterator& rhv) 
    :const_asc_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::asc_iterator::asc_iterator(base_iterator&& rhv) 
    :const_asc_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
T& FrankList<T>::asc_iterator::operator*() 
{
    return this -> ptr -> val;
}

template<typename T>
T* FrankList<T>::asc_iterator::operator->() 
{
    return this -> ptr;
}

//CONST DESC ITERATOR
template<typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(Node* rhv) 
    :base_iterator(rhv) {}

template<typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(const base_iterator& rhv) 
    :base_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(base_iterator&& rhv) 
    :base_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
const T& FrankList<T>::const_desc_iterator::operator*() const
{
    return this -> ptr -> val;
}

template<typename T>
const T* FrankList<T>::const_desc_iterator::operator->() const
{
    return this -> ptr;
}

template<typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator++()
{
    this -> ptr = this -> ptr -> desc;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator++(value_type)
{
    const_desc_iterator new_ptr = const_desc_iterator(this -> ptr);
    ++(*this);
    return new_ptr;
}

template<typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator--()
{
    this -> ptr = this -> ptr -> asc;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator--(value_type)
{
    const_desc_iterator new_ptr = const_desc_iterator(this -> ptr);
    --(*this);
    return new_ptr;
}

//DESC ITERATOR
template<typename T>
FrankList<T>::desc_iterator::desc_iterator(Node* rhv) 
    :const_desc_iterator(rhv) {}

template<typename T>
FrankList<T>::desc_iterator::desc_iterator(const base_iterator& rhv) 
    :const_desc_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::desc_iterator::desc_iterator(base_iterator&& rhv) 
    :const_desc_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
T& FrankList<T>::desc_iterator::operator*() 
{
    return this -> ptr -> val;
}

template<typename T>
T* FrankList<T>::desc_iterator::operator->() 
{
    return this -> ptr;
}


//CONST MULTI ITERATOR
template<typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(Node* rhv) 
    :base_iterator(rhv) {}

template<typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(const base_iterator& rhv) 
    :base_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(base_iterator&& rhv) 
    :base_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
const T& FrankList<T>::const_multi_iterator::operator*() const
{
    return this -> ptr -> val;
}

template<typename T>
const T* FrankList<T>::const_multi_iterator::operator->() const
{
    return this -> ptr;
}

template <typename T>
void FrankList<T>::const_multi_iterator::chmod()
{
    if(mode) mode = false;
    else mode = true;
}

template <typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator++()
{
    if (mode) 
    {
        this -> ptr = this -> ptr -> next;
    }
    else 
    {
        this -> ptr = this -> ptr -> asc;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_multi_iterator FrankList<T>::const_multi_iterator::operator++(value_type)
{
    const_multi_iterator new_ptr = const_multi_iterator(this -> ptr);
    ++(*this);
    return new_ptr;
}

template <typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator--()
{
    if (mode) 
    {
        this -> ptr = this -> ptr -> prev;
    }
    else 
    {
        this -> ptr = this -> ptr -> desc;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_multi_iterator FrankList<T>::const_multi_iterator::operator--(value_type)
{
    const_multi_iterator new_ptr = const_multi_iterator(this -> ptr);
    --(*this);
    return new_ptr;
}

//MULTI ITERATOR
template<typename T>
FrankList<T>::multi_iterator::multi_iterator(Node* rhv) 
    :const_multi_iterator(rhv) {}

template<typename T>
FrankList<T>::multi_iterator::multi_iterator(const base_iterator& rhv) 
    :const_multi_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::multi_iterator::multi_iterator(base_iterator&& rhv) 
    :const_multi_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::multi_iterator& FrankList<T>::multi_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::multi_iterator& FrankList<T>::multi_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
T& FrankList<T>::multi_iterator::operator*() 
{
    return this -> ptr -> val;
}

template<typename T>
T* FrankList<T>::multi_iterator::operator->() 
{
    return this -> ptr;
}

//CONST MULTI REVERSE ITERATOR
template<typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(Node* rhv) 
    :base_iterator(rhv) {}

template<typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(const base_iterator& rhv) 
    :base_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(base_iterator&& rhv) 
    :base_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
const T& FrankList<T>::const_multi_reverse_iterator::operator*() const
{
    return this -> ptr -> val;
}

template<typename T>
const T* FrankList<T>::const_multi_reverse_iterator::operator->() const
{
    return this -> ptr;
}

template <typename T>
void FrankList<T>::const_multi_reverse_iterator::chmod()
{
    if(mode) mode = false;
    else mode = true;
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator++()
{
    if (mode) 
    {
        this -> ptr = this -> ptr -> prev;
    }
    else 
    {
        this -> ptr = this -> ptr -> desc;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::const_multi_reverse_iterator::operator++(value_type)
{
    const_multi_reverse_iterator new_ptr = const_multi_reverse_iterator(this -> ptr);
    ++(*this);
    return new_ptr;
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator--()
{
    if (mode) 
    {
        this -> ptr = this -> ptr -> next;
    }
    else 
    {
        this -> ptr = this -> ptr -> asc;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::const_multi_reverse_iterator::operator--(value_type)
{
    const_multi_reverse_iterator new_ptr = const_multi_reverse_iterator(this -> ptr);
    --(*this);
    return new_ptr;
}

//MULTI REVERSE ITERATOR
template<typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(Node* rhv) 
    :const_multi_iterator(rhv) {}

template<typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(const base_iterator& rhv) 
    :const_multi_iterator(rhv.ptr) {}

template<typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(base_iterator&& rhv) 
    :const_multi_iterator(rhv.ptr) 
{
    rhv.ptr = nullptr;
}

template<typename T>
const typename FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator=(const base_iterator& rhv)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template<typename T>
const typename FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator=(base_iterator&& rhv)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template<typename T>
T& FrankList<T>::multi_reverse_iterator::operator*() 
{
    return this -> ptr -> val;
}

template<typename T>
T* FrankList<T>::multi_reverse_iterator::operator->() 
{
    return this -> ptr;
}


//BEGIN - END VARIATIONS
template<typename T>
typename FrankList<T>::const_iterator FrankList<T>::cbegin() const
{
    return const_iterator(head);
}

template<typename T>
typename FrankList<T>::const_iterator FrankList<T>::cend() const
{
    return const_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crbegin() const
{
    return const_reverse_iterator(tail);
}

template<typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crend() const
{
    return const_reverse_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::cabegin() const
{
    return const_asc_iterator(ahead);
}

template<typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::caend() const
{
    return const_asc_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdbegin() const
{
    return const_desc_iterator(atail);
}

template<typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdend() const
{
    return const_desc_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmbegin() const
{
    return const_multi_iterator(head);
}

template<typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmend() const
{
    return const_multi_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmabegin() const
{
    return const_multi_iterator(ahead);
}

template<typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmaend() const
{
    return const_multi_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrbegin() const
{
    return const_multi_reverse_iterator(tail);
}

template<typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrend() const
{
    return const_multi_reverse_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdbegin() const
{
    return const_multi_reverse_iterator(ahead);
}

template<typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdend() const
{
    return const_multi_reverse_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::iterator FrankList<T>::begin()
{
    return iterator(head);
}

template<typename T>
typename FrankList<T>::iterator FrankList<T>::end() 
{
    return iterator(nullptr);
}

template<typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rbegin() 
{
    return reverse_iterator(tail);
}

template<typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rend() 
{
    return reverse_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::asc_iterator FrankList<T>::abegin() 
{
    return asc_iterator(ahead);
}

template<typename T>
typename FrankList<T>::asc_iterator FrankList<T>::aend() 
{
    return asc_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dbegin() 
{
    return desc_iterator(atail);
}

template<typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dend() 
{
    return desc_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mbegin()
{
    return multi_iterator(head);
}

template<typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mend()
{
    return multi_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mabegin()
{
    return multi_iterator(ahead);
}

template<typename T>
typename FrankList<T>::multi_iterator FrankList<T>::maend()
{
    return multi_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrbegin()
{
    return multi_reverse_iterator(head);
}

template<typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrend()
{
    return multi_reverse_iterator(nullptr);
}

template<typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdbegin()
{
    return multi_reverse_iterator(ahead);
}

template<typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdend()
{
    return multi_reverse_iterator(nullptr);
}

#endif //ITERATORS_HPP
