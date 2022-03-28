/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include "ArgumentChecker.hpp"
#include "MainMenu.hpp"

class Arcade : public ICore {
    public:
        Arcade();
        ~Arcade();
        // ICore Functions
        void setPixelsPerCell(std::uint32_t pixelsPerCell);
        void setFramerate(unsigned framerate);
        ICore::Texture *loadTexture(const std::string &pngFilename, char character, ICore::Color characterColor, ICore::Color backgroundColor, std::size_t width, std::size_t height);
        void openWindow(ICore::Vector2u pixelsWantedWindowSize);
        bool isButtonPressed(ICore::Button button);
        ICore::MouseButtonReleaseEvent getMouseButtonReleaseEvent();
        void startTextInput();
        std::string getTextInput();
        void endTextInput();
        void clearScreen(ICore::Color color);
        void renderSprite(ICore::Sprite sprite);
        void addNewScore(std::uint32_t score);

        // Personal Functions
        void setDlGraphical(void *graphical);
        void changeLibraryByPath(std::string path, bool graphical);
        void initClassFromDl(bool graphical);
        void closeDl(bool graphical);
        void checkFunctionButton(void);
        void gameRestart(void);
        void goBackToMenu(void);
        void exitArcade(void);
        void gameLoop(void);
        void launchGame(void);
    protected:
        std::unique_ptr<IDisplayModule> _graphical;
        std::unique_ptr<IGameModule> _game;
        void *_dlGraphical;
        void *_dlGame;
        std::string _prevGraphPath;
        std::string _nextGraphPath;
        std::string _prevGamePath;
        std::string _nextGamePath;
        bool _inGame;
        bool _inMenu;
        unsigned _framerate;
    private:
};

#endif /* !ARCADE_HPP_ */
