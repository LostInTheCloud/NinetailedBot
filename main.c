#include "main.h"

int main()
{
    pid = fork();
    if(!pid) //child
    {
        NICK = NICK2;
        TOKEN = TOKEN2;
    }
    else //parent
    {
        NICK = NICK1;
        TOKEN = TOKEN1;
    }
    setup();
    twirc_loop(s);
    twirc_kill(s);

    return 0;
}

void setup()
{
    s = twirc_init();
    twirc_callbacks_t* cbs = twirc_get_callbacks(s);

    //    cbs->connect         = handle_everything;
    cbs->welcome = handle_welcome;
    cbs->globaluserstate = handle_everything;
    cbs->capack = handle_everything;
    cbs->ping = handle_everything;
    cbs->join = handle_join;
    cbs->part = handle_everything;
    cbs->mode = handle_everything;
    cbs->names = handle_everything;
    cbs->privmsg = handle_message;
    cbs->whisper = handle_everything;
    cbs->action = handle_everything;
    cbs->notice = handle_everything;
    cbs->roomstate = handle_everything;
    cbs->usernotice = handle_everything;
    cbs->userstate = handle_everything;
    cbs->clearchat = handle_everything;
    cbs->clearmsg = handle_everything;
    cbs->hosttarget = handle_everything;
    cbs->reconnect = handle_everything;
    cbs->invalidcmd = handle_everything;
    cbs->other = handle_everything;
    //    cbs->disconnect      = handle_everything;
    cbs->outbound = handle_everything;

    err = twirc_connect(s, "irc.chat.twitch.tv", "6667", NICK, TOKEN);
}

void handle_everything(twirc_state_t* _, twirc_event_t* evt)
{
   printf("> %s\n", evt->raw);
}

void handle_welcome(twirc_state_t* _, twirc_event_t* evt)
{
    err = twirc_cmd_join(s, "#ninetaileddolphin");
    printf("joining ninetaileddolphin as \'theninetailedbot\' ... ");
    //todo: find out what ints shall be returned and check
}

void handle_join(twirc_state_t* _, twirc_event_t* evt)
{
    printf("successful\n");
    // fprintf(LOGFILE, "> %s\n", evt->raw);
}

void handle_message(twirc_state_t* _, twirc_event_t* evt)
{
    if(strcmp(evt->message, "!squid") == 0)
    {
        twirc_cmd_privmsg(s, "#ninetaileddolphin", "Squid1 Squid2 Squid3 Squid4 ");
        return;
    }

    if(strcmp(evt->message, "!skip") == 0 && strcmp(evt->origin, "thebwuah") == 0)
    {
        twirc_cmd_privmsg(s, "#ninetaileddolphin", "!skip");
        sleep(1);
        if(pid) //parent
        {
            pthread_t num;
            pthread_create(&num, NULL, check_out_my_, NULL);
            pthread_join(num, NULL);
        }
        return;
    }

    if(!strcmp(evt->origin, "thebwuah"))
        printf("hello master\n");
}

void* check_out_my_(void* _)
{
    twirc_cmd_privmsg(s, "#ninetaileddolphin", "This Skip was brought to you by NineTailedBot\nCheck it on Github");
    return NULL;
}