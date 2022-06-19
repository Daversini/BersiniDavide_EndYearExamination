-- Solution Dependencies

IncludeDir = {}
IncludeDir["SFML"] = "%{wks.location}/ThirdParty/SFML/include"

LibraryDir = {}
LibraryDir["SFML"] = "%{wks.location}/ThirdParty/SFML/libs"

Library = {}
Library["SFMLAudio"] = "%{LibraryDir.SFML}/sfml-audio.lib"
Library["SFMLGraphics"] = "%{LibraryDir.SFML}/sfml-graphics.lib"
Library["SFMLMain"] = "%{LibraryDir.SFML}/sfml-main.lib"
Library["SFMLSystem"] = "%{LibraryDir.SFML}/sfml-system.lib"
Library["SFMLWindow"] = "%{LibraryDir.SFML}/sfml-window.lib"