project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Phoenix/src",
		"%{wks.location}/Phoenix/vendor",
	}

	links
	{
		"Phoenix"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "PH_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PH_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PH_DIST"
		runtime "Release"
		optimize "on"