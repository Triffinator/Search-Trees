#pragma once
#include "Node.h"
#include <cstdlib>

namespace Tree
{
    template <class T>
    class BSTree
    {
    public:
        BSTree();
        BSTree(T * data);

        ~BSTree();
        Tree::Node<T> * GetRoot();

        void Insert(T * data);
        Tree::Node<T> * Search(T * key);

    private:

        void Insert(T * data, Node<T> * node);
        Tree::Node<T> * Search(T* key, Node<T> * node);
        Node<T> * m_root;
    };
}

template<class T>
inline Tree::BSTree<T>::BSTree()
{
    m_root = new Node<T>();
}

template<class T>
inline Tree::BSTree<T>::BSTree(T * data)
{
    m_root = new Node<T>(data);
}

template<class T>
inline Tree::BSTree<T>::~BSTree()
{
    m_root->Destroy();
    delete m_root;
}

template<class T>
inline Tree::Node<T>* Tree::BSTree<T>::GetRoot()
{
    return m_root;
}

template<class T>
inline void Tree::BSTree<T>::Insert(T * data)
{
    if (m_root != nullptr)
    {
        Insert(data, m_root);
    }
    else
    {
        m_root = new Tree::Node<T>(data);
    }
}

template<class T>
inline void Tree::BSTree<T>::Insert(T * data, Node<T>* node)
{
    if (m_root != nullptr)
    {
        m_root->Insert((T*)data);
        return;
    }

    m_root = node;
}

template<class T>
inline Tree::Node<T>* Tree::BSTree<T>::Search(T * key)
{
    return Search(key, m_root);
}

template<class T>
inline Tree::Node<T> * Tree::BSTree<T>::Search(T * key, Node<T> * node)
{
    if (node != nullptr)
    {
        if (*key == node->GetData())
        {
            return node;
        }

        if (*key < node->GetData())
        {
            return Search(key, node->GetLeft());
        }

        if (*key > node->GetData())
        {
            return Search(key, node->GetRight());
        }

        return nullptr;
    }
    else
    {
        return nullptr;
    }
}