include "premake5-Dependencies.lua"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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

include "../Framework"
include "../Sandbox"