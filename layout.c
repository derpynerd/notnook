#pragma once 

#include <string.h>

#include "common/constants.h"
#include "includes/clay.h"

static bool updateNotes = true;
static bool updateCurrentNote = true;
static NoteTitles* notes;
char* createdString;

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
                COMPONENT_SIDEBAR_ITEM(noteIds[i], (Clay_String) { .length = strlen(notes->titles[i]), .chars = (notes->titles[i]) });
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
                    .childGap = textAreaWidth - createdDateWidth - saveButtonWidth - 20
                }),
                CLAY_RECTANGLE({ .color = COLOR_FOOTER_BACKGROUND })
            ) {

                if (updateCurrentNote) {
                    char* datetime = "2025-01-05 20:52:28"; // TODO : get date via query
                    const size_t created_len = strlen(STRING_CREATED);
                    const size_t datetime_len = strlen(datetime);

                    // Concat Created + datetime
                    createdString = malloc(created_len + datetime_len + 1000); // +1 for null-terminator
                    memcpy(createdString, STRING_CREATED, created_len);
                    memcpy(createdString + created_len, datetime, datetime_len + 1); // +1 to copy null-terminator

                    updateCurrentNote = false;
                }

                // TODO : Text field displaying creation date
                COMPONENT_CREATION_DATE((Clay_String) { .length = strlen(createdString), .chars = createdString});                

                // TODO : Button to save note
                COMPONENT_SAVE_BUTTON();

            }

        }


    }

    return Clay_EndLayout();
}