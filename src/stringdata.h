#ifndef STRINGDATA_H
#define STRINGDATA_H

#include "types.h"
#include <queue>

struct StringData
{
	ulong number;
	string text;

	StringData() {}
	StringData(ulong number_, const string &text_)
		: number(number_), text(text_) {}
};

struct FoundStringData
{
	ulong number;
	ulong position;
	string text;

	FoundStringData() {}
	FoundStringData(ulong number_, ulong position_, const string &text_)
		: number(number_), position(position_), text(text_) {}
};

typedef std::queue<StringData> InputStrings;
typedef std::vector<FoundStringData> FoundStrings;
typedef std::vector<FoundStringData>::iterator FoundStringsIterator;
typedef std::vector<FoundStringData>::const_iterator FoundStringsConstIterator;

#endif // STRINGDATA_H
