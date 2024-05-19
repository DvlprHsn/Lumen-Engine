workspace "Lumen"
    configurations { "Debug", "Release", "Distribute" }
    platforms { "x86", "x86_64" }
    startproject "Sandbox"

    outputdir = "%{cfg.buildcfg}/%{cfg.system}_%{cfg.architecture}"

project "Lumen"
    location "Lumen"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
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
        "%{prj.name}/vendor/spdlog/include"
    }

    vpaths {
    ["Headers"] = { "**.h", "**.hpp" },
    ["Sources/*"] = {"**.c", "**.cpp"},
    ["Docs"] = "**.md"
}

postbuildcommands
{
    { "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox" }
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
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{wks.location}/Lumen/src",
        "%{wks.location}/Lumen/vendor/spdlog/include"
    }

    vpaths {
    ["Headers"] = { "**.h", "**.hpp" },
    ["Sources/*"] = {"**.c", "**.cpp"},
    ["Docs"] = "**.md"
}

    links {
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

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"
