#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <memory>
using std::string;

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

typedef std::vector<string> StringList;
typedef std::vector<string>::iterator StringListIterator;
typedef std::vector<string>::const_iterator StringListConstIterator;

#endif // TYPES_H
