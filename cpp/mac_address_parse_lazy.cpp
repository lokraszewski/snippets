#include <cstring>
#include <iostream>
#include <vector>

std::vector<int> mac_parse(const std::string &s)
{

  auto constexpr mac_len = 6;
  std::vector<int> r;

  char *pend = const_cast<char *>(s.c_str());

  for (auto i = mac_len; i--;)
  {
    while (*pend && isalnum(*pend) == false) ++pend;

    if (!*pend)
      return r;

    r.push_back(strtol(pend, &pend, 16));
  }
  return r;
}

int main()
{

  std::vector<std::string> input = {"    : : }{  }", "0xbc 0xfb 0x81 0x8e 0xac 0x10 0x42 0x01", "bc:fb:81:8e:ac:10:42:01",
                                    "bc  fb           81 8e               ac 10 42 01", "bc:fb:81:"};
  std::cout << std::hex;
  for (auto mac : input)
  {
    for (auto e : mac_parse(mac))
    {
      std::cout << e << ' ';
    }
    std::cout << std::endl;
  }
}
