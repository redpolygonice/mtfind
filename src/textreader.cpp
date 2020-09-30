#include "textreader.h"

#include <fstream>

TextReader::TextReader()
{
}

void TextReader::start()
{
	if (!fs::exists(_fileName))
	{
		std::cout << "File \"" << _fileName << "\" does not exist!" << std::endl;
		return;
	}

	std::ifstream ifs(_fileName, std::ios::in);
	if (ifs.bad())
	{
		std::cout << "Can't open file \"" << _fileName << "\"" << std::endl;
		return;
	}

	ulong count = 0;
	string text;
	while(std::getline(ifs, text))
	{
		_dataMutex.lock();
		_data.push(StringData(++count, text));
		_dataMutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	ifs.close();
	print();
}

StringData TextReader::getNextString()
{
	std::lock_guard<std::mutex> lock(_stringMutex);

	if (!_data.empty())
	{
		StringData data = _data.front();
		_data.pop();
		return data;
	}

	return StringData();
}

void TextReader::addFoundString(const FoundStringData &data)
{
	_foundMutex.lock();
	_foundData.push_back(data);
	_foundMutex.unlock();
}

void TextReader::print()
{
	std::cout << _foundData.size() << std::endl;
	for (FoundStringsConstIterator it = _foundData.begin(); it != _foundData.end(); ++it)
		std::cout << (*it).number << " " << (*it).position << " " << (*it).text << std::endl;
}
