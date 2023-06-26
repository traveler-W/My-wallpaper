#ifndef OPENCLOSE_H
#define OPENCLOSE_H


class OpenClose
{
   static OpenClose*s;
public:
    OpenClose();
    ~OpenClose();
    static OpenClose* infor()
    {
        if(s==nullptr)
        {
            return s=new OpenClose;
        }
        return s;
    }
    bool selectquit;
    bool selectrun;

};

#endif // OPENCLOSE_H
