project "Glad"
	kind "StaticLib"
	language "C"
	staticruntime "off"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"src/glad.c",
		"include/glad/glad.h",
		"include//KHR/khrplatform.h"
	}

	includedirs
	{
		"include"
	}

	filter "system:linux"
        systemversion "latest"
    	pic "On"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
