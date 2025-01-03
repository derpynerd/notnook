#include <stdlib.h>

#define CLAY_IMPLEMENTATION
#include "includes/clay.h"

#include "includes/renderer/clay_renderer_raylib.c"

#include "common/constants.h"
#include "common/components.c"

#include "layout.c"

int main() {
    
    /* Setup */
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

    // Game loop
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

    /* Cleanup */
    CloseWindow();

    return 0;
}
