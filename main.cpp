#include "tinyxml.h"
#include <iostream>
#include "indexstruct.h"
#include "avltree.h"
#include "container.h"
#include "queryparser.h"
#include "xmlparser.h"
#include <stack>
#include <string>

#include "stemming/english_stem.h"



int main()
{



  xmlparser xml("wiki.xml");
  xml.loadXML();
   cout<<"finish loading!"<<endl;
   string temp("hello");
   cin>>temp;


   wchar_t* UnicodeTextBuffer = new wchar_t[temp.length()+1];
   std::wmemset(UnicodeTextBuffer, 0, temp.length()+1);
   std::mbstowcs(UnicodeTextBuffer, temp.c_str(), temp.length());
   wstring ws = UnicodeTextBuffer;
   //cout<<i;
   xml.find(ws);

/*  for(int i=0;i<800000;i++)
     { for(int j=0;j<0;j++)
      {
          //for(int k=0;k<5000;k++){}
      }
      cout<<i<<endl;
  }*/

    cout << "Hello World!" << endl;
    return 0;
}
