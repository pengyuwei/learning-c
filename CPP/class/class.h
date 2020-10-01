#ifndef _CLASS_H_
#define _OVERLOAD_H_

class Demo {
        int priv;
        void priv_func(){};
    public:
        Demo();
        Demo(int a);
        ~Demo();
    public:
        int var;
        int show(int a);
    protected:
        int prot;
    private:
        int priv2;
};

#endif