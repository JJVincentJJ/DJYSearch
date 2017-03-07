#include "indexstruct.h"
IndexStruct::IndexStruct()
{

}
void IndexStruct::avlinsert(wstring c,int id,int f)
{ //test.insert(c);
  if(avl.size()==0)
    { AvlTree<wstring> temp(c,id,f);

      avl.push_back(temp);     //caution: the cpy constructor only works for one element tree!
    }
  else
  {
      bool flag =false;
      for(int i =0;i<avl.size();i++)
      {
          if(avl.at(i).getroot()->get()[0]==c[0])
          {
              flag = true;
              avl[i].insert(c,id,f);
          }

      }
      if(!flag) avl.push_back(AvlTree<wstring>(c,id,f)); //caution the cpy constuc only works for one element tree!

   }
}
void IndexStruct::inorder()
{
   for(int i=0;i<avl.size();i++)
   {
       avl[i].inorder();
   }
}
void IndexStruct::find(std::wstring ws)
{
   /* for(int i=0;i<avl.size();i++)
    {
        if(avl[i].getroot()->get().gets()[0]==ws[0])
           { avl[i].find(container(ws,0,0));break;}
    }*/
    //test.find(container(ws,0,0));

}
