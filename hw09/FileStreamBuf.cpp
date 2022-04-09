#include "FileStreamBuf.h"
#include <iostream>

FileStreamBuf::FileStreamBuf(FILE* f, int size){
    this->file = f;
    this->size = size;
    cArray[size] = *new char[size];
    
    this->start = 0;
    this->end = size;
    this->next = end;
    
    this->startRead = 0;
    this->endRead = size;
    this->nextRead = end;
    
    setp(&this->cArray[next], &this->cArray[end]);
    setg(&this->cArray[startRead], &this->cArray[nextRead], &this->cArray[endRead]);
}

FileStreamBuf:: ~FileStreamBuf(){
    fclose(file);
}

int FileStreamBuf::overflow(int c){
    std::streambuf::overflow(c);
    this->cArray[start] = c;
    cArray [next] = start;
    fwrite(cArray, sizeof(char), 1, file);
    setp(&cArray[next], &cArray[end]);
    
    return c;
}

int FileStreamBuf::sync(){
    std::streambuf::sync();
    std::streambuf::pptr();
    fwrite(cArray, sizeof(char), 1, this->file);
    setp(&cArray[start], &cArray[end]);
    return 0;
}


int FileStreamBuf::underflow(){
    std::streambuf::underflow();
    fread(this->cArray, sizeof(char), size, this->file);
    setg(&this->cArray[startRead], &this->cArray[nextRead], &this->cArray[endRead]);
    
    return nextRead;
}

int FileStreamBuf::uflow(){
    std::streambuf::underflow();

    //fread(this->cArray, sizeof(char), 1, this->file);
    setg(&this->cArray[start], &this->cArray[next], &this->cArray[end]);
    
    return cArray[next];
}
