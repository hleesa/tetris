#include <SFML/Graphics.hpp>
#include <iostream> // 콘솔 출력을 위해 추가

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float BLOCK_SIZE = 20.f;
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

bool isValidPosition(sf::RectangleShape& gameBoard, sf::RectangleShape& block){
    auto blockPosition = block.getPosition();
    auto gameBoardPosition = gameBoard.getPosition();
    if (blockPosition.x < gameBoardPosition.x || gameBoardPosition.x  + BOARD_WIDTH * BLOCK_SIZE < blockPosition.x) {
        return false;
    }
    else if (blockPosition.y < gameBoardPosition.y || gameBoardPosition.y + BOARD_HEIGHT * BLOCK_SIZE < blockPosition.y + BLOCK_SIZE){
        return false;
    }
    return true;}

int main()
{
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "tetris");

    float boardX = (WINDOW_WIDTH - BOARD_WIDTH * BLOCK_SIZE) / 2.0f;
    float boardY = (WINDOW_HEIGHT - BOARD_HEIGHT * BLOCK_SIZE) / 2.0f;
    sf::RectangleShape gameBoard(sf::Vector2(BOARD_WIDTH * BLOCK_SIZE, BOARD_HEIGHT * BLOCK_SIZE));
    gameBoard.setPosition({boardX, boardY});
    gameBoard.setOutlineThickness(2.f);
    gameBoard.setOutlineColor(sf::Color::White);
    gameBoard.setFillColor(sf::Color::Transparent);

    sf::RectangleShape block(sf::Vector2(BLOCK_SIZE, BLOCK_SIZE));
    block.setFillColor(sf::Color::Red);
    block.setPosition({boardX + (BOARD_WIDTH - 1) * BLOCK_SIZE / 2, boardY});

    // 타이머를 위한 시계와 간격 설정
    sf::Clock clock;
    const sf::Time fallInterval = sf::seconds(0.5f); // 0.5초

    while (window.isOpen())
    {
        // 이벤트 처리 루프 (공식 튜토리얼 방식)
        while (const auto event = window.pollEvent())
        {
            // 1. 창 닫기 버튼 확인
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            // 2. 키 입력 확인
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                // scancode는 키보드 레이아웃에 상관없는 물리적 키 위치입니다.
                // ESC키의 경우 code와 scancode가 동일하게 작동합니다.
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }
            }
        }

        // 타이머 로직
        if (clock.getElapsedTime() >= fallInterval)
        {
            // 0.5초가 지났으므로 로직을 실행합니다.
            // (지금은 콘솔에 메시지를 출력하여 테스트합니다)
            std::cout << "Timer ticked! A block should fall now." << std::endl;

            block.move({0, BLOCK_SIZE});
            // 시계를 재시작하여 다음 0.5초를 셉니다.
            clock.restart();
        }

        window.clear(sf::Color::Black);
        // 점을 화면에 그립니다 (clear와 display 사이)
        window.draw(gameBoard);
        if(isValidPosition(gameBoard, block)) {
            window.draw(block);
        }

        window.display();
    }

    return 0;
}
