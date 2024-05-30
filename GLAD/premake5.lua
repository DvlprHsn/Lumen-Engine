project "GLAD"
    kind "StaticLib"
    language "C"
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
    glad = "%{wks.location}/Lumen/vendor/glad"

	systemversion "latest"

    files
    {
        "%{glad}/src/glad.c",
    }

    includedirs
    {
       "%{IncludeDirs.GLAD}"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release or Distribute"
        defines { "NDEBUG" }
        optimize "On"
