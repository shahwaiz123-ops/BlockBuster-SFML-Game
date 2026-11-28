
#include <SFML/Graphics.hpp>
#include <iostream>
#include<fstream>
#include<string>
using namespace std;
using namespace sf;

void drawPlayer(RenderWindow& window,int paddleX,int ballX,int ballY)
{
    RectangleShape paddle({ 100.f, 14.f });
    CircleShape ball(6.f);
    paddle.setFillColor(Color::Cyan);
    ball.setFillColor(Color::White);
    paddle.setPosition({ (float)paddleX,650.f });
    ball.setPosition({ (float)ballX,(float)ballY});
    window.draw(paddle);
    window.draw(ball);
}
void drawBricks(RenderWindow& window,const int bricks[8][10])

{
    RectangleShape brick({ 58.f, 23.f });
    for (int r = 0; r < 8; r++)  //rows
    {
        for (int c = 0; c < 10; c++) //cols
        {
            if (bricks[r][c] != 0)
            {
                if(bricks[r][c]==3)
                    brick.setFillColor(Color::Red);
                else if(bricks[r][c]==2)
                    brick.setFillColor(Color::Yellow);
                else if(bricks[r][c]==1)
                    brick.setFillColor(Color::Green);
                brick.setPosition({
               c * 60.f + 1,
                100.f + r * 25.f + 1
                    });
                window.draw(brick);
            }
        }

    }
}
void centertext(Text& text, float x, float y) {
    FloatRect bounds = text.getLocalBounds();
    text.setOrigin({
        bounds.position.x + bounds.size.x / 2, bounds.position.y + bounds.size.y / 2,
        });
    text.setPosition({ x,y });

}
void drawMenu(RenderWindow& window, Font& font, int gameStarted)
{
    // 1. Gradient background
    RectangleShape background({ 600.f, 10.f });
    for (int i = 0; i < 70; i++)
    {
        background.setPosition({ 0.f, i * 10.f });
        background.setFillColor(Color(
            8 + i / 5,
            12 + i / 8,
            30 + i / 2
        ));
        window.draw(background);
    }
    // 2. Background particles
    CircleShape particle(1.5f);
    particle.setFillColor(Color(100, 200, 255, 90));
    for (int i = 0; i < 60; i++)
    {
        particle.setPosition({
            (float)(24 + (i * 83) % 552),
            (float)(25 + (i * 67) % 650)
            });
        window.draw(particle);
    }
    // 3. Outer border
    RectangleShape border({ 574.f, 674.f });
    border.setPosition({ 13.f, 13.f });
    border.setFillColor(Color::Transparent);
    border.setOutlineThickness(2.f);
    border.setOutlineColor(Color(48, 74, 116));
    window.draw(border);
    // 4. Neon corner decorations
    RectangleShape cornerH({ 42.f, 3.f });
    RectangleShape cornerV({ 3.f, 42.f });
    cornerH.setFillColor(Color::Cyan);
    cornerV.setFillColor(Color::Cyan);
    for (int i = 0; i < 4; i++)
    {
        float x = 13.f;
        float y = 13.f;
        if (i % 2 == 1)
            x = 545.f;
        if (i >= 2)
            y = 684.f;
        cornerH.setPosition({ x, y });
        window.draw(cornerH);
       if (i % 2 == 1)
            x = 584.f;
        if (i >= 2)
            y = 645.f;
        cornerV.setPosition({ x, y });
        window.draw(cornerV);
    }
    // 5. Arcade edition text
    Text edition(font, "A R C A D E   E D I T I O N", 14);
    edition.setFillColor(Color(140, 172, 207));
    centertext(edition, 300.f, 35.f);
    window.draw(edition);
    // 6. Decorative bricks
    RectangleShape brick({ 56.f, 19.f });
    RectangleShape shine({ 52.f, 3.f });
    shine.setFillColor(Color(255, 255, 255, 65));
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 7; c++)
        {
            if (r == 0)
                brick.setFillColor(Color(237, 66, 109));
            else if (r == 1)
                brick.setFillColor(Color(129, 85, 239));
            else
                brick.setFillColor(Color(24, 183, 206));
            brick.setPosition({
                92.f + c * 60.f,
                64.f + r * 24.f
                });
            shine.setPosition({
                94.f + c * 60.f,
                66.f + r * 24.f
                });
            window.draw(brick);
            window.draw(shine);
        }
    }
    // 7. Title shadow
    Text shadow(font, "BLOCK BUSTER", 55);
    shadow.setStyle(Text::Bold);
    shadow.setFillColor(Color(20, 85, 124));
    centertext(shadow, 303.f, 204.f);
    window.draw(shadow);
    // 8. Main title
    Text title(font, "BLOCK BUSTER", 55);
    title.setStyle(Text::Bold);
    title.setFillColor(Color(105, 241, 255));
    centertext(title, 300.f, 200.f);
    window.draw(title);
    // 9. Subtitle
    Text subtitle(font, "BREAK. BOUNCE. CONQUER.", 17);
    subtitle.setFillColor(Color(179, 197, 235));
    centertext(subtitle, 300.f, 238.f);
    window.draw(subtitle);
    // 10. Divider line
    RectangleShape line({ 420.f, 1.f });
    line.setPosition({ 90.f, 256.f });
    line.setFillColor(Color(49, 84, 128));
    window.draw(line);
    // 11. Menu buttons
    string options[3] = {
        "NEW GAME",
        "CONTINUE GAME",
        "EXIT GAME"
    };
    Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
    RectangleShape button({ 300.f, 60.f });
    RectangleShape buttonShadow({ 300.f, 60.f });
    RectangleShape glow({ 310.f, 70.f });
    RectangleShape accent({ 5.f, 58.f });
    buttonShadow.setFillColor(Color(5, 8, 20));
   for (int i = 0; i < 3; i++)
    {
        float y = 280.f + i * 85.f;
        button.setPosition({ 150.f, y });
        buttonShadow.setPosition({
            154.f, y + 6.f
            });
        window.draw(buttonShadow);
        bool hover =
            mouse.x >= 150 && mouse.x <= 450 &&
            mouse.y >= y && mouse.y <= y + 60;
        bool disabled = (i == 1 && gameStarted == 0);
        // Default button appearance
        button.setFillColor(Color(25, 45, 88));
        button.setOutlineColor(Color(73, 231, 255));
        button.setOutlineThickness(2.f);
        accent.setFillColor(Color(73, 231, 255));
        // Exit button
        if (i == 2)
        {
            button.setFillColor(Color(56, 34, 59));
            button.setOutlineColor(Color(198, 92, 131));
            accent.setFillColor(Color(239, 102, 149));
        }
        // Hover effect
        if (hover && !disabled)
        {
            glow.setPosition({ 145.f, y - 5.f });
            glow.setFillColor(Color(40, 200, 255, 35));
            window.draw(glow);
            button.setFillColor(Color(30, 100, 165));
            button.setOutlineColor(Color::White);
        }
        // Disabled continue button
        if (disabled)
        {
            button.setFillColor(Color(40, 47, 70));
            button.setOutlineColor(Color(86, 97, 124));
            accent.setFillColor(Color(104, 117, 142));
        }
        window.draw(button);
        // Side accent
        accent.setPosition({ 151.f, y + 1.f });
        window.draw(accent);
        // Button number
        Text number(font, "0" + to_string(i + 1), 13);
        number.setFillColor(Color(130, 153, 182));
        centertext(number, 176.f, y + 30.f);
        window.draw(number);
        // Button label
        Text text(font, options[i], 23);
        text.setStyle(Text::Bold);
        text.setFillColor(Color::White);
        if (disabled)
        {
            text.setFillColor(Color(162, 173, 196));
            centertext(text, 300.f, y + 22.f);
        }
        else
        {
            centertext(text, 300.f, y + 30.f);
        }
        window.draw(text);
        // Right arrow
        Text arrow(font, ">", 20);
        arrow.setFillColor(Color(112, 219, 242));
        centertext(arrow, 425.f, y + 30.f);
        window.draw(arrow);
        // Continue status
        if (disabled)
        {
            Text status(font, "NO ACTIVE GAME", 10);
            status.setFillColor(Color(126, 141, 166));
            centertext(status, 300.f, y + 47.f);
            window.draw(status);
        }
    }
    // 12. Bottom divider
    line.setPosition({ 90.f, 547.f });
    window.draw(line);
    // Dotted ball trajectory
    CircleShape dot(2.f);
    dot.setFillColor(Color(80, 220, 255, 150));
    for (int i = 0; i < 9; i++)
    {
        dot.setPosition({
            270.f + i * 8.f,
            614.f - i * 6.f
            });
        window.draw(dot);
    }
    // 13. Glowing decorative ball
    CircleShape ballGlow(17.f);
    ballGlow.setPosition({ 320.f, 550.f });
    ballGlow.setFillColor(Color(85, 223, 255, 30));
    window.draw(ballGlow);
    CircleShape ball(6.f);
    ball.setPosition({ 331.f, 561.f });
    ball.setFillColor(Color::White);
    window.draw(ball);
    // 14. Decorative paddle
    RectangleShape paddle({ 160.f, 12.f });
    paddle.setPosition({ 220.f, 621.f });
    paddle.setFillColor(Color(60, 228, 250));
    paddle.setOutlineThickness(2.f);
    paddle.setOutlineColor(Color(30, 100, 150));
    window.draw(paddle);
    // 15. Footer
    Text footer(font, "CLASSIC ARCADE  |  V1.0", 13);
    footer.setFillColor(Color(130, 150, 187));
    centertext(footer, 300.f, 668.f);
    window.draw(footer);
}
void handleInput(RenderWindow& window,int& screen, int& gameStarted,int& score, int& level)
{
    while (const auto event = window.pollEvent())
    {
        if (event->is<Event::Closed>())
        {
            window.close();
            return;
        }
        // Escape key
        if (const auto* key =
            event->getIf<Event::KeyPressed>())
        {
            if (key->code == Keyboard::Key::Escape)
                screen = 0;
        }
        // Mouse click
        if (const auto* click =
            event->getIf<Event::MouseButtonPressed>())
        {
            if (click->button == Mouse::Button::Left
                && screen == 0)
            {
                Vector2f mouse =
                    window.mapPixelToCoords(click->position);
                float x = mouse.x;
                float y = mouse.y;
                // New Game
                if (x >= 150 && x <= 450 &&
                    y >= 280 && y <= 340)
                {
                    score = 0;
                    level = 1;
                    gameStarted = 1;
                    screen = 1;
                }
                // Continue Game
                else if (x >= 150 && x <= 450 &&
                    y >= 365 && y <= 425)
                {
                    if (gameStarted == 1)
                        screen = 1;
                }
                // Exit Game
                else if (x >= 150 && x <= 450 &&
                    y >= 450 && y <= 510)
                {
                    window.close();
                    return;
                }
            }
        }
    }
}
void updategame(int& paddleX,int& ballX,int& ballY,bool launched,int screen)
{
    
    /*------------------------------------
             TO DO FUNCTIONS 
    ------------------------------------*/
    if (screen == 1)
    {
    //TASK 1:-PADDLE MOVEMENT
        if (Keyboard::isKeyPressed(Keyboard::Key::Left) ||Keyboard::isKeyPressed(Keyboard::Key::A))
        {
            paddleX = paddleX - 8;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::D))
        {
            paddleX = paddleX + 8;
        }
        //to keep paddle within boundry of screen 
        if (paddleX < 0)
        {
            paddleX = 0;
        }
        if (paddleX > 500)
        {
            paddleX = 500;
        }
      //TASK 2:-BALL MOVEMENTS



      //TASK3:-BALL BOUNCING


      //TASK 4:-BRICK BREAKING



      //TASK 5:-SCORE AND LIVES
    
    }
}
   
