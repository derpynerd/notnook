#pragma once 

#include <string.h>

#include "common/constants.h"
#include "includes/clay-1.h"

static bool updateNotes = true;
static bool updateCurrentNote = true;
static Documents* titles;
static Documents* contents;
static Documents* created_dates;
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
                .sizing = { .width = CLAY_SIZING_FIXED(sidebarWidth), .height = GetScreenHeight() },
                .padding = { .y = 20 },
                .childAlignment = { .x = CLAY_ALIGN_X_CENTER },
                .childGap = 10
            }),
            CLAY_RECTANGLE({ .color = COLOR_SIDEBAR_BACKGROUND })
        ) {

            if (updateNotes) {
                titles = Database_GetTitles();
                updateNotes = false;
            }

            titles->count = titles->count % NOTE_MAX_COUNT;
            for (int i = 0; i < titles->count; ++i) {
                COMPONENT_SIDEBAR_ITEM(
                (Clay_String) { .length = strlen(noteIds[i]), .chars = noteIds[i] },
                (Clay_String) { .length = strlen(titles->data[i]), .chars = titles->data[i] });
            }

            COMPONENT_SCROLLBAR();
        }

        CLAY(
            CLAY_ID("MainContent"),
            CLAY_LAYOUT({
                .layoutDirection = { CLAY_TOP_TO_BOTTOM },
                .sizing = { .width = CLAY_SIZING_FIXED(mainContentWidth), .height = GetScreenHeight() }
            }),
            CLAY_RECTANGLE({ .color = COLOR_BACKGROUND })
        ) {

            CLAY(
                CLAY_ID("TextArea"),
                CLAY_LAYOUT({
                    .layoutDirection = { CLAY_TOP_TO_BOTTOM },
                    .sizing = { .width = CLAY_SIZING_PERCENT(100), .height = GetScreenHeight() * 0.6 }
                }),
                CLAY_RECTANGLE({ .color = COLOR_TEXTAREA_BACKGROUND })
            ) {

                CLAY(
                    CLAY_ID("TitleTextEditor"),
                    CLAY_LAYOUT({
                        .sizing = { .width = CLAY_SIZING_PERCENT(100), .height = CLAY_SIZING_GROW() }
                    })
                ) {}

                CLAY(
                    CLAY_ID("ContentTextEditor")
                ) {}

            }
            
            CLAY(
                CLAY_ID("Footer"),
                CLAY_LAYOUT({
                    .layoutDirection = { CLAY_LEFT_TO_RIGHT },
                    .sizing = { .width = GetScreenWidth(), .height = GetScreenHeight() * 0.15 },
                    .childAlignment = { .y = CLAY_ALIGN_Y_CENTER },
                    .childGap = mainContentWidth - createdDateWidth - saveButtonWidth - 20
                }),
                CLAY_RECTANGLE({ .color = COLOR_FOOTER_BACKGROUND })
            ) {

                if (updateCurrentNote) {
                    created_dates = Database_GetCreatedDates();
                    char* datetime = created_dates->data[0];
                    const size_t created_len = strlen(STRING_CREATED);
                    const size_t datetime_len = strlen(datetime);

                    // Concat Created + datetime
                    createdString = malloc(created_len + datetime_len + 1000); // +1 for null-terminator
                    memcpy(createdString, STRING_CREATED, created_len);
                    memcpy(createdString + created_len, datetime, datetime_len + 1); // +1 to copy null-terminator

                    updateCurrentNote = false;
                }

                // Text field displaying creation date
                COMPONENT_CREATION_DATE((Clay_String) { .length = strlen(createdString), .chars = createdString});                

                // Button to save note
                COMPONENT_SAVE_BUTTON();

            }

        }


    }

    return Clay_EndLayout();
}