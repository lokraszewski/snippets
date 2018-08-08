#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
vector<int> mac_parse(std::string s)
{
  auto constexpr mac_len = 6;
  vector<int> r;
  r.reserve(mac_len);
  std::stringstream ss(s);
  for (auto i = mac_len; i--;)
  {
    int  byte;
    char seperator;
    ss >> std::hex >> byte >> seperator;
    r.push_back(byte);
  }
  return r;
}

int main()
{

  std::vector<std::string> input = {"bc fb 81 8e ac 10 42 01", "0xbc 0xfb 0x81 0x8e 0xac 0x10 0x42 0x01", "bc:fb:81:8e:ac:10:42:01"};

  for (auto mac : input)
  {
    for (auto e : mac_parse(mac))
    {
      std::cout << std::hex << e << std::endl;
    }
  }
}
