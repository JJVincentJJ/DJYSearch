#ifndef QUERYPARSER_H
#define QUERYPARSER_H
#include <vector>
#include <container.h>

class queryparser
{

private:
    std::vector<int> p; // the vector of int after query
    std::string key;     //key word: AND OR NOT
public:
    queryparser();
    std::vector<int> AND(std::vector<int>&,std::vector<int> &);
    std::vector<int> OR(std::vector<int>&,std::vector<int>&);
    void clear();

    std::vector<int> getp();

};

#endif // QUERYPARSER_H
