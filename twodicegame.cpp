#include "splashkit.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string> // Include string header for std::to_string

const int ROLLS = 36000;
const int DICE_SIDES = 6;
const int ARRAY_SIZE = DICE_SIDES + 1;

void simulateDiceRoll(int rolls, int freq[][ARRAY_SIZE]) {
    srand(time(NULL));

    for (int i = 0; i < rolls; ++i) {
        int roll1 = 1 + rand() % DICE_SIDES;
        int roll2 = 1 + rand() % DICE_SIDES;
        ++freq[roll1][roll2];
    }
}

void draw_button(color clr, float x, float y, int btn_width, int btn_height) {
    fill_rectangle(clr, x, y, btn_width, btn_height);
}

bool button_clicked(float x_value, float y_value, int btn_width, int btn_height) {
    float right_value = x_value + btn_width;
    float bottom_value = y_value + btn_height;
    return mouse_clicked(LEFT_BUTTON) &&
           (mouse_x() >= x_value) && (mouse_x() <= right_value) &&
           (mouse_y() >= y_value) && (mouse_y() <= bottom_value);
}

void play() {
    float x = 45, y = 70;
    int btn_width = 50, btn_height = 30;
    int freq[ARRAY_SIZE][ARRAY_SIZE] = {0};

    srand(time(NULL));

    for (int i = 0; i < ROLLS; ++i) {
        int roll1 = 1 + rand() % DICE_SIDES;
        int roll2 = 1 + rand() % DICE_SIDES;
        ++freq[roll1][roll2];
    }

    for (int i = 1; i <= DICE_SIDES; ++i) {
        x += 55;
        draw_button(COLOR_GRAY, x, y, btn_width, btn_height);
        draw_text(std::to_string(i), COLOR_WHITE, "arial.ttf", 15, x, y);

        y += 35;
        draw_button(COLOR_GRAY, 45, y, btn_width, btn_height);
        draw_text(std::to_string(i), COLOR_WHITE, "arial.ttf", 15, 45, y);

        y -= 35;
        for (int j = 1; j <= DICE_SIDES; ++j) {
            x += 55;
            draw_button(COLOR_YELLOW, x, y, btn_width, btn_height);
            draw_text(std::to_string(freq[i][j]), COLOR_RED, "arial.ttf", 15, x, y);
        }
        x = 45;
        y += 35;
    }

    int sum = 0;
    for (int i = 1; i <= DICE_SIDES; ++i) {
        sum += freq[i][i];
    }

    if (sum > 6000) {
        draw_button(COLOR_DARK_GREEN, 200, 320, 100, 30);
        draw_text("Player Wins", COLOR_YELLOW, "arial.ttf", 15, 205, 320);

        draw_text("Sum of Diagonal: " + std::to_string(sum), COLOR_BLACK, "arial.ttf", 15, 150, 350);
    } else {
        draw_button(COLOR_DARK_GREEN, 200, 320, 100, 30);
        draw_text("Player Loses", COLOR_YELLOW, "arial.ttf", 15, 205, 320);

        draw_text("Sum of Diagonal: " + std::to_string(sum), COLOR_BLACK, "arial.ttf", 15, 150, 350);
    }
}

int main() {
    open_window("Die Rolling", 600, 600);
    clear_screen(COLOR_LIGHT_GREEN);

    float x = 200, y = 25;
    while (!quit_requested()) {
        process_events();

        draw_button(COLOR_DARK_GREEN, x, y, 100, 30);
        draw_text("Play Game", COLOR_YELLOW, "arial.ttf", 15, x + 5, y + 5);

        if (button_clicked(x, y, 100, 30)) {
            play();
        }

        refresh_screen();
    }

    return 0;
}


