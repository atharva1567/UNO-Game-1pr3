🎴 UNO — Console Edition
A collaborative C++ recreation of the classic UNO card game, built with clean terminal UI, modular game logic, and a polished user experience.

UNO Console Edition is a fully interactive, terminal‑based implementation of the iconic UNO card game. Designed as a collaborative C++ project, it features a structured object‑oriented architecture, a custom UI system, and a smooth gameplay loop that mirrors the real card game experience.

Players can compete against human or bot opponents, draw and play cards, trigger special actions (+2, Reverse, Skip, Wild, Wild +4), and race to empty their hand. The project emphasizes clean code organization, readable UI output, and a visually appealing menu system with colored borders and dynamic formatting.

⭐ Key Features
🎨 Polished Terminal UI
Custom double‑bordered red menu box

Yellow UNO title (matching the real card logo)

Clean spacing, alignment, and color‑controlled output

Rules screen with structured formatting

🧠 Object‑Oriented Game Architecture
Card class for color, value, and special actions

Deck class for shuffling, drawing, and managing cards

Player, HumanPlayer, and BotPlayer classes

Game class controlling turn order, rules, and win conditions

🤖 Bot Player Logic
Bots automatically choose valid playable cards

Falls back to drawing when no moves are available

Mimics simple strategic behavior

🔄 Full UNO Gameplay Rules
Match by color or number

Wild and Wild +4 cards

Skip, Reverse, Draw Two

Forced draws when no valid moves

Automatic turn rotation

🧩 Modular File Structure
Each component lives in its own .cpp / .h pair:

Card, Deck, Player, Game, Menu, UI, etc.
This makes the project easy to read, maintain, and extend.

👥 Collaborative Development
Built by a 3‑member team, with:

shared GitHub workflow

modular responsibilities

merged contributions

polished final integration

🕹️ How It Works
1. Launch the game
The program opens with a polished red double‑border menu:

Code
╔══════════════════════════════════════════════╗
║                    U N O                     ║
║                    Creators:                 ║
║         Atharva G, Adam C, Juan R            ║
║                  1. Play Now                 ║
║                  2. Rules                    ║
║                  3. Exit                     ║
╚══════════════════════════════════════════════╝
2. Choose your mode
Play Now

View Rules

Exit

3. Play UNO
Draw cards

Play matching cards

Trigger special effects

Try to empty your hand first

The game handles all rule enforcement, turn rotation, and card validation.

🧱 Tech Stack
Component	Technology
Language	C++
UI	ANSI escape codes (colors, formatting)
Build System	g++ / clang++
Platform	macOS Terminal, Linux Terminal, Windows Terminal (with ANSI enabled)


📁 Project Structure
Code
UNO/
│── Card.h / Card.cpp
│── Deck.h / Deck.cpp
│── Player.h / Player.cpp
│── HumanPlayer.h / HumanPlayer.cpp
│── BotPlayer.h / BotPlayer.cpp
│── Game.h / Game.cpp
│── Menu.h
│── UI.h
│── UNO.cpp   (main)
│── deck.txt
🚀 Future Enhancements
Multiplayer over network

Advanced bot strategy

Save/load game state

Animated card dealing

GUI version (SFML / Qt)

👥 Contributors
Atharva G — UI/UX, menu system, integration, polish

Adam C — core game logic, deck mechanics

Juan R — player system, bot logic

📜 License
MIT License (or whatever your group chooses)
