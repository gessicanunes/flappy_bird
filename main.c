#include "raylib.h"
#include <stdlib.h>


int main(){


// Defini��o da estrutura "ElementoGrafico"
typedef struct {
    Texture2D texture;
    Vector2 position;
} ElementoGrafico;

// Defini��o da estrutura "Cenario" com seus elementos
typedef struct {
    ElementoGrafico flappy[3];
    ElementoGrafico cano;
    ElementoGrafico fundo;
    ElementoGrafico gameover;
} Cenario;

// Fun��o para carregar textura a partir de um arquivo
Texture2D LoadTextureFromFile(const char *filename) {
    Image image = LoadImage(filename);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);
    return texture;
}

// Fun��o para inicializar o cen�rio
Cenario InicializarCenario() {
    Cenario cenario;

    // Carrega as texturas dos elementos
    cenario.fundo.texture = LoadTextureFromFile("./images/fundo.png");
    cenario.cano.texture = LoadTextureFromFile("./images/cano.png");
    cenario.gameover.texture = LoadTextureFromFile("./images/gameover.png");
    cenario.flappy[0].texture = LoadTextureFromFile("./images/flappy1.png");
    cenario.flappy[1].texture = LoadTextureFromFile("./images/flappy2.png");
    cenario.flappy[2].texture = LoadTextureFromFile("./images/flappy3.png");

    // Posiciona os elementos inicialmente
    for (int i = 0; i < 3; i++) {
        cenario.flappy[i].position = (Vector2){100.0f, 200.0f};  // Ajuste conforme necess�rio
    }

    cenario.cano.position = (Vector2){400.0f, 150.0f};  // Ajuste conforme necess�rio
    cenario.fundo.position = (Vector2){0.0f, 0.0f};
    cenario.gameover.position = (Vector2){200.0f, 200.0f};  // Ajuste conforme necess�rio

    return cenario;
}

// Fun��o para descarregar as texturas do cen�rio
void DescarregarCenario(Cenario *cenario) {
    for (int i = 0; i < 3; i++) {
        UnloadTexture(cenario->flappy[i].texture);
    }

    UnloadTexture(cenario->cano.texture);
    UnloadTexture(cenario->fundo.texture);
    UnloadTexture(cenario->gameover.texture);
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Cenario Example");

    // Inicializa o cen�rio
    Cenario cenario = InicializarCenario();

    SetTargetFPS(60);

    // Loop principal
    while (!WindowShouldClose()) {
        // Atualiza o jogo

        // Desenha o jogo
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Desenha os elementos do cen�rio
        for (int i = 0; i < 3; i++) {
            DrawTexture(cenario.flappy[i].texture, cenario.flappy[i].position.x, cenario.flappy[i].position.y, WHITE);
        }

        DrawTexture(cenario.cano.texture, cenario.cano.position.x, cenario.cano.position.y, WHITE);
        DrawTexture(cenario.fundo.texture, cenario.fundo.position.x, cenario.fundo.position.y, WHITE);
        DrawTexture(cenario.gameover.texture, cenario.gameover.position.x, cenario.gameover.position.y, WHITE);

        EndDrawing();
    }

    // Descarrega as texturas do cen�rio antes de fechar
    DescarregarCenario(&cenario);


    return 0;
}
