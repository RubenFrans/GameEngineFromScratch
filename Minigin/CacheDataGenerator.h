#pragma once

namespace cacheGen{

	struct Transform {
		float matrix[16] = {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};
	};

	class GameObject3D
	{
	public:
		GameObject3D()
			: m_LocalTransform{ new Transform{} }, ID{}
		{

		}
		~GameObject3D() {
			delete m_LocalTransform;
		}
		Transform* m_LocalTransform; // with a pointer this should be alot faster because it fits a cache line
		int ID;
	};

	struct CacheData {
		std::vector<float>* xData;
		std::vector<float>* yData;
	};

	class CacheDataGenerator
	{
	public:
		static CacheData GenerateClassCacheMetrics(int amountOfRuns);
		static CacheData GenerateIntCacheMetrics(int amountOfRuns);
		~CacheDataGenerator();
	private:
	};

}


