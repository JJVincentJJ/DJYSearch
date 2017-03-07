#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <vector>
#include <iostream>
struct page
{
   std::vector<int> pagenum;
   std::vector<int> frequency;
};

class container
{
private:
    std::wstring s;
    page p;

public:
    container();
    container(const container&);
    ~container();
    friend bool operator<(const container &,const container&);
    friend bool operator>(const container&, const container&);
    friend bool operator==(const container&, const container&);
    container(std::wstring ,int,int);
    void setpage(int,int);
    page getpage();
    friend std::wostream& operator<<(std::wostream&,const container&);
     std::wstring& gets();
     void frequencyplus();
   container operator+=(const container&);
   //friend container& operator+(container &,container&);

};
inline container::container(const container& c)
{
     this->s=c.s;
    this->p=c.p;
}
inline void container::frequencyplus()
{
  p.frequency[0]++;
}

inline std::wstring& container::gets()
{
    return s;
}
inline container container::operator+=(const container& c2)
{
   if(c2.p.pagenum[0]!=p.pagenum.at(p.pagenum.size()-1))
    this->setpage(c2.p.pagenum[0],c2.p.frequency[0]);
    else this->p.frequency.at(p.frequency.size()-1)++;
    return *this;
}

#endif // CONTAINER_H
