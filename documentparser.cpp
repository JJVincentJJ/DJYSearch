#include "documentparser.h"
#include "stemming/english_stem.h"
#include <vector>
documentparser::documentparser()
{
    ifstream fin;
    fin.open("stopwords");
    vector<wstring> stopwords;
    while(fin)
    {

      string temp;
   getline(fin,temp);

      // convert to wstring
      wchar_t* UnicodeTextBuffer = new wchar_t[temp.length()+1];
      std::wmemset(UnicodeTextBuffer, 0, temp.length()+1);
      std::mbstowcs(UnicodeTextBuffer, temp.c_str(), temp.length());
      //convert over
      stopwords.push_back(UnicodeTextBuffer);

    }

    fin.close();

}
void documentparser::parse(const char* c,int id)
{  int jin =1;
 //  cout<<"length: "<<strlen(c)<<endl;
    int i=0;
    string temp;
   while(c[i]!='\0')
    {
       if(c[i]!=39){
        while((c[i]>=65&&c[i]<=90)||(c[i]>=97&&c[i]<=122)||c[i]==39)
        {
            char t=c[i];
            if(t<=90&&t>39) t+=32;
            temp.push_back(t);

           i++;

        }}// while the char is english store it in string;
        if(temp.size()!=0&&temp.size()<=30)
        {   //convert temp to wstring
            wchar_t* UnicodeTextBuffer = new wchar_t[temp.length()+1];
            std::wmemset(UnicodeTextBuffer, 0, temp.length()+1);
            std::mbstowcs(UnicodeTextBuffer, temp.c_str(), temp.length());
            //convert over
            store = UnicodeTextBuffer;
            stop();

            temp.clear();
        }

       //if(store.size()!=0)
       //  {
             //  stem();
            //   stop();

             if(store.size()!=0)
             {
                 StemEnglish(store);
                 avl.insert(store,id,jin);

                 store.clear();

             }// end store size != 0
        // }

        i++;

    }

}
documentparser::documentparser(const char* c,int id)
{

    ifstream fin;
    fin.open("stopwords");
    vector<wstring> stopwords;
    while(fin)
    {

      string temp;
      getline(fin,temp);

      // convert to wstring
      wchar_t* UnicodeTextBuffer = new wchar_t[temp.length()+1];
      std::wmemset(UnicodeTextBuffer, 0, temp.length()+1);
      std::mbstowcs(UnicodeTextBuffer, temp.c_str(), temp.length());
      //convert over
      stopwords.push_back(UnicodeTextBuffer);
    }
    fin.close();
    int i=0;
    while(c[i]!='\0')
    {
        string temp;
        while((c[i]>=65&&c[i]<=90)||(c[i]>=97&&c[i]<=122)||c[i]==39)
        {
           temp.push_back(c[i]);
           i++;
        }// while the char is english store it in string;
        if(temp.size()!=0)
        {   //convert temp to wstring
            wchar_t* UnicodeTextBuffer = new wchar_t[temp.length()+1];
            std::wmemset(UnicodeTextBuffer, 0, temp.length()+1);
            std::mbstowcs(UnicodeTextBuffer, temp.c_str(), temp.length());
            //convert over
            store = UnicodeTextBuffer;
            temp.clear();
        }
        if(store.size()!=0)
        {
            stem();
            stop();
        }
}

 // test();
}
void documentparser::test()
{
    //avl.inorder();
}

void documentparser::stem()
{
      stemming::english_stem<> StemEnglish;
     // std::wstring word =store;

       StemEnglish(store);

//       store = word;


}
void documentparser::stop()
{

    for(int i =0; i <stopwords.size();i++)
    {
        if(store == stopwords[i])
           store.clear();
    }


}
vector<container>& documentparser::getcontai()
{
    //return contai;
}
