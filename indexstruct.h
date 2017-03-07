#ifndef INDEXSTRUCT
#define INDEXSTRUCT
#include "avltree.h"
#include "container.h"
#include <string>
using namespace std;
class IndexStruct
{
 private: std::vector<AvlTree<wstring>> avl;
          AvlTree<wstring> test;
public: IndexStruct();
        void avlinsert(wstring,int,int);
        void hashinsert(container);
        void inorder();
         void find(std::wstring);
         void height();

};

inline void IndexStruct::height()
{
   std::cout<<test.height(test.getroot())<<std::endl;
}

#endif // INDEXSTRUCT

