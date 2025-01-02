#include <stdlib.h>

#define CLAY_IMPLEMENTATION
#include "includes/clay.h"

#include "includes/renderer/clay_renderer_raylib.c"

const Clay_Color COLOR_LIGHT = (Clay_Color) {224, 215, 210, 255};
const Clay_Color COLOR_RED = (Clay_Color) {255, 0, 0, 255};

const int screenWidth = 800;
const int screenHeight = 600;

Clay_RenderCommandArray CreateLayout(void);

int main() {
    
    Clay_Raylib_Initialize(screenWidth, screenHeight, "Notebook", 
    FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

    uint64_t clayRequiredMemory = Clay_MinMemorySize();
    Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(clayRequiredMemory, malloc(clayRequiredMemory));

    Clay_Initialize(clayMemory, (Clay_Dimensions) {
       .width = GetScreenWidth(),
       .height = GetScreenHeight()
    });

    Clay_SetMeasureTextFunction(Raylib_MeasureText);

    while (!WindowShouldClose()) {
        
        /* Pre render logic */
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            SetMousePosition(GetScreenWidth(), GetScreenHeight());
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
    
    CLAY(CLAY_ID("OuterContainer"), CLAY_LAYOUT({ .sizing = {CLAY_SIZING_FIXED(500), CLAY_SIZING_FIXED(500)} }), CLAY_RECTANGLE({ .color = COLOR_LIGHT })) {
        CLAY(CLAY_ID("SideBar"),
            CLAY_LAYOUT({ .layoutDirection = CLAY_TOP_TO_BOTTOM, .sizing = { .width = screenWidth/4, .height = screenHeight }, .padding = { 10, 10 } }),
            CLAY_RECTANGLE({ .color = COLOR_RED })
        ) {}
            
        //     CLAY(CLAY_ID("ProfilePicture"), CLAY_LAYOUT({ .sizing = { .width = CLAY_SIZING_FIXED(60), .height = CLAY_SIZING_FIXED(60) }})) {}
            // CLAY_TEXT(CLAY_STRING("Clay - UI Library"), CLAY_TEXT_CONFIG({ .fontSize = 16 }));

        //     // Standard C code like loops etc work inside components
        //     for (int i = 0; i < 5; i++) {
        //         SidebarItemComponent();
        //     }
        // }

        // CLAY(CLAY_ID("MainContent"), CLAY_LAYOUT({ .sizing = { .width = CLAY_SIZING_FIXED(200), .height = CLAY_SIZING_FIXED(200) }}), CLAY_RECTANGLE({ .color = COLOR_LIGHT })) {}
    }

    return Clay_EndLayout();
}