include "premake5-Dependencies.lua"

workspace "BersiniDavide_EndYearExamination"
    architecture "x86_64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Framework"
include "Sandbox"