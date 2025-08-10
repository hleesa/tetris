#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Example");

    // 점 객체 생성 (루프 시작 전)
    sf::CircleShape point(2.f);
    point.setFillColor(sf::Color::White);
    point.setPosition({398.f, 298.f});

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

        window.clear(sf::Color::Black);

        // 점을 화면에 그립니다 (clear와 display 사이)
        window.draw(point);

        window.display();
    }

    return 0;
}
