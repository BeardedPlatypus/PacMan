<p align="center"><img src="https://github.com/BeardedPlatypus/PacMan/blob/master/logo.png?raw=true" alt="PacMan" title="PacMan" width=80% /></p>

# Pacman

[![Build Status](https://dev.azure.com/mwtegelaers/PacMan/_apis/build/status/BeardedPlatypus.PacMan?branchName=master)](https://dev.azure.com/mwtegelaers/PacMan/_build/latest?definitionId=1&branchName=master)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=BeardedPlatypus_PacMan&metric=alert_status)](https://sonarcloud.io/dashboard?id=BeardedPlatypus_PacMan)

A simple WIP PacMan clone written in C++ with SDL2.

## Motivation

The primary aim of this project is to develop a simple but polished PacMan game
to improve my understanding of C++ and game development in general and to 
showcase my current software engineering skills. At the end of this journey, I
hope to have implemented the different aspects of the pacman game, including the
rendering, sound, ui and ai. Furthermore, to tie it all together, the product 
should come with a working installer.

As a portfolio piece, the code itself is made available under the MIT license, 
and is available to be reused in other projects. If you decide to reuse any part,
some form of attribution is very appreciated, but not required.

## Current state

For an overview of what has been developed, and what I am currently working on,
I would direct you the azure devops boards page, which can be found 
[here](https://dev.azure.com/mwtegelaers/PacMan/_boards/board/t/PacMan%20Team/Stories).

## Installation

### To play

In order to just play the game, the game can be installed through the installer.
As part of each Azure Devops CI run, an .MSI is created. These can be found in the
pipeline section of the Azure Devops project. Once the project reaches a more 
playable state, this section will be updated.

### To develop

In order to compile and develop on your own machine, several tools need to be
installed. The [Azure Devops Pipeline file](https://github.com/BeardedPlatypus/PacMan/blob/master/azure-pipelines.yml)
provides a good overview of the steps that need to be taken to build the project
on your own machine.

* Install [vcpkg](https://github.com/microsoft/vcpkg).
* Clone this repository:

```
git clone https://github.com/BeardedPlatypus/PacMan.git 
```

* Install sdl2 sdl2-image and gtest by running the following code in a command line:

```
vcpkg install sdl2 sdl2-image gtest
vcpkg integrate install
```

* Open PacMan.sln in visual studio 2019.
* Build the project as you normally would.

Additional blog posts will be added to describe the rationale behind the choices
made. This section will be updated once they are added.

## Documentation

Currently, the documentation only lives within the actual code base. An extracted API
will be provided in the future. This section will be updated.

### Blog Articles

Different aspects of the development process will be documented in more detail
in different articles on my blog. This section will be updated.

* [SonarCloud CI](https://beardedplatypus.github.io/sonarcloud-static-code-analysis-in-a-c-project.html)
