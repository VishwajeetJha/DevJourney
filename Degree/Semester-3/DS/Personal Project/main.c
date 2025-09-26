#include "raylib.h"
#include <stdint.h>
#include <stdio.h>

//gcc main.c -lraylib -lm -ldl -lpthread -o hanoi

#define NUM_PEGS 3
#define NUM_DISCS 5

typedef struct {
    int disc;
    float x, y;       // current position
    float startX, startY;
    float targetX, targetY;
    int active;        // 0 = no move, 1 = moving
    int from, to;
    int stepNum;
} AnimDisc;

AnimDisc anim = {0};
float moveDuration = 1.5f; // 2 seconds per move
float moveTimer = 0.0f;

typedef struct {
    int discs[NUM_DISCS];
    int top; // index of top disc (-1 if empty)
} Peg;

typedef struct {
    int from, to;
} Move;

Peg pegs[NUM_PEGS];

Move moves[1024];
int moveCount = 0;
int currentMove = 0;
char lastMove[64] = "";
int step = 1;

// precompute moves
void SolveHanoi(int n, int from, int to, int aux) {
    if (n == 0) return;
    SolveHanoi(n-1, from, aux, to);
    moves[moveCount++] = (Move){from, to};
    SolveHanoi(n-1, aux, to, from);
}

void StartMove(Move m) {
    int disc = pegs[m.from].discs[pegs[m.from].top];
    pegs[m.from].top--;  // remove from source peg for rendering

    // setup the animation
    anim.disc = disc;
    anim.from = m.from;
    anim.to = m.to;
    anim.active = 1;
    anim.stepNum = step;

    anim.startX = 150 + m.from * 250 - disc * 40 / 2;
    anim.startY = 500 - (pegs[m.from].top + 1) * 30;
    anim.targetX = 150 + m.to * 250 - disc * 40 / 2;
    anim.targetY = 500 - (pegs[m.to].top + 1 + 1) * 30;

    anim.x = anim.startX;
    anim.y = anim.startY;

    moveTimer = 0.0f;
}

void UpdateAnim(float dt) {
    if (!anim.active) return;

    moveTimer += dt;
    float t = moveTimer / moveDuration;
    if (t > 1.0f) t = 1.0f;

    // linear interpolation
    anim.x = anim.startX + (anim.targetX - anim.startX) * t;
    anim.y = anim.startY + (anim.targetY - anim.startY) * t;

    if (t >= 1.0f) {
        // finish move
        pegs[anim.to].top++;
        pegs[anim.to].discs[pegs[anim.to].top] = anim.disc;

        //printing the step in the box up top
        snprintf(lastMove, sizeof(lastMove),
                 "Step %d: Move disc %d from Peg %d to Peg %d",
                 anim.stepNum, anim.disc, anim.from+1, anim.to+1);
        step++;
        anim.active = 0;
        currentMove++;
    }
}

void DrawPegsWithAnim() {
    for (int p = 0; p < NUM_PEGS; p++) {
        for (int d = 0; d <= pegs[p].top; d++) {
            int disc = pegs[p].discs[d];
            int x = 150 + p * 250 - disc * 40 / 2;
            int y = 500 - d * 30;
            DrawRectangle(x, y, disc * 40, 20, (Color){50 + 50*d, 75, 180 - 50*d, 255});
        }
    }

    // draw animated disc on top
    if (anim.active) {
        DrawRectangle(anim.x, anim.y, anim.disc * 40, 20,
                      (Color){50 + 50*(anim.disc-1), 75, 180 - 50*(anim.disc-1), 255});
    }
}


int main() {
    InitWindow(800, 600, "Hanoi na Minar");
    SetTargetFPS(60);

    // initialize pegs -- or in simpler terms put the fuckers in their place
    for (int i = 0; i < NUM_PEGS; i++) pegs[i].top = -1;
    for (int i = 0; i < NUM_DISCS; i++) {
        pegs[0].top++;
        pegs[0].discs[pegs[0].top] = NUM_DISCS - i;
    }

    // precompute all moves -- solve karne ki prakriya
    SolveHanoi(NUM_DISCS, 0, 2, 1);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime(); // seconds since last frame -- istg please don't mess with this, spent an hour trying to figure out
                                                                    //how to sync between the pegs' movement
        if (!anim.active && currentMove < moveCount) {
            StartMove(moves[currentMove]);
        }

        UpdateAnim(dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangle(50, 20, 700, 40, LIGHTGRAY);
        DrawText(lastMove, 60, 30, 20, BLACK);

        DrawPegsWithAnim();

        EndDrawing();
    }


    CloseWindow();
    return 0;
}
