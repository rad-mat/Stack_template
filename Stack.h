#pragma once

#include <new>
#define STACK_OVERFLOW      0x01
#define STACK_IS_EMPTY      0x02
#define OTHER_STACK_ERROR   0x08

class StackException
{
public:
    StackException( int errCode = OTHER_STACK_ERROR );
    const char* getReason();
private:
    int m_ErrCode;
};

inline StackException::StackException( int errCode )
{
    m_ErrCode = errCode;
}

inline const char* StackException::getReason()
{
    switch( m_ErrCode )
    {
    case STACK_OVERFLOW:    return "ERROR: Stack overflow!\n";
    case STACK_IS_EMPTY:    return "ERROR: Stack is empty!\n";
    default:                return "Stack error!\n";
    }
}

template <class type> class Stack;

template <class type> class StackItem
{
private:
    StackItem( type Key, StackItem* pHead = nullptr );
    virtual ~StackItem();
    
    type m_Key;
    StackItem* m_pNext;

    friend class Stack<type>;
};

template <class type> class Stack
{
public:
    Stack();
    virtual ~Stack();

    void push( type key );
    type pop();
    type top();
    void del();
    bool isEmpty();

private:
    StackItem<type>* m_pHead;
};

template <class type> StackItem<type>::StackItem( type Key, StackItem* pHead )
{
    m_Key = Key;
    m_pNext = pHead;
}

template <class type> StackItem<type>::~StackItem()
{
}

template <class type> Stack<type>::Stack()
{
    m_pHead = nullptr;
}

template <class type> Stack<type>::~Stack()
{
    while( !isEmpty() ) del();
}

template <class type> void Stack<type>::push( type key )
{
    StackItem<type>* p = new( std::nothrow ) StackItem<type>( key, m_pHead );
    if( !p ) throw StackException( STACK_OVERFLOW );
    m_pHead = p;
}

template <class type> type Stack<type>::pop()
{
    if( isEmpty() ) throw StackException( STACK_IS_EMPTY );
    type x = top();
    del();
    return x;
}

template <class type> type Stack<type>::top()
{
    if( isEmpty() )  throw StackException( STACK_IS_EMPTY );
    return m_pHead->m_Key;
}

template <class type> void Stack<type>::del()
{
    if( isEmpty() ) throw StackException( STACK_IS_EMPTY );
    StackItem<type>* p = m_pHead;
    m_pHead = p->m_pNext;
    delete p;
}

template <class type> bool Stack<type>::isEmpty()
{
    return !m_pHead;
}