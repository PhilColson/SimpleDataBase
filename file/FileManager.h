#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__
#include <iostream>
#include <fstream>
#include <string>
#include "../log/log.h"

using namespace std;

class FileHeader
{
public:
	FileHeader(int pos, int size):position(pos),NodeSize(size){}
	FileHeader():position(0),NodeSize(0){}
	int position;
	int NodeSize;
};

template<typename NodeType>
class FileManager
{
public:
	FileManager() :inited(false){}
	FileManager(string FileName) :inited(true){
		initWithFileName(FileName);
	}

	void initWithFileName(string FileName){
		header = FileHeader(0, sizeof(NodeType));
		//RAII
		fileHandle.open(FileName, fstream::binary | fstream::out | fstream::in);
		if (fileHandle.is_open()){
			LOG << "file is opened" << endl;
		}
		else{
			LOG << "file does not exist create and reopen it" << endl;
			fileHandle.close();
			fileHandle.open(FileName, fstream::binary | fstream::out);
			wirteHeader();
			fileHandle.close();
			fileHandle.open(FileName, fstream::binary | fstream::out | fstream::in);
		}

		/*
		if (fileHandle.fail()){
		char errmsg[100];
		strerror_s(errmsg, 100, errno);
		LOG << "open failed: " <<  errmsg << endl;

		}
		*/

		fileHandle.read(reinterpret_cast<char*>(&header), sizeof(FileHeader));

		if (fileHandle.eof()){
			LOG << "file is empty" << endl;
			wirteHeader();
		}
		else{
			LOG << "read from file\n"
				<< "position: " << header.position << " NodeSize: " << header.NodeSize << endl;
		}
		if (sizeof(NodeType) != header.NodeSize){
			LOG << "type incompatible" << endl;
			wirteHeader();
		}
		fileHandle.seekp(getPosByIndex(header.position));
		fileHandle.flush();
		inited = true;
	}

	inline int alloc(){
		internalcheck();
		int ret = header.position;
		header.position++;
		return ret;
	}

	inline FileManager& operator << (NodeType* node){
		internalcheck();
		if (node->ptrInDisk < 0){
			//allocate space for node
			node->ptrInDisk = alloc();
		}
		_writeNode(node);
		return *this;
	}

	inline bool isInited(){
		return inited;
	}

	~FileManager(){
		fileHandle.close();
	}
private:
	inline void internalcheck(){
		if (!inited){
			LOG << "error: this FileManager is not inited" << endl;
			throw exception("this FileManager is not inited");
		}
	}
	bool inited;
	void _writeNode(NodeType* node){
		fileHandle.seekp(node->ptrInDisk);
		fileHandle.write(reinterpret_cast<char*>(node), sizeof(NodeType));
	}

	void wirteHeader(){
		header.NodeSize = sizeof(NodeType);
		header.position = 0;
		fileHandle.write(reinterpret_cast<char*>(&header), sizeof(FileHeader));
	}
	ios::pos_type getPosByIndex(int index){
		return sizeof(FileHeader) + index * sizeof(NodeType);
	}
	fstream fileHandle;
	FileHeader header;
};
#endif//__FILEMANAGER_H__