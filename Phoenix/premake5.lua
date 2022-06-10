project "Phoenix"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "phpch.h"
	pchsource "src/phpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src"
	}

	links
	{
		
	}

	flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "PH_DEBUG"
		runtime "Debug"
		symbols "on"

		links
		{
			
		}

	filter "configurations:Release"
		defines "PH_RELEASE"
		runtime "Release"
		optimize "on"

		links
		{
			
		}

	filter "configurations:Dist"
		defines "PH_DIST"
		runtime "Release"
		optimize "on"

		links
		{
		
		}