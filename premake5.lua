workspace "Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
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
		-- typical Linux libs for OpenGL
		links
		{
			"GL",
			"pthread",
			"dl",
			"X11"
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
		"Engine/vendor/spdlog/include",
		"Engine/src"
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
		-- typical Linux libs for OpenGL
		links
		{
			"GL",
			"pthread",
			"dl",
			"X11"
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


