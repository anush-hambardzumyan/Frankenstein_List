#ifndef FRANKLIST_HPP
#define FRANKLIST_HPP
#include "franklist.h"

//NODE
template <typename T>
FrankList<T>::Node::Node(T val, Node* next, Node* prev, Node* asc, Node* desc)
    : val(val), next(next), prev(prev), asc(asc), desc(desc) {}

//HELPERS
template<typename T>
void FrankList<T>::put_in_sorted_order(Node* ptr)
{
    if(!head)
    {
        return;
    }

    if (!ahead) 
    {
        ahead = ptr;
        atail = ptr;
        return;
    }

    Node* cur = ahead;
    while (cur -> val <= ptr -> val && cur -> asc) 
    {
        cur = cur -> asc;
    }

    if (cur -> val < ptr -> val) 
    {
        ptr -> asc = cur -> asc;
        cur -> asc = ptr;
        ptr -> desc = cur;
        if (!ptr -> asc) 
        {
            atail = ptr;
        }
    }

    else 
    {
        ptr -> desc = cur -> desc;
        if (cur -> desc) 
        {
            cur -> desc -> asc = ptr;
        }
        else 
        {
            ahead = ptr;
        }
        ptr -> asc = cur;
        cur -> desc = ptr;
    }
}

template<typename T>
void FrankList<T>::organize_left(Node* ptr)
{
    if(!ptr || ptr == head)
    {
        return;
    }

    Node* prev_node = ptr -> prev;
    Node* next_node = ptr -> next;
    prev_node -> next = ptr -> next;

    if(next_node)
    {
        next_node -> prev = ptr -> prev;
    }

    if(prev_node -> prev)
    {
        prev_node -> prev -> next = ptr;
    }
    ptr -> prev = prev_node -> prev;
    ptr -> next = prev_node;
    prev_node -> prev = ptr;
    // std::swap(ptr->val, ptr->prev->val);
    // std::swap(ptr->asc, ptr->prev->asc);
    // std::swap(ptr->desc, ptr->prev->desc);
}

