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

			mData[pid] = mData[qid];

			return *this;
		}

		inline bool isConnected(const T& p, const T& q) const
		{
			return mData[p] == mData[q];
		}

		inline const T& root(const T& p) const
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
