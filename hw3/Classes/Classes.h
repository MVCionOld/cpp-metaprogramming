#ifndef HW3_CLASSES_H
#define HW3_CLASSES_H

#include <iostream>

class A {};

class B {};

class C {};

std::ostream& operator<<(std::ostream& os, const A& a)
{
  os << "class A";
  return os;
}

std::ostream& operator<<(std::ostream& os, const B& b)
{
  os << "class B";
  return os;
}

std::ostream& operator<<(std::ostream& os, const C& c)
{
  os << "class C";
  return os;
}

#endif //HW3_CLASSES_H
