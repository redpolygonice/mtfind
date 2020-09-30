#include "cmdparser.h"

CmdParser::CmdParser()
{
}

void CmdParser::parse(int argc, char **argv)
{
	if (argc >= 2)
		_fileName = argv[1];

	if (argc >= 3)
	{
		_mask = argv[2];
		if (_mask.size() > _maskLength)
			_mask.resize(_maskLength);
	}
}
