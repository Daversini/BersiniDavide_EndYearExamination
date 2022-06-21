project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    location "%{wks.location}/Sandbox"
    icon "%{prj.location}/res/icon.ico"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin-Int/" .. outputdir .. "/%{prj.name}")

    -- Add all C++ files from the "src/" directory and any subdirectories and "resource script" file
    files
    {
        "src/**.h",
        "src/**.cpp",
        "res/resources.rc"
    }

    -- Include Framework directory
    includedirs
    {
        "%{wks.location}/Framework/src",
    }

    -- Project linking
    links
    {
        "Framework"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"