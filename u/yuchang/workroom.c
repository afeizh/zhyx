#include <ansi.h>

inherit "/inherit/room/arearoom.c";

void create ()
{
        set ("short",HIR"神魔"NOR+HIC"雅苑"NOR);
        set ("long",

HIY"这里是（浪翻云）为工作学习而修建的工作室。\n"NOR
HIY"满目的清新的花草充满了整个的房间。\n"NOR
"\n\n"



HIG"...。..。☆.....。..。★。...。...。.....☆........。。\n"NOR
HIG"。..★..天籁妙，山水雅....。☆..。。....★.....。......\n"NOR
HIG"...。。..☆..。..........。★.。..醉露为酒玉为花...☆...\n"NOR
HIG"...。..★...若人问我归何处.。.☆。...。..。..★..。...。\n"NOR
HIG"。.......☆.。...。...★.。....彩云深处是我家.。☆......\n"NOR
HIG"...。..。☆.....。..。★。...。...。.....☆........。。\n"NOR

"\n\n"
);
       set("item_desc" , ([
"down": "房子里云雾缭绕，什么也看不清楚。\n",
]));
set("exits",
        ([
                "sanben" : "/u/sanben/workroom",
                "out" : "/u/yuchang/tianzun",
                "down" : "/d/city/guangchang",
                ]));


        set("no_death", 1);
        set("no_fight", 1);
        set("no_kill", 1);
        set("no_time", 1);
        set("sleep_room", 1);

        set("no_clean_up", 0);
        set("start_room", 1);
        setup();
        call_other("/clone/board/yuchang_b", "???");

}


void init()
{
        object me = this_player();
        tell_room( environment(me), CYN"主控电脑说道：请注意，" + me->query("title") + " "
                + me->query("name") + "(" + me->query("id") + ")" + " 来到了工作室！！！\n"NOR);

}

int valid_leave(object me, string dir)
{
        // temp access for future wiz.
        if (dir == "out" && !wizardp(me))
                return notify_fail(CYN "主控电脑" HIR "对你说道：咬死你！" HIG "魔神居" HIR "你也敢乱闯，还是好好呆着吧。\n" NOR);
        return ::valid_leave(me, dir);
}
