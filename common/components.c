/* This file contains the implementations of reusable Components */ 

#pragma once

#include "../includes/clay.h"

#include "constants.h"

void COMPONENT_SIDEBAR_ITEM(Clay_Color itemColor, Clay_Color itemHoverColor) {
    CLAY(
        CLAY_LAYOUT({ .sizing = { .width = CLAY_SIZING_FIXED(40), .height = CLAY_SIZING_FIXED(40) }, }), 
        CLAY_RECTANGLE({ .color = Clay_Hovered() ? itemColor : itemHoverColor, .cornerRadius = { 5.0f, 5.0f, 5.0f, 5.0f } })
    ) {}
}

void COMPONENT_TITLEBAR_ITEM(Clay_Color itemColor, Clay_Color itemTextColor, char* titleBoxText) {
    CLAY(
        CLAY_LAYOUT({ 
            .sizing = { .width = CLAY_SIZING_FIXED(80), .height = CLAY_SIZING_FIXED(40) },
            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER }
        }), 
        CLAY_RECTANGLE({ .color = itemColor, .cornerRadius = { 5.0f, 5.0f, 5.0f, 5.0f } })
    ) {
        CLAY_TEXT(
            CLAY_STRING(titleBoxText),
            CLAY_TEXT_CONFIG({ .fontSize = 20, .textColor = itemTextColor, .wrapMode = CLAY_TEXT_WRAP_WORDS })
        );
    }
}