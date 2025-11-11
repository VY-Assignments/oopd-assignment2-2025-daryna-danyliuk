#include "Application.h"
#include <iostream>

Application::Application()
    : window(sf::VideoMode(800, 600), "Tetris Game"),
    clock(),
    engine(),
    renderer(window),
    controller(),
    isRunning(true)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    engine.start();
}
void Application::run() {
    clock.restart();
    while (isRunning && window.isOpen()) {
        processEvents();
        float deltaTime = clock.restart().asSeconds();
        engine.update(deltaTime);
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            std::cout << "Detected key press" << std::endl;
            InputCommand command = mapKeyToCommand(event.key.code);
            if (command != InputCommand::None) {
                std::cout << "Command detected: " << static_cast<int>(command) << std::endl;
                controller.handleCommand(command, engine);
            }
        }
    }
}

InputCommand Application::mapKeyToCommand(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::Left:  
        return InputCommand::MoveLeft;
    case sf::Keyboard::Right: 
        return InputCommand::MoveRight;
    case sf::Keyboard::Down:  
        return InputCommand::MoveDown;
    case sf::Keyboard::U:    
        return InputCommand::RotateClockwise;
    case sf::Keyboard::Z:     
        return InputCommand::RotateCounterClockwise;
    case sf::Keyboard::Space:   
        return InputCommand::Restart;
    default:                  
        return InputCommand::None;
    }
}
void Application::render() {
    renderer.render(engine);
}

void Application::close() {
    window.close();
    isRunning = false;
}