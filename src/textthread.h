#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include "types.h"

class TextThread;
class TextThreads;

typedef std::shared_ptr<TextThread> TextThreadPtr;

/** Text thread */
class TextThread
{
private:
	bool _active;
	string _mask;

private:
	void run();

public:
	TextThread();
	void create(const string &mask);
	void stop() { _active = false; }
};

/** Text thread list */
class TextThreads
{
private:
	ushort _threadCount;
	std::vector<TextThreadPtr> _data;

public:
	TextThreads(ushort threadCount = 4);
	~TextThreads();
	void create(const string &mask);
	void remove();
};

#endif // TEXTTHREAD_H
