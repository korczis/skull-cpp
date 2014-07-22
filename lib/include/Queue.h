//
//  Queue.h
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

#ifndef ALGS_QUEUE_H
#define ALGS_QUEUE_H

#include <memory> // for shared_ptr

namespace algs
{
	template<typename T>
    class Queue
    {
    public:
    	class Node
    	{
    	public:
    		Node()
    		{

    		}

    		Node(T value) : mValue(value)
    		{

    		}

    		inline std::shared_ptr<Node> next()
    		{
    			return mNext;
    		}

			const inline std::shared_ptr<Node> next() const
    		{
    			return mNext;
    		}

    		inline std::shared_ptr<Node> next(std::shared_ptr<Node> next)
    		{
    			mNext = next;
    			return mNext;
    		}

    		inline std::shared_ptr<Node> prev()
    		{
    			return mPrev;
    		}

			const inline std::shared_ptr<Node> prev() const
    		{
    			return mPrev;
    		}

    		inline std::shared_ptr<Node> prev(std::shared_ptr<Node> prev)
    		{
    			mPrev = prev;
    			return mPrev;
    		}

    		inline const T& value() const
    		{
    			return mValue;
    		}

    	private:
    		T mValue;
    		std::shared_ptr<Node> mPrev;
    		std::shared_ptr<Node> mNext;
    	};

    	typedef std::shared_ptr<Node> NodePtr;

    	Queue() : mSize(0)
    	{
    		mBegin = std::shared_ptr<Node>(new Node());
    		mEnd = std::shared_ptr<Node>(new Node());

    		mBegin->next(mEnd);
    		mEnd->prev(mBegin);
    	}

    	~Queue()
    	{

    	}

    	Queue& enqueue(const T& value)
    	{
    		auto node = std::shared_ptr<Node>(new Node(value));

    		node->prev(mBegin);
    		node->next(mBegin->next());

    		mBegin->next()->prev(node);
    		mBegin->next(node);

    		mSize++;

    		return *this;
    	}

    	T dequeue()
    	{
    		auto node = mEnd->prev();

    		node->prev()->next(mEnd);
			mEnd->prev(node->prev());

    		--mSize;

    		return node->value();
    	}

    	const T& size()
    	{
    		return mSize;
    	}

    private:
    	NodePtr mBegin;
    	NodePtr mEnd;
    	T mSize;
    };
}

#endif // ALGS_QUEUE_H
