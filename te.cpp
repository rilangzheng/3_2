#include<iostream>
#include<cstring>
using namespace std;
class Name
{
    public:
        Name(const char *pn);//char*等价于字符数组
        Name(const Name &Obj);
        ~Name();
        void setname(const char *pn);
        void showname();
    protected:
        char *pName;
        int size;
};
//定义复制构造函数
Name::Name(const Name &Obj)
{
    cout<<"copying"<<Obj.pName<<"into its own block\n";
    pName=new char[strlen(Obj.pName)+1];
    if(pName!=0) strcpy_s(pName,strlen(Obj.pName)+1,Obj.pName);
    size=Obj.size;
}

//构造函数
Name::Name(const char *pn)
{
    cout<<"Constructing"<<pn<<endl;
    pName=new char[strlen(pn)+1];
    if(pName!=0) strcpy_s(pName,strlen(pn)+1,pn);
    size=strlen(pn);
}

//析构
Name::~Name()
{
    cout<<"destructing"<<pName<<endl;
    pName[0]='\0';
    delete []pName;
    pName=NULL;
    size=0;
}

//成员函数
void Name::setname(const char *pn)
{
    delete []pName;
    pName=new char[strlen(pn)+1];
    if(pName!=0) strcpy_s(pName,strlen(pn)+1,pn);
    size=strlen(pn);
}
void Name::showname()
{
    cout<<pName<<endl;
}
int main()
{
    Name obj1("Noname");
    Name obj2=obj1;
    obj1.showname();
    obj2.showname();
    obj1.setname("aaa");
    obj2.setname("bbb");
    obj1.showname();
    obj2.showname();
}