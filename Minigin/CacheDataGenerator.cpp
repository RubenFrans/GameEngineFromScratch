#include "MiniginPCH.h"
#include "CacheDataGenerator.h"
#include <chrono>

using namespace cacheGen;

cacheGen::CacheData CacheDataGenerator::GenerateClassCacheMetrics(int amountOfRuns)
{
	const int bufferLength{ 1000000 };
	GameObject3D* buffer = new GameObject3D[bufferLength];

	//float* xDataStepSize = new float[];
	//float* yDataAverageTimeForStep = new float[];

	std::vector<float>* m_xData = new std::vector<float>{};
	std::vector<float>* m_yData = new std::vector<float>{};

	CacheData data{ m_xData, m_yData };

	for (int stepSize = 1; stepSize <= 1024; stepSize *= 2)
	{

		long long totalTime{};

		for (int i = 0; i < amountOfRuns; i++)
		{
			auto start = std::chrono::high_resolution_clock::now();

			for (int j = 0; j < bufferLength; j += stepSize)
			{
				buffer[i].m_LocalTransform->matrix[0] *= 2;
			}

			auto end = std::chrono::high_resolution_clock::now();
			totalTime += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		}

		m_xData->push_back(float(stepSize));
		m_yData->push_back(float(totalTime / amountOfRuns));

		std::cout << stepSize << ';' << totalTime / amountOfRuns << std::endl;

	}

	delete[] buffer;

	return data;
}

cacheGen::CacheData CacheDataGenerator::GenerateIntCacheMetrics(int amountOfRuns)
{

	const int bufferLength{ 10000000 };
	int* buffer = new int[bufferLength] {};


	std::vector<float>* m_xData = new std::vector<float>{};
	std::vector<float>* m_yData = new std::vector<float>{};

	CacheData data{ m_xData, m_yData };

	for (int stepSize = 1; stepSize <= 1024; stepSize *= 2)
	{

		long long totalTime{};

		for (int i = 0; i < amountOfRuns; i++)
		{
			auto start = std::chrono::high_resolution_clock::now();

			for (int j = 0; j < bufferLength; j += stepSize)
			{
				buffer[i] *= 2;
			}

			auto end = std::chrono::high_resolution_clock::now();
			totalTime += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		}

		m_xData->push_back(float(stepSize));
		m_yData->push_back(float(totalTime / amountOfRuns));

		std::cout << stepSize << ';' << totalTime / amountOfRuns << std::endl;
	}

	delete[] buffer;

	return data;
}
