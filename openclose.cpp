#include "openclose.h"
OpenClose* OpenClose::s=nullptr;
OpenClose::OpenClose()
{

}

OpenClose::~OpenClose()
{
    s=nullptr;
    delete s;
}
