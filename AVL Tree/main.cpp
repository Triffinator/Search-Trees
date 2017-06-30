#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Node.h"
#include "AVLTree.h"
#include "BSTree.h"

template <class T>
void Search(Tree::AVLTree<T> * avl, T * attempt)
{
    std::cout << "Value searched: " << *attempt << "\n" << std::endl;

    Tree::Node<T> * node = avl->Search(attempt);
    if (node != nullptr)
    {
        T data = node->GetData();
        std::cout << "Value found: " << data << std::endl;
    }
    else
    {
        std::cout << "Data not found!" << std::endl;
    }
}

template <class T>
Tree::AVLTree<T> * Populate(Tree::AVLTree<T> * avl)
{
    int** a = new int*();

    for (int i = 0; i < 10; ++i)
    {
        a[i] = new int;
        *a[i] = rand() % 1000 + 1;
        std::cout << *a[i] << "\n" << std::endl;
        avl->Insert(a[i]);
    }

    return avl;
}

template <class T>
Tree::AVLTree<T> * Populate(Tree::AVLTree<T> * avl, int seed)
{
    int** a = new int*();

    srand(seed);

    return Populate(avl);
}

int main(int argc, char ** argv)
{ 
    Tree::AVLTree<int> * avl = new Tree::AVLTree<int>();

    //int seed = 0;
    int seed = time(NULL);
    avl = Populate(avl, seed);

    //int attempt = 10001;
    int attempt = 856;
    Search(avl, &attempt);

    int pause;
    std::cin >> pause;

    return 0;
}