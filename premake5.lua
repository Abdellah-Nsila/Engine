workspace "Engine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["ENGINE"] = "Engine/src"
IncludeDir["spdlog"] = "Engine/vendor/spdlog/include"
IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"
IncludeDir["Glad"] = "Engine/vendor/Glad/include"
IncludeDir["ImGui"] = "Engine/vendor/imgui"
IncludeDir["glm"] = "Engine/vendor/glm"

include "Engine/vendor/GLFW"
include "Engine/vendor/Glad"
include "Engine/vendor/imgui"

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	--* Precompiled Header
	pchheader "enginepch.h"
	pchsource "Engine/src/enginepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{IncludeDir.ENGINE}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	filter "system:linux"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"ENGINE_PLATFORM_LINUX",
			"ENGINE_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE"
		}
		 -- needed for shared libs on Linux
		buildoptions
		{
			"-fPIC"
		}
		links
		{
			"GLFW", "Glad", "ImGui", -- premake targets
			"GL", "X11", "Xrandr", "Xinerama", "Xcursor", "Xfixes", "pthread", "dl" -- typical Linux libs for OpenGL
		}
		postbuildcommands
		{
			("{MKDIR} ../bin/" .. outputDir .. "/Sandbox"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox/")
		}

	filter "configurations:Debug"
		defines "ENGINE_DEBUG"
		buildoptions { "-g" } -- Debug info + strict warnings optional (, "-Wall", "-Wextra", "-Wpedantic")
		symbols "On"
	
	filter "configurations:Release"
		defines "ENGINE_RELEASE"
		buildoptions { "-O2", "-DNDEBUG" } -- Normal optimization
		optimize "On"
	
	filter "configurations:Dist"
		defines "ENGINE_DIST"
		buildoptions { "-O3", "-DNDEBUG" } -- Max optimization
		optimize "On"







project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{IncludeDir.ENGINE}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Engine"
	}

	filter "system:linux"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"ENGINE_PLATFORM_LINUX"
		}
		 -- needed for shared libs on Linux
		buildoptions
		{
			"-fPIC"
		}

	filter "configurations:Debug"
		defines "ENGINE_DEBUG"
		buildoptions { "-g" } -- Debug info + strict warnings optional (, "-Wall", "-Wextra", "-Wpedantic")
		symbols "On"
	
	filter "configurations:Release"
		defines "ENGINE_RELEASE"
		buildoptions { "-O2", "-DNDEBUG" } -- Normal optimization
		optimize "On"
	
	filter "configurations:Dist"
		defines "ENGINE_DIST"
		buildoptions { "-O3", "-DNDEBUG" } -- Max optimization
		optimize "On"


