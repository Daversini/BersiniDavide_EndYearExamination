<p align = "center">
    <img src="Sandbox/res/icon.ico" alt="Sandbox Logo" width="250">
</p>

<br>

# **MyEngine Framework**
A simple **SFML-ready Framework** that supports the creation of game objects with attachable components.
<br>
`Please help me to find a name, I have no imagination (ㆆ_ㆆ)`

<br>

# **Table of Contents** 📍
- [**Requirements**](#requirements) 🏷️
- [**How to install**](#how-to-install) 🚀
- [**Currently supported functionalities**](#currently-supported-functionalities) ⚙️
- [**Getting Started**](#getting-started) 🎬
- [**Contributing**](#contributing) 🤝
- [**License**](#license) 📜
- [**Contact**](#contact) 📧

<br>

## **Requirements**
To open and build the **Solution** you need **Visual Studio** installed on your computer ([**Reccomended Visual Studio 2019**](https://visualstudio.microsoft.com/vs/older-downloads/)).
<br>
To run the executable you also need **OpenGL32** installed.
<br>
In order to generate the **documentation** you need to have installed [**Doxygen**](https://github.com/doxygen/doxygen) as an environment variable.

<br>

## **How to install**
1. First of all, clone this [**Repository**](https://github.com/Daversini/BersiniDavide_EndYearExamination). (Note that you have to clone it into a path **WITHOUT** spaces, otherwise the [Visual Studio Post build copy command will fail](https://stackoverflow.com/a/44393723/17818428))
<br>
2. Then run the `GenSolution.bat` file inside the `/Scripts` folder and select a **Visual Studio** version to generate the **Solution**.
<br>
3. Open the **Solution** and try to build the **Framework**.
<br>

If there are no errors, you can now [**start to build your own Sandbox!**](#getting-started)
<br>

> NB: If you want to generate the **documentation**, run `GenDocumentation.bat` file inside the `/Scripts` folder. It will automatically open `index.html` under `/Docs/html`

<br>

## **Currently supported Functionalities**

At the moment the Framework supports the creation of simple **Game Objects** (as a **Sprite**, or a **Character**) and the possibility to attach different **Components** to them.

### As for `Game Objects`:
- #### **`Area2D`**
    A **GameObject** with a 2D Area controlled by a **RectTransform Component**.
- #### **`Sprite`**
    An **Area2D** with a **Renderer2D Component**.
- #### **`Character`**
    A **Sprite** that can be controlled with an **InputController** and a **MovementComponent**.

### As for `Components`:
- #### **`RectTransform`**
    A **Component** capable of giving a rectangle portion transform to a **GameObject**.
- #### **`Renderer2D`**
    A **Component** capable of giving 2D rendering to a **GameObject**.
- #### **`InputController`**
    A **Component** capable of receiving keyboard inputs from a **GameObject**.
- #### **`MovementComponent`**
    A **Component** capable of calculating the movement of a **GameObject**.

<br>

## **Getting Started**
### After you followed every step in the [installation](#how-to-install) guide, you can now start the **Solution** and open `Sandbox.cpp`.

<br>

To run the **Sandbox** you need to include these headers:
```cpp
#include <MyEngine/Core/EntryPoint.h>
#include "SandboxLayer.h"
```

You'll see a class that extends **Application**. It looks something like this:
```cpp
class Sandbox : public MyEngine::Application
{
public:
	Sandbox() : Application(1920, 1080, "Sandbox")
	{
		// Game Settings
		enableFPSLimit();
		setMaxFPS(60);

		// Push SandboxLayer to Application
		pushLayer(new SandboxLayer);
	}

	~Sandbox() {}
};
```

In order to create an **Application**, we implement this method from the **Framework**:
```cpp
MyEngine::Application* MyEngine::createApplication()
{
	return new Sandbox;
}
```

<br>

### You can now open `SandboxLayer.cpp` were all **SandboxLayer** methods are implemented

<br>

Go into the **onAttach()** method and start to create your first **Game Object**!
```cpp
MyEngine::Sprite* background = new MyEngine::Sprite();  // Creation of a Sprite Game Object
```

Now you need to define custom properties for the **Game Object**
```cpp
// Make sure that the texture path is correct!
background->renderer->setTextureSource("resources/textures/AOT-background.jpg", true, true);
background->rectangleTransform->setScale(1920, 1080);
```

When you're done with a **Game Object** you need to push that into **allEntities** vector
```cpp
allEntities.push_back(background);
```

<br>

Now let's create a **Character** that we can move in the viewport
```cpp
MyEngine::Character* player = new MyEngine::Character();    // Move the Character with WASD
player->renderer->setTextureSource("resources/textures/Mikasa.png", true, false);
player->movementComponent->speed = 300;
player->rectangleTransform->setScale(400, 400);
player->rectangleTransform->setPosition(1920 / 2 - 400 / 2, 1080 / 2 - 400 / 2);
allEntities.push_back(player);
```

<br>

After the creation of all **Game Objects**, return **allEntities** back to the **Application**
```cpp
return allEntities;
```

<br>


### And we're done! You now have a movable **Character** rendered over a custom background!

<br>

## **Contributing**

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<br>

## **License**

Distributed under the MIT License. See `LICENSE` for more information.

<br>

## **Contact**

Davide Bersini - [@Daversini](https://twitter.com/Daversini) - bersini.davide@gmail.com

Project Link: [https://github.com/Daversini/BersiniDavide_EndYearExamination](https://github.com/Daversini/BersiniDavide_EndYearExamination)