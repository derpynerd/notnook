#pragma once

#include "../includes/clay.h"

/* Clay Init Constants */
const char* APP_NAME = "notnook";
const char* APP_LOGO_PATH = "resources/book.png";
const char* APP_FONT_PATH = "resources/Roboto-Regular.ttf";
const int APP_FONT_ID_BODY_16 = 0;

/* Database Constants */
const char* DATABASE_PATH = "resources/notes.db";
const char* DATABASE_ERROR_FAILED_TO_OPEN_DATABASE = "FAILED_TO_OPEN_DATABASE";
const char* DATABASE_ERROR_FAILED_TO_EXEC_QUERY = "FAILED_TO_EXEC_QUERY";

const char* DATABASE_SETUP_TABLE_QUERY =    "CREATE TABLE IF NOT EXISTS notes ("
                                            "id INTEGER PRIMARY KEY,"
                                            "title TEXT NOT NULL,"
                                            "content TEXT,"
                                            "created_time TEXT);";
const char* DATABASE_SAVE_NOTE_QUERY = "INSERT INTO notes (title, content, created_time) VALUES ('balls', 'Test Content 2', datetime('now'));";
const char* DATABASE_GET_TITLES_QUERY = "SELECT title FROM notes;";

/* Note Constants */
typedef struct {
    char** titles;
    unsigned int count;
} NoteTitles;

const unsigned int NOTE_MAX_COUNT = 15;

char* noteIds[15] = {"Note1", "Note2", "Note3", "Note4", "Note5", "Note6", "Note7", "Note8", "Note9", "Note10", "Note11", "Note12", "Note13", "Note14", "Notes15"};

/* Screen Constants */
const int screenWidth = 800;
const int screenHeight = 600;

const int sidebarWidth = 220;
const int sidebarHeight = screenHeight;
const int sidebarItemWidth = sidebarWidth - 20;
const int sidebarItemHeight = 30;

const int mainContentWidth = screenWidth - sidebarWidth;
const int mainContentHeight = screenHeight;

const int footerWidth = screenWidth;
const int footerHeight = 70;

const int textAreaWidth = screenWidth - sidebarWidth;
const int textAreaHeight = screenHeight - footerHeight;

/* Theme Colors */
const Clay_Color COLOR_BACKGROUND = (Clay_Color) {18, 18, 18, 255}; // dark gray
const Clay_Color COLOR_TEXT = (Clay_Color) {224, 224, 224, 255}; // white-ish gray
const Clay_Color COLOR_HIGHLIGHTED_TEXT = (Clay_Color) {216, 233, 241, 255}; // light blue

const Clay_Color COLOR_SIDEBAR_BACKGROUND = (Clay_Color) {40, 40, 40, 255}; // darkish gray
const Clay_Color COLOR_SIDEBAR_ITEM = (Clay_Color) {74, 144, 226, 255}; // muted blue
const Clay_Color COLOR_SIDEBAR_ITEM_HOVER = (Clay_Color) {90, 155, 255, 255}; // lighter blue
const Clay_Color COLOR_SIDEBAR_BORDER = (Clay_Color) {85, 85, 85, 255}; // medium gray

const Clay_Color COLOR_FOOTER_BACKGROUND = (Clay_Color) {45, 45, 45, 255}; // dark-ish gray
const Clay_Color COLOR_FOOTER_ITEM = (Clay_Color) {176, 176, 176, 255}; // light gray
const Clay_Color COLOR_FOOTER_ITEM_HOVER = (Clay_Color) {26, 115, 232, 255}; // blue

const Clay_Color COLOR_TEXTAREA_BACKGROUND = (Clay_Color) {30, 30, 30, 255}; // dark gray

const Clay_Color COLOR_ERROR_RED = (Clay_Color) {211, 47, 47, 255}; // red
const Clay_Color COLOR_WARNING_YELLOW = (Clay_Color) {255, 152, 0, 255}; // yellow
const Clay_Color COLOR_SUCCESS_GREEN = (Clay_Color) {76, 175, 80, 255}; // green

/* Generel Colors */
const Clay_Color COLOR_BLACK = (Clay_Color) {0, 0, 0, 255};
const Clay_Color COLOR_LIGHT = (Clay_Color) {224, 215, 210, 255};
const Clay_Color COLOR_RED = (Clay_Color) {255, 0, 0, 255};
const Clay_Color COLOR_ORANGE = (Clay_Color) {225, 138, 50, 255};
const Clay_Color COLOR_YELLOW = (Clay_Color) {255, 255, 51, 255};
