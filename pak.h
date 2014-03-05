
#ifndef PAK_H__
#define PAK_H__

#include "file.h"

struct PakEntry {
	char name[32];
	uint32_t offset;
	uint32_t size;
};

struct Pak {

	static const char *FILENAME;

	File _f;
	PakEntry *_entries;
	int _entriesCount;

	Pak(const char *dataPath);
	~Pak();

	void readEntries();
	const PakEntry *find(const char *name);
	void loadData(const PakEntry *e, uint8_t *buf, uint32_t *size);
};

#endif