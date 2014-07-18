//
//  AlgoritmsTest.cpp
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

#include "UnionFind.h"

using namespace algs;

typedef int ELEMENT_TYPE;
typedef UnionFind<ELEMENT_TYPE> AlgClass;

namespace 
{
	static const int SIZE = 10;

	inline AlgClass* Create()
	{
		return new AlgClass(SIZE);
	}

	inline void SafeDelete(AlgClass* alg)
	{
		delete alg;
		alg = 0;
	}
};

TEST(UnionFind, UnionFind) {
	auto alg = Create();

	EXPECT_NE(alg, (AlgClass*)NULL);

	for(auto i = 0; i < alg->size(); i++)
	{
		EXPECT_EQ((*alg)[i], i);
	}

	SafeDelete(alg);
}

TEST(UnionFind, connect) {
	auto alg = Create();

	alg->connect(0, 1);

	EXPECT_EQ((*alg)[0], 1);

	SafeDelete(alg);
}

TEST(UnionFind, isConnected) {
	auto alg = Create();

	auto res = alg->isConnected(0, 1);
	EXPECT_EQ(res, false);

	alg->connect(0, 1);

	res = alg->isConnected(0, 1);
	EXPECT_EQ(res, true);

	res = alg->isConnected(2, 3);
	EXPECT_EQ(res, false);

	alg->connect(2, 3);

	res = alg->isConnected(2, 3);
	EXPECT_EQ(res, true);

	res = alg->isConnected(0, 3);
	EXPECT_EQ(res, false);

	alg->connect(1, 2);

	res = alg->isConnected(0, 3);
	EXPECT_EQ(res, true);

	SafeDelete(alg);
}

TEST(UnionFind, size) {
	auto alg = Create();

	EXPECT_EQ(alg->size(), SIZE);

	SafeDelete(alg);
}
