#include "xmlparser.h"

xmlparser::xmlparser()
{

}
xmlparser::xmlparser(char *s)
{
    xmlname = s;
}

SuccessEnum xmlparser::loadXML()
{   int id;
    TiXmlDocument doc;
    if(!doc.LoadFile(xmlname))
    {
        cerr << doc.ErrorDesc() << endl;
        return FAILURE;
    }

    TiXmlElement* root = doc.FirstChildElement();
    if(root == NULL)
    {
        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
        return FAILURE;

    }
    cout<<"start parsing"<<endl;
   for(TiXmlElement* ele = root->FirstChildElement(); ele != NULL; ele= ele->NextSiblingElement())
    {
      string elemName = ele->Value();
       if(elemName == "page")
        {


            for(TiXmlElement* elem = ele->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
            {
            string elemName = elem->Value();


        if(elemName == "id")
            {

                const char* temp =elem->GetText();
                id=0;
               for(int i=0;i<strlen(temp);i++)
               {

                   id+=pow(10,(strlen(temp)-i-1))*(int(temp[i])-48);

               }
               //cout<<id<<endl;
            }
            else if(elemName == "revision")
            {
                //const char* arr;

                for(TiXmlElement* e = elem->FirstChildElement("text"); e != NULL; e = e->NextSiblingElement("text"))
                {    //arr = e->Attribute("xml:space");
                    //cout<<id<<endl;
                   // if(e->GetText()==NULL)cout<<"ok"<<endl;
                    if(e->GetText()!=NULL&&strlen(e->GetText())<=300000) //if(id!=277&&id!=1521&&id!=1882&&id!=2478){
                    {   //documentparser jin(e->GetText(),id);
                        //  vector<container> add = jin.getcontai();
                        docum.parse(e->GetText(),id);
                        // dbv.push_back(docum.getcontai());
                      //  cout<<"size: "<<docum.getcontai().size()<<endl;
                       // for(int i=0;i<docum.getcontai().size();i++) index.avlinsert(docum.getcontai()[i]);
                       // docum.clear();

                    }

                }


            }
        }
    }
}
 //index.height();
    return SUCCESS;
}
