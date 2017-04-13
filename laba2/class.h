//
// Created by yriy on 22.03.17.
//

#ifndef LABA2_CLASS_H_H
#define LABA2_CLASS_H_H

#include <iostream>
#include <cstring>
#include <cstdlib>

class String {
public:

    enum {
        defoult_lenght = 1
    };
    enum {
        defoult_symbol = 'c'
    };

    String() {
        data_ = new char[defoult_lenght];
        lenght_ = 1;
    }

    String(String &str)
    {
        data_ = new char[str.lenght_];
        lenght_ = str.lenght_;
        for(size_t i = 0; i < lenght_; ++i)
        {
            data_[i] = str.data_[i];
        }
    }

    String(size_t size)
    {
        data_ = new char[size];
        lenght_ = size;
        for(size_t i = 0; i < size; ++i)
        {
            data_[i] = defoult_symbol;
        }
    }

    void strcpy_(char* str)
    {
        size_t len = 0;
        while(str[len] != '\0')
            len++;
        delete[] data_;
        lenght_ = len;
        data_ = new char[lenght_];
        for(size_t i = 0; i < lenght_; ++i)
        {
            data_[i] = str[i];
        }
    }


    void print()
    {
        std::cout << data_ << " :  " << lenght_ << std::endl;
    }

    const char* data() const
    {
        return data_;
    }

    char& operator[](size_t i)
    {
        return data_[i];
    }

    void operator+=(size_t col)
    {
        char* buf = new char[lenght_ + col];
        for(size_t i = 0; i < lenght_; ++i)
            buf[i] = data_[i];
        for(size_t j = 0; j < col; ++j)
            buf[lenght_ + j] = defoult_symbol;
        delete[] data_;
        data_ = buf;
        lenght_ += col;
    }

    String operator+(String& s2)
    {
        char* ans = new char[lenght_ + s2.lenght_];

        int i = 0;
        for(; i <  lenght_; i++)
            ans[i] = data_[i];
        for(int j = 0; j < s2.lenght_; i++, j++)
            ans[i] = s2[j];
        strcpy_(ans);
        return *this;
    }


    ~String ()
    {
        delete[] data_;
    }

    

private:

    char* data_;
    size_t lenght_;
};

#endif //LABA2_CLASS_H_H
