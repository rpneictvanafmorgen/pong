#include "raylib.h"

#include <cmath>
#include <string>

struct Paddle {
    Rectangle bounds{};
    float speed = 420.0f;
};

struct Ball {
    Vector2 position{};
    Vector2 velocity{};
    float radius = 10.0f;
};

static void KeepPaddleOnScreen(Paddle& paddle, int screenHeight)
{
    if (paddle.bounds.y < 0.0f) {
        paddle.bounds.y = 0.0f;
    }

    if (paddle.bounds.y + paddle.bounds.height > screenHeight) {
        paddle.bounds.y = screenHeight - paddle.bounds.height;
    }
}

static void ResetBall(Ball& ball, int screenWidth, int screenHeight, int direction)
{
    ball.position = {
        static_cast<float>(screenWidth) / 2.0f,
        static_cast<float>(screenHeight) / 2.0f,
    };

    ball.velocity = {
        330.0f * static_cast<float>(direction),
        190.0f,
    };
}

static void MovePlayerPaddle(Paddle& paddle, float deltaTime, int screenHeight)
{
    if (IsKeyDown(KEY_W)) {
        paddle.bounds.y -= paddle.speed * deltaTime;
    }

    if (IsKeyDown(KEY_S)) {
        paddle.bounds.y += paddle.speed * deltaTime;
    }

    KeepPaddleOnScreen(paddle, screenHeight);
}

static void MoveComputerPaddle(Paddle& paddle, const Ball& ball, float deltaTime, int screenHeight)
{
    const float paddleCenter = paddle.bounds.y + paddle.bounds.height / 2.0f;

    if (ball.position.y < paddleCenter - 8.0f) {
        paddle.bounds.y -= paddle.speed * deltaTime;
    }

    if (ball.position.y > paddleCenter + 8.0f) {
        paddle.bounds.y += paddle.speed * deltaTime;
    }

    KeepPaddleOnScreen(paddle, screenHeight);
}

static void BounceBallOffPaddle(Ball& ball, const Paddle& paddle)
{
    if (!CheckCollisionCircleRec(ball.position, ball.radius, paddle.bounds)) {
        return;
    }

    const float paddleCenter = paddle.bounds.y + paddle.bounds.height / 2.0f;
    const float hitPosition = (ball.position.y - paddleCenter) / (paddle.bounds.height / 2.0f);

    ball.velocity.x *= -1.05f;
    ball.velocity.y = hitPosition * 330.0f;

    if (std::abs(ball.velocity.x) < 250.0f) {
        ball.velocity.x = ball.velocity.x < 0.0f ? -250.0f : 250.0f;
    }
}

int main()
{
    constexpr int screenWidth = 900;
    constexpr int screenHeight = 520;

    InitWindow(screenWidth, screenHeight, "Pong - C++ Example");
    SetTargetFPS(60);

    Paddle player{
        Rectangle{40.0f, screenHeight / 2.0f - 55.0f, 18.0f, 110.0f},
        440.0f,
    };

    Paddle computer{
        Rectangle{screenWidth - 58.0f, screenHeight / 2.0f - 55.0f, 18.0f, 110.0f},
        345.0f,
    };

    Ball ball{};
    ResetBall(ball, screenWidth, screenHeight, 1);

    int playerScore = 0;
    int computerScore = 0;

    while (!WindowShouldClose()) {
        const float deltaTime = GetFrameTime();

        MovePlayerPaddle(player, deltaTime, screenHeight);
        MoveComputerPaddle(computer, ball, deltaTime, screenHeight);

        ball.position.x += ball.velocity.x * deltaTime;
        ball.position.y += ball.velocity.y * deltaTime;

        if (ball.position.y - ball.radius <= 0.0f || ball.position.y + ball.radius >= screenHeight) {
            ball.velocity.y *= -1.0f;
        }

        BounceBallOffPaddle(ball, player);
        BounceBallOffPaddle(ball, computer);

        if (ball.position.x < -ball.radius) {
            computerScore++;
            ResetBall(ball, screenWidth, screenHeight, 1);
        }

        if (ball.position.x > screenWidth + ball.radius) {
            playerScore++;
            ResetBall(ball, screenWidth, screenHeight, -1);
        }

        BeginDrawing();
        ClearBackground(Color{18, 20, 24, 255});

        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, Color{70, 76, 86, 255});
        DrawText("W/S", 42, 22, 24, Color{210, 215, 224, 255});
        DrawText("CPU", screenWidth - 98, 22, 24, Color{210, 215, 224, 255});

        const std::string scoreText = std::to_string(playerScore) + " : " + std::to_string(computerScore);
        const int scoreWidth = MeasureText(scoreText.c_str(), 48);
        DrawText(scoreText.c_str(), screenWidth / 2 - scoreWidth / 2, 24, 48, RAYWHITE);

        DrawRectangleRec(player.bounds, Color{80, 185, 140, 255});
        DrawRectangleRec(computer.bounds, Color{230, 120, 90, 255});
        DrawCircleV(ball.position, ball.radius, Color{245, 222, 115, 255});

        DrawText("Move with W and S. First player to keep the rally going wins bragging rights.",
            34, screenHeight - 34, 18, Color{170, 177, 188, 255});

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
