#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include "libtwirc.h"

#include "settings.h"

void setup();

void handle_everything(twirc_state_t* s, twirc_event_t* evt);

void handle_welcome(twirc_state_t* s, twirc_event_t* evt);

void handle_join(twirc_state_t* s, twirc_event_t* evt);

void handle_message(twirc_state_t* s, twirc_event_t* evt);

void* check_out_my_(void* _);

int err, pid;
twirc_state_t* s;
char *NICK, *TOKEN;