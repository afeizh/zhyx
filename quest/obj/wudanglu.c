#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLU"������¼"NOR, ({ "qizhen-yulu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ��������¼��\n");
          }

    setup();
}

