project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    location "%{wks.location}/Sandbox"
    icon "%{prj.location}/res/icon.ico"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin-Int/" .. outputdir .. "/%{prj.name}")

    -- Visual Studio Debug working directory
    debugdir ("%{cfg.targetdir}")

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
        "%{IncludeDir.SFML}"
    }

    -- Project linking
    links
    {
        "Framework"
    }

    postbuildmessage "Copying resources into project..."
    postbuildcommands
    {
        "{COPYDIR} %{prj.location}/res/textures %{cfg.targetdir}/resources/textures",
        "{COPYDIR} %{prj.location}/res/fonts %{cfg.targetdir}/resources/fonts"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"