void drawGame(RenderWindow& window,Font& font, int screen, int gameStarted,const int bricks[8][10],int paddleX,int ballX,int ballY)
{
    window.clear(Color(25, 25, 45));
    // Main menu screen
    if (screen == 0)
    {
        drawMenu(window, font, gameStarted);
    }
    // Gameplay screen
    else if (screen == 1)
    {
        drawBricks(window,bricks);
        drawPlayer(window,paddleX,ballX,ballY);
    }
    window.display();
}
bool loadlevel(int bricks[8][10]) {
    ifstream fin("level.txt");
    if (!fin) {
        cout << "file not found" << endl;
        return false;
    }
    int rows, cols;
    fin >> rows >> cols;
    if (!fin || rows != 8 || cols!=10) {   // to check number of rows and cols if they exceed display the message 
        cout << "level size is out of range" << endl;
        return false;
}
    for (int r = 0;r < 8;r++) {
        for (int c = 0;c < 10;c++) {
            fin >> bricks[r][c];
            if (bricks[r][c] > 3||bricks[r][c]<0||!fin)
            {
                cout << "error in brick number" << endl;
                return false;
            }
        }
    }
    fin.close();
    return true;   // successfull load bool function
}

int main()
{
    RenderWindow window(VideoMode({ 600, 700 }), "Block Buster");
    window.setFramerateLimit(60);
    Font font;
    if (!font.openFromFile("arial.ttf"))
    {
        cout << "Font loading failed!" << endl;
        return 1;
    }
    int screen = 0;
    int gameStarted = 0;
    int score = 0;
    int level = 1;
    int paddleX = 250;
    int ballX = 294;
    int ballY = 638;

    int dx = 0;
    int y = 0;
    bool launched = false;
    int bricks[8][10] = {};  //array is empty so we need to load the file 
    if (!loadlevel(bricks)) {
        return 1;               //if file is not found then program get close imediatly for this function type should be bool not void 
    }
    while (window.isOpen())
    {
        // Input
        handleInput(window, screen,
            gameStarted, score, level);
        if (!window.isOpen())
            break;
        // Update
        updategame(paddleX,ballX,ballY,launched,screen);
        // Draw
        drawGame(window, font, screen, gameStarted,bricks,paddleX,ballX,ballY);
    }

    return 0;
}