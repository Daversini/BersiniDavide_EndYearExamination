-- Solution Dependencies

-- Includes directories
IncludeDir = {}
IncludeDir["SFML"] = "%{wks.location}/ThirdParty/SFML/include"

-- Libraries directories
LibraryDir = {}
LibraryDir["SFML"] = "%{wks.location}/ThirdParty/SFML/libs"

-- Libraries configurations
LibDebug = {}
LibDebug["SFMLMain"] = "%{LibraryDir.SFML}/sfml-main-d.lib"
LibDebug["SFMLSystem"] = "%{LibraryDir.SFML}/sfml-system-s-d.lib"
LibDebug["SFMLWindow"] = "%{LibraryDir.SFML}/sfml-window-s-d.lib"
LibDebug["SFMLGraphics"] = "%{LibraryDir.SFML}/sfml-graphics-s-d.lib"
LibDebug["SFMLAudio"] = "%{LibraryDir.SFML}/sfml-audio-s-d.lib"

LibRelease = {}
LibRelease["SFMLMain"] = "%{LibraryDir.SFML}/sfml-main.lib"
LibRelease["SFMLSystem"] = "%{LibraryDir.SFML}/sfml-system-s.lib"
LibRelease["SFMLWindow"] = "%{LibraryDir.SFML}/sfml-window-s.lib"
LibRelease["SFMLGraphics"] = "%{LibraryDir.SFML}/sfml-graphics-s.lib"
LibRelease["SFMLAudio"] = "%{LibraryDir.SFML}/sfml-audio-s.lib"