#include "LinuxWindow.h"
#include "Engine/Log.h"

#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Engine
{

	static bool	s_GLFWInitialized = false;

	static	void	GLFWErrorCallback(int error_code, const char* description)
	{
		ENGINE_CORE_ERROR("GLFW Error ({0}) : {1}", error_code, description);
	}

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
		glfwSetErrorCallback(GLFWErrorCallback);
		if (!s_GLFWInitialized)
		{
			int	success = glfwInit();
			s_GLFWInitialized = true;
		}

		this->m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(this->m_Window);
		int	status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ENGINE_CORE_ASSERT(status, "Failed to Initialize Glad!");
		glfwSetWindowUserPointer(this->m_Window, &this->m_Data);
		this->SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(this->m_Window,
			[](GLFWwindow* window, int width, int height)
			{
				// Get Window data and update them
				WindowData&	data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				// Create an Event and dispatch it
				WindowResizeEvent	event(width, height);
				data.EventCallback(event);
			}
		);

		glfwSetWindowCloseCallback(this->m_Window,
			[](GLFWwindow* window)
			{
				WindowData&	data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent	event;
				data.EventCallback(event);
			}
		);

		glfwSetKeyCallback(this->m_Window,
			[](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData&	data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent	event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent	event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent	event(key, 1);
						data.EventCallback(event);
						break;
					}
					default:
						break;
				}
			}
		);

		glfwSetCharCallback(this->m_Window,
			[](GLFWwindow* window, unsigned int keycode)
			{
				WindowData&	data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent	event(keycode);
				data.EventCallback(event);
			});

		glfwSetMouseButtonCallback(this->m_Window,
			[](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData&	data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent	event(button);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent	event(button);
						data.EventCallback(event);
						break;
					}
					default:
						break;
				}
			}
		);

		glfwSetScrollCallback(this->m_Window,
			[](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData&	data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent	event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			}
		);

		glfwSetCursorPosCallback(this->m_Window,
			[](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData&	data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent	event((float)xPos, (float)yPos);
				data.EventCallback(event);
			}
		);
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

	inline void*	LinuxWindow::GetNativeWindow() const
	{
		return ((void*)(this->m_Window));
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