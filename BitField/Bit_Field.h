#ifndef _BIT_FIELD_H_
#define _BIT_FIELD_H_

enum
{
	READ = 01,
	WRITE = 02
};

typedef unsigned int Bit;

class File
{
public:
	Bit mode: 2;
	Bit modified: 1;
	Bit prot_owner: 3;
	Bit prot_group: 3;
	Bit prot_world: 3;

	void write() { modified = 1; }
	void close() 
	{
		if(modified)
		{
			//save data;
		}
	}

	inline int File::isRead() { return mode & READ; }
	inline int File::isWrite() { return mode & WRITE; }

};


void ExampleFile()
{
	File myFile;
	myFile.mode |= READ;
	if(myFile.mode & READ)
	{
		//mode READ is set;
	}
}

#endif