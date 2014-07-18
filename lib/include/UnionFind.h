#ifndef ALGS_UNION_FIND_H
#define ALGS_UNION_FIND_H

namespace algs
{
	template<typename T>
    class UnionFind
    {
    public:
		UnionFind(const T& size) : mSize(size)
		{
			mData = new T[size];

			for(T i = 0; i < size; i++)
			{
				mData[i] = i;
			}
		}

		~UnionFind()
		{
			delete[] mData; mData = 0;
		}

		inline const T& size() const
		{
			return mSize;
		}

		const T& operator[](T index) const
		{
			return mData[index];
		}

		inline UnionFind& connect(const T& p, const T& q)
		{
			auto pid = mData[p];
			auto qid = mData[q];

			for(auto i = 0; i < mSize; i++)
			{
				if(mData[i] == pid)
				{
					mData[i] = qid;
				}
			}

			return *this;
		}

		inline bool isConnected(const T& p, const T& q) const
		{
			return mData[p] == mData[q];
		}

	private:
		const T mSize;
		T* mData;
    };
}

#endif // ALGS_UNION_FIND_H
