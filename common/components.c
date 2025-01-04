/* This file contains the implementations of reusable Components */ 

#pragma once

#include "../includes/clay.h"

#include "constants.h"

void COMPONENT_SIDEBAR_ITEM(char* itemId, Clay_Color itemTextColor, Clay_Color itemHighlightedTextColor, Clay_Color itemColor, Clay_Color itemHoverColor) {
    CLAY(
        CLAY_ID(itemId),
        CLAY_LAYOUT({ 
            .sizing = { .width = CLAY_SIZING_FIXED(sidebarItemWidth), .height = CLAY_SIZING_FIXED(sidebarItemHeight) },
            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
        }), 
        CLAY_RECTANGLE({ .color = Clay_Hovered() ? itemHoverColor : itemColor, .cornerRadius = { 5.0f, 5.0f, 5.0f, 5.0f } })
    ) {
        CLAY_TEXT(
            CLAY_STRING("dddddddddddddddd"), // TODO : Populate text from database here
            CLAY_TEXT_CONFIG({ .fontSize = 16, .textColor = Clay_Hovered() ? itemHighlightedTextColor : itemTextColor, .wrapMode = CLAY_TEXT_WRAP_NONE })
        );
    }
}

void COMPONENT_TITLEBAR_ITEM(char* itemId, Clay_Color itemColor, Clay_Color itemTextColor, char* titleBoxText) {
    CLAY(
        CLAY_ID(itemId),
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