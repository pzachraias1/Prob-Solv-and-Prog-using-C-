#ifndef FILESTREAMBUF_H
#define FILESTREAMBUF_H
#include <iostream>

class FileStreamBuf: public std::streambuf {
private:
    FILE* file;
    int size;
    int start, next, end;
    char cArray [];
    
public:
    FileStreamBuf(FILE* f, int size);
    virtual ~FileStreamBuf();
    int overflow(int c);
    int sync();
    //int underflow();
};

#endif
