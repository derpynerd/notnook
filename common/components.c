/* This file contains the implementations of reusable Components */ 

#pragma once

#include "../includes/clay.h"

#include "constants.h"

void COMPONENT_SIDEBAR_ITEM(char* noteId, char* noteTitle) {
    CLAY(
        CLAY_ID(noteId),
        CLAY_LAYOUT({ 
            .sizing = { .width = CLAY_SIZING_FIXED(sidebarItemWidth), .height = CLAY_SIZING_FIXED(sidebarItemHeight) },
            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER }
        }), 
        CLAY_RECTANGLE({ .color = Clay_Hovered() ? COLOR_SIDEBAR_ITEM_HOVER : COLOR_SIDEBAR_ITEM, .cornerRadius = { 5.0f, 5.0f, 5.0f, 5.0f } })
    ) {
        CLAY_TEXT(
            CLAY_STRING(noteTitle),
            CLAY_TEXT_CONFIG({ .fontSize = 16, .textColor = Clay_Hovered() ? COLOR_HIGHLIGHTED_TEXT : COLOR_TEXT, .wrapMode = CLAY_TEXT_WRAP_NONE })
        );

        // if (Clay_Hovered()) {
        //     SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        // } else {
        //     SetMouseCursor(MOUSE_CURSOR_ARROW);
        // }
    }
}

void COMPONENT_SCROLLBAR() {
    Clay_ScrollContainerData scrollData = Clay_GetScrollContainerData(Clay_GetElementId(CLAY_STRING("SideBar")));

    if (scrollData.found) {

        CLAY(
            CLAY_ID("ScrollBar"),
            CLAY_FLOATING({
                .offset = { .y = -(scrollData.scrollPosition->y / scrollData.contentDimensions.height) * scrollData.scrollContainerDimensions.height },
                .zIndex = 1,
                .parentId = Clay_GetElementId(CLAY_STRING("SideBar")).id,
                .attachment = {.element = CLAY_ATTACH_POINT_RIGHT_TOP, .parent = CLAY_ATTACH_POINT_RIGHT_TOP}
            })
        ) {
            CLAY(CLAY_ID("ScrollBarButton"),
                CLAY_LAYOUT({ .sizing = {CLAY_SIZING_FIXED(5), CLAY_SIZING_FIXED((scrollData.scrollContainerDimensions.height / scrollData.contentDimensions.height) * scrollData.scrollContainerDimensions.height) }}),
                CLAY_RECTANGLE({ .cornerRadius = {6}, .color = Clay_PointerOver(Clay__HashString(CLAY_STRING("ScrollBar"), 0, 0)) ? (Clay_Color){100, 100, 140, 150} : (Clay_Color){120, 120, 160, 150} })
            ) {}
        
        }
    }

}

void COMPONENT_CREATION_DATE(char* createdString) {
    CLAY(
        CLAY_ID("CreatedDateString"),
        CLAY_LAYOUT({
            .sizing = { .width = CLAY_SIZING_FIXED(createdDateWidth), .height = CLAY_SIZING_FIXED(createdDateHeight) },
            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
        })
    ) {
        CLAY_TEXT(
            CLAY_STRING(createdString),
            CLAY_TEXT_CONFIG({ .fontSize = 14, .textColor = COLOR_TEXT, .wrapMode = CLAY_TEXT_WRAP_NEWLINES })
        );
    }
}

void COMPONENT_SAVE_BUTTON() {
    CLAY(
        CLAY_ID("SaveButton"),
        CLAY_LAYOUT({
            .sizing = { .width = CLAY_SIZING_FIXED(saveButtonWidth), .height = CLAY_SIZING_FIXED(saveButtonHeight) },
            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
        }),
        CLAY_RECTANGLE({ .color = Clay_Hovered() ? COLOR_SIDEBAR_ITEM_HOVER : COLOR_SIDEBAR_ITEM, .cornerRadius = { 5.0f, 5.0f, 5.0f, 5.0f } })
    ) {
        CLAY_TEXT(
            CLAY_STRING(STRING_SAVE),
            CLAY_TEXT_CONFIG({ .fontSize = 18, .textColor = COLOR_TEXT, .wrapMode = CLAY_TEXT_WRAP_NONE })
        );
    }
}
