#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T t;
   Node<T>* sig;
};

template <typename T>
Node<T>* add(Node<T>*& p,T e)
{
   // inicializo con memoria dinamica y valores en nuevo node
   Node<T>* nuevo = new Node<T>();
   nuevo->t = e;
   nuevo->sig = NULL;

   if (p!=NULL)
   {
      // creamos un node auxiliar que apunte a p
      Node<T>* aux = p;
      while (aux->sig!=NULL)
      {
         // aux apunte al siguiente node
         aux = aux->sig;
      }
         // enlazo el nuevo nodo
         aux->sig = nuevo;
   }
   else
   {
      // cambio la direccion apuntada por p , y nuevo es el primero
      p = nuevo;
   }
   return nuevo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{
   
   return NULL;
}

template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K))
{
   T t;
   return t;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   T t;
   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))
{
   return NULL;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{
   return NULL;
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
   return NULL;
}

template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))
{
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   return true;
}

template <typename T>
void free(Node<T>*& p)
{
}

template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
   return NULL;
}

template <typename T> T pop(Node<T>*& p)
{
   T t;
   return t;
}

template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)
{
   return NULL;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
   return NULL;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t;
   return t;
}

template <typename T>
T dequeue(Node<T>*& q)
{
   T t;
   return t;
}


#endif
