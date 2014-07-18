//
//  QueueTest.cpp
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

#include "gtest/gtest.h"

#include "Queue.h"

using namespace algs;

typedef int ELEMENT_TYPE;
typedef Queue<ELEMENT_TYPE> AlgClass;

namespace 
{
	static const int SIZE = 10;

	inline AlgClass* Create()
	{
		return new AlgClass();
	}

	inline void SafeDelete(AlgClass* alg)
	{
		delete alg;
		alg = 0;
	}
};

TEST(Queue, Queue) {
	auto alg = Create();

	SafeDelete(alg);
}

TEST(Queue, dequeue) {
	auto alg = Create();

	alg->enqueue(1);
	alg->enqueue(2);
	alg->enqueue(3);

	auto res = alg->dequeue();
	EXPECT_EQ(res, 1);

	res = alg->dequeue();
	EXPECT_EQ(res, 2);

	res = alg->dequeue();
	EXPECT_EQ(res, 3);
	
	SafeDelete(alg);
}

TEST(Queue, enqueue) {
	auto alg = Create();

	alg->enqueue(1);
	alg->enqueue(2);
	alg->enqueue(3);
	
	SafeDelete(alg);
}