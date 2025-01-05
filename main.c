#include <stdlib.h>

#define CLAY_IMPLEMENTATION
#include "includes/clay.h"
#include "includes/renderer/clay_renderer_raylib.c"

#include "common/constants.h"
#include "common/components.c"
#include "common/database.c"

#include "layout.c"

int main() {

    /* Setup */
    Clay_Raylib_Initialize(screenWidth, screenHeight, APP_NAME, 
    FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

    uint64_t clayRequiredMemory = Clay_MinMemorySize();
    Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(clayRequiredMemory, malloc(clayRequiredMemory));

    Clay_Initialize(clayMemory, (Clay_Dimensions) {
       .width = GetScreenWidth(),
       .height = GetScreenHeight()
    });

    Clay_SetMeasureTextFunction(Raylib_MeasureText);
    Clay_SetDebugModeEnabled(true); // Debugging mode enabled

    Raylib_fonts[APP_FONT_ID_BODY_16] = (Raylib_Font) {
        .font = LoadFontEx(APP_FONT_PATH, 48, 0, 400),
        .fontId = APP_FONT_ID_BODY_16
    };
    SetTextureFilter(Raylib_fonts[APP_FONT_ID_BODY_16].font.texture, TEXTURE_FILTER_BILINEAR);

    Image logo = LoadImage(APP_LOGO_PATH);
    ImageFormat(&logo, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    SetWindowIcon(logo);

    char* errorMessage = NotNook_SetupDatabase();
    if (errorMessage != NULL) {
        printf(errorMessage);
        // TODO : display error popup on screen - errorPopup(errorMessage);
    } else {
        printf("Database setup successful\n");
    }

    // Game loop
    while (!WindowShouldClose()) {
        
        /* Pre render logic */
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { // Fix this - Only update when inside button
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        } else {
            SetMouseCursor(MOUSE_CURSOR_ARROW);
        }

        Clay_SetPointerState((Clay_Vector2) { GetMouseX(), GetMouseY() }, IsMouseButtonDown(MOUSE_BUTTON_LEFT)); // Capture mouse state

        /* UI Layout */ 
        Clay_RenderCommandArray renderCommands = CreateLayout();

        /* Rendering logic */
        BeginDrawing();
        Clay_Raylib_Render(renderCommands);
        EndDrawing();

    }

    /* Cleanup */
    CloseWindow();

    return 0;
}
