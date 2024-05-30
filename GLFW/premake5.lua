project "GLFW"
    kind "StaticLib"
    language "C"
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
    glfw = "%{wks.location}/Lumen/vendor/glfw"

	systemversion "latest"

    files
    {
        "%{glfw}/src/context.c",
		"%{glfw}/src/init.c",
		"%{glfw}/src/input.c",
		"%{glfw}/src/monitor.c",

		"%{glfw}/src/null_init.c",
		"%{glfw}/src/null_joystick.c",
		"%{glfw}/src/null_monitor.c",
		"%{glfw}/src/null_window.c",

		"%{glfw}/src/platform.c",
		"%{glfw}/src/vulkan.c",
		"%{glfw}/src/window.c",
    }

    includedirs
    {
       "%{IncludeDirs.GLFW}",
    }

    filter "system:windows"
		files
		{
			"%{glfw}/src/win32_init.c",
			"%{glfw}/src/win32_joystick.c",
			"%{glfw}/src/win32_module.c",
			"%{glfw}/src/win32_monitor.c",
			"%{glfw}/src/win32_time.c",
			"%{glfw}/src/win32_thread.c",
			"%{glfw}/src/win32_window.c",
			"%{glfw}/src/wgl_context.c",
			"%{glfw}/src/egl_context.c",
			"%{glfw}/src/osmesa_context.c"
		}

		defines 
		{
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}


	filter "system:linux"
		files
		{
			"%{glfw}/src/x11_init.c",
			"%{glfw}/src/x11_monitor.c",
			"%{glfw}/src/x11_window.c",
			"%{glfw}/src/xkb_unicode.c",
			"%{glfw}/src/posix_module.c",
			"%{glfw}/src/posix_time.c",
			"%{glfw}/src/posix_thread.c",
			"%{glfw}/src/posix_module.c",
			"%{glfw}/src/glx_context.c",
			"%{glfw}/src/egl_context.c",
			"%{glfw}/src/osmesa_context.c",
			"%{glfw}/src/linux_joystick.c"
		}

		defines
		{
			"_GLFW_X11"
		}

	filter "system:macosx"
		files
		{
			"src/cocoa_init.m",
			"src/cocoa_monitor.m",
			"src/cocoa_window.m",
			"src/cocoa_joystick.m",
			"src/cocoa_time.c",
			"src/nsgl_context.m",
			"src/posix_thread.c",
			"src/posix_module.c",
			"src/osmesa_context.c",
			"src/egl_context.c"
		}

		defines
		{
			"_GLFW_COCOA"
		}

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release or Distribute"
        defines { "NDEBUG" }
        optimize "On"
