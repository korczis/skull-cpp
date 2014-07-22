//
//  FixedStack.h
//  algorithms
//
// The MIT License (MIT)
//
// Copyright (c) 2014 Tomas Korcak <korczis@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef ALGS_LINKED_FIXED_STACK_H
#define ALGS_LINKED_FIXED_STACK_H

#include <memory> // for shared_ptr

namespace algs
{
	template<typename T>
    class FixedStack
    {
    public:
        FixedStack(const T size) : mIndex(0)
        {
            mData = new T[size];
        }

        ~FixedStack()
        {
            delete[] mData;
        }

        FixedStack& push(const T& value)
        {
            mData[mIndex++] = value;

            return *this;
        }

        T pop()
        {
            return mData[--mIndex];
        }

        const T& size() const
        {
            return mIndex;
        }

    private:
        T* mData;
        T mIndex;
    };
}

#endif // ALGS_LINKED_FIXED_STACK_H
