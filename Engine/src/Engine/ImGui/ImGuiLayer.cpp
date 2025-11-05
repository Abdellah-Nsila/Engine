#include "enginepch.h"
#include "Engine/Core.h"
#include "ImGuiLayer.h"
#include "Engine/Application.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

//TODO: Temp
#include <GLFW/glfw3.h>
#include "glad/glad.h"

namespace Engine
{
	
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{
	}
	
	ImGuiLayer::~ImGuiLayer()
	{
	}

	void	ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO&	io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410");

	}

	void	ImGuiLayer::OnDetach()
	{

	}

	void	ImGuiLayer::OnUpdate()
	{
		ImGuiIO&		io = ImGui::GetIO();
		Application&	app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float	time = (float)glfwGetTime();
		io.DeltaTime = this->m_Time > 0.0f ? (time - this->m_Time) : (1.0f / 60.0f);
		this->m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool	show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void	ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher	dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		// dispatcher.Dispatch<KeyTypedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
	}

	bool	ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO&	io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return (false);
	}

	bool	ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO&	io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return (false);
	}

	bool	ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO&	io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());
		
		return (false);
	}

	bool	ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
	{
		ImGuiIO&	io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();
		
		return (false);
	}

	bool	ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		ImGuiIO&	io = ImGui::GetIO();
		// io.;
		
		return (false);
	}

	bool	ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		ImGuiIO&	io = ImGui::GetIO();
		// io.;
		
		return (false);
	}

	// bool	ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
	// {
		// ImGuiIO&	io = ImGui::GetIO();
		// io.;
		
		// return (false);
	// }

	bool	ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO&	io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		
		return (false);
	}

}