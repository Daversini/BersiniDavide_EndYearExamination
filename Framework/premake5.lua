project "Framework"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    location "%{wks.location}/Framework"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin-Int/" .. outputdir .. "/%{prj.name}")

    -- Pre-compiled header declaration
    pchheader "MyEngine/Utils/pch.h"
    pchsource "src/MyEngine/Utils/pch.cpp"

    -- Add all C++ files from the "src/" directory and any subdirectories
    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    -- Preprocessor directives
    defines
    {
        "SFML_STATIC",
        "LIBRARY_EXPORTS"
    }

    -- List of Include directories
    includedirs
    {
        "%{prj.location}/src",
        "%{IncludeDir.SFML}"
    }

    -- Required libraries for SFML static linking
    links
    {
        -- Windows
        "gdi32",
        "winmm",

        -- OpenGL
        "opengl32",

        -- SFML
        "%{LibraryDir.SFML}/freetype.lib",
        "%{LibraryDir.SFML}/openal32.lib",
        "%{LibraryDir.SFML}/flac.lib",
        "%{LibraryDir.SFML}/vorbisenc.lib",
        "%{LibraryDir.SFML}/vorbisfile.lib",
        "%{LibraryDir.SFML}/vorbis.lib",
        "%{LibraryDir.SFML}/ogg.lib"
    }

    postbuildmessage "Copying Framework depencencies into project..."
    postbuildcommands
    {
        "{COPY} %{cfg.targetdir}/*.dll %{wks.location}/Bin/" .. outputdir .. "/Sandbox/"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"
        
        links
        {
            -- SFML libraries on Debug configuration
            "%{LibDebug.SFMLSystem}",
            "%{LibDebug.SFMLWindow}",
            "%{LibDebug.SFMLGraphics}",
            "%{LibDebug.SFMLAudio}",
            "%{LibDebug.SFMLMain}"
        }

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

        links
        {
            -- SFML libraries on Release configuration
            "%{LibRelease.SFMLSystem}",
            "%{LibRelease.SFMLWindow}",
            "%{LibRelease.SFMLGraphics}",
            "%{LibRelease.SFMLAudio}",
            "%{LibRelease.SFMLMain}"
        }