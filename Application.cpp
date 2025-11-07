#include "Application.h"

Application::Application()
    : window(sf::VideoMode(800, 600), "Tetris Game"),
    clock(),
    engine(),
    renderer(window),
    controller(),
    isRunning(true)
{
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
            InputCommand command = mapKeyToCommand(event.key.code);
            if (command != InputCommand::None) {
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
        return InputCommand::Pause;
    default:                  
        return InputCommand::None;
    }
}

void Application::render() {
    renderer.render(engine);
}

void Application::update(float deltaTime) {
}

void Application::close() {
    window.close();
    isRunning = false;
}