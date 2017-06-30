#pragma once

namespace Tree
{
    template <class T>
    class Node
    {
        public:
            Node();
            Node(Node<T> * node);
            Node(T * data);

            ~Node();

            void Insert(T * data);

            T * GetDataAddress();
            T GetData();
            void SetData(T * data);

            Node<T> * GetRight();
            Node<T> * GetLeft();

        protected:
            void Insert(T * data, Node<T> * node);

            Node<T> * m_right;
            Node<T> * m_left;

            T * m_data;
    };
}

template <class T>
inline Tree::Node<T>::Node()
{
    m_left = nullptr;
    m_right = nullptr;
    m_data = nullptr;
}

template<class T>
inline Tree::Node<T>::Node(Node<T> * node)
{
    m_left = nullptr;
    m_right = nullptr;
    m_data = &node->GetData();
}

template<class T>
inline Tree::Node<T>::Node(T * data)
{
    m_left = nullptr;
    m_right = nullptr;
    m_data = data;
}

template <class T>
inline Tree::Node<T>::~Node()
{
    delete m_left;
    delete m_right;
}

template <class T>
inline void Tree::Node<T>::Insert(T * data)
{
    if(m_data == nullptr)
    {
        m_data = data;
        return;
    }

    if (*data == *m_data)
    {
        return;
    }

    if (*data < *m_data)
    {
        if(m_left == nullptr)
        {
            m_left = new Node<T>(data);
        }
        else
        {
            Insert(data, m_left); 
        }

        return;
    }
    else if (*data > *m_data)
    {
        if (m_right == nullptr)
        {
            m_right = new Node<T>(data);
        }
        else
        {
            Insert(data, m_right);
        }

        return;
    }
}

template <class T>
inline void Tree::Node<T>::Insert(T * data, Node<T> * node)
{
    if(node->GetData() == NULL)
    {
        node->SetData(data);
        return;
    }

    if (data == (T*)node->GetData())
    {
        return;
    }

    if (data < (T*)node->GetData())
    {
        if (node->m_left != nullptr)
        {
            node->Insert(data, node->m_left);
        }
        else
        {
            node->m_left = new Node<T>(data);
        }

        return;
    }
    else if (data > (T*)node->GetData())
    {
        if (node->m_right != nullptr)
        {
            node->Insert(data, node->m_right);
        }
        else
        {
            node->m_right = new Node<T>(data);
        }

        return;
    }
}

template<class T>
inline T * Tree::Node<T>::GetDataAddress()
{
    return m_data;
}

template<class T>
inline T Tree::Node<T>::GetData()
{
    if(m_data == nullptr)
    {
        return NULL;
    }
    
    return *m_data;
}

template<class T>
inline void Tree::Node<T>::SetData(T * data)
{
    m_data = data;
}

template<class T>
inline Tree::Node<T> * Tree::Node<T>::GetRight()
{
    return m_right;
}

template<class T>
inline Tree::Node<T> * Tree::Node<T>::GetLeft()
{
    return m_left;
}
