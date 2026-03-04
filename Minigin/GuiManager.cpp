#include "GuiManager.h"
#include <imgui.h>
#include <imgui_plot.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>
#include <cmath>
#include <chrono>

void dae::GuiManager::Render()
{
	//ImGui::ShowDemoWindow(); // For demonstration purposes, do not keep this in your engine

	bool isOpen{};
	ImGui::Begin("Exercise 1", &isOpen);
	ImGui::InputInt("# samples", &m_InfoEx1.numberOfSamples);
	bool isPressed = ImGui::Button("Trash the cache");
	
	if (isPressed)
	{
		CalcResults(m_InfoEx1);
		m_InfoEx1.show = true;
	}
	
	if (m_InfoEx1.show)
	{
		ImGui::PlotConfig config{};
		config.values.xs = m_InfoEx1.xs.data();
		config.values.count = m_NumberOfSteps;
		config.values.ys = m_InfoEx1.ys.data();
		config.values.color = ImColor(0, 255, 0);
		config.frame_size = ImVec2(225, 150);
		config.scale.min = 0;
		config.scale.max = m_InfoEx1.ys[0];
		config.tooltip.show = true;
		config.tooltip.format = "x=%.2f, y=%.2f";
		config.grid_x.show = true;
		config.grid_y.show = true;
		config.line_thickness = 2.f;
		
		ImGui::Plot("plot", config);
	}

	ImGui::End();
}

void dae::GuiManager::CalcResults(GraphInfo& info)
{
	info.totalResults.resize(m_NumberOfSteps);
	info.xs.resize(m_NumberOfSteps);
	info.ys.resize(m_NumberOfSteps);

	// Make an array of the requested type
	constexpr int size{ 10'000'000 };
	int* pArray = new int[size]{};
	int stepsize = {};

	for (stepsize = 1; stepsize <= 1024; stepsize *= 2)
	{
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < size; i += stepsize)
		{
			pArray[i] *= 2;
		}
		auto end = std::chrono::high_resolution_clock::now();
		info.totalResults[stepsize] += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		info.xs[stepsize] = static_cast<float>(stepsize);
	}	

	// Divide the total to retrieve the average
	for (int step{ 0 }; step < m_NumberOfSteps; ++step)
		info.ys[step] = static_cast<float>(info.totalResults[step] / info.numberOfSamples);

	delete[] pArray;
}
