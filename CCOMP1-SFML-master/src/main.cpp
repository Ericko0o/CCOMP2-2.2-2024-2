#include <iostream>
#include <SFML/Graphics.hpp>
#include "chessGame.h"
using namespace std;

// Función para mostrar el menú inicial
bool showMenu(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("Texturesa/arial.ttf"); // Asegúrate de que este archivo exista

    // Cargar imagen de fondo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.jpeg")) { // Asegúrate de que la ruta de la imagen sea correcta
        cout << "Error cargando la imagen de fondo" << endl;
        return false;
    }
    sf::Sprite background(backgroundTexture);

    // Configurar el texto de las opciones
    sf::Text playText("PLAY", font, 50);
    playText.setPosition(100, 150);
    playText.setFillColor(sf::Color::White);

    sf::Text exitText("EXIT", font, 50);
    exitText.setPosition(100, 250);
    exitText.setFillColor(sf::Color::White);

    // Crear los recuadros para las opciones
    sf::RectangleShape playRect(sf::Vector2f(playText.getGlobalBounds().width + 20, playText.getGlobalBounds().height + 10));
    playRect.setPosition(90, 159);
    playRect.setFillColor(sf::Color(50, 50, 50, 200)); // Fondo semitransparente
    playRect.setOutlineColor(sf::Color::White);
    playRect.setOutlineThickness(3);

    sf::RectangleShape exitRect(sf::Vector2f(exitText.getGlobalBounds().width + 20, exitText.getGlobalBounds().height + 10));
    exitRect.setPosition(90, 259);
    exitRect.setFillColor(sf::Color(50, 50, 50, 200)); // Fondo semitransparente
    exitRect.setOutlineColor(sf::Color::White);
    exitRect.setOutlineThickness(3);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Verificar si el clic está dentro de las áreas de las opciones
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    if (playRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        return true; // Usuario seleccionó "JUGAR"
                    }

                    if (exitRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        window.close(); // Usuario seleccionó "SALIR"
                        return false;
                    }
                }
            }
        }

        // Dibujar el menú con la imagen de fondo
        window.clear();
        window.draw(background); // Fondo de la imagen
        window.draw(playRect); // Recuadro de "JUGAR"
        window.draw(playText);
        window.draw(exitRect); // Recuadro de "SALIR"
        window.draw(exitText);
        window.display();
    }

    return false; // Si la ventana se cierra
}

int main() {
    sf::RenderWindow window(sf::VideoMode(768, 512), "Ajedrez 2 jugadores", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    // Mostrar el menú inicial
    if (!showMenu(window)) {
        return 0; // Salir si el usuario seleccionó "SALIR"
    }

    ChessGame chess(sf::Color(235, 236, 208), sf::Color(178, 147, 112));

    // Bucle principal del juego
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                // Regresar al menú si se presiona ESC
                if (!showMenu(window)) {
                    return 0; // Salir si el usuario seleccionó "SALIR" desde el menú
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if ((0 <= event.mouseButton.x) && (event.mouseButton.x <= 512) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 512)) {
                        unsigned int buttonPos{(event.mouseButton.x / 64) + ((event.mouseButton.y / 64) * 8)};

                        if (!chess.getSelected())
                            chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                    } else if ((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (5 <= event.mouseButton.y) && (event.mouseButton.y <= 45)) {
                        chess.restart();
                    }
                }
            }
        }

        window.clear();
        window.draw(chess);
        window.display();
    }

    return 0;
}
