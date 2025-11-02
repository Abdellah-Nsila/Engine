#include "LinuxWindow.h"
#include "Engine/Log.h"

namespace Engine
{

	static bool	s_GLFWInitialized = false;

	Window*	Window::Create(const WindowProps& props)
	{
		return (new LinuxWindow(props));
	}

	LinuxWindow::LinuxWindow(const WindowProps& props)
	{
		this->Init(props);
	}

	LinuxWindow::~LinuxWindow()
	{
		this->Shutdown();
	}

	void	LinuxWindow::Init(const WindowProps& props)
	{
		this->m_Data.Title = props.Title;
		this->m_Data.Width = props.Width;
		this->m_Data.Height = props.Height;

		ENGINE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int	success = glfwInit();
			s_GLFWInitialized = true;
		}

		this->m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(this->m_Window);
		glfwSetWindowUserPointer(this->m_Window, &this->m_Data);
		this->SetVSync(true);
	}

	void	LinuxWindow::Shutdown()
	{
		glfwDestroyWindow(this->m_Window);
		glfwTerminate();
	}

	void	LinuxWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(this->m_Window);
	}

	inline unsigned int	LinuxWindow::GetWidth() const
	{
		return this->m_Data.Width;
	}

	inline unsigned int	LinuxWindow::GetHeight() const
	{
		return this->m_Data.Height;
	}

	void	LinuxWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		this->m_Data.VSync = enabled;
	}

	bool	LinuxWindow::IsVSync() const
	{
		return (this->m_Data.VSync);
	}

}