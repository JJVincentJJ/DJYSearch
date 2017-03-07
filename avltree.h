#ifndef AVLTREE
#define AVLTREE
#include "node.h"
#include <iostream>

template <class T>
class AvlTree
{
   private: Node<T>* root;
            //T key;
    bool sameflag ; // check for same value happen
            void insert(T&,Node<T>*&,int&,int&);
            void rotatecase1(Node<T>* &);
            void rotatecase2(Node<T>* &);
            void rotatecase3(Node<T>* &);
            void rotatecase4(Node<T>* &);
   public: AvlTree();
            AvlTree(const AvlTree<T>&);
            AvlTree(T t,int,int);
           //AvlTree(const AvlTree & avl);
           ~AvlTree();
           bool isEmpty();
           void insert(T&,int&,int&);
           void delet();
           int height(Node<T> *);
           int max(int,int);
            void find(T);
            T find(Node<T>*,T );
           void inorder(Node<T>*);
           void inorder();
           Node<T>* getroot();
           const Node<T>* getconstrot() const;


};
template <class T>
const Node<T>* AvlTree<T>::getconstrot() const
{
    return root;
}

template <class T>
AvlTree<T>::AvlTree(const AvlTree<T>& avl)
{
 int id = avl.getconstrot()->p.pagenum[0];
 int f = avl.getconstrot()->p.frequency[0];
 root =  new Node<T> (avl.getconstrot()->getconst(),id,f);
}
template<class T>
AvlTree<T>::AvlTree(T t,int id,int f)
{
    root = new Node<T>(t,id,f);
}

template<class T>
Node<T>* AvlTree<T>::getroot()
{
    return root;
}
template <class T>
void AvlTree<T>::find(T t)
{
     find(root,t);

}
template <class T>
T AvlTree<T>::find(Node<T>* n,T t)
{

    if(t==n->get())
    {
       std::wcout<<n->get()<<std::endl;
       for(int i=0;i<n->p.pagenum.size();i++)
       {
           std::cout<<n->p.pagenum[i]<<" "<<n->p.frequency[i]<<"times"<<std::endl;
       }

        return n->get();
    }
    else
    {
        if(t>n->get())
        {    if(n->getright()!=NULL)
              { return find(n->getright(),t);}
              else return t;
        }
           else if(t<n->get())
            {
                if(n->getleft()!=NULL)
                  {  return find(n->getleft(),t);}
               else return t;
            }

    }
}
template <class T>
void AvlTree<T>::inorder()
{
    inorder(root);
}

template <class T>
void AvlTree<T>::inorder(Node<T> * node)
{
    if(node->getleft()==NULL&&node->getright()==NULL)
    {
        std::wcout<<node->get()<<" "<<std::endl;
    }
    else
    {
        if(node->getleft()!=NULL)inorder(node->getleft());
        std::wcout<<node->get()<<" "<<std::endl;
        if(node->getright()!=NULL)inorder(node->getright());
    }
}

template <class T>
AvlTree<T>::AvlTree()
{
    root = NULL;
}

template <class T>
bool AvlTree<T>::isEmpty()
{
    if(root==NULL) return true;
    else return false;
}
template <class T>
void AvlTree<T>::insert(T& t,int& page,int& f)
{  sameflag =false;
    insert(t,root,page,f);
}
template <class T>
void AvlTree<T>::insert(T& t,Node<T>*& node,int& page,int& f)
{
    if(node==NULL)
    {
        node = new Node<T>(t,page,f);
    }
    else if(t == node->get())
        {  sameflag = true;
          if( page == node->p.pagenum.back())
          {
              node->p.frequency.back()++;
          }
          else{node->p.pagenum.push_back(page);node->p.frequency.push_back(f);}
        }
    else
        if(t<node->get()) //left
        {
            insert(t,node->getleft(),page,f);
            if(height(node->getleft())-height(node->getright())==2)
                if(t<node->getleft()->get())
                {
                    rotatecase1(node);
                }
            else rotatecase2(node);
        }
    else if(t>node->get()) //right
        {
            insert(t,node->getright(),page,f);
            if(height(node->getright())-height(node->getleft())==2)
                if(t>node->getright()->get())
                {
                    rotatecase4(node);
                }
            else rotatecase3(node);
        }

   if(!sameflag) node->setheight(max(height(node->getleft()),height(node->getright()))+1);

}
template <class T>
void AvlTree<T>::delet()
{
    delete root;
    root = NULL;
}
template <class T>
int AvlTree<T>::height(Node<T> * node)
{
    if(node == NULL) return 0;
    else
    return node->getheight();
}

template <class T>
void AvlTree<T>::rotatecase1(Node<T>*& node)
{
    Node<T> * temp = node->getleft();
    node->setleft(temp->getright());
    temp->setright(node);
    temp->setheight(max(height(temp->getleft()),height(temp->getright()))+1);
    node->setheight(max(height(node->getleft()),height(node->getright()))+1);
    node = temp;


}
template <class T>
void AvlTree<T>::rotatecase4(Node<T> *& node)
{
    Node<T> * temp = node->getright();
    node->setright(temp->getleft());
    temp->setleft(node);
    temp->setheight(max(height(temp->getleft()),height(temp->getright()))+1);
    node->setheight(max(height(node->getleft()),height(node->getright()))+1);
    node  = temp;

}
template <class T>
void AvlTree<T>::rotatecase2(Node<T> *& node)
{
    rotatecase4(node->getleft());
    rotatecase1(node);
}
template <class T>
void AvlTree<T>::rotatecase3(Node<T> *& node)
{
    rotatecase1(node->getright());
    rotatecase4(node);
}
template <class T>
int AvlTree<T>::max(int i1,int i2)
{
    if(i1>i2) return i1;
    if(i2>i1) return i2;
    if(i1==i2) return i1;
}

template <class T>
AvlTree<T>::~AvlTree()
{
    delete root;
}

#endif // AVLTREE
