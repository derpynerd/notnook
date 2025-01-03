#pragma once

#include "../includes/clay.h"

#include "constants.h"

void COMPONENT_SIDEBAR_ITEM() {
    CLAY(
        CLAY_LAYOUT({ .sizing = { .width = CLAY_SIZING_FIXED(40), .height = CLAY_SIZING_FIXED(40) }, }), 
        CLAY_RECTANGLE({ .color = COLOR_ORANGE, .cornerRadius = { 5.0f, 5.0f, 5.0f, 5.0f } })
    ) {}
}

void COMPONENT_TITLEBAR_ITEM(char* titleBoxText) {
    CLAY(
        CLAY_LAYOUT({ 
            .sizing = { .width = CLAY_SIZING_FIXED(80), .height = CLAY_SIZING_FIXED(40) },
            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER }
        }), 
        CLAY_RECTANGLE({ .color = COLOR_YELLOW, .cornerRadius = { 5.0f, 5.0f, 5.0f, 5.0f } })
    ) {
        CLAY_TEXT(
            CLAY_STRING(titleBoxText),
            CLAY_TEXT_CONFIG({ .fontSize = 20, .textColor = COLOR_BLACK, .wrapMode = CLAY_TEXT_WRAP_WORDS })
        );
    }
}