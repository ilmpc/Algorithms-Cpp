#include <boost/ut.hpp>
#include <../lib/main.cpp>

using namespace boost::ut;
int main() {
  expect(true);
  expect(a() == 1);
}