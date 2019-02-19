

#ifndef TEST_H
#define TEST_H
class test
{
  public :
    test()=default;
    ~test() noexcept =default;
    test(const test &)=default;
    test & operator=(const test &)=default;
    test(test &&)=default;
    test & operator=(test &&)=default;
};

#endif
