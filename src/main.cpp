#include "cmdparser.h"
#include "textreader.h"
#include "textthread.h"
#include "counter.h"

int main(int argc, char **argv)
{
	CmdParser cmdParser;
	cmdParser.parse(argc, argv);

	Counter counter;
	TextThreads threads;
	threads.create(cmdParser.getMask());

	TextReader::instance()->setFileName(cmdParser.getInputFile());
	TextReader::instance()->start();

	counter.show();
	return 0;
}
