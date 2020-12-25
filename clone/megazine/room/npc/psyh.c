#include <ansi.h>

inherit NPC;
inherit F_DEALER;

mixed ask_me();

void create()
{
        set_name("派送丫鬟", ({ "paisong yahuan","yahuan","paisong"}) );
        set("title",HIW "〖地狱〗杂志社" NOR);
        set("gender", "女性" );
        set("age", 21);
        set("long", "这是一位的美丽发送小姐，她正在发送〖地狱〗杂志,看来你可以向她要杂志。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小姐");

        set("inquiry", ([
                "zazhi": "这是我们提供给玩家的〖地狱〗杂志。\n",
                "地狱杂志" : (: ask_me :),
                "杂志"     : (: ask_me :),
                "杂志目录" : (: ask_me :),
                "风狐" : "这个都不知道，你是不是人啊，他就是我们尊敬的社长啊！\n",
                "wfoxd": "这个都不知道，你是不是人啊，他就是我们尊敬的社长啊！\n",
        ]));

        set("chat_chance", 10);
        set("chat_msg", ({
                "派送小姐说道：我们的〖地狱〗杂志就是好，推出就得到了大家的认可。\n"
                "派送小姐对你说道：你没看过〖地狱〗杂志吗？那就太可惜了！\n",
                "派送小姐把手上的〖地狱〗杂志整理了一下。\n",
        }));

        setup();
        carry_object("clone/cloth/female5-cloth")->wear();
}

void init()
{
        add_action("do_follow","follow");
}

int do_follow(string arg)
{
        object me;

        if (arg != "me")
                return 0;

        me = this_player();

        message_vision("$N跟在$n的后面。\n", this_object(), me);
        set_leader(me);
        return 1;
}

mixed ask_me()
{
        object me, ob;

        me = this_player();
        if (me->query_temp("杂志") == 1)
                return "我已经给了你，现在每人最多就只能要一册。";

        command("say 好的！我马上给你。");
        ob = new("/clone/megazine/obj/zazhi6");
          ob->move(me);
          message_vision("聊天丫鬟给了$N一册〖地狱〗杂志目录。\n", me);
          me->set_temp("杂志", 1);
        return 1;
}
