#ifndef TEXTPROC_H
#define TEXTPROC_H

#include "types.h"
#include "singleton.h"
#include "stringdata.h"

#include <mutex>

/** Text processor */
class TextReader : public Singleton<TextReader>
{
	friend class Singleton<TextReader>;

private:
	string _fileName;
	string _mask;
	InputStrings _data;
	FoundStrings _foundData;
	std::mutex _dataMutex;
	std::mutex _stringMutex;
	std::mutex _foundMutex;

private:
	TextReader();
	void print();

public:
	void start();
	inline void setFileName(const string &fileName) { _fileName = fileName; }
	inline void setMask(const string &mask) { _mask = mask; }
	inline string getMask() const { return _mask; }
	StringData getNextString();
	void addFoundString(const FoundStringData &data);
};

#endif // TEXTPROC_H