template<typename T>
void FrankList<T>::organize_right(Node* ptr)
{
    std::swap(ptr->val, ptr->next->val);
    std::swap(ptr->asc, ptr->next->asc);
    std::swap(ptr->desc, ptr->next->desc);
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert_def(iter pos, const_reference val)
{
    if(pos.ptr)
    {
        if(pos.ptr == tail) push_back(val);
        else if (pos.ptr == head) push_front(val);
        else 
        {
            Node* new_node = new Node(val);
            pos.ptr -> prev -> next = new_node;
            new_node -> prev = pos.ptr -> prev;
            pos.ptr -> prev = new_node;
            new_node -> next = pos.ptr;
            put_in_sorted_order(new_node);
        }
    }
    return pos;
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert_rev(iter pos, const_reference val)
{
    if(pos.ptr)
    {
        insert_def(pos, val);
        ++pos;
    }
    return pos;
}

//FRANKLIST CTORS
template<typename T>
FrankList<T>::FrankList()
    : head(nullptr) , tail(nullptr) , ahead(nullptr) , atail(nullptr) {}

template<typename T>
FrankList<T>::FrankList(size_type size)
{
    for(int i = 0; i < size; ++i)
    {
        push_back(T());
    }
}

template<typename T>
FrankList<T>::FrankList(size_type size, const_reference init)
{
    for(int i = 0; i < size; ++i)
    {
        push_back(init);
    }
}

template<typename T>
FrankList<T>::FrankList(std::initializer_list<value_type> init)
{
    head = nullptr;
    tail = nullptr;
    ahead = nullptr;
    atail = nullptr;
    for (auto it = init.begin(); it != init.end(); ++it) 
    {
        push_back(*it);
    }
}

template<typename T>
FrankList<T>::FrankList(const FrankList<value_type>& rhv) 
{
    head = nullptr;
    tail = nullptr;
    ahead = nullptr;
    atail = nullptr;

    Node* ptr = rhv.head;
    while(ptr)
    {
        push_back(ptr -> val);
        ptr = ptr -> next;
    }
}

template<typename T>
FrankList<T>::FrankList(FrankList<value_type>&& rhv)
    : head(rhv.head), tail(rhv.tail), ahead(rhv.ahead), atail(rhv.atail)
{
    rhv.head = nullptr;
    rhv.tail = nullptr;
    rhv.ahead = nullptr;
    rhv.atail = nullptr;
}

template<typename T>
template<typename input_iterator>
FrankList<T>::FrankList(input_iterator f, input_iterator l)
{
    head = tail = ahead = atail = nullptr;
    for(auto it = f ; it != l; ++it)
    {
        push_back(*it);
    }
}

template<typename T>
FrankList<T>::~FrankList()
{
    clear();
}

//FRANKLIST METHODS
template<typename T>
void FrankList<T>::swap(FrankList<value_type>& rhv) {
    std::swap(head, rhv.head);
    std::swap(tail, rhv.tail);
    std::swap(ahead, rhv.ahead);
    std::swap(atail, rhv.atail);
}

template <typename T>
std::size_t FrankList<T>::size() const
{
    if(!head)
    {
        return 0;
    }
    else
    {
        int listsize = 0;
        Node* current = head;
        while(current)
        {
            ++listsize;
            current = current -> next;
        }
        return listsize;
    }
}

template<typename T>
bool FrankList<T>::empty() const
{
    if(!head)
    {
        return true;
    }
    return false;
}

template<typename T>
void FrankList<T>::clear() noexcept
{
    if(head)
    {
        Node* current = head;
        Node* nextNode = nullptr;
        while(current) {
            nextNode = current -> next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        ahead = nullptr;
        atail = nullptr;
    }
}

template<typename T>
void FrankList<T>::push_back(const_reference elem)
{
    if (!head) 
    {
        head = new Node(elem);
        tail = head;
        ahead = head;
        atail = head;
    } 
    else 
    {
        Node* ptr = new Node(elem);
        ptr -> prev = tail;
        tail -> next = ptr;
        tail = ptr;
        put_in_sorted_order(ptr);
    }
}

template<typename T>
void FrankList<T>::push_front(const_reference elem)
{
    if(!head)
    {
        head = new Node(elem);
        tail = head;
        ahead = head;
        atail = head;
    }

    else 
    {
        Node* ptr = new Node(elem);
        ptr -> prev = nullptr;
        ptr -> next = head;
        head -> prev = ptr;
        head = ptr;
        put_in_sorted_order(ptr);
    }
}

template<typename T>
void FrankList<T>::pop_back()
{
    if(head)
    {
        if(size() == 1)
        {
            clear();
            return;
        }

        if (tail -> asc) 
        {
            tail -> asc -> desc = tail -> desc;
        }
        if (tail -> desc) 
        {
            tail -> desc -> asc = tail -> asc;
        }

        if(atail == tail)
        {
            if(atail -> desc)
            {
                atail -> desc -> asc = nullptr;
                atail = atail -> desc;
            }
        }

        if(ahead == tail)
        {
            if(ahead -> asc)
            {
                ahead -> asc -> desc = nullptr;
                ahead = ahead -> asc;
            }
        }
        

        Node* ptr = tail;
        tail = tail -> prev;
        tail -> next = nullptr;
        delete ptr;
    }
}

template<typename T>
void FrankList<T>::pop_front()
{
    if(head)
    {
        if(size() == 1)
        {
            clear();
            return;
        }

        if(head -> asc)
        {
            head -> asc -> desc = head -> desc;
        }

        if(head -> desc)
        {
            head -> desc -> asc = head -> asc;
        }

        if(head == atail)
        {
            if(atail -> desc)
            {
                
                atail -> desc -> asc = nullptr;
                atail = atail -> desc;
            }
        }
        
        if(head == ahead)
        {
            if(ahead -> asc)
            {
                ahead -> asc -> desc = nullptr;
                ahead = ahead -> asc;
            }
        }
        
        Node* ptr = head;
        head = head -> next;
        head -> prev = nullptr;
        delete ptr;
    }
}

template<typename T>
void FrankList<T>::print(bool sorted, bool reversed)
{
    if(sorted == false && reversed == false)
    {
        Node* ptr = head;
        while (ptr != nullptr) 
        {
            std::cout << ptr -> val << " ";
            ptr = ptr -> next;
        }
        std::cout << std::endl;
    }

    if(sorted == true && reversed == false)
    {
        Node* ptr = ahead;
        while(ptr)
        {
            std::cout << ptr -> val << " ";
            ptr = ptr -> asc;
        }
        std::cout << std::endl;
    }

    if(sorted == true && reversed == true)
    {
        Node* ptr = atail;
        while(ptr)
        {
            std::cout << ptr -> val << " ";
            ptr = ptr -> desc;
        }
        std::cout << std::endl;
    }

    if(sorted == false && reversed == true)
    {
        Node* ptr = tail;
        while(ptr != nullptr)
        {
            std::cout << ptr -> val << " ";
            ptr = ptr -> prev;
        }
        std::cout << std::endl;
    }
}

template<typename T>
void FrankList<T>::resize(size_type s, const_reference init)
{
    int listsize = size();
    if(s == listsize)
    {
        return;
    }

    if(s > listsize)
    {
        for(int i = 0; i < s - listsize; ++i)
        {
            this -> push_back(init);
        }
    }

    if(s < listsize)
    {
        if(s < 0)
        {
            std::cerr << "Invalid argument: " << std::endl;
            return;
        }
        for(int i = 0; i < listsize - s; ++i)
        {
            this -> pop_back();
        }
    }
}

template<typename T>
const T& FrankList<T>::front() const
{
    if(head)
    {
        return head -> val;
    }
    std::cerr << "List is empty: " << std::endl;
    return -1;
}

template<typename T>
T& FrankList<T>::front()
{
    if(head)
    {
        return head -> val;
    }
    std::cerr << "List is empty: " << std::endl;
    exit(0);
}    

template<typename T>
T& FrankList<T>::back() 
{
    if(head)
    {
        return tail -> val;
    }
    std::cerr << "List is empty: " << std::endl;
    T val = T();
    return val;
}

template<typename T>
const T& FrankList<T>::back() const
{
    if(head)
    {
        return tail -> val;
    }
    std::cerr << "List is empty: " << std::endl;
    exit(0);
}

template<typename T>
const T& FrankList<T>::min() const
{
    if(head)
    {
        return ahead -> val;
    }
    std::cerr << "List is empty: " << std::endl;
    exit(0);
}

template<typename T>
T& FrankList<T>::min() 
{
    if(head)
    {
        return ahead -> val;
    }
    std::cerr << "List is empty: " << std::endl;
    exit(0);
}

template<typename T>
const T& FrankList<T>::max() const
{
    if(head)
    {
        return atail -> val;
    }
    std::cerr << "List is empty: " << std::endl;
    exit(0);
}

template<typename T>
T& FrankList<T>::max() 
{
    if(head)
    {
        return atail -> val;
    }
    std::cerr << "List is empty: " << std::endl;
    exit(0);
}

template<typename T>
void FrankList<T>::reverse()
{
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while(curr != nullptr)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template<typename T>
typename FrankList<T>::iterator FrankList<T>::find(const_reference elem)
{
    iterator it = begin();
    while(it != end())
    {
        if(*it == elem)
        {
            organize_left(it.ptr);
            return it;
        }
        ++it;
    }
    return end();
}

template<typename T>
typename FrankList<T>::iterator FrankList<T>::rfind(const_reference elem)
{
    reverse_iterator it = rbegin();
    while(it != rend())
    {
        if(*it == elem)
        {
            organize_right(it.ptr);
            return it;
        }
        ++it;
    }
    return rend();
}

template <typename T>
template <typename iter>
iter FrankList<T>::erase(iter pos)
{
    iter it(pos.ptr);
    ++it;
    if (pos.ptr == head) 
    {
        pop_front();
        return it;
    }
    if (pos.ptr == tail) 
    {
        pop_back();
        return it;
    }

    Node* ptr = pos.ptr;
    if (ptr -> prev) 
    {
        ptr -> prev -> next = ptr -> next;
    }
    if (ptr -> next) 
    {
        ptr -> next -> prev = ptr -> prev;
    }
    if (ptr -> asc) 
    {
        ptr -> asc -> desc = ptr -> desc;
    }
    if (ptr -> desc) 
    {
        ptr -> desc -> asc = ptr -> asc;
    }
    return it;
}

template <typename T>
template <typename iter>
iter FrankList<T>::erase(iter f, iter l)
{
    for(; f != l; f = erase(f)) {}
    return f;
}

template<typename T>
void FrankList<T>::remove(const_reference val)
{
    iterator it = find(val);
    if(it != end())
    {
        erase(it);
    }
}

template<typename T>
template <typename unary_predicate>
void FrankList<T>::remove_if(unary_predicate func)
{
    iterator it = begin();
    while(it != end())
    {
        if(func(*it))
        {
            it = erase(it);
        }
        else ++it;
    }
}

template<typename T>
template <typename unary_predicate>
void FrankList<T>::traverse(unary_predicate func, bool sorted, bool reversed)
{
    if(!sorted && !reversed)
    {
        auto it = begin();
        while(it != end())
        {
            func(*it);
            ++it;
        }
    }

    if(sorted && !reversed)
    {
        auto it = abegin();
        while(it != aend())
        {
            func(*it);
            ++it;
        }
    }

    if(!sorted && reversed)
    {
        auto it = rbegin();
        while(it != rend())
        {
            func(*it);
            --it;
        }
    }

    if(sorted && reversed)
    {
        auto it = dbegin();
        while(it != dend())
        {
            func(*it);
            --it;
        }
    }
}

template<typename T>
template <typename iter>
iter FrankList<T>::insert(iter pos, size_type size, const_reference val)
{
    for(std::size_t i = 0; i < size; ++i)
    {
        pos = insert(pos,val);
    }
    return pos;
}

template<typename T>
template <typename iter>
iter FrankList<T>::insert(iter pos, std::initializer_list<value_type> init)
{
    for(auto it = init.begin(); it != init.end(); ++it)
    {
        insert(pos,*it);
    }
    return pos;
}

template<typename T>
template <typename iter, typename input_iterator>
iter FrankList<T>::insert(iter pos, input_iterator f, input_iterator l)
{
    for(; f != l; pos = insert(pos,*f) , f++) {}
    return pos;
}

template<typename T>
void FrankList<T>::sort(bool reversed)
{
    if(!head) return;

    if(!reversed)
    {
        Node* tmp = ahead;
        while(tmp)
        {
            tmp -> next = tmp -> asc;
            tmp -> prev = tmp -> desc;
            tmp = tmp -> next;
        }
        head = ahead;
        tail = atail;
    }
    else
    {
        Node* tmp = atail;
        while(tmp)
        {
            tmp -> next = tmp -> desc;
            tmp -> prev = tmp -> asc;
            tmp = tmp -> next;
        }
        head = atail;
        tail = ahead;
    }
}

//ASSIGNMENTS AND OPERATORS
template<typename T>
const FrankList<T>& FrankList<T>::operator=(const FrankList<value_type>& rhv)
{   
    if(this != &rhv)
    {
        this->clear();
        Node* ptr = rhv.head;
        while(ptr)
        {
            push_back(ptr -> val);
            ptr = ptr -> next;
        }
    }
    return *this;
}

template<typename T>
const FrankList<T>& FrankList<T>::operator=(FrankList<value_type>&& rhv)
{   
    if(this != &rhv)
    {
        this->clear();
        this -> head = rhv.head;
        this -> tail = rhv.tail;
        this -> ahead = rhv.ahead;
        this -> atail = rhv.atail;
        rhv.clear();
    }
    return *this;
}

template<typename T>
const FrankList<T>& FrankList<T>::operator=(std::initializer_list<value_type> init)
{
    this -> clear();
    for (int i = 0; i < init.size(); ++i)
    {
        push_back(*(init.begin() + i));
    }
    return *this;
}

template<typename T>
bool FrankList<T>::operator==(const FrankList<value_type>& rhv) const 
{
    if(this->size() != rhv.size()) return false;
    
    Node* ptr1 = this->head;
    Node* ptr2 = rhv.head;

    while(ptr1 && ptr2) 
    {
        if(ptr1->val != ptr2->val) return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}

template<typename T>
bool FrankList<T>::operator!=(const FrankList<value_type>& rhv) const 
{
    return !operator==(rhv);
}

template<typename T>
bool FrankList<T>::operator<(const FrankList<value_type>& rhv) const 
{
    Node* ptr1 = this->head;
    Node* ptr2 = rhv.head;

    while (ptr1 && ptr2) 
    {
        if (ptr1->val < ptr2->val) return true;
        else if (ptr1->val > ptr2->val) return false;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return (ptr1 == nullptr && ptr2 != nullptr);
}

template<typename T>
bool FrankList<T>::operator>(const FrankList<value_type>& rhv) const 
{
    return rhv < *this;
}

template<typename T>
bool FrankList<T>::operator>=(const FrankList<value_type>& rhv) const 
{
    return !operator<(rhv);
}

template<typename T>
bool FrankList<T>::operator<=(const FrankList<value_type>& rhv) const 
{
    return !operator>(rhv);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const FrankList<T>& rhv)
{
    typename FrankList<T>::Node* tmp = rhv.GetHead();
    while (tmp != nullptr) 
    {
        out << tmp->val << " ";
        tmp = tmp->next;
    }
    return out;
}

#endif //FRANKLIST_HPP


