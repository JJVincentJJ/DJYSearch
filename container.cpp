#include "container.h"

container::container()
{
    //s="null";

}
container::container(std::wstring s,int pagenum, int f)
{
    this->s=s;
    this->setpage(pagenum,f);
}
container::~container()
{

}
void container::setpage(int pagenum,int f)
{
    p.pagenum.push_back(pagenum);
    p.frequency.push_back(f);
}
bool operator<(const container& c,const container& c1)
{
    return c.s<c1.s;
}
bool operator>( const container& c,const container& c1)
{
    return c.s>c1.s;
}
bool operator==(const container& c,const container& c1)
{
    return c.s==c1.s;
}
std::wostream& operator<<(std::wostream& o,const container & c)
{
     o<<c.s.c_str()<<std::endl;
     o<<L"\t"<<L"page: ";
     for(int i=0;i<c.p.pagenum.size();i++)
     {
         o<<c.p.pagenum[i]<<L" appears:"<<c.p.frequency[i]<<L"times!!   ";
     }

     o<<std::endl;
  return o;
}
page container::getpage()
{
    return this->p;
}
