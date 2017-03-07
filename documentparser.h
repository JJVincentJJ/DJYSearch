#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H
#include "stemming/english_stem.h"
#include <fstream>
#include <iostream>
#include <string>
#include  "queryparser.h"
#include "avltree.h"
#include <vector>
#include "indexstruct.h"
using namespace std;
class documentparser
{
private: wstring store;
         vector<wstring> stopwords;
        // vector<wstring> contai;
         vector<int> cool;
         int id;
         AvlTree<wstring> avl;
         stemming::english_stem<> StemEnglish;



public:
    documentparser();
    documentparser(const char*,int id); // take the text from xml parser
    void parse(const char*,int id);
    void stem();
    void stop();
    void setstore(wstring);
    void test();
    vector<container>& getcontai();
    wstring getstore();
    void clear();
    void find();


};
inline void documentparser::find()
{

    avl.find(store);
}

inline void documentparser::clear()
{
    //contai.clear();
    store.clear();
}

inline wstring documentparser::getstore()
{
  return store;
}
inline void documentparser::setstore(wstring ws)
{
    this->store = ws;
}

#endif // DOCUMENTPARSER_H
