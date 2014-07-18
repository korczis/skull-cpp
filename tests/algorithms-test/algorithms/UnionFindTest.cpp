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

TEST(UnionFind, UnionFind) {
	auto alg = new UnionFind<int>(10);
	EXPECT_NE(alg, (UnionFind<int>*)NULL);

	for(auto i = 0; i < alg->size(); i++)
	{
		EXPECT_EQ((*alg)[i], i);
	}

	delete alg;
}

TEST(UnionFind, connect) {
	auto alg = new UnionFind<int>(10);

	auto res = alg->isConnected(0, 1);
	EXPECT_EQ(res, false);

	alg->connect(0, 1);

	res = alg->isConnected(0, 1);
	EXPECT_EQ(res, true);

	delete alg;
}

TEST(UnionFind, union) {
	auto alg = new UnionFind<int>(10);

	alg->connect(0, 1);

	EXPECT_EQ((*alg)[0], 1);

	delete alg;
}
