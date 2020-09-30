#include "textthread.h"
#include "textreader.h"
#include "stringdata.h"
#include "common.h"

#include <regex>

TextThread::TextThread()
:_active(false)
{
}

void TextThread::create(const string &mask)
{
	_active = true;
	_mask = mask;
	std::thread theTread([this]() { run(); });
	theTread.detach();
}

void TextThread::run()
{
	std::smatch match;
	std::regex regEx(_mask);

	while (_active)
	{
		StringData stringData = TextReader::instance()->getNextString();
		if (!stringData.text.empty())
		{
			string text = stringData.text;
			while (std::regex_search(text, match, regEx))
			{
				FoundStringData foundData(stringData.number, match.position(), match.str());
				TextReader::instance()->addFoundString(foundData);
				text = match.suffix().str();
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

TextThreads::TextThreads(ushort threadCount)
:_threadCount(threadCount)
{
}

TextThreads::~TextThreads()
{
	remove();
}

void TextThreads::create(const string &mask)
{
	// Prepare mask for regex
	string regMask = strReplace(mask, "?", ".?");
	//std::cout << regMask << std::endl;

	// Create threads
	for (int i = 0; i < _threadCount; ++i)
	{
		TextThreadPtr threadPtr(new TextThread());
		threadPtr->create(regMask);
		_data.push_back(threadPtr);
	}
}

void TextThreads::remove()
{
	for (TextThreadPtr threadPtr : _data)
		threadPtr->stop();
	_data.clear();
}
