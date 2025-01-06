#pragma once 

#include "common/constants.h"
#include "includes/clay.h"

static bool updateNotes = true;
static NoteTitles* notes;

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
            CLAY_SCROLL({ .vertical = true }),
            CLAY_LAYOUT({
                .layoutDirection = { CLAY_TOP_TO_BOTTOM },
                .sizing = { .width = CLAY_SIZING_FIXED(sidebarWidth), .height = CLAY_SIZING_FIXED(sidebarHeight) },
                .padding = { .y = 20 },
                .childAlignment = { .x = CLAY_ALIGN_X_CENTER },
                .childGap = 10
            }),
            CLAY_RECTANGLE({ .color = COLOR_SIDEBAR_BACKGROUND })
        ) {

            if (updateNotes) {
                notes = Database_GetAllNotes();
                updateNotes = false;
            }

            notes->count = notes->count % NOTE_MAX_COUNT;
            for (int i = 0; i < notes->count; ++i) {
                COMPONENT_SIDEBAR_ITEM(noteIds[i], notes->titles[i]);
            }

            COMPONENT_SCROLLBAR();
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