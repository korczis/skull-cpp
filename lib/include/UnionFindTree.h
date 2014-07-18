//
//  UnionFindTree.h
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

#ifndef ALGS_UNION_FIND_TREE_H
#define ALGS_UNION_FIND_TREE_H

namespace algs
{
	template<typename T>
    class UnionFindTree
    {
    public:
		UnionFindTree(const T& size) : mSize(size)
		{
			mData = new T[size];

			for(auto i = 0; i < size; i++)
			{
				mData[i] = i;
			}
		}

		~UnionFindTree()
		{
			delete[] mData; mData = 0;
		}

		const T& operator[](const T& index) const
		{
			return mData[index];
		}

		inline UnionFindTree& connect(const T& p, const T& q)
		{
			auto pid = root(p);
			auto qid = root(q);

			mData[pid] = qid;

			return *this;
		}

		inline bool isConnected(const T& p, const T& q) const
		{
			return root(p) == root(q);
		}

		inline const T root(const T& p) const
		{
			auto res = mData[p];
			while(res != mData[res])
			{
				res = mData[res];
			}

			return res;
		}

		inline const T& size() const
		{
			return mSize;
		}

	private:
		const T mSize;
		T* mData;
    };
}

#endif // ALGS_UNION_FIND_TREE_H
