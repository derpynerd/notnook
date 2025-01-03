#include <stdlib.h>

#define CLAY_IMPLEMENTATION
#include "includes/clay.h"

#include "includes/renderer/clay_renderer_raylib.c"

#include "common/constants.h"
#include "common/components.c"

Clay_RenderCommandArray CreateLayout(void);

int main() {
    
    Clay_Raylib_Initialize(screenWidth, screenHeight, "notnook", 
    FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

    uint64_t clayRequiredMemory = Clay_MinMemorySize();
    Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(clayRequiredMemory, malloc(clayRequiredMemory));

    Clay_Initialize(clayMemory, (Clay_Dimensions) {
       .width = GetScreenWidth(),
       .height = GetScreenHeight()
    });

    Clay_SetMeasureTextFunction(Raylib_MeasureText);

    Raylib_fonts[FONT_ID_BODY_16] = (Raylib_Font) {
        .font = LoadFontEx("resources/Roboto-Regular.ttf", 48, 0, 400),
        .fontId = FONT_ID_BODY_16
    };
    SetTextureFilter(Raylib_fonts[FONT_ID_BODY_16].font.texture, TEXTURE_FILTER_BILINEAR);

    while (!WindowShouldClose()) {
        
        /* Pre render logic */
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        } else {
            SetMouseCursor(MOUSE_CURSOR_ARROW);
        }

        /* UI Layout */ 
        Clay_RenderCommandArray renderCommands = CreateLayout();

        /* Rendering logic */
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Clay_Raylib_Render(renderCommands);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}

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