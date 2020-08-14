# MurrayEngine
_MurrayEngine_ was a collaborative effort by me (Nicklas RC) and Mia H on our asssigment in course PROG3 (HT2015) at Stockholm University DSV to create a game engine using C++ and SDL2.
This repo has been migrated from CloudForge to GitHub in order to preserve it.

Below is the original sumbission documentation (in Swedish)

## Information
Denna uppgift är uppdelad I två delar – spelmotorn (som vi kallat MurrayEngine) och implementationen (kallat Implementation).

## Plattform
Vi har använt oss av Windows och Visual Studio 2013 Pro, samt Ubuntu och g++ för att testa koden. Obs att för g++ ange flaggan ”-std=c++11”.

## Kompilering
Börja med att skapa ett static library av MurrayEngine, och länka sedan det i kompileringen av Implementation.

## Externa bibliotek
Vi har använt oss av följande externa bibliotek:
* SDL2-2.0.3
* SDL2_ttf-2.0.12
* SDL2_image-2.0.0

Då externa bibliotek anropas olika beroende på plattform så har vi villkorat in dessa i vår kod på följande vis:

```
#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif
```

## Resursfiler
Programmet använder flera externa filer (.cfg, .png och .ttf). Dessa ligger under mappen ./Resources och måste placeras i samma mapp som det kompilerade programmet ligger i för att spelet ska starta.

## Spelkontroller

I spelet använder man sig av följande kontroller:
* W: Gå uppåt
* S: Gå nedåt
* A: Gå vänster
* D: Gå höger
* Mellanslag: Skjut
* F1: Ladda om karta
* Retur: Starta textinmatning (Retur för att avsluta)
