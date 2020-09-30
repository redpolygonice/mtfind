#ifndef CMDPARSER_H
#define CMDPARSER_H

#include "types.h"

/** Command line parser */
class CmdParser
{
private:
	string _fileName;
	string _mask;
	const ushort _maskLength = 100;

public:
	CmdParser();
	void parse(int argc, char **argv);
	inline string getInputFile() const { return _fileName; }
	inline string getMask() const { return _mask; }
};

#endif // CMDPARSER_H
