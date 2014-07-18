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

		inline const T& size()
		{
			return mSize;
		}

		const T& operator[](T index)
		{
			return mData[index];
		}

	private:
		const T mSize;
		T* mData;
    };
}

#endif // ALGS_UNION_FIND_H