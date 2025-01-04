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
        CLAY_RECTANGLE({ .color = COLOR_BACKGROUND })
    ) {

        CLAY(
            CLAY_ID("SideBar"),
            CLAY_LAYOUT({
                .layoutDirection = { CLAY_TOP_TO_BOTTOM },
                .sizing = { .width = CLAY_SIZING_FIXED(sidebarWidth), .height = CLAY_SIZING_FIXED(sidebarHeight) },
                .padding = { .y = 20 },
                .childAlignment = { .x = CLAY_ALIGN_X_CENTER },
                .childGap = 10
            }),
            CLAY_RECTANGLE({ .color = COLOR_SIDEBAR_BACKGROUND }),
            CLAY_BORDER({ .right = { 4, COLOR_SIDEBAR_BORDER } })
        ) {

            char* noteIds[5] = {"Note1", "Note2", "Note3", "Note4", "Note5"};

            for (int i = 0; i < 5; ++i) {
                COMPONENT_SIDEBAR_ITEM(noteIds[i], COLOR_TEXT, COLOR_HIGHLIGHTED_TEXT, COLOR_SIDEBAR_ITEM, COLOR_SIDEBAR_ITEM_HOVER);
            }

        }

        CLAY(
            CLAY_ID("MainContent"),
            CLAY_LAYOUT({
                .layoutDirection = { CLAY_TOP_TO_BOTTOM },
                .sizing = { .width = CLAY_SIZING_FIXED(mainContentWidth), .height = CLAY_SIZING_FIXED(mainContentHeight) }
            }),
            CLAY_RECTANGLE({ .color = COLOR_BACKGROUND })
        ) {

            CLAY(
                CLAY_ID("TextArea"),
                CLAY_LAYOUT({
                    .layoutDirection = { CLAY_TOP_TO_BOTTOM },
                    .sizing = { .width = CLAY_SIZING_FIXED(textAreaWidth), .height = CLAY_SIZING_FIXED(textAreaHeight) }
                }),
                CLAY_RECTANGLE({ .color = COLOR_TEXTAREA_BACKGROUND })
            ) {}
            
            CLAY(
                CLAY_ID("Footer"),
                CLAY_LAYOUT({
                    .layoutDirection = { CLAY_LEFT_TO_RIGHT },
                    .sizing = { .width = CLAY_SIZING_FIXED(footerWidth), .height = CLAY_SIZING_FIXED(footerHeight) },
                    .childAlignment = { .y = CLAY_ALIGN_Y_CENTER },
                    .padding = { .x = 40 },
                    .childGap = 30
                }),
                CLAY_RECTANGLE({ .color = COLOR_FOOTER_BACKGROUND })
            ) {

                // TODO : Text field displaying creation date

                // TODO : Button to save note

            }


        }



    }

    return Clay_EndLayout();
}