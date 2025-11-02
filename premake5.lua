workspace "Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["ENGINE"] = "Engine/src"
IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"
IncludeDir["spdlog"] = "Engine/vendor/spdlog/include"

include "Engine/vendor/GLFW"

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
	}

	includedirs
	{
		"%{IncludeDir.ENGINE}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW"
	}

	filter "system:linux"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"ENGINE_PLATFORM_LINUX",
			"ENGINE_ENABLE_ASSERTS"
		}
		 -- needed for shared libs on Linux
		buildoptions
		{
			"-fPIC"
		}
		links
		{
			"GLFW", -- glfw premake target
			"GL", "X11", "Xrandr", "Xinerama", "Xcursor", "Xfixes", "pthread", "dl" -- typical Linux libs for OpenGL
		}
		postbuildcommands
		{
			("{MKDIR} ../bin/" .. outputDir .. "/Sandbox"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox/")
		}

	filter "configurations:Debug"
		defines "ENGINE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "ENGINE_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "ENGINE_DIST"
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
		symbols "On"
	
	filter "configurations:Release"
		defines "ENGINE_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "ENGINE_DIST"
		optimize "On"


