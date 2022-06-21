include "premake5-Dependencies.lua"

workspace "BersiniDavide_EndYearExamination"
    location "../"
    architecture "x86_64"
    startproject "Sandbox"

    -- Solution configurations
    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "../Framework"
include "../Sandbox"