#ifndef ALGS_UNION_FIND_WEIGHTED_TREE_H
#define ALGS_UNION_FIND_WEIGHTED_TREE_H

namespace algs
{
	template<typename T>
    class UnionFindWeightedTree
    {
    public:
		UnionFindWeightedTree(const T& size) : mSize(size)
		{
			mHeight = new T[size];
			mData = new T[size];

			for(auto i = 0; i < size; i++)
			{
				mHeight[i] = 1;
				mData[i] = i;
			}
		}

		~UnionFindWeightedTree()
		{
			delete[] mData; mData = 0;
			delete[] mHeight; mHeight = 0;
		}

		const T& operator[](const T& index) const
		{
			return mData[index];
		}

		inline UnionFindWeightedTree& connect(const T& p, const T& q)
		{
			auto pid = root(p);
			auto qid = root(q);

			if(pid == qid)
			{
				return *this;
			}

			if(mHeight[p] < mHeight[q])
			{
				mHeight[p] += mHeight[q];
				mData[pid] = qid;
			}
			else
			{
				mHeight[q] += mHeight[p];
				mData[qid] = pid;
			}

			return *this;
		}

		inline bool isConnected(const T& p, const T& q) const
		{
			return root(p) == root(q);
		}

		inline const T& root(const T& p) const
		{
			auto res = mData[p];
			while(res != mData[res])
			{
				mData[res] = mData[mData[res]];
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
		T* mHeight;
		T* mData;
    };
}

#endif // ALGS_UNION_FIND_WEIGHTED_TREE_H
