#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

struct SymbolTableNode {
  std::string m_name;
  std::string m_type;
  std::string m_attribute;

  SymbolTableNode(std::string name, std::string type, std::string attr = "")
      : m_name(name), m_type(type), m_attribute(attr) {}
};

/**** Symbol Table ****/
// | ID  || NAME  | TYPE | ATTRIBUTE |
// | --- || ----  | ---- | --------- |
// | id1 || name1 | type | attribute |
// | id2 || name2 | type | attribute |
// | id3 || name3 | type | attribute |
//   ...
// | idn || namen | type | attribute |
/**** End ****/

using SymbolTable = std::unordered_map<std::string, SymbolTableNode>;
using Token = std::pair<std::string, std::unique_ptr<SymbolTableNode>>;

auto createNode(std::string name, std::string type, std::string attr = "")
{
  return std::move(std::make_unique<SymbolTableNode>(name, type, attr));
}