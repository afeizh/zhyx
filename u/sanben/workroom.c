#include <ansi.h>
#include <room.h>
inherit ROOM;

#define QINGTIAN    "/u/sanben/special/tianzi/qingtian.c"
#define SPECIAL     "/data/item/special/"


int is_chat_room()
{
        return 1;
}

void create()
{       object ob;
        set("short", HIY "\n\n                大笨工作室" NOR);
        set("long", HIY "\n\n"
"这里想必就是传说中的笨蛋聚居所,\n"
"有道是：不是笨蛋不进来，进来就是大笨蛋。\n"
"所以欢迎你，笨蛋!\n\n" NOR
);

        set("exits", ([
                 "gc" : "/d/city/guangchang",
                   "kd" : "/d/city/kedian",
                //   "idl" : "/u/idle/workroom",
        ]));
        set("objects", ([
                "/clone/money/coin" : 1,
        ]));

        set("no_fight", 1);
        set("valid_startroom", 1);
        set("sleep_room", 1);
        set("chat_room",1);
        set("valid_startroom", 1);
        set("no_stab",1);
      //   set("outdoors", "city");
        setup();
                 "/clone/board/sanben_b"->foo();

}

void init()
{

    add_action("do_giveout", "giveout");
    add_action("do_place", "place");
    add_action("do_ip", "ip");
    add_action("do_start", "start");
    add_action("do_pretend", "pretend");
    add_action("do_test", "test");
}
/*
int do_giveout()
{
   object gift, *users;
   int i;

   users = users();
   for(i=0;i<sizeof(users);i++)
   {
       gift = new("/clone/money/gold");
       gift->set_amount(10);
       gift->move(users[i]);
       tell_object(users[i],HIR"叮~~~天降财神到~~~\n"NOR
       HIG"恭喜你收到了中华英雄巫师组分发的礼物,本次礼物是"NOR YEL"十两黄金。\n"NOR);

   }

   return 1;
}*/
/*

int do_giveout()
{
   object gift, *users;
   int i;

   users = users();
   for(i=0;i<sizeof(users);i++)
   {
       gift = new("/u/sanben/giftpack");
       gift->move(users[i]);
       tell_object(users[i],HIR"叮~~~天降财神到~~~\n"NOR
       HIG"恭喜你收到了中华英雄巫师组分发的小礼物包，\n请open giftpack看看你的运气。\n"NOR);
   }
   return 1;
}*/

int do_giveout()
{
   object gift, *users;
   int i;

   users = users();
   for(i=0;i<sizeof(users);i++)
   {
       gift = new("/u/sanben/obj/shenyou_worst");
       gift->move(users[i]);
       tell_object(users[i],HIR"叮~~~天降财神到~~~\n"NOR
       HIG"恭喜你收到了中华英雄巫师组分发的春节礼物--最最劣质神佑果。\n\n"NOR);
   }
   return 1;
}




/*
int do_place()
{
   string *alldir, dir, dir_name, *allfile,file;
   int i;
   object place, gift;
   mapping dir_list = ([
                "/d/beijing/" : "北京城",
                "/d/changan/" : "长安城",
                "/d/city/" : "扬州城",
                "/d/city3/" : "成都城",
                "/d/dali/" : "大理城",
                "/d/guanwai/" : "关外",
                "/d/hangzhou/" : "杭州城",
                "/d/kaifeng/" : "开封城",
                "/d/jingzhou/" : "荆州城",
                "/d/luoyang/" : "洛阳城",
                "/d/lingxiao/" : "凌霄城",
                "/d/quanzhen/" : "终南山",
                "/d/wudang/" : "武当山",
                "/d/zhongzhou/" : "中州城",
                "/d/shaolin/" : "少林寺地区",
                "/d/wudu/" : "五毒教地区",
                "/d/xingxiu/" : "西域",
                "/d/huashan/" : "华山",
                "/d/emei/" : "峨眉山",
    ]);
   remove_call_out("remind");
   call_out("remind", 3500);

   alldir = keys(dir_list);

   dir = alldir[random(sizeof(alldir))];
   if ( ! dir || dir == 0 ) dir = "/d/wudang/";
   dir_name = dir_list[dir];

   message( "gift", BLINK HIY"【天降礼物】" NOR HIG
            "天神在" + dir_name + "撒下了几张礼物兑换劵，大家何不群起而寻之！\n"NOR, users() );

   allfile = get_dir(dir);

   for(i = 0;i < 20;i++)
   {
      file = dir + allfile[random(sizeof(allfile))];

      if ( file[<2..<1] != ".c") continue;

      write(file + "\n");
      if ( find_object(file) )
         place = find_object(file);
      else
          place = load_object(file);

      if (  place )
      {
          if ( i <= 2 ) gift = new("/u/sanben/giftcard1");
          else
          if ( i > 2 && i <= 7 ) gift = new("/u/sanben/giftcard2");
          else
             gift = new("/u/sanben/giftcard3");
          gift->move(place);
          tell_room(place, HIC"突然只见天神从云端里探出头来，撒下一张礼劵。\n"NOR);
      }
   }
   return 1;


}

void remind()
{

   message( "gift", BLINK HIY"【天降礼物】" NOR HIR
            "天神将在三分钟后分发奖劵，请要寻宝的人做好准备。\n"NOR, users() );

   remove_call_out("do_place");
   call_out("do_place", 180);


}*/

int do_ip()
{
    object *users, gift;
    int i, ii, same, num;
    string *ip_list, ip;

    users = users();


    for( i = 0; i < sizeof(users); i++)
    {
       same = 0;
       num = sizeof(ip_list);
       ip = query_ip_number(users[i]);

       if ( num > 0 )
       {
          for(ii=0;ii<num;ii++)
          {
             if ( ip_list[ii] == ip ) same = 1;
          }
       }


       if ( same == 0 )
       {
           gift = new("/u/sanben/giftpack");
           gift->move(users[i]);

           tell_object(users[i],HIR"叮~~~天降财神到~~~\n"NOR
           HIG"恭喜你收到了中华英雄巫师组分发的小礼物包，\n请open giftpack看看你的运气。\n"NOR);
       }

       if ( ! ip_list )
          ip_list = ({ip});
       else
          ip_list += ({ip});

    }
    return 1;
}

int do_start1()
{
    remove_call_out("count_down");
    call_out("count_down", 5, 5);
    return 1;
}

int do_start()
{
    remove_call_out("do_ip");
    call_out("do_ip", 60);
    message( "story", HIY"【天降财神】天神将在一分种"
              "后按IP发放礼物，请大家做好准备! \n"NOR, users() );
    return 1;
}


void count_down(int i)
	{


		 message( "story", HIY"【天降财神】天神将在" + chinese_number(i) +
                        "秒后按IP发放礼物，请大家做好准备! \n"NOR, users() );
		i = i-1;
		if (i > 0 )
		{

			remove_call_out("count_down");
                	call_out("count_down", 1, i);
		}
		else
		{	message( "story", "\n", users() );
			message( "story", HIG"【天降财神】" + HIY"现在发放礼物!\n"NOR, users() );
			remove_call_out("do_ip");
                	call_out("do_ip", 2, i);
		}
	}


void do_pretend()
{
     object me = this_player();

              me->set_temp("apply/name", ({ "北丑" }));
              me->set_temp("apply/short", ({ "武林泰斗「北戏子」北丑(bei chou)" }));
              me->set_temp("apply/long", ({ "武林泰斗「北戏子」北丑(bei chou)" }));

}
