#pragma once
#include <vector>

namespace dae
{
	struct GraphInfo
	{
		bool show;
		int numberOfSamples;
		std::vector<float> xs;
		std::vector<float> ys;
		std::vector<long long> totalResults;
	};
	class GuiManager
	{
	public:
		GuiManager() = default;
		~GuiManager() = default;

		void Render();

	private:
		const int m_NumberOfSteps{ 11 };

		GraphInfo m_InfoEx1{ false, 100, std::vector<float>{}, std::vector<float>{}, std::vector<long long>{} };
		//bool m_ShowEx1{ false };
		//int m_NumberOfSamplesEx1{ 100 };
		//std::vector<float> m_XsEx1;
		//std::vector<float> m_YsEx1;
		//std::vector<long long> m_SumResultsEx1;

		//bool showEx2{ false };

		void CalcResults(GraphInfo& info);
	};
}