#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "documentparser.h"
#include "tinyxml.h"
#include <iostream>
#include <string>
#include <cmath>
#include "indexstruct.h"
using namespace std;
enum SuccessEnum {FAILURE, SUCCESS};
class xmlparser
{
private: char* xmlname;
        // IndexStruct index;
         documentparser docum;

        // vector <const char *> words;
public:
    xmlparser();
    xmlparser(char*);
    SuccessEnum loadXML();
    void find(wstring);

};
inline void xmlparser::find(wstring ws)
{

   docum.setstore(ws);
   docum.stem();
   docum.find();
}

#endif // XMLPARSER_H
