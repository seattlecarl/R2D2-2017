/**
 * \file      button.cc
 * \author    Rene de Kluis, Koen de Groot
 * \copyright Copyright (c) 2017, The R2D2 Team
 * \license   See LICENSE
 */

#include "button.hh"
#include <iostream>
#include "mouse.hh"

Button::Button(sf::RenderWindow & window, sf::Vector2f position, 
               sf::Vector2f size, buttonCommand id, std::string text, bool isVisable):
    window(window),
    position(position),
    size(size),
    id(id),
    isVisable(isVisable)
{
    button.setSize(size);
    button.setOutlineColor(sf::Color::Red);
    button.setOutlineThickness(2);
    button.setPosition(position);

    if (!font.loadFromFile(fontName)) {
        std::cerr << "Requested font could not be loaded.\n";
    }
    buttonText.setFont(font);
    buttonText.setPosition(position);
    buttonText.setString(text);
    buttonText.setColor(sf::Color::Black);
    buttonText.setScale(
        float(((1 / buttonText.getGlobalBounds().width) * (size.x-(size.x/20)))),
        float((1 / buttonText.getGlobalBounds().height) * size.y/2)
    );

    if (!isVisable) {
        button.setFillColor(sf::Color::Transparent);
        button.setOutlineColor(sf::Color::Transparent);
        buttonText.setColor(sf::Color::Transparent);
    }

}

void Button::draw() {
    if (isVisable) {
        if (isFocused) {
            button.setFillColor(sf::Color::Blue);
        }
        else {
            button.setFillColor(sf::Color::White);
        }
    }
    isFocused = false;
    window.draw(button);
    window.draw(buttonText);
}

void Button::setFocus(bool b) {
    isFocused = b;
}

bool Button::getFocus() {
    return isFocused;
}

void Button::setSize(sf::Vector2f newSize) {
    button.setSize(newSize);
    size = newSize;
}
void Button::setText(std::string newText) {
    buttonText.setString(newText);
}

void Button::setPosition(sf::Vector2f newPosition) {
    button.setPosition(newPosition);
    buttonText.setPosition(newPosition);
    position = newPosition;
}

void Button::setFont(std::string newFont) {
    font.loadFromFile(newFont);
}

void Button::setVisable(bool visable) {
    isVisable = visable;
    if (visable) {
        button.setFillColor(sf::Color::White);
        button.setOutlineColor(sf::Color::Red);
        buttonText.setColor(sf::Color::Black);
    }
    else {
        button.setFillColor(sf::Color::Transparent);
        button.setOutlineColor(sf::Color::Transparent);
        buttonText.setColor(sf::Color::Transparent);
    }
}

bool Button::isPressed() {
    if (getBounds().contains(getMousePosition(window))) {
        if (button.getFillColor() != sf::Color::Transparent) {
            isFocused = true;
        }
    }
    return isFocused;
}

sf::Vector2f Button::getPosition(){
    return position;
}
buttonCommand Button::getId(){
    return id;
}
sf::Vector2f Button::getSize(){
    return size;
}

sf::FloatRect Button::getBounds() {
    return sf::FloatRect(position.x, position.y, size.x, size.y);
}
