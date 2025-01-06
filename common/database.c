#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/sqlite3.h"
#include "constants.h"

static sqlite3 *database;
char* errorMessage;

char* ExecQuery(char* query, int (*callback)(void*,int,char**,char**), void* store) {

    int exit = 0;

    exit = sqlite3_open(DATABASE_PATH, &database);
    if (exit != SQLITE_OK) {
        fprintf(stderr, "%s: %s\n", DATABASE_ERROR_FAILED_TO_OPEN_DATABASE, sqlite3_errmsg(database));
        return (char *)DATABASE_ERROR_FAILED_TO_OPEN_DATABASE;
    }

    exit = sqlite3_exec(database, query, callback, store, &errorMessage);
    if (exit != SQLITE_OK) {
        fprintf(stderr ,"%s: %s\n", DATABASE_ERROR_FAILED_TO_EXEC_QUERY, errorMessage);
        sqlite3_free(errorMessage);
        return (char *)DATABASE_ERROR_FAILED_TO_EXEC_QUERY;
    }

    sqlite3_close(database);

    return NULL;
}

char* Database_Setup() {
    char* createTableQuery = "CREATE TABLE IF NOT EXISTS notes ("
                            "id INTEGER PRIMARY KEY,"
                            "title TEXT NOT NULL,"
                            "content TEXT,"
                            "created_time TEXT);";
    
    return ExecQuery(createTableQuery, NULL, NULL);
}

char* Database_SaveNote() { // get values from arguments
    char* saveQuery = "INSERT INTO notes (title, content, created_time) VALUES ('balls', 'Test Content 2', datetime('now'));";
    
    return ExecQuery(saveQuery, NULL, NULL);
}

void* Database_GetAllNotes() {

    char* query = "SELECT title FROM notes;";

    sqlite3_stmt *pstmt; // prepared statements corresponding to sql
    int rc; // return code from sqlite

    rc = sqlite3_open_v2(DATABASE_PATH, &database, SQLITE_OPEN_READONLY, NULL);
    if ( rc ) {
        fprintf(stderr, "%s: %s\n", DATABASE_ERROR_FAILED_TO_OPEN_DATABASE, sqlite3_errmsg(database));
        sqlite3_close_v2(database);
        return NULL;
    }

    rc = sqlite3_prepare_v3(database, query, -1, 0, &pstmt, NULL);
    if ( rc ) {
        fprintf(stderr ,"%s: %s\n", DATABASE_ERROR_FAILED_TO_EXEC_QUERY, sqlite3_errmsg(database));
        sqlite3_finalize(pstmt);
        sqlite3_close_v2(database);
        return NULL;
    }

    char** titles = malloc(sizeof(char*) * NOTE_MAX_COUNT);

    unsigned int count = 0;
    while(sqlite3_step(pstmt) == SQLITE_ROW) {
        titles[count] = malloc(sizeof(char) * 100); // FIX : Determine max size of title
        strncpy(titles[count], sqlite3_column_text(pstmt, 0), 100);
        
        count++;
    }

    NoteTitles* noteTitles = malloc(sizeof(NoteTitles*) * count);
    noteTitles->titles = titles;
    noteTitles->count = count;

    sqlite3_finalize(pstmt);
    sqlite3_close_v2(database);

    return noteTitles;
}