project "Framework"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    location "%{wks.location}/Framework"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin-Int/" .. outputdir .. "/%{prj.name}")

    -- Add all C++ files from the "src/" directory and any subdirectories
    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    -- List of Include directories
    includedirs
    {
        "src",
        "%{IncludeDir.SFML}"
    }

    -- List of Libraries to link against
    links
    {
        "%{Library.SFMLAudio}",
        "%{Library.SFMLGraphics}",
        "%{Library.SFMLMain}",
        "%{Library.SFMLSystem}",
        "%{Library.SFMLWindow}"
    }

    postbuildcommands
    {
        "{COPY} %{wks.location}/Bin/" .. outputdir .. "/Framework/*.dll %{wks.location}/Bin/" .. outputdir .. "/Sandbox/"
    }
    postbuildmessage "Copying depencencies..."

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"