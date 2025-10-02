# Folke - A Simple 2D Game Engine

Folke is a lightweight 2D game engine built in C++ using SDL2. It features an Entity Component System (ECS) architecture and is designed for creating 2D games with efficient rendering and game object management.

## Features

### Core Engine
- **SDL2 Integration**: Full SDL2 support for rendering, input handling, and window management
- **Entity Component System (ECS)**: Clean, modular architecture for game objects
- **Component-Based Design**: Flexible system for adding behaviors to entities
- **Game Loop**: Fixed timestep game loop with proper frame timing (30 FPS)
- **Logging System**: Built-in logging with different severity levels (Info, Warning, Error)

### Graphics & Rendering
- **SDL2 Renderer**: Hardware-accelerated rendering with VSync support
- **Fullscreen Support**: Borderless fullscreen window mode
- **Asset Management**: Organized asset structure for sprites, fonts, sounds, and tilemaps

### Mathematics
- **GLM Integration**: OpenGL Mathematics library for vector and matrix operations
- **Transform System**: Position, scale, and rotation components for entities

### Development Tools
- **Cross-Platform Build**: Support for both Visual Studio (Windows) and Makefile (Linux/Unix)
- **ImGui Integration**: Immediate mode GUI for debugging and development tools
- **Sol2 Integration**: Lua scripting support for game logic

## Project Structure

```
folk-engine/
├── src/                    # Source code
│   ├── Main.cpp           # Entry point
│   ├── Game/              # Core game class
│   ├── ECS/               # Entity Component System
│   ├── Logger/            # Logging utilities
│   ├── Components/        # Game components
│   └── Systems/           # Game systems
├── libs/                  # Third-party libraries
│   ├── glm/              # OpenGL Mathematics
│   ├── imgui/            # ImGui for debug UI
│   ├── lua/              # Lua scripting
│   └── sol/              # Sol2 Lua binding
├── assets/               # Game assets
│   ├── fonts/           # Font files
│   ├── images/          # Sprites and textures
│   ├── sounds/          # Audio files
│   └── tilemaps/        # Map data
└── Debug/               # Build output
```

## Dependencies

- **SDL2**: Graphics, audio, and input handling
- **SDL2_image**: Image loading support
- **SDL2_ttf**: TrueType font rendering
- **SDL2_mixer**: Audio mixing
- **GLM**: Mathematics library for 3D graphics
- **ImGui**: Immediate mode GUI
- **Lua**: Scripting language
- **Sol2**: C++ Lua binding library

## Building

### Windows (Visual Studio)
1. Open `Folke.sln` in Visual Studio
2. Build the solution (Ctrl+Shift+B)
3. Run the executable from `Debug/Folke.exe`

### Linux/Unix (Makefile)
```bash
# Install dependencies (Ubuntu/Debian)
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev liblua5.3-dev

# Build the project
make build

# Run the game
make run

# Clean build files
make clean
```

## Current Implementation Status

### ✅ Completed
- Basic game window and SDL2 initialization
- Game loop with proper timing
- ECS architecture foundation
- Entity creation and management
- Component system with type safety
- System registration and management
- Transform component for position/scale/rotation
- Logging system with multiple severity levels
- Cross-platform build system

### 🚧 In Progress
- Movement system implementation
- Component and system integration
- Asset loading and management

### 📋 Planned Features
- Sprite rendering system
- Animation system
- Collision detection
- Audio system integration
- Input handling system
- Scene management
- Tilemap rendering
- Particle systems
- Lua scripting integration

## Getting Started

1. Clone the repository
2. Install the required dependencies
3. Build the project using your preferred method
4. Run the executable

The engine currently initializes a fullscreen window and runs the basic game loop. Press ESC to exit.

## Architecture

The engine uses an Entity Component System (ECS) pattern:

- **Entities**: Unique identifiers for game objects
- **Components**: Data containers (e.g., TransformComponent for position/rotation)
- **Systems**: Logic processors that operate on entities with specific components

This architecture provides flexibility and performance benefits for game development.

## Contributing

This is a learning project focused on understanding game engine architecture and C++ development. Contributions and suggestions are welcome!

## License

This project is open source and available under the MIT License.
