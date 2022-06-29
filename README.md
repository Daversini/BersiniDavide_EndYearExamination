<p align = "center">
    <img src="Sandbox/res/icon.ico" alt="icon" width="200">
</p>

<br>

# **MyEngine Framework**
A simple **SFML-ready Framework** that supports the creation of game objects with attachable components.
<br>
`Please help me to find a name, I have no imagination (ㆆ_ㆆ)`

<br>

# **Table of Contents** 📍
- [**Requirements**](#requirements) 🏷️

- [**How to install**](#how-to-install-⚙️) ⚙️

- [**Currently supported functionalities**](#currently-supported-functionalities)

- [**Getting Started**](#getting-started)

- [**Documentation**](#documentation)

- [**Credits**](#credits)

<br>

## **Requirements** 🏷️
To open and build the **Solution** you need **Visual Studio** installed on your computer ([**Reccomended Visual Studio 2019**](https://visualstudio.microsoft.com/vs/older-downloads/)).
<br>
To run the executable you also need **OpenGL32** installed.
<br>
In order to generate the [**documentation**](#documentation) you need to have installed [**Doxygen**](https://github.com/doxygen/doxygen) as an environment variable.

<br>

## **How to install** ⚙️
> First of all, clone this [**Repository**](https://github.com/Daversini/BersiniDavide_EndYearExamination).
<br>
Then run the `GenSolution.bat` file under the `/Scripts` folder and select a **Visual Studio** version to generate the **Solution**.
<br>
Open the **Solution** and try to build the **Framework**.
<br>
If there are no errors, you can now [**start to build your own Sandbox!**](#get-started)

<br>

## **Currently supported Functionalities**

At the moment the Framework supports the creation of simple `Game Objects` (as a `Sprite`, or a `Character`) and the possibility to attach different `components` to them.

### As for `Game Objects`:
- #### **`Area2D`**
    A *`GameObject`* with a 2D Area controlled by a **RectTransform Component**.

- #### **`Sprite`**
    An *`Area2D`* with a **Renderer2D Component**.

- #### **`Character`**
    A *`Sprite`* that can be controlled with an **InputController** and a **MovementComponent**.


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

<br>

## **Documentation**

<br>

## **Credits**