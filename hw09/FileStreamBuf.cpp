#include "FileStreamBuf.h"
#include <iostream>

FileStreamBuf::FileStreamBuf(FILE* f, int size){
    this->file = f;
    this->size = size;
    cArray[size] = *new char[size];
    
    this->start = 0;
    this->end = size;
    this->next = end;
    
    setp(&this->cArray[next], &this->cArray[end]);
    //setg(&this->cArray[start], &this->cArray[next], &this->cArray[end]);
}

FileStreamBuf:: ~FileStreamBuf(){
    fclose(file);
}

int FileStreamBuf::overflow(int c){
    std::streambuf::overflow(c);
    this->cArray[start] = c;
    cArray [next] = start+1;
    cArray [end] = size;
    fwrite(cArray, sizeof(char), size, file);
    setp(&cArray[next], &cArray[end]);
    
    return c;
}

int FileStreamBuf::sync(){
    std::streambuf::sync();
    std::streambuf::pptr();
    fwrite(cArray, sizeof(char), size, this->file);
    setp(&cArray[start], &cArray[end]);
    return 0;
}

/**
int FileStreamBuf::underflow(){
    fread(this->cArray, sizeof(char), size, this->file);
    
    return 0;
}
 */
