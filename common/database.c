#pragma once

#include <stdio.h>
#include "../includes/sqlite3.h"
#include "constants.h"

static sqlite3 *database;
char* errorMessage;

static int print_callback(void* data, int argc, char** argv, char** azColName) {
    int i; 
    fprintf(stderr, "%s: ", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    }
    
    // return notes

    printf("\n"); 
    return 0; 
}

char* ExecQuery(char* query, int (*callback)(void*,int,char**,char**)) {

    int exit = 0;

    exit = sqlite3_open(DATABASE_PATH, &database);
    if (exit != SQLITE_OK) {
        printf("Error opening database: %s\n", sqlite3_errmsg(database));
        return (char *)DATABASE_ERROR_FAILED_TO_OPEN_DATABASE;
    }

    exit = sqlite3_exec(database, query, callback, 0, &errorMessage);
    if (exit != SQLITE_OK) {
        printf("Error creating table: %s\n", errorMessage);
        sqlite3_free(errorMessage);
        return (char *)DATABASE_ERROR_FAILED_TO_CREATE_TABLE;
    }

    sqlite3_close(database);

    return NULL;
}

char* NotNook_SetupDatabase() {
    char* createTableQuery = "CREATE TABLE IF NOT EXISTS notes ("
                            "id INTEGER PRIMARY KEY,"
                            "title TEXT NOT NULL,"
                            "content TEXT,"
                            "datetime DATETIME CURRENT_TIMESTAMP);";
    
    return ExecQuery(createTableQuery, NULL);
}

char* NotNook_GetNotes() {
    char* getQuery = "SELECT * FROM notes";
    
    return ExecQuery(getQuery, print_callback);
}

char* NotNook_SaveNote() {
    char* saveQuery = "INSERT INTO notes (title, content) VALUES ('Test Title', 'Test Content')";
    
    return ExecQuery(saveQuery, NULL);
}