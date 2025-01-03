#pragma once 

#include "common/constants.h"

#include "includes/clay.h"

Clay_RenderCommandArray CreateLayout() {

    Clay_BeginLayout();
    
    CLAY(
        CLAY_ID("MainWindow"),
        CLAY_LAYOUT({
            .sizing = { .width = GetScreenWidth(), .height = GetScreenHeight() }
        }),
        CLAY_RECTANGLE({ .color = COLOR_BLUE })
    ) {

        CLAY(
            CLAY_ID("SideBar"),
            CLAY_LAYOUT({
                .layoutDirection = { CLAY_TOP_TO_BOTTOM },
                .sizing = { .width = CLAY_SIZING_FIXED(50), .height = GetScreenHeight() },
                .padding = { .y = 20 },
                .childAlignment = { .x = CLAY_ALIGN_X_CENTER },
                .childGap = 20
            }),
            CLAY_RECTANGLE({ .color = COLOR_LIGHT })
        ) {

            for (int i = 0; i < 5; ++i) {
                COMPONENT_SIDEBAR_ITEM();
            }

        }

        CLAY(
            CLAY_ID("TitleBar"),
            CLAY_LAYOUT({
                .layoutDirection = { CLAY_LEFT_TO_RIGHT },
                .sizing = { .width = GetScreenWidth(), .height = CLAY_SIZING_FIXED(80) },
                .childAlignment = { .y = CLAY_ALIGN_Y_CENTER },
                .padding = { .x = 40 },
                .childGap = 30
            }),
            CLAY_RECTANGLE({ .color = COLOR_RED })
        ) {

            char* titleBoxTexts[4] = {"File", "Edit", "View", "Help"};

            for (int i = 0; i < 4; ++i) {
                COMPONENT_TITLEBAR_ITEM(titleBoxTexts[i]);
            }

        }

    }

    return Clay_EndLayout();
}