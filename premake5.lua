workspace "Lumen"
    configurations { "Debug", "Release", "Distribute" }
    platforms { "x86", "x86_64" }
    startproject "Sandbox"

    outputdir = "%{cfg.buildcfg}/%{cfg.system}_%{cfg.architecture}"

    IncludeDirs = {}
    IncludeDirs["GLFW"] = "%{wks.location}/Lumen/vendor/glfw/include"
    IncludeDirs["SPDLOG"] = "%{wks.location}/Lumen/vendor/spdlog/include"
    IncludeDirs["GLAD"] = "%{wks.location}/Lumen/vendor/glad/include"

    include "GLFW"
    include "GLAD"

project "Lumen"
    location "Lumen"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    systemversion "latest"
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "stdafx.h"
    pchsource "%{prj.name}/src/stdafx.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDirs.SPDLOG}",
        "%{IncludeDirs.GLFW}",
        "%{IncludeDirs.GLAD}"
    }

    links 
    {
        "GLFW",
        "GLAD"
    }

    postbuildcommands
    {
        "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
    }

    filter { "system:windows", "architecture:x86" }
        defines
        {
            "LUMEN_PLATFORM_WIN32",
            "LUMEN_BUILD_DLL",
            "WIN32"
        }

    filter { "system:windows", "architecture:x86_64" }
        defines
        {
            "LUMEN_PLATFORM_WIN64",
            "LUMEN_BUILD_DLL"
        }

    filter { "system:macosx" }
        defines
        {
            "LUMEN_PLATFORM_MACOS",
            "LUMEN_BUILD_DLL"
        }
        systemversion "latest"
        links
        {
            "Cocoa.framework",
            "IOKit.framework",
            "CoreFoundation.framework"
        }

    filter { "system:linux" }
        defines
        {
            "LUMEN_PLATFORM_LINUX",
            "LUMEN_BUILD_DLL"
        }
        links
        {
            "dl",
            "pthread"
        }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release or Distribute"
        defines { "NDEBUG" }
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    systemversion "latest"
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{wks.location}/Lumen/src",
        "%{wks.location}/%{IncludeDirs.SPDLOG}",
        "%{wks.location}/%{IncludeDirs.GLFW}",
        "%{wks.location}/%{IncludeDirs.GLAD}" 
    }

    links 
    {
        "Lumen"
    }

    filter {"system:windows", "architecture:x86"}
        defines {
            "LUMEN_PLATFORM_WIN32",
            "WIN32"
        }

    filter {"system:windows", "architecture:x86_64"}
        defines {
            "LUMEN_PLATFORM_WIN64"
        }

    filter {"system:macosx"}
        defines {
            "LUMEN_PLATFORM_MACOS"
        }

    filter {"system:linux"}
        defines {
            "LUMEN_PLATFORM_LINUX"
        }

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release or Distribute"
        defines {"NDEBUG"}
        optimize "On"
