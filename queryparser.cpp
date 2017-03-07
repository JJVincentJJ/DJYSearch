#include "queryparser.h"

queryparser::queryparser()
{

}
std::vector<int> queryparser::getp()
{
    return p;
}

std::vector<int> queryparser::AND(std::vector<int> &c1,std::vector<int> & c2)
{
    for(int i=0;i<c1.size();i++)
    {
        for(int j=0;j<c2.size();j++)
        {
            if(c1[i]==c2[j])
                p.push_back(c1[i]);
        }
    }
    return p;
}
std::vector<int> queryparser::OR(std::vector<int>& c1,std::vector<int> & c2)
{
    for(int i=0;i<c1.size();i++)
    {
        p.push_back(c1[i]);
    }
    for(int i=0;i<c2.size();i++)
    {
        bool flag =false;
        for(int j=0;j<c1.size();j++)
        {
            if(c2[i]==c1[j])
                 flag = true;
        }
        if(!flag)
            p.push_back(c2[i]);
    }
        return p;
}
void queryparser::clear()
{
    p.clear();
}
