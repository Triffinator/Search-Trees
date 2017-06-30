#pragma once
#include "Node.h"

namespace Tree
{
	template <class T>
	class TreeBase
	{
		public:
			TreeBase();
			TreeBase(Node<T> * node);
			TreeBase(T * data);
			TreeBase(T data);

			~TreeBase();

			virtual Node<T>* GetRoot();

		protected:
			Node<T> * m_root;
	};
}

template<class T>
inline Tree::TreeBase<T>::TreeBase()
{
	m_root = new Node<T>();
}

template<class T>
inline Tree::TreeBase<T>::TreeBase(Node<T>* node)
{
	m_root = new Node<T>(node);
}

template<class T>
inline Tree::TreeBase<T>::TreeBase(T * data)
{
	m_root = new Node<T>(data);
}

template<class T>
inline Tree::TreeBase<T>::TreeBase(T data)
{
	m_root = new Node<T>(&data);
}

template<class T>
inline Tree::TreeBase<T>::~TreeBase()
{
	delete m_root;
}